#pragma once

#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QString>

class HeadDetector
{
public:

	HeadDetector						();
	~HeadDetector						();

	void		setOriginalImage		(cv::Mat& originalImage);

	cv::Mat&	getResultFeatures		();

	void		runDetect				();

	bool		loadFeatures			(QString fileName);
	bool		saveFeatures			(QString fileName);

private:

	cv::Mat*	m_originalImage;

	cv::Mat		m_features;
};
