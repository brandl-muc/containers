/*
    unstable_vector - A std::vector based container which has member functions
        with higher speed by not preserving the order of its elements
    Copyright (C) 2017 Matthäus Brandl

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "../../src/unstable_vector.h"

#include <gmock/gmock.h>

using mbr::container::unstable_vector;

namespace container_tests
{
    namespace
    {
        using Fixture_UnstableVector = ::testing::Test;
    }

    TEST_F(Fixture_UnstableVector, Construct_Default_IsEmpty)
    {
        // arrange

        // act
        unstable_vector<int> uvec;

        // assert
        ASSERT_TRUE(uvec.empty());
    }

    TEST_F(Fixture_UnstableVector, Construct_NTimesCopy_ContainsNCopies)
    {
        // arrange
        auto const times = 15u;
        auto const value = 42;

        // act
        unstable_vector<int> uvec(times, value);

        // assert
        EXPECT_EQ(times, uvec.size());
        EXPECT_THAT(uvec, ::testing::Each(value));
    }
}
