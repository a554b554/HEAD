#include "HeadDetector.h"

#include "stasm_dll.h"

#include <QFile>
#include <QTextStream>

static const int iEnd76ToMid76[] =
{
	0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13,	14,	15,	16,	17,	18,
	19,	20,	21,	22,	23,	24,	25,	26,	27,	68,	28,	69,	29,	70,	30,	71,	31,	32,	72,
	33,	73,	34,	74,	35,	75,	36,	37,	38,	39,	40,	41,	42,	43,	44,	45,	46,	47,	48,
	49,	50,	51,	52,	53,	54,	55,	56,	57,	58,	59,	60,	61,	62,	63,	64,	65,	66,	67
};

HeadDetector::HeadDetector()
{
	m_originalImage = NULL;
}

HeadDetector::~HeadDetector()
{}

void HeadDetector::setOriginalImage(cv::Mat& originalImage)
{
	m_originalImage = &originalImage;
}

cv::Mat& HeadDetector::getResultFeatures()
{
	return m_features;
}

void HeadDetector::runDetect()
{
	imwrite("Tmp/original.png", *m_originalImage);
	char* imgArray = new char[m_originalImage->rows * m_originalImage->cols * 3];
	for (int hI = 0; hI < m_originalImage->rows; hI++)
		for (int wI = 0; wI < m_originalImage->cols; wI++)
			for (int dimI = 0; dimI < 3; dimI++)
				imgArray[(hI * m_originalImage->cols + wI) * 3 + dimI] = m_originalImage->at<cv::Vec4b>(hI, wI)[dimI];
	int featureNum;
	int features[200];
	AsmSearchDll(&featureNum, features,
		"Tmp/original.png", imgArray, m_originalImage->cols, m_originalImage->rows, 1,
		"../data/mu-76-2d.conf", "../data/mu-76-2d.conf");
	delete[] imgArray;
	QFile imgFile("Tmp/original.png");
	imgFile.remove();

	m_features = cv::Mat::zeros(1, 76, CV_32FC2);
	for (int featureI = 0; featureI < 76; featureI++)
		m_features.at<cv::Vec2f>(0, featureI) = cv::Vec2f(
			features[iEnd76ToMid76[featureI] * 2 + 0],
			features[iEnd76ToMid76[featureI] * 2 + 1]);
}

bool HeadDetector::loadFeatures(QString fileName)
{
	QFile featureFile(fileName);
	featureFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream featureStream(&featureFile);
	int featureNum;
	featureStream >> featureNum;
	m_features = cv::Mat::zeros(1, featureNum, CV_32FC2);
	for (int i = 0; i < featureNum; i++)
		featureStream >> m_features.at<cv::Vec2f>(0, i)[0] >> m_features.at<cv::Vec2f>(0, i)[1];
	featureFile.close();
	return true;
}

bool HeadDetector::saveFeatures(QString fileName)
{
	QFile featureFile(fileName);
	featureFile.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream featureStream(&featureFile);
	featureStream << "76\n";
	for (int i = 0; i < 76; i++)
		featureStream << m_features.at<cv::Vec2f>(0, i)[0] << " " << m_features.at<cv::Vec2f>(0, i)[1] << "\n";
	featureFile.close();
	return true;
}
