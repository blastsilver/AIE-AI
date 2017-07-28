#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace fuse
	{
		namespace detail
		{
			// [vec#] swizzle_1 definition
			template<int N, typename T, int E0, int E1, int E2, int E3>
			struct swizzle_1 : public swizzle_0<N, T> {};

			// [vec2] swizzle_1 definition
			template<typename T, int E0, int E1>
			struct swizzle_1<2, T, E0, E1, -1, -2> : public swizzle_0<2, T>
			{
				// return vector 2
				vec<2, T> operator()()
				{
					return vec<2, T>((*this)[E0], (*this)[E1]);
				};
			};

			// [vec3] swizzle_1 definition
			template<typename T, int E0, int E1, int E2>
			struct swizzle_1<3, T, E0, E1, E2, -1> : public swizzle_0<3, T>
			{
				// return vector 3
				vec<3, T> operator()()
				{
					return vec<3, T>((*this)[E0], (*this)[E1], (*this)[E2]);
				};
			};

			// [vec4] swizzle_1 definition
			template<typename T, int E0, int E1, int E2, int E3>
			struct swizzle_1<4, T, E0, E1, E2, E3> : public swizzle_0<4, T>
			{
				// return vector 4
				vec<4, T> operator()()
				{
					return vec<4, T>((*this)[E0], (*this)[E1], (*this)[E2], (*this)[E3]);
				};
			};
		} // namespace detail
	} // namespace fuse

/**************************************************************************************************/