#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	namespace fuse
	{
		namespace detail
		{
			// [####] swizzle_0 definition
			template<int N, typename T>
			struct swizzle_0
			{
			protected:
				// variables
				char m_buffer[1];
				// operator overload { swizzle_0[i] }
				inline T & operator[](int index) { return ((T*)(&m_buffer[0]))[index]; };
			};
		} // namespace detail
	} // namespace fuse

/**************************************************************************************************/