#include "gtest/gtest.h"

extern "C" {
#include <production.h>
}

class ProductionTest : public ::testing::Test {
protected:
	void SetUp() override {
	}

	void TearDown() override {}
};

TEST_F(ProductionTest, Test_sum) {
	// Arange
	// Act
	int n = sum(3, 4);
	//Assert
	EXPECT_EQ(7, n);
}
