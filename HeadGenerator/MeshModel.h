#pragma once

#include "Container.h"

#include <QVector>
#include <QString>

class Mesh;

class MeshModel
{
public:

	MeshModel								();
	~MeshModel								();

	void				clear				();

	bool				loadModel			(QString fileName);
	bool				saveModel			(QString fileName);

	int					faceNum;
	int					posNum;
	int					texNum;

	int*				posInds;
	int*				texInds;
	int*				posCounts;
	QVector<int>*		posFaceInds;

	cml::Vec3f*			curPos;
	cml::Vec3f*			curNor;
	cml::Vec2f*			curTex;
};
