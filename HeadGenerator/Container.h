#pragma once

#include <math.h>
#include <string.h>

#undef MIN
#undef MAX
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

namespace cml
{
	class Vec3b;
	class Vec2i;
	class Vec3i;
	class Vec4i;
	class Vec2f;
	class Vec3f;
	class Vec4f;
	class Vec2d;
	class Vec3d;
	class Vec4d;
	class Mat3f;
	class Mat4f;
	class Mat3d;
	class Mat4d;

	class Vec3b
	{
	public:

		inline Vec3b();
		inline Vec3b(const Vec3b& v);
		inline Vec3b(char a, char b, char c);

		inline char& operator[](int i);
		inline const char& operator[](int i) const;

		inline Vec3b operator+(const Vec3b& v) const;
		inline Vec3b operator-(const Vec3b& v) const;
		inline Vec3b operator*(char v) const;
		inline Vec3b operator/(char v) const;

		inline Vec3b& operator=(const Vec3b& v);
		inline Vec3b& operator+=(const Vec3b& v);
		inline Vec3b& operator-=(const Vec3b& v);
		inline Vec3b& operator*=(char v);
		inline Vec3b& operator/=(char v);

		char	val[3];
	};

	class Vec2i
	{
	public:

		inline Vec2i();
		inline Vec2i(const Vec2i& v);
		inline Vec2i(int a, int b);

		inline int& operator[](int i);
		inline const int& operator[](int i) const;

		inline Vec2i operator+(const Vec2i& v) const;
		inline Vec2i operator-(const Vec2i& v) const;
		inline Vec2i operator*(int v) const;
		inline Vec2i operator/(int v) const;

		inline Vec2i& operator=(const Vec2i& v);
		inline Vec2i& operator=(const Vec2f& v);
		inline Vec2i& operator=(const Vec2d& v);
		inline Vec2i& operator+=(const Vec2i& v);
		inline Vec2i& operator-=(const Vec2i& v);
		inline Vec2i& operator*=(int v);
		inline Vec2i& operator/=(int v);

		inline int dot(const Vec2i& v) const;
		inline int cross(const Vec2i& v) const;
		inline double len() const;
		inline int len2() const;

		int		val[2];
	};

	class Vec3i
	{
	public:

		inline Vec3i();
		inline Vec3i(const Vec3i& v);
		inline Vec3i(int a, int b, int c);

		inline int& operator[](int i);
		inline const int& operator[](int i) const;

		inline Vec3i operator+(const Vec3i& v) const;
		inline Vec3i operator-(const Vec3i& v) const;
		inline Vec3i operator*(int v) const;
		inline Vec3i operator/(float v) const;

		inline Vec3i& operator=(const Vec3i& v);
		inline Vec3i& operator=(const Vec3f& v);
		inline Vec3i& operator=(const Vec3d& v);
		inline Vec3i& operator+=(const Vec3i& v);
		inline Vec3i& operator-=(const Vec3i& v);
		inline Vec3i& operator*=(int v);
		inline Vec3i& operator/=(float v);

		inline int dot(const Vec3i& v) const;
		inline Vec3i cross(const Vec3i& v) const;
		inline double len() const;
		inline int len2() const;

		int		val[3];
	};

	class Vec4i
	{
	public:

		inline Vec4i();
		inline Vec4i(const Vec4i& v);
		inline Vec4i(int a, int b, int c, int d);

		inline int& operator[](int i);
		inline const int& operator[](int i) const;

		inline Vec4i operator+(const Vec4i& v) const;
		inline Vec4i operator-(const Vec4i& v) const;
		inline Vec4i operator*(int v) const;
		inline Vec4i operator/(int v) const;

		inline Vec4i& operator=(const Vec4i& v);
		inline Vec4i& operator=(const Vec4f& v);
		inline Vec4i& operator=(const Vec4d& v);
		inline Vec4i& operator+=(const Vec4i& v);
		inline Vec4i& operator-=(const Vec4i& v);
		inline Vec4i& operator*=(int v);
		inline Vec4i& operator/=(int v);

		inline int dot(const Vec4i& v) const;
		inline double len() const;
		inline int len2() const;

		int		val[4];
	};

	class Vec2f
	{
	public:

		inline Vec2f();
		inline Vec2f(const Vec2f& v);
		inline Vec2f(float a, float b);

		inline float& operator[](int i);
		inline const float& operator[](int i) const;

		inline Vec2f operator+(const Vec2f& v) const;
		inline Vec2f operator-(const Vec2f& v) const;
		inline Vec2f operator*(float v) const;
		inline Vec2f operator/(float v) const;

		inline Vec2f& operator=(const Vec2f& v);
		inline Vec2f& operator=(const Vec2i& v);
		inline Vec2f& operator=(const Vec2d& v);
		inline Vec2f& operator+=(const Vec2f& v);
		inline Vec2f& operator-=(const Vec2f& v);
		inline Vec2f& operator*=(float v);
		inline Vec2f& operator/=(float v);

		inline float dot(const Vec2f& v) const;
		inline float cross(const Vec2f& v) const;
		inline float len() const;
		inline float len2() const;

		inline void normalize();

		float	val[2];
	};

	class Vec3f
	{
	public:

		inline Vec3f();
		inline Vec3f(const Vec3f& v);
		inline Vec3f(const Vec3d& v);
		inline Vec3f(float a, float b, float c);

		inline float& operator[](int i);
		inline const float& operator[](int i) const;

		inline Vec3f operator+(const Vec3f& v) const;
		inline Vec3f operator-(const Vec3f& v) const;
		inline Vec3f operator*(float v) const;
		inline Vec3f operator/(float v) const;

		inline Vec3f& operator=(const Vec3f& v);
		inline Vec3f& operator=(const Vec3i& v);
		inline Vec3f& operator=(const Vec3d& v);
		inline Vec3f& operator+=(const Vec3f& v);
		inline Vec3f& operator-=(const Vec3f& v);
		inline Vec3f& operator*=(float v);
		inline Vec3f& operator/=(float v);

		inline float dot(const Vec3f& v) const;
		inline Vec3f cross(const Vec3f& v) const;
		inline float len() const;
		inline float len2() const;

		inline void normalize();

		float	val[3];
	};

	class Vec4f
	{
	public:

		inline Vec4f();
		inline Vec4f(const Vec4f& v);
		inline Vec4f(float a, float b, float c, float d);

		inline float& operator[](int i);
		inline const float& operator[](int i) const;

		inline Vec4f operator+(const Vec4f& v) const;
		inline Vec4f operator-(const Vec4f& v) const;
		inline Vec4f operator*(float v) const;
		inline Vec4f operator/(float v) const;

		inline Vec4f& operator=(const Vec4f& v);
		inline Vec4f& operator=(const Vec4i& v);
		inline Vec4f& operator=(const Vec4d& v);
		inline Vec4f& operator+=(const Vec4f& v);
		inline Vec4f& operator-=(const Vec4f& v);
		inline Vec4f& operator*=(float v);
		inline Vec4f& operator/=(float v);

		inline float dot(const Vec4f& v) const;
		inline float len() const;
		inline float len2() const;

		inline void normalize();

		float	val[4];
	};

	class Vec2d
	{
	public:

		inline Vec2d();
		inline Vec2d(const Vec2d& v);
		inline Vec2d(double a, double b);

		inline double& operator[](int i);
		inline const double& operator[](int i) const;

		inline Vec2d operator+(const Vec2d& v) const;
		inline Vec2d operator-(const Vec2d& v) const;
		inline Vec2d operator*(double v) const;
		inline Vec2d operator/(double v) const;

		inline Vec2d& operator=(const Vec2d& v);
		inline Vec2d& operator=(const Vec2i& v);
		inline Vec2d& operator=(const Vec2f& v);
		inline Vec2d& operator+=(const Vec2d& v);
		inline Vec2d& operator-=(const Vec2d& v);
		inline Vec2d& operator*=(double v);
		inline Vec2d& operator/=(double v);

