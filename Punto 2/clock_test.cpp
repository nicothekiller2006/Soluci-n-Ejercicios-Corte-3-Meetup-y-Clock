#include "clock.h"
#include <gtest/gtest.h>

using date_independent::clock;

TEST(ClockTest, On_the_hour) {
    EXPECT_EQ("08:00", std::string(date_independent::clock::at(8, 0)));
}

TEST(ClockTest, Past_the_hour) {
    EXPECT_EQ("11:09", std::string(date_independent::clock::at(11, 9)));
}

TEST(ClockTest, Add_minutes) {
    auto clock1 = date_independent::clock::at(10, 0).plus(3);
    EXPECT_EQ("10:03", std::string(clock1));
}

TEST(ClockTest, Subtract_minutes) {
    auto clock1 = date_independent::clock::at(10, 3).minus(3);
    EXPECT_EQ("10:00", std::string(clock1));
}

TEST(ClockTest, Clocks_with_same_time_are_equal) {
    EXPECT_EQ(date_independent::clock::at(15, 37), date_independent::clock::at(15, 37));
}

TEST(ClockTest, Wrap_around_negative_hours) {
    EXPECT_EQ("21:00", std::string(date_independent::clock::at(-3, 0)));
}
