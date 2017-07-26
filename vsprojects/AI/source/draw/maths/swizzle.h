#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

    //https://github.com/g-truc/glm/tree/master/glm/detail

    namespace draw
    {
        // swizzle base 0
        template<typename T, int size> class swizzle0 {
            protected:
                T data[size]
        };

        // swizzle base 1
        template<int size, typename T, int E1, int E2, int E3, int E4>
        class swizzle1 : public swizzle0<float, size> {
        };

        template<int size, typename T, int E1, int E2>
        class swizzle1<2, T, E1, E2, -1, -2> : public swizzle0<float, 2>
        {
            T operator()() const { return T{ this->data[E1], this->data[E2] }; };
        };

        template<int size, typename T, int E1, int E2, int E3>
        class swizzle1<3, T, E1, E2, E3, -1> : public swizzle0<float, 3>
        {
            T operator()() const { return T{ this->data[E1], this->data[E2], this->data[E3] }; };
        };

        template<int size, typename T, int E1, int E2, int E3, int E4>
        class swizzle1<4, T, E1, E2, E3, E4> : public swizzle0<float, 4>
        {
            T operator()() const { return T{ this->data[E1], this->data[E2], this->data[E3], this->data[E4] }; };
        };

        // swizzle base 2
        template<int size, typename T, int E1, int E2, int E3, int E4>
        class swizzle2 : public swizzle1<size, T, E1, E2, E3, E4>
        {
            swizzle2 & operator=(swizzle2 const & other)
            {
                
            }
        };
    }

/**************************************************************************************************/