		inline double dot(const Vec2d& v) const;
		inline double cross(const Vec2d& v) const;
		inline double len() const;
		inline double len2() const;

		inline void normalize();

		double	val[2];
	};

	class Vec3d
	{
	public:

		inline Vec3d();
		inline Vec3d(const Vec3d& v);
		inline Vec3d(const Vec3f& v);
		inline Vec3d(double a, double b, double c);

		inline double& operator[](int i);
		inline const double& operator[](int i) const;

		inline Vec3d operator+(const Vec3d& v) const;
		inline Vec3d operator-(const Vec3d& v) const;
		inline Vec3d operator*(double v) const;
		inline Vec3d operator/(double v) const;

		inline Vec3d& operator=(const Vec3d& v);
		inline Vec3d& operator=(const Vec3i& v);
		inline Vec3d& operator=(const Vec3f& v);
		inline Vec3d& operator+=(const Vec3d& v);
		inline Vec3d& operator-=(const Vec3d& v);
		inline Vec3d& operator*=(double v);
		inline Vec3d& operator/=(double v);

		inline double dot(const Vec3d& v) const;
		inline Vec3d cross(const Vec3d& v) const;
		inline double len() const;
		inline double len2() const;

		inline void normalize();

		double	val[3];
	};

	class Vec4d
	{
	public:

		inline Vec4d();
		inline Vec4d(const Vec4d& v);
		inline Vec4d(double a, double b, double c, double d);

		inline double& operator[](int i);
		inline const double& operator[](int i) const;

		inline Vec4d operator+(const Vec4d& v) const;
		inline Vec4d operator-(const Vec4d& v) const;
		inline Vec4d operator*(double v) const;
		inline Vec4d operator/(double v) const;

		inline Vec4d& operator=(const Vec4d& v);
		inline Vec4d& operator=(const Vec4i& v);
		inline Vec4d& operator=(const Vec4f& v);
		inline Vec4d& operator+=(const Vec4d& v);
		inline Vec4d& operator-=(const Vec4d& v);
		inline Vec4d& operator*=(double v);
		inline Vec4d& operator/=(double v);

		inline double dot(const Vec4d& v) const;
		inline double len() const;
		inline double len2() const;
		inline void normalize();

		double	val[4];
	};

	class Mat3f
	{
	public:

		inline Mat3f();
		inline Mat3f(const Mat3f& v);

		inline float& operator[](int i);
		inline const float& operator[](int i) const;
		inline float& operator()(int i, int j);
		inline const float& operator()(int i, int j) const;

		inline Mat3f operator+(const Mat3f& v) const;
		inline Mat3f operator-(const Mat3f& v) const;
		inline Mat3f operator*(float v) const;
		inline Mat3f operator/(float v) const;

		inline Vec3f operator*(const Vec3f& v) const;

		inline Mat3f& operator=(const Mat3f& v);
		inline Mat3f& operator=(const Mat3d& v);
		inline Mat3f& operator+=(const Mat3f& v);
		inline Mat3f& operator-=(const Mat3f& v);
		inline Mat3f& operator*=(float v);
		inline Mat3f& operator/=(float v);

		inline Mat3f& addScaled(const Mat3f& v, float s);

		float	val[9];
	};

	class Mat4f
	{
	public:

		inline Mat4f();
		inline Mat4f(const Mat4f& v);

		inline float& operator[](int i);
		inline const float& operator[](int i) const;
		inline float& operator()(int i, int j);
		inline const float& operator()(int i, int j) const;

		inline Mat4f operator+(const Mat4f& v) const;
		inline Mat4f operator-(const Mat4f& v) const;
		inline Mat4f operator*(float v) const;
		inline Mat4f operator/(float v) const;

		inline Vec3f operator*(const Vec3f& v) const;
		inline Vec3f mulLinear(const Vec3f& v) const;

		inline Mat4f& operator=(const Mat4f& v);
		inline Mat4f& operator=(const Mat4d& v);
		inline Mat4f& operator+=(const Mat4f& v);
		inline Mat4f& operator-=(const Mat4f& v);
		inline Mat4f& operator*=(float v);
		inline Mat4f& operator/=(float v);

		inline Mat4f& addScaled(const Mat4f& v, float s);

		float val[12];
	};

	class Mat3d
	{
	public:

		inline Mat3d();
		inline Mat3d(const Mat3d& v);

		inline double& operator[](int i);
		inline const double& operator[](int i) const;
		inline double& operator()(int i, int j);
		inline const double& operator()(int i, int j) const;

		inline Mat3d operator+(const Mat3d& v) const;
		inline Mat3d operator-(const Mat3d& v) const;
		inline Mat3d operator*(double v) const;
		inline Mat3d operator/(double v) const;

		inline Vec3d operator*(const Vec3d& v) const;

		inline Mat3d& operator=(const Mat3d& v);
		inline Mat3d& operator=(const Mat3f& v);
		inline Mat3d& operator+=(const Mat3d& v);
		inline Mat3d& operator-=(const Mat3d& v);
		inline Mat3d& operator*=(double v);
		inline Mat3d& operator/=(double v);

		inline Mat3d& addScaled(const Mat3d& v, double s);

		double	val[9];
	};

	class Mat4d
	{
	public:

		inline Mat4d();
		inline Mat4d(const Mat4d& v);

		inline double& operator[](int i);
		inline const double& operator[](int i) const;
		inline double& operator()(int i, int j);
		inline const double& operator()(int i, int j) const;

		inline Mat4d operator+(const Mat4d& v) const;
		inline Mat4d operator-(const Mat4d& v) const;
		inline Mat4d operator*(double v) const;
		inline Mat4d operator/(double v) const;

		inline Vec3d operator*(const Vec3d& v) const;
		inline Vec3d mulLinear(const Vec3d& v) const;

		inline Mat4d& operator=(const Mat4d& v);
		inline Mat4d& operator=(const Mat4f& v);
		inline Mat4d& operator+=(const Mat4d& v);
		inline Mat4d& operator-=(const Mat4d& v);
		inline Mat4d& operator*=(double v);
		inline Mat4d& operator/=(double v);

		inline Mat4d& addScaled(const Mat4d& v, double s);

		double	val[12];
	};

	inline Vec3b::Vec3b()
	{}

	inline Vec3b::Vec3b(const Vec3b& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
	}

	inline Vec3b::Vec3b(char a, char b, char c)
	{
		val[0] = a;
		val[1] = b;
		val[2] = c;
	}

	inline char& Vec3b::operator[](int i)
	{
		return val[i];
	}

	inline const char& Vec3b::operator[](int i) const
	{
		return val[i];
	}

	inline Vec3b Vec3b::operator+(const Vec3b& v) const
	{
		return Vec3b(val[0] + v.val[0], val[1] + v.val[1], val[2] + v.val[2]);
	}

	inline Vec3b Vec3b::operator-(const Vec3b& v) const
	{
		return Vec3b(val[0] - v.val[0], val[1] - v.val[1], val[2] - v.val[2]);
	}

	inline Vec3b Vec3b::operator*(char v) const
	{
		return Vec3b(val[0] * v, val[1] * v, val[2] * v);
	}

	inline Vec3b Vec3b::operator/(char v) const
	{
		return Vec3b(val[0] / v, val[1] / v, val[2] / v);
	}

