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

#include <list>

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
        unstable_vector<int> const result;

        // assert
        ASSERT_TRUE(result.empty());
    }

    TEST_F(Fixture_UnstableVector, Construct_NTimesCopy_ContainsNCopies)
    {
        // arrange
        auto const times = 15u;
        auto const value = 42;

        // act
        unstable_vector<int> const result(times, value);

        // assert
        EXPECT_EQ(times, result.size());
        EXPECT_THAT(result, ::testing::Each(value));
    }

    TEST_F(Fixture_UnstableVector, Construct_NTimesDefault_ContainsNCopies)
    {
        // arrange
        auto const times = 15u;

        // act
        unstable_vector<int> const result(times);

        // assert
        EXPECT_EQ(times, result.size());
        EXPECT_THAT(result, ::testing::Each(decltype(result)::value_type{}));
    }

    TEST_F(Fixture_UnstableVector, Construct_IteratorPair_ContainsSameElements)
    {
        // arrange
        std::list<int> input(10);
        std::iota(input.begin(), input.end(), 0);

        // act
        unstable_vector<int> const result(input.cbegin(), input.cend());

        // assert
        EXPECT_THAT(result, ::testing::ElementsAreArray(input));
    }

    TEST_F(Fixture_UnstableVector, Construct_Copy_ContainersAreEqual)
    {
        // arrange
        unstable_vector<int> input(10);
        std::iota(input.begin(), input.end(), -5);

        // act
        unstable_vector<int> const result(input);

        // assert
        EXPECT_THAT(result, ::testing::ContainerEq(input));
    }

    TEST_F(Fixture_UnstableVector, Construct_Move_InputWasMoved)
    {
        // arrange
        unstable_vector<int> template_(10);
        std::iota(template_.begin(), template_.end(), -5);
        unstable_vector<int> input(template_);

        // act
        unstable_vector<int> const result(std::move(input));

        // assert
        EXPECT_TRUE(input.empty());
        EXPECT_THAT(result, ::testing::ContainerEq(template_));
    }

    TEST_F(Fixture_UnstableVector, Construct_CopyFromUnderlying_ContainersAreEqual)
    {
        // arrange
        unstable_vector<int>::vector_type input{10};
        std::iota(input.begin(), input.end(), -5);

        // act
        unstable_vector<int> const result{input};

        // assert
        EXPECT_THAT(result, ::testing::ElementsAreArray(input));
    }

    TEST_F(Fixture_UnstableVector, Construct_MoveFromUnderlying_InputWasMoved)
    {
        // arrange
        unstable_vector<int>::vector_type template_{10};
        std::iota(template_.begin(), template_.end(), -5);
        decltype(template_) input{template_};

        // act
        unstable_vector<int> const result{std::move(input)};

        // assert
        EXPECT_TRUE(input.empty());
        EXPECT_THAT(result, ::testing::ElementsAreArray(template_));
    }
    
    TEST_F(Fixture_UnstableVector, Construct_InitializerList_ContainsListElements)
    {
        // arrange
        std::initializer_list<int> const iList = {1, 2, 3, 4, 5};

        // act
        unstable_vector<int> const result = iList;
        
        // assert
        EXPECT_THAT(result, ::testing::ElementsAreArray(iList));
    }
}
