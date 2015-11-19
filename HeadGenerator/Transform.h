#pragma once

#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QString>

class Quatern
{

public:
	Quatern							();
	Quatern							(const Quatern &q);
	Quatern							(const cv::Matx33f &mat);
	Quatern							(const cv::Vec3f &euler);
	Quatern							(const float &inR, const cv::Vec3f &inV);
	Quatern							(const cv::Vec3f &axis, const float &angle);
	Quatern							(const cv::Vec3f &from, const cv::Vec3f &to);

	void			set				(const float &inR, const cv::Vec3f &inV);
	const float&	operator[]		(int i) const;

	float			getR			() const;
	cv::Vec3f		getV			() const;
	float			getAngle		() const;
	cv::Vec3f		getAxis			() const;

	Quatern			operator*		(const Quatern &q) const;
	cv::Vec3f		operator*		(const cv::Vec3f &p) const;
	bool			operator==		(const Quatern &oth) const;

	Quatern			inverse			() const;

	cv::Matx33f		toMat			() const;
	cv::Vec3f		toEuler			() const;

	Quatern			slerp			(Quatern &q, float t) const;

	float			m_r;
	cv::Vec3f		m_v;
};

class Transform
{

public:
	Transform						();
	Transform						(const Transform &t);
	Transform						(const float &inScale, const cv::Vec3f &inTrans, const Quatern &inRot);

	void			load			(const QString &fileName);
	void			save			(const QString &fileName);

	void			setTransform	(const float &inScale, const cv::Vec3f &inTrans, const Quatern &inRot);
	void			setScale		(const float &inScale);
	void			setTrans		(const cv::Vec3f &inTrans);
	void			setRot			(const Quatern &inRot);
	void			setCenter		(const cv::Vec3f &center);

	void			updateMat		();

	float			getScale		() const;
	cv::Vec3f		getTrans		() const;
	Quatern			getRot			() const;

	cv::Vec3f		getCenter		() const;

	Transform		operator*		(const Transform &t) const;
	cv::Vec3f		operator*		(const cv::Vec3f &v) const;

	Transform		inverse			() const;

	cv::Matx44f		toMat			() const;

	Quatern			m_rot;
	float			m_scale;
	cv::Vec3f		m_trans;

	cv::Vec3f		m_center;

	cv::Matx44f		m_mat;
};
