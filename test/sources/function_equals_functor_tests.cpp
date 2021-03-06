///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's One Zero Functors Library
// Copyright (C) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "primordialmachine/one_zero_functors/include.hpp"
#include <gtest/gtest.h>

template<typename T>
struct test
{
  void operator()() const
  {
    using namespace primordialmachine;
    ASSERT_EQ(one_functor<T>()(), one<T>());
    ASSERT_EQ(one<T>(), one_functor<T>()());
    ASSERT_EQ(zero_functor<T>()(), zero<T>());
    ASSERT_EQ(zero<T>(), zero_functor<T>()());
  }
}; // struct test

// Performs the following tests:
// * functor == function
// * function == functor
// for the one functor/function.
// * functor == function
// * function == functor
// for the zero functor/function.
TEST(one_zero_functor_tests, function_equals_functor_tests)
{
  test<char>()();
  test<signed char>()();
  test<unsigned char>()();

  test<signed short int>()();
  test<unsigned short int>()();

  test<signed long int>()();
  test<unsigned long int>()();

  test<signed long long int>()();
  test<unsigned long long int>()();

  test<int8_t>()();
  test<uint8_t>()();

  test<int16_t>()();
  test<uint16_t>()();

  test<int32_t>()();
  test<uint32_t>()();

  test<int64_t>()();
  test<uint64_t>()();

  test<float>()();
  test<double>()();
  test<long double>()();
}
