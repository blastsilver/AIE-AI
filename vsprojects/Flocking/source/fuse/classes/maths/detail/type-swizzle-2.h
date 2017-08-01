#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace fuse
	{
		namespace detail
		{
			// [vec#] swizzle_2 definition { REPEATS = 0 }
			template<int N, typename T, int E0, int E1, int E2, int E3, int REPEATS>
			struct swizzle_2 : public swizzle_1<N, T, E0, E1, E2, E3>
			{
				// operator overload { swizzle_2[i] }
				T & operator[](int i)
				{
					const int offset[4] = { E0, E1, E2, E3 };
					return swizzle_0<N, T>::operator[](offset[i]);
				};
				// operator overload { swizzle_2 = vec<N,T> }
				swizzle_2 & operator=(const vec<N, T> & other)
				{
					struct operation { void operator()(T & a, const T & b) { a = b; }; };
					return apply_operation(other, operation());
				};
				// operator overload { swizzle_2 += vec<N,T> }
				swizzle_2 & operator+=(const vec<N, T> & other)
				{
					struct operation { void operator()(T & a, const T & b) { a += b; }; };
					return apply_operation(other, operation());
				};
				// operator overload { swizzle_2 -= vec<N,T> }
				swizzle_2 & operator-=(const vec<N, T> & other)
				{
					struct operation { void operator()(T & a, const T & b) { a -= b; }; };
					return apply_operation(other, operation());
				};
				// operator overload { swizzle_2 *= vec<N,T> }
				swizzle_2 & operator*=(const vec<N, T> & other)
				{
					struct operation { void operator()(T & a, const T & b) { a *= b; }; };
					return apply_operation(other, operation());
				};
				// operator overload { swizzle_2 /= vec<N,T> }
				swizzle_2 & operator/=(const vec<N, T> & other)
				{
					struct operation { void operator()(T & a, const T & b) { a /= b; }; };
					return apply_operation(other, operation());
				};
			protected:
				// apply structure operation
				template<typename OPERATION_T>
				swizzle_2 & apply_operation(const vec<N, T> & other, OPERATION_T op)
				{
					for (int i = 0; i < N; i++) op((*this)[i], other[i]);
					return *this;
				};
			};

			// [vec#] swizzle_2 definition { REPEATS = 1 }
			template<int N, typename T, int E0, int E1, int E2, int E3>
			struct swizzle_2<N, T, E0, E1, E2, E3, 1> : public swizzle_1<N, T, E0, E1, E2, E3>
			{
				// operator overload { swizzle_2[i] }
				T & operator[](int i)
				{
					const int offset[4] = { E0, E1, E2, E3 };
					return swizzle_0<N, T>::operator[](offset[i]);
				};
			};
		} // namespace detail
	} // namespace fuse

/**************************************************************************************************/