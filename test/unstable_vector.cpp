#include "../src/unstable_vector.h"

#include <gtest/gtest.h>

using mbr::container::unstable_vector; 

TEST(unstable_vector, DefaultConstructor_IsEmpty)
{
	// arrange
	
	// act
	unstable_vector<int> uvec;
	
	// assert
    ASSERT_TRUE(uvec.empty());
}