#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    namespace fuse
    {
		template<typename T>
        struct vec<2, T>
		{
            // defaults
            inline vec() : vec(0, 0) {};
            inline vec(T n) : vec(n, n) {};
			inline vec(const vec & n) : vec(n.x, n.y) {};
            inline vec(T x, T y) { this->x = x; this->y = y; };
			// operator overload
			inline vec operator=(const vec & a) { xy = a; return *this; };
			inline friend vec operator+=(const vec & a, const vec & b) { a.xy += a; return *this; };
			inline friend vec operator-=(const vec & a, const vec & b) { a.xy -= a; return *this; };
			inline friend vec operator*=(const vec & a, const vec & b) { a.xy *= a; return *this; };
			inline friend vec operator/=(const vec & a, const vec & b) { a.xy /= a; return *this; };
			inline friend vec operator+(const vec & a, const vec & b) { return vec(a.x + b.x, a.y + b.y); };
			inline friend vec operator-(const vec & a, const vec & b) { return vec(a.x - b.x, a.y - b.y); };
			inline friend vec operator*(const vec & a, const vec & b) { return vec(a.x * b.x, a.y * b.y); };
			inline friend vec operator/(const vec & a, const vec & b) { return vec(a.x / b.x, a.y / b.y); };
			// operator overload { vec<2, T>[i] }
			inline T & operator[](int index) { return ((T*)(&this->x))[index]; };
			// operator overload { vec<2, T>[i] }
			inline T const & operator[](int index) const { return ((T*)(&this->x))[index]; };
            // variables
            union {
                struct { T x, y; };
                struct { T r, g; };
				// swizzle to vector2
				struct { detail::swizzle<2, T, 0, 0, -1, -2> xx; };
				struct { detail::swizzle<2, T, 0, 1, -1, -2> xy; };
				struct { detail::swizzle<2, T, 1, 0, -1, -2> yx; };
				struct { detail::swizzle<2, T, 1, 1, -1, -2> yy; };
				// swizzle to vector3
				struct { detail::swizzle<3, T, 0, 0, 0, -2> xxx; };
				struct { detail::swizzle<3, T, 0, 0, 1, -2> xxy; };
				struct { detail::swizzle<3, T, 0, 1, 0, -2> xyx; };
				struct { detail::swizzle<3, T, 0, 1, 1, -2> xyy; };
				struct { detail::swizzle<3, T, 1, 0, 0, -2> yxx; };
				struct { detail::swizzle<3, T, 1, 0, 1, -2> yxy; };
				struct { detail::swizzle<3, T, 1, 1, 0, -2> yyx; };
				struct { detail::swizzle<3, T, 1, 1, 1, -2> yyy; };
				// swizzle to vector4
				struct { detail::swizzle<4, T, 0, 0, 0, 0> xxxx; };\
				struct { detail::swizzle<4, T, 0, 0, 0, 1> xxxy; };\
				struct { detail::swizzle<4, T, 0, 0, 1, 0> xxyx; };\
				struct { detail::swizzle<4, T, 0, 0, 1, 1> xxyy; };\
				struct { detail::swizzle<4, T, 0, 1, 0, 0> xyxx; };\
				struct { detail::swizzle<4, T, 0, 1, 0, 1> xyxy; };\
				struct { detail::swizzle<4, T, 0, 1, 1, 0> xyyx; };\
				struct { detail::swizzle<4, T, 0, 1, 1, 1> xyyy; };\
				struct { detail::swizzle<4, T, 1, 0, 0, 0> yxxx; };\
				struct { detail::swizzle<4, T, 1, 0, 0, 1> yxxy; };\
				struct { detail::swizzle<4, T, 1, 0, 1, 0> yxyx; };\
				struct { detail::swizzle<4, T, 1, 0, 1, 1> yxyy; };\
				struct { detail::swizzle<4, T, 1, 1, 0, 0> yyxx; };\
				struct { detail::swizzle<4, T, 1, 1, 0, 1> yyxy; };\
				struct { detail::swizzle<4, T, 1, 1, 1, 0> yyyx; };\
				struct { detail::swizzle<4, T, 1, 1, 1, 1> yyyy; };
            };
        };
    } // namespace fuse

/**************************************************************************************************/