#include "Transform.h"

#include <QFile>
#include <QTextStream>

using namespace cv;

Quatern::Quatern()
{
	m_r = 1.f;
	m_v = Vec3f(0, 0, 0);
}

Quatern::Quatern(const Quatern &q)
{
	m_r = q.getR();
	m_v = q.getV();
}

Quatern::Quatern(const Matx33f &mat)
{
	float trace = mat(0, 0) + mat(1, 1) + mat(2, 2);
	if (trace > 0.f){
		float s = 0.5f / sqrtf(trace + 1.f);
		m_r = 0.25f / s;
		m_v = Vec3f(mat(2, 1) - mat(1, 2), mat(0, 2) - mat(2, 0), mat(1, 0) - mat(0, 1)) * s;
	}
	else{
		if (mat(0, 0) > mat(1, 1) && mat(0, 0) > mat(2, 2)){
			float s = 2.f * sqrtf(1.f + mat(0, 0) - mat(1, 1) - mat(2, 2));
			m_r = (mat(2, 1) - mat(1, 2)) / s;
			m_v = Vec3f(0.25f * s ,(mat(0, 1) + mat(1, 0)) / s ,(mat(0, 2) + mat(2, 0)) / s);
		}
		else if (mat(1, 1) > mat(2, 2)){
			float s = 2.f * sqrtf(1.f + mat(1, 1) - mat(0, 0) - mat(2, 2));
			m_r = (mat(0, 2) - mat(2, 0)) / s;
			m_v = Vec3f((mat(0, 1) + mat(1, 0)) / s, 0.25f * s ,(mat(1, 2) + mat(2, 1)) / s);
		}
		else {
			float s = 2.f * sqrtf(1.f + mat(2, 2) - mat(0, 0) - mat(1, 1));
			m_r = (mat(1, 0) - mat(0, 1)) / s;
			m_v = Vec3f((mat(0, 2) + mat(2, 0)) / s ,(mat(1, 2) + mat(2, 1)) / s ,0.25f * s);
		}
	}
}

Quatern::Quatern(const Vec3f &euler)
{
	Vec3f cosVal, sinVal;
	for (int dimI = 0; dimI < 3; dimI++){
		cosVal[dimI] = cosf(euler[dimI] / 2.f);
		sinVal[dimI] = sinf(euler[dimI] / 2.f);
	}
	m_r = cosVal[0] * cosVal[1] * cosVal[2] + sinVal[0] * sinVal[1] * sinVal[2];
	m_v[0] = sinVal[0] * cosVal[1] * cosVal[2] - cosVal[0] * sinVal[1] * sinVal[2];
	m_v[1] = cosVal[0] * sinVal[1] * cosVal[2] + sinVal[0] * cosVal[1] * sinVal[2];
	m_v[2] = cosVal[0] * cosVal[1] * sinVal[2] - sinVal[0] * sinVal[1] * cosVal[2];
}

Quatern::Quatern(const float &inR, const Vec3f &inV)
{
	m_r = inR;
	m_v = inV;
}

Quatern::Quatern(const Vec3f &axis, const float &angle)
{
	m_r = cosf(angle * 0.5f);
	float axisL = sqrtf(axis.dot(axis));
	Vec3f axisN = axis * (1.f / axisL);
	m_v = axisN * sinf(angle * 0.5f);
}

Quatern::Quatern(const Vec3f &from, const Vec3f &to)
{
	float fromLenSq = from.dot(from);
	float toLenSq = to.dot(to);
	if (fromLenSq < toLenSq){
		Vec3f mid = from * sqrtf(toLenSq / fromLenSq) + to;
		float fac = 1.f / sqrtf(mid.dot(mid) * toLenSq);
		m_r = mid.dot(to) * fac;
		m_v = mid.cross(to) * fac;
	}
	else{
		Vec3f mid = from + to * sqrtf(fromLenSq / toLenSq);
		float fac = 1.f / sqrtf(mid.dot(mid) * fromLenSq);
		m_r = from.dot(mid) * fac;
		m_v = from.cross(mid) * fac;
	}
}

void Quatern::set(const float &inR, const Vec3f &inV)
{
	float ratio = 1.f / sqrtf(inR * inR + inV.dot(inV)); 
	m_r = inR * ratio;
	m_v = inV * ratio;
}

const float &Quatern::operator[](int i) const
{
	return (i == 0) ? m_r : m_v[i - 1];
}

float Quatern::getR() const
{
	return m_r;
}

Vec3f Quatern::getV() const
{
	return m_v;
}

