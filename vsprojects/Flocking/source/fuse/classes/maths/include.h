#pragma once
/** Dependencies **********************************************************************************/

	namespace fuse
	{
		// objects
		template<int N, typename T> struct vec;
		template<int C, int R, typename T> struct mat;
		// definitions
		template <typename T> using vec2 = vec<2, T>;
		template <typename T> using vec3 = vec<3, T>;
		template <typename T> using vec4 = vec<4, T>;
		template <typename T> using mat2 = mat<2, 2, T>;
		template <typename T> using mat3 = mat<3, 2, T>;
		template <typename T> using mat4 = mat<4, 2, T>;
	} // namespace fuse

	// required headers
	#include "detail\type-swizzle-0.h"
	#include "detail\type-swizzle-1.h"
	#include "detail\type-swizzle-2.h"
	#include "detail\type-swizzle.h"
	#include "vector\type-vec2.h"
	#include "vector\type-vec3.h"
	#include "vector\type-vec4.h"

/** Declarations **********************************************************************************/
/**************************************************************************************************/