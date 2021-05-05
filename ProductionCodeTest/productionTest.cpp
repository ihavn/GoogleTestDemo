#include <stdint.h>
#include "gtest/gtest.h"
#include "../../fff/fff.h"

DEFINE_FFF_GLOBALS

extern "C" {
#include <hal.h>
#include <production.h>
#include <my_utils.h>
}

// Create mocks for HAL functions
FAKE_VALUE_FUNC(int8_t, bar, int8_t, int8_t); // int8_t util_add(int8_t n1, int8_t n2)
FAKE_VOID_FUNC(hal_create, uint8_t);
FAKE_VALUE_FUNC(int16_t, hal_getVoltage, uint8_t);
FAKE_VALUE_FUNC(uint8_t, foo, uint8_t);    // uint8_t foo(uint8_t x)

class ProductionTest : public ::testing::Test {
protected:
	void SetUp() override {
		RESET_FAKE(bar);
		RESET_FAKE(hal_create);
		RESET_FAKE(hal_getVoltage);
		RESET_FAKE(foo);
		FFF_RESET_HISTORY();
	}

	void TearDown() override {}
};

TEST_F(ProductionTest, Test_hal_create_is_called) {
	// Arange
	// Act
	production_create();

	//Assert
	ASSERT_EQ(1u, hal_create_fake.call_count);
	ASSERT_EQ(10u, hal_create_fake.arg0_val);
}

TEST_F(ProductionTest, Test_hal_getVoltage_is_called) {
	// Arange
	uint8_t _sensor = 12;
	// Setup the value to be returned by the fake hal_getVoltage
	hal_getVoltage_fake.return_val = 15;

	// Act
	production_meassureTemperature(_sensor);
	int8_t _temp = production_getTemperature(_sensor);

	//Assert
	ASSERT_EQ(1u, hal_getVoltage_fake.call_count); // Test that hal_getVoltage(...) is called
	ASSERT_EQ(_sensor, hal_getVoltage_fake.arg0_val); // Test that hal_getVoltage(...) is called with the right argument
	ASSERT_EQ(15*2, _temp); // Test that production_getTemperature(...) returned the expected value
}
