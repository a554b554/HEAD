#include "MeshModel.h"

#include <QFile>
#include <QTextStream>

#include <vector>

using namespace cml;

MeshModel::MeshModel()
{
	faceNum = 0;
	posNum = 0;
	texNum = 0;

	posInds = NULL;
	texInds = NULL;
	posCounts = NULL;
	posFaceInds = NULL;

	curPos = NULL;
	curNor = NULL;
	curTex = NULL;
}

MeshModel::~MeshModel()
{}

void MeshModel::clear()
{
	faceNum = 0;
	posNum = 0;
	texNum = 0;

	delete[] posInds;
	delete[] texInds;
	delete[] posCounts;
	delete[] posFaceInds;
	delete[] curPos;
	delete[] curNor;
	delete[] curTex;

	posInds = NULL;
	texInds = NULL;
	posCounts = NULL;
	posFaceInds = NULL;
	curPos = NULL;
	curNor = NULL;
	curTex = NULL;
}

bool MeshModel::loadModel(QString fileName)
{
	QFile modelFile(fileName);
	if (!modelFile.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;
	QTextStream modelStream(&modelFile);

	QVector<Vec3f> readVertices;
	QVector<Vec2f> readTexCoords;
	QVector<int> readVertexInds;
	QVector<int> readTexCoordInds;

	faceNum = 0;
	while (true){
		if (modelStream.atEnd())
			break;
		QString line = modelStream.readLine();
		QTextStream lineStream(&line);

		if (line.startsWith("v ")){
			lineStream.seek(2);
			Vec3f vertex;
			lineStream >> vertex[0] >> vertex[1] >> vertex[2];
			readVertices.push_back(vertex);
		}
		else if (line.startsWith("vt ")){
			lineStream.seek(3);
			Vec2f texCoord;
			lineStream >> texCoord[0] >> texCoord[1];
			readTexCoords.push_back(texCoord);
		}
		else if (line.startsWith("f ")){
			faceNum++;
			lineStream.seek(2);
			Vec3i vertexInd(0, 0, 0);
			Vec3i texCoordInd(0, 0, 0);
			char dummyChar;
			int dummyInt;
			for (int dimI = 0; dimI < 3; ++dimI){
				lineStream >> vertexInd[dimI];
				lineStream >> dummyChar;
				if (dummyChar == '/'){
					lineStream >> texCoordInd[dimI];
					lineStream >> dummyChar;
					if (dummyChar == '/')
						lineStream >> dummyInt;
				}
				readVertexInds.push_back(vertexInd[dimI] - 1);
				readTexCoordInds.push_back(texCoordInd[dimI] - 1);
			}
			lineStream.skipWhiteSpace();
			if (!lineStream.atEnd()){
				faceNum++;
				readVertexInds.push_back(vertexInd[0] - 1);
				readVertexInds.push_back(vertexInd[2] - 1);
				readTexCoordInds.push_back(texCoordInd[0] - 1);
				readTexCoordInds.push_back(texCoordInd[2] - 1);
				lineStream >> dummyInt;
				readVertexInds.push_back(dummyInt - 1);
				lineStream >> dummyChar;
				if (dummyChar == '/'){
					lineStream >> dummyInt;
					readTexCoordInds.push_back(dummyInt - 1);
					lineStream >> dummyChar;
					if (dummyChar == '/')
						lineStream >> dummyInt;
				}
			}
		}
	}
	modelFile.close();

	if (readVertexInds.size() != faceNum * 3 || readTexCoordInds.size() != faceNum * 3){
		printf("Error reading head model, incorrect face vertex size!\n");
		return false;
	}

	posNum = readVertices.size();
	texNum = readTexCoords.size();

	delete[] posInds;
	delete[] texInds;
	delete[] posCounts;
	delete[] posFaceInds;
	delete[] curPos;
	delete[] curNor;
	delete[] curTex;
	posInds = new int[faceNum * 3];
	texInds = new int[faceNum * 3];
	posCounts = new int[posNum];
	posFaceInds = new QVector<int>[posNum];
	curPos = new Vec3f[posNum];
	curNor = new Vec3f[faceNum];
	curTex = new Vec2f[texNum];

	memcpy(posInds, &readVertexInds[0], sizeof(int) * faceNum * 3);
	memcpy(texInds, &readTexCoordInds[0], sizeof(int) * faceNum * 3);

	memset(posCounts, 0, sizeof(int) * posNum);
	for (int faceI = 0; faceI < faceNum; ++faceI){
		for (int vertexI = 0; vertexI < 3; vertexI++)
			posCounts[posInds[faceI * 3 + vertexI]]++;
	}

	for (int faceI = 0; faceI < faceNum; faceI++){
		for (int vertexI = 0; vertexI < 3; vertexI++)
			posFaceInds[posInds[faceI * 3 + vertexI]].append(faceI * 3 + vertexI);
	}

	memcpy(curPos, readVertices.data(), sizeof(Vec3f) * posNum);
	memcpy(curTex, readTexCoords.data(), sizeof(Vec2f) * texNum);

	return true;
}

bool MeshModel::saveModel(QString fileName)
{
	QFile modelFile(fileName);
	if (!modelFile.open(QIODevice::WriteOnly | QIODevice::Text))
		return false;
	QTextStream modelStream(&modelFile);

	for (int posI = 0; posI < posNum; posI++)
		modelStream << "v " << curPos[posI][0] << " " << curPos[posI][1] << " " << curPos[posI][2] << "\n";
	for (int posI = 0; posI < texNum; posI++)
		modelStream << "vt " << curTex[posI][0] << " " << curTex[posI][1] << "\n";
	for (int faceI = 0; faceI < faceNum; faceI++)
		modelStream << "f " << posInds[faceI * 3] + 1 << "/" << texInds[faceI * 3] + 1 << " " << posInds[faceI * 3 + 1] + 1 << "/" << texInds[faceI * 3 + 1] + 1 << " " << posInds[faceI * 3 + 2] + 1 << "/" << texInds[faceI * 3 + 2] + 1 << "\n";
	modelFile.close();
	return true;
}
