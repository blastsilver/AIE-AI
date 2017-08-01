#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace fuse
    {
		template<typename T>
        struct vec<3, T>
		{
            // defaults
            inline vec() : vec(0, 0, 0) {};
            inline vec(T n) : vec(n, n, n) {};
			inline vec(const vec & n) : vec(n.x, n.y, n.z) {};
			inline vec(vec<2, T> & a, T b) : vec(a.x, a.y, b) {};
			inline vec(T a, vec<2, T> & b) : vec(a, b.x, b.y) {};
			inline vec(T x, T y, T z) { this->x = x; this->y = y; this->z = z; };
			// operator overload
			inline vec operator=(const vec & a) { xyz = a; return *this; };
			inline friend vec operator+=(const vec & a, const vec & b) { a.xyz += a; return *this; };
			inline friend vec operator-=(const vec & a, const vec & b) { a.xyz -= a; return *this; };
			inline friend vec operator*=(const vec & a, const vec & b) { a.xyz *= a; return *this; };
			inline friend vec operator/=(const vec & a, const vec & b) { a.xyz /= a; return *this; };
			inline friend vec operator+(const vec & a, const vec & b) { return vec(a.x + b.x, a.y + b.y, a.z + b.z); };
			inline friend vec operator-(const vec & a, const vec & b) { return vec(a.x - b.x, a.y - b.y, a.z - b.z); };
			inline friend vec operator*(const vec & a, const vec & b) { return vec(a.x * b.x, a.y * b.y, a.z * b.z); };
			inline friend vec operator/(const vec & a, const vec & b) { return vec(a.x / b.x, a.y / b.y, a.z / b.z); };
			// operator overload { vec<3, T>[i] }
			inline T & operator[](int index) { return ((T*)(&this->x))[index]; };
			// operator overload { vec<3, T>[i] }
			inline T const & operator[](int index) const { return ((T*)(&this->x))[index]; };
            // variables
            union {
                struct { T x, y, z; };
                struct { T r, g, b; };
				// detail::swizzle to vector2
				struct { detail::swizzle<2, T, 0, 0, -1, -2> xx; };
				struct { detail::swizzle<2, T, 0, 1, -1, -2> xy; };
				struct { detail::swizzle<2, T, 0, 2, -1, -2> xz; };
				struct { detail::swizzle<2, T, 1, 0, -1, -2> yx; };
				struct { detail::swizzle<2, T, 1, 1, -1, -2> yy; };
				struct { detail::swizzle<2, T, 1, 2, -1, -2> yz; };
				struct { detail::swizzle<2, T, 2, 0, -1, -2> zx; };
				struct { detail::swizzle<2, T, 2, 1, -1, -2> zy; };
				struct { detail::swizzle<2, T, 2, 2, -1, -2> zz; };
				// detail::swizzle to vector3
				struct { detail::swizzle<3, T, 0, 0, 0, -1> xxx; };
				struct { detail::swizzle<3, T, 0, 0, 1, -1> xxy; };
				struct { detail::swizzle<3, T, 0, 0, 2, -1> xxz; };
				struct { detail::swizzle<3, T, 0, 1, 0, -1> xyx; };
				struct { detail::swizzle<3, T, 0, 1, 1, -1> xyy; };
				struct { detail::swizzle<3, T, 0, 1, 2, -1> xyz; };
				struct { detail::swizzle<3, T, 0, 2, 0, -1> xzx; };
				struct { detail::swizzle<3, T, 0, 2, 1, -1> xzy; };
				struct { detail::swizzle<3, T, 0, 2, 2, -1> xzz; };
				struct { detail::swizzle<3, T, 1, 0, 0, -1> yxx; };
				struct { detail::swizzle<3, T, 1, 0, 1, -1> yxy; };
				struct { detail::swizzle<3, T, 1, 0, 2, -1> yxz; };
				struct { detail::swizzle<3, T, 1, 1, 0, -1> yyx; };
				struct { detail::swizzle<3, T, 1, 1, 1, -1> yyy; };
				struct { detail::swizzle<3, T, 1, 1, 2, -1> yyz; };
				struct { detail::swizzle<3, T, 1, 2, 0, -1> yzx; };
				struct { detail::swizzle<3, T, 1, 2, 1, -1> yzy; };
				struct { detail::swizzle<3, T, 1, 2, 2, -1> yzz; };
				struct { detail::swizzle<3, T, 2, 0, 0, -1> zxx; };
				struct { detail::swizzle<3, T, 2, 0, 1, -1> zxy; };
				struct { detail::swizzle<3, T, 2, 0, 2, -1> zxz; };
				struct { detail::swizzle<3, T, 2, 1, 0, -1> zyx; };
				struct { detail::swizzle<3, T, 2, 1, 1, -1> zyy; };
				struct { detail::swizzle<3, T, 2, 1, 2, -1> zyz; };
				struct { detail::swizzle<3, T, 2, 2, 0, -1> zzx; };
				struct { detail::swizzle<3, T, 2, 2, 1, -1> zzy; };
				struct { detail::swizzle<3, T, 2, 2, 2, -1> zzz; };
				// detail::swizzle to vector4
				struct { detail::swizzle<4, T, 0, 0, 0, 0> xxxx; };
				struct { detail::swizzle<4, T, 0, 0, 0, 1> xxxy; };
				struct { detail::swizzle<4, T, 0, 0, 0, 2> xxxz; };
				struct { detail::swizzle<4, T, 0, 0, 1, 0> xxyx; };
				struct { detail::swizzle<4, T, 0, 0, 1, 1> xxyy; };
				struct { detail::swizzle<4, T, 0, 0, 1, 2> xxyz; };
				struct { detail::swizzle<4, T, 0, 0, 2, 0> xxzx; };
				struct { detail::swizzle<4, T, 0, 0, 2, 1> xxzy; };
				struct { detail::swizzle<4, T, 0, 0, 2, 2> xxzz; };
				struct { detail::swizzle<4, T, 0, 1, 0, 0> xyxx; };
				struct { detail::swizzle<4, T, 0, 1, 0, 1> xyxy; };
				struct { detail::swizzle<4, T, 0, 1, 0, 2> xyxz; };
				struct { detail::swizzle<4, T, 0, 1, 1, 0> xyyx; };
				struct { detail::swizzle<4, T, 0, 1, 1, 1> xyyy; };
				struct { detail::swizzle<4, T, 0, 1, 1, 2> xyyz; };
				struct { detail::swizzle<4, T, 0, 1, 2, 0> xyzx; };
				struct { detail::swizzle<4, T, 0, 1, 2, 1> xyzy; };
				struct { detail::swizzle<4, T, 0, 1, 2, 2> xyzz; };
				struct { detail::swizzle<4, T, 0, 2, 0, 0> xzxx; };
				struct { detail::swizzle<4, T, 0, 2, 0, 1> xzxy; };
				struct { detail::swizzle<4, T, 0, 2, 0, 2> xzxz; };
				struct { detail::swizzle<4, T, 0, 2, 1, 0> xzyx; };
				struct { detail::swizzle<4, T, 0, 2, 1, 1> xzyy; };
				struct { detail::swizzle<4, T, 0, 2, 1, 2> xzyz; };
				struct { detail::swizzle<4, T, 0, 2, 2, 0> xzzx; };
				struct { detail::swizzle<4, T, 0, 2, 2, 1> xzzy; };
				struct { detail::swizzle<4, T, 0, 2, 2, 2> xzzz; };
				struct { detail::swizzle<4, T, 1, 0, 0, 0> yxxx; };
				struct { detail::swizzle<4, T, 1, 0, 0, 1> yxxy; };
				struct { detail::swizzle<4, T, 1, 0, 0, 2> yxxz; };
				struct { detail::swizzle<4, T, 1, 0, 1, 0> yxyx; };
				struct { detail::swizzle<4, T, 1, 0, 1, 1> yxyy; };
				struct { detail::swizzle<4, T, 1, 0, 1, 2> yxyz; };
				struct { detail::swizzle<4, T, 1, 0, 2, 0> yxzx; };
				struct { detail::swizzle<4, T, 1, 0, 2, 1> yxzy; };
				struct { detail::swizzle<4, T, 1, 0, 2, 2> yxzz; };
				struct { detail::swizzle<4, T, 1, 1, 0, 0> yyxx; };
				struct { detail::swizzle<4, T, 1, 1, 0, 1> yyxy; };
				struct { detail::swizzle<4, T, 1, 1, 0, 2> yyxz; };
				struct { detail::swizzle<4, T, 1, 1, 1, 0> yyyx; };
				struct { detail::swizzle<4, T, 1, 1, 1, 1> yyyy; };
				struct { detail::swizzle<4, T, 1, 1, 1, 2> yyyz; };
				struct { detail::swizzle<4, T, 1, 1, 2, 0> yyzx; };
				struct { detail::swizzle<4, T, 1, 1, 2, 1> yyzy; };
				struct { detail::swizzle<4, T, 1, 1, 2, 2> yyzz; };
				struct { detail::swizzle<4, T, 1, 2, 0, 0> yzxx; };
				struct { detail::swizzle<4, T, 1, 2, 0, 1> yzxy; };
				struct { detail::swizzle<4, T, 1, 2, 0, 2> yzxz; };
				struct { detail::swizzle<4, T, 1, 2, 1, 0> yzyx; };
				struct { detail::swizzle<4, T, 1, 2, 1, 1> yzyy; };
				struct { detail::swizzle<4, T, 1, 2, 1, 2> yzyz; };
				struct { detail::swizzle<4, T, 1, 2, 2, 0> yzzx; };
				struct { detail::swizzle<4, T, 1, 2, 2, 1> yzzy; };
				struct { detail::swizzle<4, T, 1, 2, 2, 2> yzzz; };
				struct { detail::swizzle<4, T, 2, 0, 0, 0> zxxx; };
				struct { detail::swizzle<4, T, 2, 0, 0, 1> zxxy; };
				struct { detail::swizzle<4, T, 2, 0, 0, 2> zxxz; };
				struct { detail::swizzle<4, T, 2, 0, 1, 0> zxyx; };
				struct { detail::swizzle<4, T, 2, 0, 1, 1> zxyy; };
				struct { detail::swizzle<4, T, 2, 0, 1, 2> zxyz; };
				struct { detail::swizzle<4, T, 2, 0, 2, 0> zxzx; };
				struct { detail::swizzle<4, T, 2, 0, 2, 1> zxzy; };
				struct { detail::swizzle<4, T, 2, 0, 2, 2> zxzz; };
				struct { detail::swizzle<4, T, 2, 1, 0, 0> zyxx; };
				struct { detail::swizzle<4, T, 2, 1, 0, 1> zyxy; };
				struct { detail::swizzle<4, T, 2, 1, 0, 2> zyxz; };
				struct { detail::swizzle<4, T, 2, 1, 1, 0> zyyx; };
				struct { detail::swizzle<4, T, 2, 1, 1, 1> zyyy; };
				struct { detail::swizzle<4, T, 2, 1, 1, 2> zyyz; };
				struct { detail::swizzle<4, T, 2, 1, 2, 0> zyzx; };
				struct { detail::swizzle<4, T, 2, 1, 2, 1> zyzy; };
				struct { detail::swizzle<4, T, 2, 1, 2, 2> zyzz; };
				struct { detail::swizzle<4, T, 2, 2, 0, 0> zzxx; };
				struct { detail::swizzle<4, T, 2, 2, 0, 1> zzxy; };
				struct { detail::swizzle<4, T, 2, 2, 0, 2> zzxz; };
				struct { detail::swizzle<4, T, 2, 2, 1, 0> zzyx; };
				struct { detail::swizzle<4, T, 2, 2, 1, 1> zzyy; };
				struct { detail::swizzle<4, T, 2, 2, 1, 2> zzyz; };
				struct { detail::swizzle<4, T, 2, 2, 2, 0> zzzx; };
				struct { detail::swizzle<4, T, 2, 2, 2, 1> zzzy; };
				struct { detail::swizzle<4, T, 2, 2, 2, 2> zzzz; };
            };
        };
    } // namespace fuse

/**************************************************************************************************/