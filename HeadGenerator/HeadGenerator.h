#pragma once

#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#include "Transform.h"

#include "MeshModel.h"

class HeadGenerator
{
public:
	HeadGenerator						();
	~HeadGenerator						();

	void			reset				();

	void			setSize				(int width, int height);
	void			setFeatures			(cv::Mat *features);
	void			setHeadModel		(MeshModel& headModel);

	void			runHeadGenerate		();

	void			getTransform		(double& x, double& y, double& r);
	Transform&		getTransform		();
	double			getHeadCenter		();

	int				getBoundaryNum		();
	cv::Mat&		getBoundaryVertices	();

private:
	void			resetModel			();
	void			updateModel			();
	void			updateBoundary		();
	void			updateFeature		();
	void			updateNormal		();
	void			calculateBoundary	();
	void			pojectionEstimate	(bool init);
	void			coefficientEstimate	();
	void			prepareResultArrays	();

	int				m_imageWidth;
	int				m_imageHeight;

	int				m_estimateDone;
	int				m_activeFeatureNumber;
	int				m_boundaryFaceNumber;
	int				m_interiorFaceNumber;
	int				m_boundaryVertexNumber;

	cv::Mat			m_defaultFeatureIndexArray;
	cv::Mat			m_fittingFeatureIndexArray;
	cv::Mat			m_featureWeightArray;
	cv::Mat			m_featureActiveArray;
	cv::Mat			m_averageHeadArray;
	cv::Mat			m_headFaceNeighborArray;
	cv::Mat			m_headFaceIndexArray;
	cv::Mat			m_headFaceBoundaryArray;
	cv::Mat			m_headFaceNormalFlagArray;
	cv::Mat			m_boundaryIndexArray;
	cv::Mat			m_basisHeadValueArray;
	cv::Mat			m_basisHeadVectorArray;
	cv::Mat			m_basisCoefficientArray;
	cv::Mat			m_basisLambdaMatInv;
	cv::Mat			m_fittingHeadArray;
	cv::Mat			m_projectFittingHeadArray;
	cv::Mat			m_modelFeatureArray;
	cv::Mat			m_projectModelFeatureArray;
	cv::Mat			m_imageFeatureArray;
	cv::Mat			m_featureDepthArray;
	cv::Mat			m_resultFeatureArray;
	cv::Mat			m_boundaryVertexArray;

	Transform		m_transform;
	float			m_baseDepth;

	int				m_estimateIteration;
	int				m_projectionIteration;
	float			m_coefEnergy;

	MeshModel*		m_headModel;
};