float Quatern::getAngle() const
{
	float vL = sqrtf(m_v.dot(m_v));
	return 2.f * atan2f(vL, m_r);
}

Vec3f Quatern::getAxis() const
{
	float vL = sqrtf(m_v.dot(m_v));
	return m_v * (1.f / vL);
}

Quatern Quatern::operator*(const Quatern &q) const
{
	return Quatern(q.getR() * m_r - m_v.dot(q.getV()), q.getV() * m_r + m_v * q.getR() + m_v.cross(q.getV()));
}

Vec3f Quatern::operator*(const Vec3f &p) const
{
	Vec3f v2 = m_v + m_v;
	Vec3f vsq2(m_v[0] * v2[0], m_v[1] * v2[1], m_v[2] * v2[2]);
	Vec3f rv2 = v2 * m_r;
	Vec3f vv2(m_v[1] * v2[2], m_v[0] * v2[2], m_v[0] * v2[1]);
	return Vec3f(
		p[0] * (1.f - vsq2[1] - vsq2[2]) + p[1] * (vv2[2] - rv2[2]) + p[2] * (vv2[1] + rv2[1]),
		p[1] * (1.f - vsq2[2] - vsq2[0]) + p[2] * (vv2[0] - rv2[0]) + p[0] * (vv2[2] + rv2[2]),
		p[2] * (1.f - vsq2[0] - vsq2[1]) + p[0] * (vv2[1] - rv2[1]) + p[1] * (vv2[0] + rv2[0]));
}

bool Quatern::operator==(const Quatern &p) const
{
	return (m_r == p.getR() && m_v == p.getV()) || (m_r == -p.getR() && m_v == -p.getV());
}

Quatern Quatern::inverse() const
{
	return Quatern(-m_r, m_v);
}

Matx33f Quatern::toMat() const
{
	Matx33f mat;
	mat(0, 0) = m_r * m_r + m_v[0] * m_v[0] - m_v[1] * m_v[1] - m_v[2] * m_v[2];
	mat(0, 1) = 2.f * (m_v[0] * m_v[1] - m_r * m_v[2]);
	mat(0, 2) = 2.f * (m_r * m_v[1] + m_v[0] * m_v[2]);
	mat(1, 0) = 2.f * (m_v[0] * m_v[1] + m_r * m_v[2]);
	mat(1, 1) = m_r * m_r - m_v[0] * m_v[0] + m_v[1] * m_v[1] - m_v[2] * m_v[2];
	mat(1, 2) = 2.f * (m_v[1] * m_v[2] - m_r * m_v[0]);
	mat(2, 0) = 2.f * (m_v[0] * m_v[2] - m_r * m_v[1]);
	mat(2, 1) = 2.f * (m_r * m_v[0] + m_v[1] * m_v[2]);
	mat(2, 2) = m_r * m_r - m_v[0] * m_v[0] - m_v[1] * m_v[1] + m_v[2] * m_v[2];
	return mat;
}

Vec3f Quatern::toEuler() const
{
	Vec3f euler;
	euler[0] = atan2f(2.f * (m_r * m_v[0] + m_v[1] * m_v[2]), 1.f - 2.f * (m_v[0] * m_v[0] + m_v[1] * m_v[1]));
	euler[1] = asinf(2.f * (m_r * m_v[1] - m_v[2] * m_v[0]));
	euler[2] = atan2f(2.f * (m_r * m_v[2] + m_v[0] * m_v[1]), 1.f - 2.f * (m_v[1] * m_v[1] + m_v[2] * m_v[2]));
	return euler;
}

Quatern Quatern::slerp(Quatern &q, float t) const
{
	Quatern qm;
	float cosHalfTheta = m_r * q.getR() + m_v.dot(q.getV());
	if (abs(cosHalfTheta) >= 1.f)
		return Quatern(m_r, m_v);
	float halfTheta = acos(cosHalfTheta);
	float sinHalfTheta = sqrtf(1.f - cosHalfTheta * cosHalfTheta);
	if (fabs(sinHalfTheta) < 0.001f)
		return Quatern(m_r * 0.5f + q.getR() * 0.5f, m_v * 0.5f + q.getV() * 0.5f);
	float ratioA = sinf((1.f - t) * halfTheta) / sinHalfTheta;
	float ratioB = sinf(t * halfTheta) / sinHalfTheta; 
	return Quatern(m_r * ratioA + q.getR() * ratioB, m_v * ratioA + q.getV() * ratioB);
}

Transform::Transform()
{
	m_scale = 1.f;
	updateMat();
}

Transform::Transform(const Transform &t)
{
	m_scale = t.getScale();
	m_trans = t.getTrans();
	m_rot = t.getRot();
	updateMat();
}

