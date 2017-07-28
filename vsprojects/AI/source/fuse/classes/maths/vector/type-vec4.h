#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace fuse
    {
		template<typename T>
        struct vec<4, T>
		{
            // defaults
            inline vec() : vec(0, 0, 0, 0) {};
            inline vec(T n) : vec(n, n, n, n) {};
			inline vec(const vec & n) : vec(n.x, n.y, n.z, n.w) {};
			inline vec(vec<3, T> & a, T b) : vec(a.x, a.y, a.z, b) {};
			inline vec(T a, vec<3, T> & b) : vec(a, b.x, b.y, b.z) {};
			inline vec(vec<2, T> & a, T b, T c) : vec(a.x, a.y, b, c) {};
			inline vec(T a, vec<2, T> & b, T c) : vec(a, b.x, b.y, c) {};
			inline vec(T a, T b, vec<2, T> & c) : vec(a, b, c.x, c.y) {};
			inline vec(vec<2, T> & a, vec<2, T> & b) : vec(a.x, a.y, b.x, b.y) {};
			inline vec(T x, T y, T z, T w) { this->x = x; this->y = y; this->z = z; this->w = w; };
			// operator overload
			inline vec operator=(const vec & a) { xyzw = a; return *this; };
			inline friend vec operator+=(const vec & a, const vec & b) { a.xyzw += a; return *this; };
			inline friend vec operator-=(const vec & a, const vec & b) { a.xyzw -= a; return *this; };
			inline friend vec operator*=(const vec & a, const vec & b) { a.xyzw *= a; return *this; };
			inline friend vec operator/=(const vec & a, const vec & b) { a.xyzw /= a; return *this; };
			inline friend vec operator+(const vec & a, const vec & b) { return vec(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); };
			inline friend vec operator-(const vec & a, const vec & b) { return vec(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); };
			inline friend vec operator*(const vec & a, const vec & b) { return vec(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); };
			inline friend vec operator/(const vec & a, const vec & b) { return vec(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); };
			// operator overload { vec<4, T>[i] }
			inline T & operator[](int index) { return ((T*)(&this->x))[index]; };
			// operator overload { vec<4, T>[i] }
			inline T const & operator[](int index) const { return ((T*)(&this->x))[index]; };
            // variables
            union {
                struct { T x, y, z, w; };
                struct { T r, g, b, a; };
				// detail::swizzle to vector2
				struct { detail::swizzle<2, T, 0, 0, -1, -2> xx; };
				struct { detail::swizzle<2, T, 0, 1, -1, -2> xy; };
				struct { detail::swizzle<2, T, 0, 2, -1, -2> xz; };
				struct { detail::swizzle<2, T, 0, 3, -1, -2> xw; };
				struct { detail::swizzle<2, T, 1, 0, -1, -2> yx; };
				struct { detail::swizzle<2, T, 1, 1, -1, -2> yy; };
				struct { detail::swizzle<2, T, 1, 2, -1, -2> yz; };
				struct { detail::swizzle<2, T, 1, 3, -1, -2> yw; };
				struct { detail::swizzle<2, T, 2, 0, -1, -2> zx; };
				struct { detail::swizzle<2, T, 2, 1, -1, -2> zy; };
				struct { detail::swizzle<2, T, 2, 2, -1, -2> zz; };
				struct { detail::swizzle<2, T, 2, 3, -1, -2> zw; };
				struct { detail::swizzle<2, T, 3, 0, -1, -2> wx; };
				struct { detail::swizzle<2, T, 3, 1, -1, -2> wy; };
				struct { detail::swizzle<2, T, 3, 2, -1, -2> wz; };
				struct { detail::swizzle<2, T, 3, 3, -1, -2> ww; };
				// detail::swizzle to vector3
				struct { detail::swizzle<3, T, 0, 0, 0, -1> xxx; };
				struct { detail::swizzle<3, T, 0, 0, 1, -1> xxy; };
				struct { detail::swizzle<3, T, 0, 0, 2, -1> xxz; };
				struct { detail::swizzle<3, T, 0, 0, 3, -1> xxw; };
				struct { detail::swizzle<3, T, 0, 1, 0, -1> xyx; };
				struct { detail::swizzle<3, T, 0, 1, 1, -1> xyy; };
				struct { detail::swizzle<3, T, 0, 1, 2, -1> xyz; };
				struct { detail::swizzle<3, T, 0, 1, 3, -1> xyw; };
				struct { detail::swizzle<3, T, 0, 2, 0, -1> xzx; };
				struct { detail::swizzle<3, T, 0, 2, 1, -1> xzy; };
				struct { detail::swizzle<3, T, 0, 2, 2, -1> xzz; };
				struct { detail::swizzle<3, T, 0, 2, 3, -1> xzw; };
				struct { detail::swizzle<3, T, 0, 3, 0, -1> xwx; };
				struct { detail::swizzle<3, T, 0, 3, 1, -1> xwy; };
				struct { detail::swizzle<3, T, 0, 3, 2, -1> xwz; };
				struct { detail::swizzle<3, T, 0, 3, 3, -1> xww; };
				struct { detail::swizzle<3, T, 1, 0, 0, -1> yxx; };
				struct { detail::swizzle<3, T, 1, 0, 1, -1> yxy; };
				struct { detail::swizzle<3, T, 1, 0, 2, -1> yxz; };
				struct { detail::swizzle<3, T, 1, 0, 3, -1> yxw; };
				struct { detail::swizzle<3, T, 1, 1, 0, -1> yyx; };
				struct { detail::swizzle<3, T, 1, 1, 1, -1> yyy; };
				struct { detail::swizzle<3, T, 1, 1, 2, -1> yyz; };
				struct { detail::swizzle<3, T, 1, 1, 3, -1> yyw; };
				struct { detail::swizzle<3, T, 1, 2, 0, -1> yzx; };
				struct { detail::swizzle<3, T, 1, 2, 1, -1> yzy; };
				struct { detail::swizzle<3, T, 1, 2, 2, -1> yzz; };
				struct { detail::swizzle<3, T, 1, 2, 3, -1> yzw; };
				struct { detail::swizzle<3, T, 1, 3, 0, -1> ywx; };
				struct { detail::swizzle<3, T, 1, 3, 1, -1> ywy; };
				struct { detail::swizzle<3, T, 1, 3, 2, -1> ywz; };
				struct { detail::swizzle<3, T, 1, 3, 3, -1> yww; };
				struct { detail::swizzle<3, T, 2, 0, 0, -1> zxx; };
				struct { detail::swizzle<3, T, 2, 0, 1, -1> zxy; };
				struct { detail::swizzle<3, T, 2, 0, 2, -1> zxz; };
				struct { detail::swizzle<3, T, 2, 0, 3, -1> zxw; };
				struct { detail::swizzle<3, T, 2, 1, 0, -1> zyx; };
				struct { detail::swizzle<3, T, 2, 1, 1, -1> zyy; };
				struct { detail::swizzle<3, T, 2, 1, 2, -1> zyz; };
				struct { detail::swizzle<3, T, 2, 1, 3, -1> zyw; };
				struct { detail::swizzle<3, T, 2, 2, 0, -1> zzx; };
				struct { detail::swizzle<3, T, 2, 2, 1, -1> zzy; };
				struct { detail::swizzle<3, T, 2, 2, 2, -1> zzz; };
				struct { detail::swizzle<3, T, 2, 2, 3, -1> zzw; };
				struct { detail::swizzle<3, T, 2, 3, 0, -1> zwx; };
				struct { detail::swizzle<3, T, 2, 3, 1, -1> zwy; };
				struct { detail::swizzle<3, T, 2, 3, 2, -1> zwz; };
				struct { detail::swizzle<3, T, 2, 3, 3, -1> zww; };
				struct { detail::swizzle<3, T, 3, 0, 0, -1> wxx; };
				struct { detail::swizzle<3, T, 3, 0, 1, -1> wxy; };
				struct { detail::swizzle<3, T, 3, 0, 2, -1> wxz; };
				struct { detail::swizzle<3, T, 3, 0, 3, -1> wxw; };
				struct { detail::swizzle<3, T, 3, 1, 0, -1> wyx; };
				struct { detail::swizzle<3, T, 3, 1, 1, -1> wyy; };
				struct { detail::swizzle<3, T, 3, 1, 2, -1> wyz; };
				struct { detail::swizzle<3, T, 3, 1, 3, -1> wyw; };
				struct { detail::swizzle<3, T, 3, 2, 0, -1> wzx; };
				struct { detail::swizzle<3, T, 3, 2, 1, -1> wzy; };
				struct { detail::swizzle<3, T, 3, 2, 2, -1> wzz; };
				struct { detail::swizzle<3, T, 3, 2, 3, -1> wzw; };
				struct { detail::swizzle<3, T, 3, 3, 0, -1> wwx; };
				struct { detail::swizzle<3, T, 3, 3, 1, -1> wwy; };
				struct { detail::swizzle<3, T, 3, 3, 2, -1> wwz; };
				struct { detail::swizzle<3, T, 3, 3, 3, -1> www; };
				// detail::swizzle to vector4
				struct { detail::swizzle<4, T, 0, 0, 0, 0> xxxx; };
				struct { detail::swizzle<4, T, 0, 0, 0, 1> xxxy; };
				struct { detail::swizzle<4, T, 0, 0, 0, 2> xxxz; };
				struct { detail::swizzle<4, T, 0, 0, 0, 3> xxxw; };
				struct { detail::swizzle<4, T, 0, 0, 1, 0> xxyx; };
				struct { detail::swizzle<4, T, 0, 0, 1, 1> xxyy; };
				struct { detail::swizzle<4, T, 0, 0, 1, 2> xxyz; };
				struct { detail::swizzle<4, T, 0, 0, 1, 3> xxyw; };
				struct { detail::swizzle<4, T, 0, 0, 2, 0> xxzx; };
				struct { detail::swizzle<4, T, 0, 0, 2, 1> xxzy; };
				struct { detail::swizzle<4, T, 0, 0, 2, 2> xxzz; };
				struct { detail::swizzle<4, T, 0, 0, 2, 3> xxzw; };
				struct { detail::swizzle<4, T, 0, 0, 3, 0> xxwx; };
				struct { detail::swizzle<4, T, 0, 0, 3, 1> xxwy; };
				struct { detail::swizzle<4, T, 0, 0, 3, 2> xxwz; };
				struct { detail::swizzle<4, T, 0, 0, 3, 3> xxww; };
				struct { detail::swizzle<4, T, 0, 1, 0, 0> xyxx; };
				struct { detail::swizzle<4, T, 0, 1, 0, 1> xyxy; };
				struct { detail::swizzle<4, T, 0, 1, 0, 2> xyxz; };
				struct { detail::swizzle<4, T, 0, 1, 0, 3> xyxw; };
				struct { detail::swizzle<4, T, 0, 1, 1, 0> xyyx; };
				struct { detail::swizzle<4, T, 0, 1, 1, 1> xyyy; };
				struct { detail::swizzle<4, T, 0, 1, 1, 2> xyyz; };
				struct { detail::swizzle<4, T, 0, 1, 1, 3> xyyw; };
				struct { detail::swizzle<4, T, 0, 1, 2, 0> xyzx; };
				struct { detail::swizzle<4, T, 0, 1, 2, 1> xyzy; };
				struct { detail::swizzle<4, T, 0, 1, 2, 2> xyzz; };
				struct { detail::swizzle<4, T, 0, 1, 2, 3> xyzw; };
				struct { detail::swizzle<4, T, 0, 1, 3, 0> xywx; };
				struct { detail::swizzle<4, T, 0, 1, 3, 1> xywy; };
				struct { detail::swizzle<4, T, 0, 1, 3, 2> xywz; };
				struct { detail::swizzle<4, T, 0, 1, 3, 3> xyww; };
				struct { detail::swizzle<4, T, 0, 2, 0, 0> xzxx; };
				struct { detail::swizzle<4, T, 0, 2, 0, 1> xzxy; };
				struct { detail::swizzle<4, T, 0, 2, 0, 2> xzxz; };
				struct { detail::swizzle<4, T, 0, 2, 0, 3> xzxw; };
				struct { detail::swizzle<4, T, 0, 2, 1, 0> xzyx; };
				struct { detail::swizzle<4, T, 0, 2, 1, 1> xzyy; };
				struct { detail::swizzle<4, T, 0, 2, 1, 2> xzyz; };
				struct { detail::swizzle<4, T, 0, 2, 1, 3> xzyw; };
				struct { detail::swizzle<4, T, 0, 2, 2, 0> xzzx; };
				struct { detail::swizzle<4, T, 0, 2, 2, 1> xzzy; };
				struct { detail::swizzle<4, T, 0, 2, 2, 2> xzzz; };
				struct { detail::swizzle<4, T, 0, 2, 2, 3> xzzw; };
				struct { detail::swizzle<4, T, 0, 2, 3, 0> xzwx; };
				struct { detail::swizzle<4, T, 0, 2, 3, 1> xzwy; };
				struct { detail::swizzle<4, T, 0, 2, 3, 2> xzwz; };
				struct { detail::swizzle<4, T, 0, 2, 3, 3> xzww; };
				struct { detail::swizzle<4, T, 0, 3, 0, 0> xwxx; };
				struct { detail::swizzle<4, T, 0, 3, 0, 1> xwxy; };
				struct { detail::swizzle<4, T, 0, 3, 0, 2> xwxz; };
				struct { detail::swizzle<4, T, 0, 3, 0, 3> xwxw; };
				struct { detail::swizzle<4, T, 0, 3, 1, 0> xwyx; };
				struct { detail::swizzle<4, T, 0, 3, 1, 1> xwyy; };
				struct { detail::swizzle<4, T, 0, 3, 1, 2> xwyz; };
				struct { detail::swizzle<4, T, 0, 3, 1, 3> xwyw; };
				struct { detail::swizzle<4, T, 0, 3, 2, 0> xwzx; };
				struct { detail::swizzle<4, T, 0, 3, 2, 1> xwzy; };
				struct { detail::swizzle<4, T, 0, 3, 2, 2> xwzz; };
				struct { detail::swizzle<4, T, 0, 3, 2, 3> xwzw; };
				struct { detail::swizzle<4, T, 0, 3, 3, 0> xwwx; };
				struct { detail::swizzle<4, T, 0, 3, 3, 1> xwwy; };
				struct { detail::swizzle<4, T, 0, 3, 3, 2> xwwz; };
				struct { detail::swizzle<4, T, 0, 3, 3, 3> xwww; };
				struct { detail::swizzle<4, T, 1, 0, 0, 0> yxxx; };
				struct { detail::swizzle<4, T, 1, 0, 0, 1> yxxy; };
				struct { detail::swizzle<4, T, 1, 0, 0, 2> yxxz; };
				struct { detail::swizzle<4, T, 1, 0, 0, 3> yxxw; };
				struct { detail::swizzle<4, T, 1, 0, 1, 0> yxyx; };
				struct { detail::swizzle<4, T, 1, 0, 1, 1> yxyy; };
				struct { detail::swizzle<4, T, 1, 0, 1, 2> yxyz; };
				struct { detail::swizzle<4, T, 1, 0, 1, 3> yxyw; };
				struct { detail::swizzle<4, T, 1, 0, 2, 0> yxzx; };
				struct { detail::swizzle<4, T, 1, 0, 2, 1> yxzy; };
				struct { detail::swizzle<4, T, 1, 0, 2, 2> yxzz; };
				struct { detail::swizzle<4, T, 1, 0, 2, 3> yxzw; };
				struct { detail::swizzle<4, T, 1, 0, 3, 0> yxwx; };
				struct { detail::swizzle<4, T, 1, 0, 3, 1> yxwy; };
				struct { detail::swizzle<4, T, 1, 0, 3, 2> yxwz; };
				struct { detail::swizzle<4, T, 1, 0, 3, 3> yxww; };
				struct { detail::swizzle<4, T, 1, 1, 0, 0> yyxx; };
				struct { detail::swizzle<4, T, 1, 1, 0, 1> yyxy; };
				struct { detail::swizzle<4, T, 1, 1, 0, 2> yyxz; };
				struct { detail::swizzle<4, T, 1, 1, 0, 3> yyxw; };
				struct { detail::swizzle<4, T, 1, 1, 1, 0> yyyx; };
				struct { detail::swizzle<4, T, 1, 1, 1, 1> yyyy; };
				struct { detail::swizzle<4, T, 1, 1, 1, 2> yyyz; };
				struct { detail::swizzle<4, T, 1, 1, 1, 3> yyyw; };
				struct { detail::swizzle<4, T, 1, 1, 2, 0> yyzx; };
				struct { detail::swizzle<4, T, 1, 1, 2, 1> yyzy; };
				struct { detail::swizzle<4, T, 1, 1, 2, 2> yyzz; };
				struct { detail::swizzle<4, T, 1, 1, 2, 3> yyzw; };
				struct { detail::swizzle<4, T, 1, 1, 3, 0> yywx; };
				struct { detail::swizzle<4, T, 1, 1, 3, 1> yywy; };
				struct { detail::swizzle<4, T, 1, 1, 3, 2> yywz; };
				struct { detail::swizzle<4, T, 1, 1, 3, 3> yyww; };
				struct { detail::swizzle<4, T, 1, 2, 0, 0> yzxx; };
				struct { detail::swizzle<4, T, 1, 2, 0, 1> yzxy; };
				struct { detail::swizzle<4, T, 1, 2, 0, 2> yzxz; };
				struct { detail::swizzle<4, T, 1, 2, 0, 3> yzxw; };
				struct { detail::swizzle<4, T, 1, 2, 1, 0> yzyx; };
				struct { detail::swizzle<4, T, 1, 2, 1, 1> yzyy; };
				struct { detail::swizzle<4, T, 1, 2, 1, 2> yzyz; };
				struct { detail::swizzle<4, T, 1, 2, 1, 3> yzyw; };
				struct { detail::swizzle<4, T, 1, 2, 2, 0> yzzx; };
				struct { detail::swizzle<4, T, 1, 2, 2, 1> yzzy; };
				struct { detail::swizzle<4, T, 1, 2, 2, 2> yzzz; };
				struct { detail::swizzle<4, T, 1, 2, 2, 3> yzzw; };
				struct { detail::swizzle<4, T, 1, 2, 3, 0> yzwx; };
				struct { detail::swizzle<4, T, 1, 2, 3, 1> yzwy; };
				struct { detail::swizzle<4, T, 1, 2, 3, 2> yzwz; };
				struct { detail::swizzle<4, T, 1, 2, 3, 3> yzww; };
				struct { detail::swizzle<4, T, 1, 3, 0, 0> ywxx; };
				struct { detail::swizzle<4, T, 1, 3, 0, 1> ywxy; };
				struct { detail::swizzle<4, T, 1, 3, 0, 2> ywxz; };
				struct { detail::swizzle<4, T, 1, 3, 0, 3> ywxw; };
				struct { detail::swizzle<4, T, 1, 3, 1, 0> ywyx; };
				struct { detail::swizzle<4, T, 1, 3, 1, 1> ywyy; };
				struct { detail::swizzle<4, T, 1, 3, 1, 2> ywyz; };
				struct { detail::swizzle<4, T, 1, 3, 1, 3> ywyw; };
				struct { detail::swizzle<4, T, 1, 3, 2, 0> ywzx; };
				struct { detail::swizzle<4, T, 1, 3, 2, 1> ywzy; };
				struct { detail::swizzle<4, T, 1, 3, 2, 2> ywzz; };
				struct { detail::swizzle<4, T, 1, 3, 2, 3> ywzw; };
				struct { detail::swizzle<4, T, 1, 3, 3, 0> ywwx; };
				struct { detail::swizzle<4, T, 1, 3, 3, 1> ywwy; };
				struct { detail::swizzle<4, T, 1, 3, 3, 2> ywwz; };
				struct { detail::swizzle<4, T, 1, 3, 3, 3> ywww; };
				struct { detail::swizzle<4, T, 2, 0, 0, 0> zxxx; };
				struct { detail::swizzle<4, T, 2, 0, 0, 1> zxxy; };
				struct { detail::swizzle<4, T, 2, 0, 0, 2> zxxz; };
				struct { detail::swizzle<4, T, 2, 0, 0, 3> zxxw; };
				struct { detail::swizzle<4, T, 2, 0, 1, 0> zxyx; };
				struct { detail::swizzle<4, T, 2, 0, 1, 1> zxyy; };
				struct { detail::swizzle<4, T, 2, 0, 1, 2> zxyz; };
				struct { detail::swizzle<4, T, 2, 0, 1, 3> zxyw; };
				struct { detail::swizzle<4, T, 2, 0, 2, 0> zxzx; };
				struct { detail::swizzle<4, T, 2, 0, 2, 1> zxzy; };
				struct { detail::swizzle<4, T, 2, 0, 2, 2> zxzz; };
				struct { detail::swizzle<4, T, 2, 0, 2, 3> zxzw; };
				struct { detail::swizzle<4, T, 2, 0, 3, 0> zxwx; };
				struct { detail::swizzle<4, T, 2, 0, 3, 1> zxwy; };
				struct { detail::swizzle<4, T, 2, 0, 3, 2> zxwz; };
				struct { detail::swizzle<4, T, 2, 0, 3, 3> zxww; };
				struct { detail::swizzle<4, T, 2, 1, 0, 0> zyxx; };
				struct { detail::swizzle<4, T, 2, 1, 0, 1> zyxy; };
				struct { detail::swizzle<4, T, 2, 1, 0, 2> zyxz; };
				struct { detail::swizzle<4, T, 2, 1, 0, 3> zyxw; };
				struct { detail::swizzle<4, T, 2, 1, 1, 0> zyyx; };
				struct { detail::swizzle<4, T, 2, 1, 1, 1> zyyy; };
				struct { detail::swizzle<4, T, 2, 1, 1, 2> zyyz; };
				struct { detail::swizzle<4, T, 2, 1, 1, 3> zyyw; };
				struct { detail::swizzle<4, T, 2, 1, 2, 0> zyzx; };
				struct { detail::swizzle<4, T, 2, 1, 2, 1> zyzy; };
				struct { detail::swizzle<4, T, 2, 1, 2, 2> zyzz; };
				struct { detail::swizzle<4, T, 2, 1, 2, 3> zyzw; };
				struct { detail::swizzle<4, T, 2, 1, 3, 0> zywx; };
				struct { detail::swizzle<4, T, 2, 1, 3, 1> zywy; };
				struct { detail::swizzle<4, T, 2, 1, 3, 2> zywz; };
				struct { detail::swizzle<4, T, 2, 1, 3, 3> zyww; };
				struct { detail::swizzle<4, T, 2, 2, 0, 0> zzxx; };
				struct { detail::swizzle<4, T, 2, 2, 0, 1> zzxy; };
				struct { detail::swizzle<4, T, 2, 2, 0, 2> zzxz; };
				struct { detail::swizzle<4, T, 2, 2, 0, 3> zzxw; };
				struct { detail::swizzle<4, T, 2, 2, 1, 0> zzyx; };
				struct { detail::swizzle<4, T, 2, 2, 1, 1> zzyy; };
				struct { detail::swizzle<4, T, 2, 2, 1, 2> zzyz; };
				struct { detail::swizzle<4, T, 2, 2, 1, 3> zzyw; };
				struct { detail::swizzle<4, T, 2, 2, 2, 0> zzzx; };
				struct { detail::swizzle<4, T, 2, 2, 2, 1> zzzy; };
				struct { detail::swizzle<4, T, 2, 2, 2, 2> zzzz; };
				struct { detail::swizzle<4, T, 2, 2, 2, 3> zzzw; };
				struct { detail::swizzle<4, T, 2, 2, 3, 0> zzwx; };
				struct { detail::swizzle<4, T, 2, 2, 3, 1> zzwy; };
				struct { detail::swizzle<4, T, 2, 2, 3, 2> zzwz; };
				struct { detail::swizzle<4, T, 2, 2, 3, 3> zzww; };
				struct { detail::swizzle<4, T, 2, 3, 0, 0> zwxx; };
				struct { detail::swizzle<4, T, 2, 3, 0, 1> zwxy; };
				struct { detail::swizzle<4, T, 2, 3, 0, 2> zwxz; };
				struct { detail::swizzle<4, T, 2, 3, 0, 3> zwxw; };
				struct { detail::swizzle<4, T, 2, 3, 1, 0> zwyx; };
				struct { detail::swizzle<4, T, 2, 3, 1, 1> zwyy; };
				struct { detail::swizzle<4, T, 2, 3, 1, 2> zwyz; };
				struct { detail::swizzle<4, T, 2, 3, 1, 3> zwyw; };
				struct { detail::swizzle<4, T, 2, 3, 2, 0> zwzx; };
				struct { detail::swizzle<4, T, 2, 3, 2, 1> zwzy; };
				struct { detail::swizzle<4, T, 2, 3, 2, 2> zwzz; };
				struct { detail::swizzle<4, T, 2, 3, 2, 3> zwzw; };
				struct { detail::swizzle<4, T, 2, 3, 3, 0> zwwx; };
				struct { detail::swizzle<4, T, 2, 3, 3, 1> zwwy; };
				struct { detail::swizzle<4, T, 2, 3, 3, 2> zwwz; };
				struct { detail::swizzle<4, T, 2, 3, 3, 3> zwww; };
				struct { detail::swizzle<4, T, 3, 0, 0, 0> wxxx; };
				struct { detail::swizzle<4, T, 3, 0, 0, 1> wxxy; };
				struct { detail::swizzle<4, T, 3, 0, 0, 2> wxxz; };
				struct { detail::swizzle<4, T, 3, 0, 0, 3> wxxw; };
				struct { detail::swizzle<4, T, 3, 0, 1, 0> wxyx; };
				struct { detail::swizzle<4, T, 3, 0, 1, 1> wxyy; };
				struct { detail::swizzle<4, T, 3, 0, 1, 2> wxyz; };
				struct { detail::swizzle<4, T, 3, 0, 1, 3> wxyw; };
				struct { detail::swizzle<4, T, 3, 0, 2, 0> wxzx; };
				struct { detail::swizzle<4, T, 3, 0, 2, 1> wxzy; };
				struct { detail::swizzle<4, T, 3, 0, 2, 2> wxzz; };
				struct { detail::swizzle<4, T, 3, 0, 2, 3> wxzw; };
				struct { detail::swizzle<4, T, 3, 0, 3, 0> wxwx; };
				struct { detail::swizzle<4, T, 3, 0, 3, 1> wxwy; };
				struct { detail::swizzle<4, T, 3, 0, 3, 2> wxwz; };
				struct { detail::swizzle<4, T, 3, 0, 3, 3> wxww; };
				struct { detail::swizzle<4, T, 3, 1, 0, 0> wyxx; };
				struct { detail::swizzle<4, T, 3, 1, 0, 1> wyxy; };
				struct { detail::swizzle<4, T, 3, 1, 0, 2> wyxz; };
				struct { detail::swizzle<4, T, 3, 1, 0, 3> wyxw; };
				struct { detail::swizzle<4, T, 3, 1, 1, 0> wyyx; };
				struct { detail::swizzle<4, T, 3, 1, 1, 1> wyyy; };
				struct { detail::swizzle<4, T, 3, 1, 1, 2> wyyz; };
				struct { detail::swizzle<4, T, 3, 1, 1, 3> wyyw; };
				struct { detail::swizzle<4, T, 3, 1, 2, 0> wyzx; };
				struct { detail::swizzle<4, T, 3, 1, 2, 1> wyzy; };
				struct { detail::swizzle<4, T, 3, 1, 2, 2> wyzz; };
				struct { detail::swizzle<4, T, 3, 1, 2, 3> wyzw; };
				struct { detail::swizzle<4, T, 3, 1, 3, 0> wywx; };
				struct { detail::swizzle<4, T, 3, 1, 3, 1> wywy; };
				struct { detail::swizzle<4, T, 3, 1, 3, 2> wywz; };
				struct { detail::swizzle<4, T, 3, 1, 3, 3> wyww; };
				struct { detail::swizzle<4, T, 3, 2, 0, 0> wzxx; };
				struct { detail::swizzle<4, T, 3, 2, 0, 1> wzxy; };
				struct { detail::swizzle<4, T, 3, 2, 0, 2> wzxz; };
				struct { detail::swizzle<4, T, 3, 2, 0, 3> wzxw; };
				struct { detail::swizzle<4, T, 3, 2, 1, 0> wzyx; };
				struct { detail::swizzle<4, T, 3, 2, 1, 1> wzyy; };
				struct { detail::swizzle<4, T, 3, 2, 1, 2> wzyz; };
				struct { detail::swizzle<4, T, 3, 2, 1, 3> wzyw; };
				struct { detail::swizzle<4, T, 3, 2, 2, 0> wzzx; };
				struct { detail::swizzle<4, T, 3, 2, 2, 1> wzzy; };
				struct { detail::swizzle<4, T, 3, 2, 2, 2> wzzz; };
				struct { detail::swizzle<4, T, 3, 2, 2, 3> wzzw; };
				struct { detail::swizzle<4, T, 3, 2, 3, 0> wzwx; };
				struct { detail::swizzle<4, T, 3, 2, 3, 1> wzwy; };
				struct { detail::swizzle<4, T, 3, 2, 3, 2> wzwz; };
				struct { detail::swizzle<4, T, 3, 2, 3, 3> wzww; };
				struct { detail::swizzle<4, T, 3, 3, 0, 0> wwxx; };
				struct { detail::swizzle<4, T, 3, 3, 0, 1> wwxy; };
				struct { detail::swizzle<4, T, 3, 3, 0, 2> wwxz; };
				struct { detail::swizzle<4, T, 3, 3, 0, 3> wwxw; };
				struct { detail::swizzle<4, T, 3, 3, 1, 0> wwyx; };
				struct { detail::swizzle<4, T, 3, 3, 1, 1> wwyy; };
				struct { detail::swizzle<4, T, 3, 3, 1, 2> wwyz; };
				struct { detail::swizzle<4, T, 3, 3, 1, 3> wwyw; };
				struct { detail::swizzle<4, T, 3, 3, 2, 0> wwzx; };
				struct { detail::swizzle<4, T, 3, 3, 2, 1> wwzy; };
				struct { detail::swizzle<4, T, 3, 3, 2, 2> wwzz; };
				struct { detail::swizzle<4, T, 3, 3, 2, 3> wwzw; };
				struct { detail::swizzle<4, T, 3, 3, 3, 0> wwwx; };
				struct { detail::swizzle<4, T, 3, 3, 3, 1> wwwy; };
				struct { detail::swizzle<4, T, 3, 3, 3, 2> wwwz; };
				struct { detail::swizzle<4, T, 3, 3, 3, 3> wwww; };
            };
        };
    } // namespace fuse

/**************************************************************************************************/