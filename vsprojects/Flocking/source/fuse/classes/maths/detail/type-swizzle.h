#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace fuse
	{
		namespace detail
		{
			// [vec#] swizzle definition
			template<int N, typename T, int E0, int E1, int E2, int E3>
			struct swizzle : public swizzle_2<N, T, E0, E1, E2, E3, (E0 == E1 || E0 == E2 || E0 == E3 || E1 == E2 || E1 == E3 || E2 == E3)>
			{
				// operator overload { (vec<N,T>) swizzle }
				operator vec<N, T>() { return (*this)(); };
				// operator overload { swizzle = vec<N,T> }
				using swizzle_2<N, T, E0, E1, E2, E3, (E0 == E1 || E0 == E2 || E0 == E3 || E1 == E2 || E1 == E3 || E2 == E3)>::operator=;
			};
		} // namespace detail
	} // namespace fuse

/**************************************************************************************************/