Transform::Transform(const float &inScale, const Vec3f &inTrans, const Quatern &inRot)
{
	m_scale = inScale;
	m_trans = inTrans;
	m_rot = inRot;
	updateMat();
}

void Transform::load(const QString &fileName)
{
	QFile transformFile(fileName);
	if (!transformFile.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	char buffer[1280];
	Matx33f rotMat;
	transformFile.readLine(buffer, 256);
	sscanf_s(buffer, "%f %f %f\n", &rotMat(0, 0), &rotMat(0, 1), &rotMat(0, 2));
	transformFile.readLine(buffer, 256);
	sscanf_s(buffer, "%f %f %f\n", &rotMat(1, 0), &rotMat(1, 1), &rotMat(1, 2));
	transformFile.readLine(buffer, 256);
	sscanf_s(buffer, "%f %f %f\n", &rotMat(2, 0), &rotMat(2, 1), &rotMat(2, 2));
	Vec3f transVec;
	transformFile.readLine(buffer, 256);
	sscanf_s(buffer, "%f %f %f\n", &transVec[0], &transVec[1], &transVec[2]);
	float scale = 1.0f;
	transformFile.readLine(buffer, 256);
	sscanf_s(buffer, "%f\n", &scale);
	transformFile.readLine(buffer, 256);
	sscanf_s(buffer, "%f %f %f\n", &m_center[0], &m_center[1], &m_center[2]);
	transformFile.close();
	setTransform(scale, transVec, Quatern(rotMat));
}

void Transform::save(const QString &fileName)
{
	QFile transformFile(fileName);
	transformFile.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream transformStream(&transformFile);
	Matx33f rotateMat = m_rot.toMat();
	transformStream << rotateMat(0, 0) << " " << rotateMat(0, 1) << " " << rotateMat(0, 2) << "\n";
	transformStream << rotateMat(1, 0) << " " << rotateMat(1, 1) << " " << rotateMat(1, 2) << "\n";
	transformStream << rotateMat(2, 0) << " " << rotateMat(2, 1) << " " << rotateMat(2, 2) << "\n";
	transformStream << m_trans[0] << " " << m_trans[1] << " " << -100.f * m_scale << "\n";
	transformStream << m_scale << "\n";
	transformStream << m_center[0] << " " << m_center[1] << " " << m_center[2] << "\n";
	transformFile.close();
}

void Transform::updateMat()
{
	Matx33f rotMat = m_rot.toMat();
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			m_mat(j, i) = rotMat(j, i) * m_scale;
		m_mat(i, 3) = m_trans[i];
		m_mat(3, i) = 0.f;
	}
	m_mat(3, 3) = 1.f;
}

void Transform::setScale(const float &inScale)
{
	m_scale = inScale;
	updateMat();
}

void Transform::setTrans(const Vec3f &inTrans)
{
	m_trans = inTrans;
	updateMat();
}

void Transform::setRot(const Quatern &inRot)
{
	m_rot = inRot;
	updateMat();
}

void Transform::setCenter(const cv::Vec3f &center)
{
	m_center = center;
}

void Transform::setTransform(const float &inScale, const Vec3f &inTrans, const Quatern &inRot)
{
	m_scale = inScale;
	m_trans = inTrans;
	m_rot = inRot;
	updateMat();
}

float Transform::getScale() const
{
	return m_scale;
}

Vec3f Transform::getTrans() const
{
	return m_trans;
}

Quatern Transform::getRot() const
{
	return m_rot;
}

Vec3f Transform::getCenter() const
{
	return m_center;
}

Transform Transform::operator*(const Transform &t) const
{
	Transform nt;
	nt.setTransform(m_scale * t.getScale(), m_trans + m_rot * (t.getTrans() * m_scale), m_rot * t.getRot());
	return nt;
}

Vec3f Transform::operator*(const Vec3f &v) const
{
	return Vec3f((m_mat * Vec4f(v[0], v[1], v[2], 1.f)).val);
}

Transform Transform::inverse() const
{
	Transform nt;
	nt.setTransform(1.f / m_scale, m_rot.inverse() * -m_trans * (1.f / m_scale), m_rot.inverse());
	return nt;
}

Matx44f Transform::toMat() const
{
	Matx44f mat;
	Matx33f rotMat = m_rot.toMat();
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			mat(j, i) = rotMat(j, i) * m_scale;
		mat(i, 3) = m_trans[i];
		mat(3, i) = 0.f;
	}
	mat(3, 3) = 1.f;
	return mat;
}