	inline Vec3b& Vec3b::operator=(const Vec3b& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3b& Vec3b::operator+=(const Vec3b& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		return *this;
	}

	inline Vec3b& Vec3b::operator-=(const Vec3b& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		return *this;
	}

	inline Vec3b& Vec3b::operator*=(char v)
	{
		val[0] *= v;
		val[1] *= v;
		val[2] *= v;
		return *this;
	}

	inline Vec3b& Vec3b::operator/=(char v)
	{
		val[0] /= v;
		val[1] /= v;
		val[2] /= v;
		return *this;
	}

	inline Vec2i::Vec2i()
	{}

	inline Vec2i::Vec2i(const Vec2i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
	}

	inline Vec2i::Vec2i(int a, int b)
	{
		val[0] = a;
		val[1] = b;
	}

	inline int& Vec2i::operator[](int i)
	{
		return val[i];
	}

	inline const int& Vec2i::operator[](int i) const
	{
		return val[i];
	}

	inline Vec2i Vec2i::operator+(const Vec2i& v) const
	{
		return Vec2i(val[0] + v.val[0], val[1] + v.val[1]);
	}

	inline Vec2i Vec2i::operator-(const Vec2i& v) const
	{
		return Vec2i(val[0] - v.val[0], val[1] - v.val[1]);
	}

	inline Vec2i Vec2i::operator*(int v) const
	{
		return Vec2i(val[0] * v, val[1] * v);
	}

	inline Vec2i Vec2i::operator/(int v) const
	{
		return Vec2i(val[0] / v, val[1] / v);
	}

	inline Vec2i& Vec2i::operator=(const Vec2i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2i& Vec2i::operator=(const Vec2f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2i& Vec2i::operator=(const Vec2d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2i& Vec2i::operator+=(const Vec2i& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		return *this;
	}

	inline Vec2i& Vec2i::operator-=(const Vec2i& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		return *this;
	}

	inline Vec2i& Vec2i::operator*=(int v)
	{
		val[0] *= v;
		val[1] *= v;
		return *this;
	}

	inline Vec2i& Vec2i::operator/=(int v)
	{
		val[0] /= v;
		val[1] /= v;
		return *this;
	}

	inline int Vec2i::dot(const Vec2i& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1];
	}

	inline int Vec2i::cross(const Vec2i& v) const
	{
		return val[0] * v.val[1] - val[1] * v.val[0];
	}

	inline double Vec2i::len() const
	{
		return sqrt(double(val[0] * val[0] + val[1] * val[1]));
	}

	inline int Vec2i::len2() const
	{
		return val[0] * val[0] + val[1] * val[1];
	}

	inline Vec3i::Vec3i()
	{}

	inline Vec3i::Vec3i(const Vec3i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
	}

	inline Vec3i::Vec3i(int a, int b, int c)
	{
		val[0] = a;
		val[1] = b;
		val[2] = c;
	}

	inline int& Vec3i::operator[](int i)
	{
		return val[i];
	}

	inline const int& Vec3i::operator[](int i) const
	{
		return val[i];
	}

	inline Vec3i Vec3i::operator+(const Vec3i& v) const
	{
		return Vec3i(val[0] + v.val[0], val[1] + v.val[1], val[2] + v.val[2]);
	}

	inline Vec3i Vec3i::operator-(const Vec3i& v) const
	{
		return Vec3i(val[0] - v.val[0], val[1] - v.val[1], val[2] - v.val[2]);
	}

	inline Vec3i Vec3i::operator*(int v) const
	{
		return Vec3i(val[0] * v, val[1] * v, val[2] * v);
	}

	inline Vec3i Vec3i::operator/(float v) const
	{
		return Vec3i(val[0] / v, val[1] / v, val[2] / v);
	}

	inline Vec3i& Vec3i::operator=(const Vec3i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3i& Vec3i::operator=(const Vec3f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3i& Vec3i::operator=(const Vec3d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3i& Vec3i::operator+=(const Vec3i& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		return *this;
	}

	inline Vec3i& Vec3i::operator-=(const Vec3i& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		return *this;
	}

	inline Vec3i& Vec3i::operator*=(int v)
	{
		val[0] *= v;
		val[1] *= v;
		val[2] *= v;
		return *this;
	}

	inline Vec3i& Vec3i::operator/=(float v)
	{
		val[0] /= v;
		val[1] /= v;
		val[2] /= v;
		return *this;
	}

	inline int Vec3i::dot(const Vec3i& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2];
	}

	inline Vec3i Vec3i::cross(const Vec3i& v) const
	{
		return Vec3i(val[1] * v.val[2] - val[2] * v.val[1], val[2] * v.val[0] - val[0] * v.val[2], val[0] * v.val[1] - val[1] * v.val[0]);
	}

	inline double Vec3i::len() const
	{
		return sqrt(double(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]));
	}

	inline int Vec3i::len2() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2];
	}

	inline Vec4i::Vec4i()
	{}

	inline Vec4i::Vec4i(const Vec4i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
	}

	inline Vec4i::Vec4i(int a, int b, int c, int d)
	{
		val[0] = a;
		val[1] = b;
		val[2] = c;
		val[3] = d;
	}

	inline int& Vec4i::operator[](int i)
	{
		return val[i];
	}

	inline const int& Vec4i::operator[](int i) const
	{
		return val[i];
	}

	inline Vec4i Vec4i::operator+(const Vec4i& v) const
	{
		return Vec4i(val[0] + v.val[0], val[1] + v.val[1], val[2] + v.val[2], val[3] + v.val[3]);
	}

	inline Vec4i Vec4i::operator-(const Vec4i& v) const
	{
		return Vec4i(val[0] - v.val[0], val[1] - v.val[1], val[2] - v.val[2], val[3] - v.val[3]);
	}

	inline Vec4i Vec4i::operator*(int v) const
	{
		return Vec4i(val[0] * v, val[1] * v, val[2] * v, val[3] * v);
	}

	inline Vec4i Vec4i::operator/(int v) const
	{
		return Vec4i(val[0] * v, val[1] * v, val[2] * v, val[3] * v);
	}

	inline Vec4i& Vec4i::operator=(const Vec4i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4i& Vec4i::operator=(const Vec4f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4i& Vec4i::operator=(const Vec4d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4i& Vec4i::operator+=(const Vec4i& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		val[3] += v.val[3];
		return *this;
	}

	inline Vec4i& Vec4i::operator-=(const Vec4i& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		val[3] -= v.val[3];
		return *this;
	}

	inline Vec4i& Vec4i::operator*=(int v)
	{
		val[0] *= v;
		val[1] *= v;
		val[2] *= v;
		val[3] *= v;
		return *this;
	}

	inline Vec4i& Vec4i::operator/=(int v)
	{
		val[0] /= v;
		val[1] /= v;
		val[2] /= v;
		val[3] /= v;
		return *this;
	}

	inline int Vec4i::dot(const Vec4i& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2] + val[3] * v.val[3];
	}

	inline double Vec4i::len() const
	{
		return sqrt(double(val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + val[3] * val[3]));
	}

	inline int Vec4i::len2() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + val[3] * val[3];
	}

	inline Vec2f::Vec2f()
	{}

	inline Vec2f::Vec2f(const Vec2f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
	}

	inline Vec2f::Vec2f(float a, float b)
	{
		val[0] = a;
		val[1] = b;
	}

	inline float& Vec2f::operator[](int i)
	{
		return val[i];
	}

	inline const float& Vec2f::operator[](int i) const
	{
		return val[i];
	}

	inline Vec2f Vec2f::operator+(const Vec2f& v) const
	{
		return Vec2f(val[0] + v.val[0], val[1] + v.val[1]);
	}

	inline Vec2f Vec2f::operator-(const Vec2f& v) const
	{
		return Vec2f(val[0] - v.val[0], val[1] - v.val[1]);
	}

	inline Vec2f Vec2f::operator*(float v) const
	{
		return Vec2f(val[0] * v, val[1] * v);
	}

	inline Vec2f Vec2f::operator/(float v) const
	{
		float fac = 1.f / v;
		return Vec2f(val[0] * fac, val[1] * fac);
	}

	inline Vec2f& Vec2f::operator=(const Vec2f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2f& Vec2f::operator=(const Vec2i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2f& Vec2f::operator=(const Vec2d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2f& Vec2f::operator+=(const Vec2f& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		return *this;
	}

	inline Vec2f& Vec2f::operator-=(const Vec2f& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		return *this;
	}

	inline Vec2f& Vec2f::operator*=(float v)
	{
		val[0] *= v;
		val[1] *= v;
		return *this;
	}

	inline Vec2f& Vec2f::operator/=(float v)
	{
		float fac = 1.f / v;
		val[0] *= fac;
		val[1] *= fac;
		return *this;
	}

	inline float Vec2f::dot(const Vec2f& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1];
	}

	inline float Vec2f::cross(const Vec2f& v) const
	{
		return val[0] * v.val[1] - val[1] * v.val[0];
	}

	inline float Vec2f::len() const
	{
		return sqrtf(val[0] * val[0] + val[1] * val[1]);
	}

	inline float Vec2f::len2() const
	{
		return val[0] * val[0] + val[1] * val[1];
	}

	inline void Vec2f::normalize()
	{
		float fac = 1.f / sqrtf(val[0] * val[0] + val[1] * val[1]);
		val[0] *= fac;
		val[1] *= fac;
	}

	inline Vec3f::Vec3f()
	{}

	inline Vec3f::Vec3f(const Vec3f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
	}

	inline Vec3f::Vec3f(const Vec3d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
	}

	inline Vec3f::Vec3f(float a, float b, float c)
	{
		val[0] = a;
		val[1] = b;
		val[2] = c;
	}

	inline float& Vec3f::operator[](int i)
	{
		return val[i];
	}

	inline const float& Vec3f::operator[](int i) const
	{
		return val[i];
	}

	inline Vec3f Vec3f::operator+(const Vec3f& v) const
	{
		return Vec3f(val[0] + v.val[0], val[1] + v.val[1], val[2] + v.val[2]);
	}

	inline Vec3f Vec3f::operator-(const Vec3f& v) const
	{
		return Vec3f(val[0] - v.val[0], val[1] - v.val[1], val[2] - v.val[2]);
	}

	inline Vec3f Vec3f::operator*(float v) const
	{
		return Vec3f(val[0] * v, val[1] * v, val[2] * v);
	}

	inline Vec3f Vec3f::operator/(float v) const
	{
		float fac = 1.f / v;
		return Vec3f(val[0] * fac, val[1] * fac, val[2] * fac);
	}

	inline Vec3f& Vec3f::operator=(const Vec3f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3f& Vec3f::operator=(const Vec3i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3f& Vec3f::operator=(const Vec3d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3f& Vec3f::operator+=(const Vec3f& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		return *this;
	}

	inline Vec3f& Vec3f::operator-=(const Vec3f& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		return *this;
	}

	inline Vec3f& Vec3f::operator*=(float v)
	{
		val[0] *= v;
		val[1] *= v;
		val[2] *= v;
		return *this;
	}

	inline Vec3f& Vec3f::operator/=(float v)
	{
		float fac = 1.f / v;
		val[0] *= fac;
		val[1] *= fac;
		val[2] *= fac;
		return *this;
	}

	inline float Vec3f::dot(const Vec3f& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2];
	}

	inline Vec3f Vec3f::cross(const Vec3f& v) const
	{
		return Vec3f(val[1] * v.val[2] - val[2] * v.val[1], val[2] * v.val[0] - val[0] * v.val[2], val[0] * v.val[1] - val[1] * v.val[0]);
	}

	inline float Vec3f::len() const
	{
		return sqrtf(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
	}

	inline float Vec3f::len2() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2];
	}

	inline void Vec3f::normalize()
	{
		float fac = 1.f / sqrtf(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
		val[0] *= fac;
		val[1] *= fac;
		val[2] *= fac;
	}

	inline Vec4f::Vec4f()
	{}

	inline Vec4f::Vec4f(const Vec4f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
	}

	inline Vec4f::Vec4f(float a, float b, float c, float d)
	{
		val[0] = a;
		val[1] = b;
		val[2] = c;
		val[3] = d;
	}

	inline float& Vec4f::operator[](int i)
	{
		return val[i];
	}

	inline const float& Vec4f::operator[](int i) const
	{
		return val[i];
	}

	inline Vec4f Vec4f::operator+(const Vec4f& v) const
	{
		return Vec4f(val[0] + v.val[0], val[1] + v.val[1], val[2] + v.val[2], val[3] + v.val[3]);
	}

	inline Vec4f Vec4f::operator-(const Vec4f& v) const
	{
		return Vec4f(val[0] - v.val[0], val[1] - v.val[1], val[2] - v.val[2], val[3] - v.val[3]);
	}

	inline Vec4f Vec4f::operator*(float v) const
	{
		return Vec4f(val[0] * v, val[1] * v, val[2] * v, val[3] * v);
	}

	inline Vec4f Vec4f::operator/(float v) const
	{
		float fac = 1.f / v;
		return Vec4f(val[0] * fac, val[1] * fac, val[2] * fac, val[3] * fac);
	}

	inline Vec4f& Vec4f::operator=(const Vec4f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4f& Vec4f::operator=(const Vec4i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4f& Vec4f::operator=(const Vec4d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4f& Vec4f::operator+=(const Vec4f& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		val[3] += v.val[3];
		return *this;
	}

	inline Vec4f& Vec4f::operator-=(const Vec4f& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		val[3] -= v.val[3];
		return *this;
	}

	inline Vec4f& Vec4f::operator*=(float v)
	{
		val[0] *= v;
		val[1] *= v;
		val[2] *= v;
		val[3] *= v;
		return *this;
	}

	inline Vec4f& Vec4f::operator/=(float v)
	{
		float fac = 1.f / v;
		val[0] *= fac;
		val[1] *= fac;
		val[2] *= fac;
		val[3] *= fac;
		return *this;
	}

	inline float Vec4f::dot(const Vec4f& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2] + val[3] * v.val[3];
	}

	inline float Vec4f::len() const
	{
		return sqrtf(val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + val[3] * val[3]);
	}

	inline float Vec4f::len2() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + val[3] * val[3];
	}

	inline void Vec4f::normalize()
	{
		float fac = 1.f / sqrtf(val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + val[3] * val[3]);
		val[0] *= fac;
		val[1] *= fac;
		val[2] *= fac;
		val[3] *= fac;
	}

	inline Vec2d::Vec2d()
	{}

	inline Vec2d::Vec2d(const Vec2d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
	}

	inline Vec2d::Vec2d(double a, double b)
	{
		val[0] = a;
		val[1] = b;
	}

	inline double& Vec2d::operator[](int i)
	{
		return val[i];
	}

	inline const double& Vec2d::operator[](int i) const
	{
		return val[i];
	}

	inline Vec2d Vec2d::operator+(const Vec2d& v) const
	{
		return Vec2d(val[0] + v.val[0], val[1] + v.val[1]);
	}

	inline Vec2d Vec2d::operator-(const Vec2d& v) const
	{
		return Vec2d(val[0] - v.val[0], val[1] - v.val[1]);
	}

	inline Vec2d Vec2d::operator*(double v) const
	{
		return Vec2d(val[0] * v, val[1] * v);
	}

	inline Vec2d Vec2d::operator/(double v) const
	{
		double fac = 1. / v;
		return Vec2d(val[0] * fac, val[1] * fac);
	}

	inline Vec2d& Vec2d::operator=(const Vec2d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2d& Vec2d::operator=(const Vec2i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2d& Vec2d::operator=(const Vec2f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		return *this;
	}

	inline Vec2d& Vec2d::operator+=(const Vec2d& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		return *this;
	}

	inline Vec2d& Vec2d::operator-=(const Vec2d& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		return *this;
	}

	inline Vec2d& Vec2d::operator*=(double v)
	{
		val[0] *= v;
		val[1] *= v;
		return *this;
	}

	inline Vec2d& Vec2d::operator/=(double v)
	{
		double fac = 1. / v;
		val[0] *= fac;
		val[1] *= fac;
		return *this;
	}

	inline double Vec2d::dot(const Vec2d& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1];
	}

	inline double Vec2d::cross(const Vec2d& v) const
	{
		return val[0] * v.val[1] - val[1] * v.val[0];
	}

	inline double Vec2d::len() const
	{
		return sqrt(val[0] * val[0] + val[1] * val[1]);
	}

	inline double Vec2d::len2() const
	{
		return val[0] * val[0] + val[1] * val[1];
	}

	inline void Vec2d::normalize()
	{
		double fac = 1. / sqrt(val[0] * val[0] + val[1] * val[1]);
		val[0] *= fac;
		val[1] *= fac;
	}

	inline Vec3d::Vec3d()
	{}

	inline Vec3d::Vec3d(const Vec3d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
	}

	inline Vec3d::Vec3d(const Vec3f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
	}

	inline Vec3d::Vec3d(double a, double b, double c)
	{
		val[0] = a;
		val[1] = b;
		val[2] = c;
	}

	inline double& Vec3d::operator[](int i)
	{
		return val[i];
	}

	inline const double& Vec3d::operator[](int i) const
	{
		return val[i];
	}

	inline Vec3d Vec3d::operator+(const Vec3d& v) const
	{
		return Vec3d(val[0] + v.val[0], val[1] + v.val[1], val[2] + v.val[2]);
	}

	inline Vec3d Vec3d::operator-(const Vec3d& v) const
	{
		return Vec3d(val[0] - v.val[0], val[1] - v.val[1], val[2] - v.val[2]);
	}

	inline Vec3d Vec3d::operator*(double v) const
	{
		return Vec3d(val[0] * v, val[1] * v, val[2] * v);
	}

	inline Vec3d Vec3d::operator/(double v) const
	{
		double fac = 1. / v;
		return Vec3d(val[0] * fac, val[1] * fac, val[2] * fac);
	}

	inline Vec3d& Vec3d::operator=(const Vec3d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3d& Vec3d::operator=(const Vec3i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3d& Vec3d::operator=(const Vec3f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		return *this;
	}

	inline Vec3d& Vec3d::operator+=(const Vec3d& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		return *this;
	}

	inline Vec3d& Vec3d::operator-=(const Vec3d& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		return *this;
	}

	inline Vec3d& Vec3d::operator*=(double v)
	{
		val[0] *= v;
		val[1] *= v;
		val[2] *= v;
		return *this;
	}

	inline Vec3d& Vec3d::operator/=(double v)
	{
		double fac = 1. / v;
		val[0] *= fac;
		val[1] *= fac;
		val[2] *= fac;
		return *this;
	}

	inline double Vec3d::dot(const Vec3d& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2];
	}

	inline Vec3d Vec3d::cross(const Vec3d& v) const
	{
		return Vec3d(val[1] * v.val[2] - val[2] * v.val[1], val[2] * v.val[0] - val[0] * v.val[2], val[0] * v.val[1] - val[1] * v.val[0]);
	}

	inline double Vec3d::len() const
	{
		return sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
	}

	inline double Vec3d::len2() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2];
	}

	inline void Vec3d::normalize()
	{
		double fac = 1. / sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
		val[0] *= fac;
		val[1] *= fac;
		val[2] *= fac;
	}

	inline Vec4d::Vec4d()
	{}

	inline Vec4d::Vec4d(const Vec4d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
	}

	inline Vec4d::Vec4d(double a, double b, double c, double d)
	{
		val[0] = a;
		val[1] = b;
		val[2] = c;
		val[3] = d;
	}

	inline double& Vec4d::operator[](int i)
	{
		return val[i];
	}

	inline const double& Vec4d::operator[](int i) const
	{
		return val[i];
	}

	inline Vec4d Vec4d::operator+(const Vec4d& v) const
	{
		return Vec4d(val[0] + v.val[0], val[1] + v.val[1], val[2] + v.val[2], val[3] + v.val[3]);
	}

	inline Vec4d Vec4d::operator-(const Vec4d& v) const
	{
		return Vec4d(val[0] - v.val[0], val[1] - v.val[1], val[2] - v.val[2], val[3] - v.val[3]);
	}

	inline Vec4d Vec4d::operator*(double v) const
	{
		return Vec4d(val[0] * v, val[1] * v, val[2] * v, val[3] * v);
	}

	inline Vec4d Vec4d::operator/(double v) const
	{
		double fac = 1. / v;
		return Vec4d(val[0] * fac, val[1] * fac, val[2] * fac, val[3] * fac);
	}

	inline Vec4d& Vec4d::operator=(const Vec4d& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4d& Vec4d::operator=(const Vec4i& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4d& Vec4d::operator=(const Vec4f& v)
	{
		val[0] = v.val[0];
		val[1] = v.val[1];
		val[2] = v.val[2];
		val[3] = v.val[3];
		return *this;
	}

	inline Vec4d& Vec4d::operator+=(const Vec4d& v)
	{
		val[0] += v.val[0];
		val[1] += v.val[1];
		val[2] += v.val[2];
		val[3] += v.val[3];
		return *this;
	}

	inline Vec4d& Vec4d::operator-=(const Vec4d& v)
	{
		val[0] -= v.val[0];
		val[1] -= v.val[1];
		val[2] -= v.val[2];
		val[3] -= v.val[3];
		return *this;
	}

	inline Vec4d& Vec4d::operator*=(double v)
	{
		val[0] *= v;
		val[1] *= v;
		val[2] *= v;
		val[3] *= v;
		return *this;
	}

	inline Vec4d& Vec4d::operator/=(double v)
	{
		double fac = 1. / v;
		val[0] *= fac;
		val[1] *= fac;
		val[2] *= fac;
		val[3] *= fac;
		return *this;
	}

	inline double Vec4d::dot(const Vec4d& v) const
	{
		return val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2] + val[3] * v.val[3];
	}

	inline double Vec4d::len() const
	{
		return sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + val[3] * val[3]);
	}

	inline double Vec4d::len2() const
	{
		return val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + val[3] * val[3];
	}

	inline void Vec4d::normalize()
	{
		double fac = 1. / sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + val[3] * val[3]);
		val[0] *= fac;
		val[1] *= fac;
		val[2] *= fac;
		val[3] *= fac;
	}

	inline Mat3f::Mat3f()
	{
		memset(val, 0, sizeof(float) * 9);
	}

	inline Mat3f::Mat3f(const Mat3f& v)
	{
		memcpy(val, v.val, sizeof(float) * 9);
	}

	inline float& Mat3f::operator[](int i)
	{
		return val[i];
	}

	inline const float& Mat3f::operator[](int i) const
	{
		return val[i];
	}

	inline float& Mat3f::operator()(int i, int j)
	{
		return val[i * 3 + j];
	}

	inline const float& Mat3f::operator()(int i, int j) const
	{
		return val[i * 3 + j];
	}

	inline Mat3f Mat3f::operator+(const Mat3f& v) const
	{
		Mat3f ret;
		ret.val[0] = val[0] + v.val[0]; ret.val[1] = val[1] + v.val[1]; ret.val[2] = val[2] + v.val[2];
		ret.val[3] = val[3] + v.val[3]; ret.val[4] = val[4] + v.val[4]; ret.val[5] = val[5] + v.val[5];
		ret.val[6] = val[6] + v.val[6]; ret.val[7] = val[7] + v.val[7]; ret.val[8] = val[8] + v.val[8];
		return ret;
	}

	inline Mat3f Mat3f::operator-(const Mat3f& v) const
	{
		Mat3f ret;
		ret.val[0] = val[0] - v.val[0]; ret.val[1] = val[1] - v.val[1]; ret.val[2] = val[2] - v.val[2];
		ret.val[3] = val[3] - v.val[3]; ret.val[4] = val[4] - v.val[4]; ret.val[5] = val[5] - v.val[5];
		ret.val[6] = val[6] - v.val[6]; ret.val[7] = val[7] - v.val[7]; ret.val[8] = val[8] - v.val[8];
		return ret;
	}

	inline Mat3f Mat3f::operator*(float v) const
	{
		Mat3f ret;
		ret.val[0] = val[0] * v; ret.val[1] = val[1] * v; ret.val[2] = val[2] * v;
		ret.val[3] = val[3] * v; ret.val[4] = val[4] * v; ret.val[5] = val[5] * v;
		ret.val[6] = val[6] * v; ret.val[7] = val[7] * v; ret.val[8] = val[8] * v;
		return ret;
	}

	inline Mat3f Mat3f::operator/(float v) const
	{
		float fac = 1.f / v;
		Mat3f ret;
		ret.val[0] = val[0] * fac; ret.val[1] = val[1] * fac; ret.val[2] = val[2] * fac;
		ret.val[3] = val[3] * fac; ret.val[4] = val[4] * fac; ret.val[5] = val[5] * fac;
		ret.val[6] = val[6] * fac; ret.val[7] = val[7] * fac; ret.val[8] = val[8] * fac;
		return ret;
	}

	inline Vec3f Mat3f::operator*(const Vec3f& v) const
	{
		return Vec3f(
			val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2],
			val[3] * v.val[0] + val[4] * v.val[1] + val[5] * v.val[2],
			val[6] * v.val[0] + val[7] * v.val[1] + val[8] * v.val[2]);
	}

	inline Mat3f& Mat3f::operator=(const Mat3f& v)
	{
		memcpy(val, v.val, sizeof(float) * 9);
		return *this;
	}

	inline Mat3f& Mat3f::operator=(const Mat3d& v)
	{
		val[0] = v.val[0]; val[1] = v.val[1]; val[2] = v.val[2];
		val[3] = v.val[3]; val[4] = v.val[4]; val[5] = v.val[5];
		val[6] = v.val[6]; val[7] = v.val[7]; val[8] = v.val[8];
		return *this;
	}

	inline Mat3f& Mat3f::operator+=(const Mat3f& v)
	{
		val[0] += v.val[0]; val[1] += v.val[1]; val[2] += v.val[2];
		val[3] += v.val[3]; val[4] += v.val[4]; val[5] += v.val[5];
		val[6] += v.val[6]; val[7] += v.val[7]; val[8] += v.val[8];
		return *this;
	}

	inline Mat3f& Mat3f::operator-=(const Mat3f& v)
	{
		val[0] -= v.val[0]; val[1] -= v.val[1]; val[2] -= v.val[2];
		val[3] -= v.val[3]; val[4] -= v.val[4]; val[5] -= v.val[5];
		val[6] -= v.val[6]; val[7] -= v.val[7]; val[8] -= v.val[8];
		return *this;
	}

	inline Mat3f& Mat3f::operator*=(float v)
	{
		val[0] *= v; val[1] *= v; val[2] *= v;
		val[3] *= v; val[4] *= v; val[5] *= v;
		val[6] *= v; val[7] *= v; val[8] *= v;
		return *this;
	}

	inline Mat3f& Mat3f::operator/=(float v)
	{
		float fac = 1.f / v;
		val[0] *= fac; val[1] *= fac; val[2] *= fac;
		val[3] *= fac; val[4] *= fac; val[5] *= fac;
		val[6] *= fac; val[7] *= fac; val[8] *= fac;
		return *this;
	}

	inline Mat3f& Mat3f::addScaled(const Mat3f& v, float s)
	{
		val[0] += s * v.val[0]; val[1] += s * v.val[1]; val[2] += s * v.val[2];
		val[3] += s * v.val[3]; val[4] += s * v.val[4]; val[5] += s * v.val[5];
		val[6] += s * v.val[6]; val[7] += s * v.val[7]; val[8] += s * v.val[8];
		return *this;
	}

	Mat4f::Mat4f()
	{
		memset(val, 0, sizeof(float) * 12);
	}

	Mat4f::Mat4f(const Mat4f& v)
	{
		memcpy(val, v.val, sizeof(float) * 12);
	}

	inline float& Mat4f::operator[](int i)
	{
		return val[i];
	}

	inline const float& Mat4f::operator[](int i) const
	{
		return val[i];
	}

	inline float& Mat4f::operator()(int i, int j)
	{
		return val[i * 4 + j];
	}

	inline const float& Mat4f::operator()(int i, int j) const
	{
		return val[i * 4 + j];
	}

	inline Mat4f Mat4f::operator+(const Mat4f& v) const
	{
		Mat4f ret;
		ret.val[0] = val[0] + v.val[0]; ret.val[1] = val[1] + v.val[1]; ret.val[2] = val[2] + v.val[2]; ret.val[3] = val[3] + v.val[3];
		ret.val[4] = val[4] + v.val[4]; ret.val[5] = val[5] + v.val[5]; ret.val[6] = val[6] + v.val[6]; ret.val[7] = val[7] + v.val[7];
		ret.val[8] = val[8] + v.val[8]; ret.val[9] = val[9] + v.val[9]; ret.val[10] = val[10] + v.val[10]; ret.val[11] = val[11] + v.val[11];
		return ret;
	}

	inline Mat4f Mat4f::operator-(const Mat4f& v) const
	{
		Mat4f ret;
		ret.val[0] = val[0] - v.val[0]; ret.val[1] = val[1] - v.val[1]; ret.val[2] = val[2] - v.val[2]; ret.val[3] = val[3] - v.val[3];
		ret.val[4] = val[4] - v.val[4]; ret.val[5] = val[5] - v.val[5]; ret.val[6] = val[6] - v.val[6]; ret.val[7] = val[7] - v.val[7];
		ret.val[8] = val[8] - v.val[8]; ret.val[9] = val[9] - v.val[9]; ret.val[10] = val[10] - v.val[10]; ret.val[11] = val[11] - v.val[11];
		return ret;
	}

	inline Mat4f Mat4f::operator*(float v) const
	{
		Mat4f ret;
		ret.val[0] = val[0] * v; ret.val[1] = val[1] * v; ret.val[2] = val[2] * v; ret.val[3] = val[3] * v;
		ret.val[4] = val[4] * v; ret.val[5] = val[5] * v; ret.val[6] = val[6] * v; ret.val[7] = val[7] * v;
		ret.val[8] = val[8] * v; ret.val[9] = val[9] * v; ret.val[10] = val[10] * v; ret.val[11] = val[11] * v;
		return ret;
	}

	inline Mat4f Mat4f::operator/(float v) const
	{
		float fac = 1.f / v;
		Mat4f ret;
		ret.val[0] = val[0] * fac; ret.val[1] = val[1] * fac; ret.val[2] = val[2] * fac; ret.val[3] = val[3] * fac;
		ret.val[4] = val[4] * fac; ret.val[5] = val[5] * fac; ret.val[6] = val[6] * fac; ret.val[7] = val[7] * fac;
		ret.val[8] = val[8] * fac; ret.val[9] = val[9] * fac; ret.val[10] = val[10] * fac; ret.val[11] = val[11] * fac;
		return ret;
	}

	inline Vec3f Mat4f::operator*(const Vec3f& v) const
	{
		return Vec3f(
			val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2] + val[3],
			val[4] * v.val[0] + val[5] * v.val[1] + val[6] * v.val[2] + val[7],
			val[8] * v.val[0] + val[9] * v.val[1] + val[10] * v.val[2] + val[11]);
	}

	inline Vec3f Mat4f::mulLinear(const Vec3f& v) const
	{
		return Vec3f(
			val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2],
			val[4] * v.val[0] + val[5] * v.val[1] + val[6] * v.val[2],
			val[8] * v.val[0] + val[9] * v.val[1] + val[10] * v.val[2]);
	}

	inline Mat4f& Mat4f::operator=(const Mat4f& v)
	{
		memcpy(val, v.val, sizeof(float) * 12);
		return *this;
	}

	inline Mat4f& Mat4f::operator=(const Mat4d& v)
	{
		val[0] = v.val[0]; val[1] = v.val[1]; val[2] = v.val[2]; val[3] = v.val[3];
		val[4] = v.val[4]; val[5] = v.val[5]; val[6] = v.val[6]; val[7] = v.val[7];
		val[8] = v.val[8]; val[9] = v.val[9]; val[10] = v.val[10]; val[11] = v.val[11];
		return *this;
	}

	inline Mat4f& Mat4f::operator+=(const Mat4f& v)
	{
		val[0] += v.val[0]; val[1] += v.val[1]; val[2] += v.val[2]; val[3] += v.val[3];
		val[4] += v.val[4]; val[5] += v.val[5]; val[6] += v.val[6]; val[7] += v.val[7];
		val[8] += v.val[8]; val[9] += v.val[9]; val[10] += v.val[10]; val[11] += v.val[11];
		return *this;
	}

	inline Mat4f& Mat4f::operator-=(const Mat4f& v)
	{
		val[0] -= v.val[0]; val[1] -= v.val[1]; val[2] -= v.val[2]; val[3] -= v.val[3];
		val[4] -= v.val[4]; val[5] -= v.val[5]; val[6] -= v.val[6]; val[7] -= v.val[7];
		val[8] -= v.val[8]; val[9] -= v.val[9]; val[10] -= v.val[10]; val[11] -= v.val[11];
		return *this;
	}

	inline Mat4f& Mat4f::operator*=(float v)
	{
		val[0] *= v; val[1] *= v; val[2] *= v; val[3] *= v;
		val[4] *= v; val[5] *= v; val[6] *= v; val[7] *= v;
		val[8] *= v; val[9] *= v; val[10] *= v; val[11] *= v;
		return *this;
	}

	inline Mat4f& Mat4f::operator/=(float v)
	{
		float fac = 1.f / v;
		val[0] *= fac; val[1] *= fac; val[2] *= fac; val[3] *= fac;
		val[4] *= fac; val[5] *= fac; val[6] *= fac; val[7] *= fac;
		val[8] *= fac; val[9] *= fac; val[10] *= fac; val[11] *= fac;
		return *this;
	}

	inline Mat4f& Mat4f::addScaled(const Mat4f& v, float s)
	{
		val[0] += s * v.val[0]; val[1] += s * v.val[1]; val[2] += s * v.val[2]; val[3] += s * v.val[3];
		val[4] += s * v.val[4]; val[5] += s * v.val[5]; val[6] += s * v.val[6]; val[7] += s * v.val[7];
		val[8] += s * v.val[8]; val[9] += s * v.val[9]; val[10] += s * v.val[10]; val[11] += s * v.val[11];
		return *this;
	}

	inline Mat3d::Mat3d()
	{
		memset(val, 0, sizeof(double) * 9);
	}

	inline Mat3d::Mat3d(const Mat3d& v)
	{
		memcpy(val, v.val, sizeof(double) * 9);
	}

	inline double& Mat3d::operator[](int i)
	{
		return val[i];
	}

	inline const double& Mat3d::operator[](int i) const
	{
		return val[i];
	}

	inline double& Mat3d::operator()(int i, int j)
	{
		return val[i * 3 + j];
	}

	inline const double& Mat3d::operator()(int i, int j) const
	{
		return val[i * 3 + j];
	}

	inline Mat3d Mat3d::operator+(const Mat3d& v) const
	{
		Mat3d ret;
		ret.val[0] = val[0] + v.val[0]; ret.val[1] = val[1] + v.val[1]; ret.val[2] = val[2] + v.val[2];
		ret.val[3] = val[3] + v.val[3]; ret.val[4] = val[4] + v.val[4]; ret.val[5] = val[5] + v.val[5];
		ret.val[6] = val[6] + v.val[6]; ret.val[7] = val[7] + v.val[7]; ret.val[8] = val[8] + v.val[8];
		return ret;
	}

	inline Mat3d Mat3d::operator-(const Mat3d& v) const
	{
		Mat3d ret;
		ret.val[0] = val[0] - v.val[0]; ret.val[1] = val[1] - v.val[1]; ret.val[2] = val[2] - v.val[2];
		ret.val[3] = val[3] - v.val[3]; ret.val[4] = val[4] - v.val[4]; ret.val[5] = val[5] - v.val[5];
		ret.val[6] = val[6] - v.val[6]; ret.val[7] = val[7] - v.val[7]; ret.val[8] = val[8] - v.val[8];
		return ret;
	}

	inline Mat3d Mat3d::operator*(double v) const
	{
		Mat3d ret;
		ret.val[0] = val[0] * v; ret.val[1] = val[1] * v; ret.val[2] = val[2] * v;
		ret.val[3] = val[3] * v; ret.val[4] = val[4] * v; ret.val[5] = val[5] * v;
		ret.val[6] = val[6] * v; ret.val[7] = val[7] * v; ret.val[8] = val[8] * v;
		return ret;
	}

	inline Mat3d Mat3d::operator/(double v) const
	{
		double fac = 1. / v;
		Mat3d ret;
		ret.val[0] = val[0] * fac; ret.val[1] = val[1] * fac; ret.val[2] = val[2] * fac;
		ret.val[3] = val[3] * fac; ret.val[4] = val[4] * fac; ret.val[5] = val[5] * fac;
		ret.val[6] = val[6] * fac; ret.val[7] = val[7] * fac; ret.val[8] = val[8] * fac;
		return ret;
	}

	inline Vec3d Mat3d::operator*(const Vec3d& v) const
	{
		return Vec3d(
			val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2],
			val[3] * v.val[0] + val[4] * v.val[1] + val[5] * v.val[2],
			val[6] * v.val[0] + val[7] * v.val[1] + val[8] * v.val[2]);
	}

	inline Mat3d& Mat3d::operator=(const Mat3d& v)
	{
		memcpy(val, v.val, sizeof(double) * 9);
		return *this;
	}

	inline Mat3d& Mat3d::operator=(const Mat3f& v)
	{
		val[0] = v.val[0]; val[1] = v.val[1]; val[2] = v.val[2];
		val[3] = v.val[3]; val[4] = v.val[4]; val[5] = v.val[5];
		val[6] = v.val[6]; val[7] = v.val[7]; val[8] = v.val[8];
		return *this;
	}

	inline Mat3d& Mat3d::operator+=(const Mat3d& v)
	{
		val[0] += v.val[0]; val[1] += v.val[1]; val[2] += v.val[2];
		val[3] += v.val[3]; val[4] += v.val[4]; val[5] += v.val[5];
		val[6] += v.val[6]; val[7] += v.val[7]; val[8] += v.val[8];
		return *this;
	}

	inline Mat3d& Mat3d::operator-=(const Mat3d& v)
	{
		val[0] -= v.val[0]; val[1] -= v.val[1]; val[2] -= v.val[2];
		val[3] -= v.val[3]; val[4] -= v.val[4]; val[5] -= v.val[5];
		val[6] -= v.val[6]; val[7] -= v.val[7]; val[8] -= v.val[8];
		return *this;
	}

	inline Mat3d& Mat3d::operator*=(double v)
	{
		val[0] *= v; val[1] *= v; val[2] *= v;
		val[3] *= v; val[4] *= v; val[5] *= v;
		val[6] *= v; val[7] *= v; val[8] *= v;
		return *this;
	}

	inline Mat3d& Mat3d::operator/=(double v)
	{
		double fac = 1. / v;
		val[0] *= fac; val[1] *= fac; val[2] *= fac;
		val[3] *= fac; val[4] *= fac; val[5] *= fac;
		val[6] *= fac; val[7] *= fac; val[8] *= fac;
		return *this;
	}

	inline Mat3d& Mat3d::addScaled(const Mat3d& v, double s)
	{
		val[0] += s * v.val[0]; val[1] += s * v.val[1]; val[2] += s * v.val[2];
		val[3] += s * v.val[3]; val[4] += s * v.val[4]; val[5] += s * v.val[5];
		val[6] += s * v.val[6]; val[7] += s * v.val[7]; val[8] += s * v.val[8];
		return *this;
	}

	inline Mat4d::Mat4d()
	{
		memset(val, 0, sizeof(double) * 12);
	}

	inline Mat4d::Mat4d(const Mat4d& v)
	{
		memcpy(val, v.val, sizeof(double) * 12);
	}

	inline double& Mat4d::operator[](int i)
	{
		return val[i];
	}

	inline const double& Mat4d::operator[](int i) const
	{
		return val[i];
	}

	inline double& Mat4d::operator()(int i, int j)
	{
		return val[i * 4 + j];
	}

	inline const double& Mat4d::operator()(int i, int j) const
	{
		return val[i * 4 + j];
	}

	inline Mat4d Mat4d::operator+(const Mat4d& v) const
	{
		Mat4d ret;
		ret.val[0] = val[0] + v.val[0]; ret.val[1] = val[1] + v.val[1]; ret.val[2] = val[2] + v.val[2]; ret.val[3] = val[3] + v.val[3];
		ret.val[4] = val[4] + v.val[4]; ret.val[5] = val[5] + v.val[5]; ret.val[6] = val[6] + v.val[6]; ret.val[7] = val[7] + v.val[7];
		ret.val[8] = val[8] + v.val[8]; ret.val[9] = val[9] + v.val[9]; ret.val[10] = val[10] + v.val[10]; ret.val[11] = val[11] + v.val[11];
		return ret;
	}

	inline Mat4d Mat4d::operator-(const Mat4d& v) const
	{
		Mat4d ret;
		ret.val[0] = val[0] - v.val[0]; ret.val[1] = val[1] - v.val[1]; ret.val[2] = val[2] - v.val[2]; ret.val[3] = val[3] - v.val[3];
		ret.val[4] = val[4] - v.val[4]; ret.val[5] = val[5] - v.val[5]; ret.val[6] = val[6] - v.val[6]; ret.val[7] = val[7] - v.val[7];
		ret.val[8] = val[8] - v.val[8]; ret.val[9] = val[9] - v.val[9]; ret.val[10] = val[10] - v.val[10]; ret.val[11] = val[11] - v.val[11];
		return ret;
	}

	inline Mat4d Mat4d::operator*(double v) const
	{
		Mat4d ret;
		ret.val[0] = val[0] * v; ret.val[1] = val[1] * v; ret.val[2] = val[2] * v; ret.val[3] = val[3] * v;
		ret.val[4] = val[4] * v; ret.val[5] = val[5] * v; ret.val[6] = val[6] * v; ret.val[7] = val[7] * v;
		ret.val[8] = val[8] * v; ret.val[9] = val[9] * v; ret.val[10] = val[10] * v; ret.val[11] = val[11] * v;
		return ret;
	}

	inline Mat4d Mat4d::operator/(double v) const
	{
		double fac = 1. / v;
		Mat4d ret;
		ret.val[0] = val[0] * fac; ret.val[1] = val[1] * fac; ret.val[2] = val[2] * fac; ret.val[3] = val[3] * fac;
		ret.val[4] = val[4] * fac; ret.val[5] = val[5] * fac; ret.val[6] = val[6] * fac; ret.val[7] = val[7] * fac;
		ret.val[8] = val[8] * fac; ret.val[9] = val[9] * fac; ret.val[10] = val[10] * fac; ret.val[11] = val[11] * fac;
		return ret;
	}

	inline Vec3d Mat4d::operator*(const Vec3d& v) const
	{
		return Vec3d(
			val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2] + val[3],
			val[4] * v.val[0] + val[5] * v.val[1] + val[6] * v.val[2] + val[7],
			val[8] * v.val[0] + val[9] * v.val[1] + val[10] * v.val[2] + val[11]);
	}

	inline Vec3d Mat4d::mulLinear(const Vec3d& v) const
	{
		return Vec3d(
			val[0] * v.val[0] + val[1] * v.val[1] + val[2] * v.val[2],
			val[4] * v.val[0] + val[5] * v.val[1] + val[6] * v.val[2],
			val[8] * v.val[0] + val[9] * v.val[1] + val[10] * v.val[2]);
	}

	inline Mat4d& Mat4d::operator=(const Mat4d& v)
	{
		memcpy(val, v.val, sizeof(double) * 12);
		return *this;
	}

	inline Mat4d& Mat4d::operator=(const Mat4f& v)
	{
		val[0] = v.val[0]; val[1] = v.val[1]; val[2] = v.val[2]; val[3] = v.val[3];
		val[4] = v.val[4]; val[5] = v.val[5]; val[6] = v.val[6]; val[7] = v.val[7];
		val[8] = v.val[8]; val[9] = v.val[9]; val[10] = v.val[10]; val[11] = v.val[11];
		return *this;
	}

	inline Mat4d& Mat4d::operator+=(const Mat4d& v)
	{
		val[0] += v.val[0]; val[1] += v.val[1]; val[2] += v.val[2]; val[3] += v.val[3];
		val[4] += v.val[4]; val[5] += v.val[5]; val[6] += v.val[6]; val[7] += v.val[7];
		val[8] += v.val[8]; val[9] += v.val[9]; val[10] += v.val[10]; val[11] += v.val[11];
		return *this;
	}

	inline Mat4d& Mat4d::operator-=(const Mat4d& v)
	{
		val[0] -= v.val[0]; val[1] -= v.val[1]; val[2] -= v.val[2]; val[3] -= v.val[3];
		val[4] -= v.val[4]; val[5] -= v.val[5]; val[6] -= v.val[6]; val[7] -= v.val[7];
		val[8] -= v.val[8]; val[9] -= v.val[9]; val[10] -= v.val[10]; val[11] -= v.val[11];
		return *this;
	}

	inline Mat4d& Mat4d::operator*=(double v)
	{
		val[0] *= v; val[1] *= v; val[2] *= v; val[3] *= v;
		val[4] *= v; val[5] *= v; val[6] *= v; val[7] *= v;
		val[8] *= v; val[9] *= v; val[10] *= v; val[11] *= v;
		return *this;
	}

	inline Mat4d& Mat4d::operator/=(double v)
	{
		double fac = 1. / v;
		val[0] *= fac; val[1] *= fac; val[2] *= fac; val[3] *= fac;
		val[4] *= fac; val[5] *= fac; val[6] *= fac; val[7] *= fac;
		val[8] *= fac; val[9] *= fac; val[10] *= fac; val[11] *= fac;
		return *this;
	}

	inline Mat4d& Mat4d::addScaled(const Mat4d& v, double s)
	{
		val[0] += s * v.val[0]; val[1] += s * v.val[1]; val[2] += s * v.val[2]; val[3] += s * v.val[3];
		val[4] += s * v.val[4]; val[5] += s * v.val[5]; val[6] += s * v.val[6]; val[7] += s * v.val[7];
		val[8] += s * v.val[8]; val[9] += s * v.val[9]; val[10] += s * v.val[10]; val[11] += s * v.val[11];
		return *this;
	}
}
