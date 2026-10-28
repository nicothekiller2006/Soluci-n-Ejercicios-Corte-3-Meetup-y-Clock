#include "meetup.h"
#include <gtest/gtest.h>
#include <chrono>

using namespace std::chrono_literals;

TEST(MeetupTest, Monteenth_of_may_2013) {
    meetup::scheduler s(std::chrono::May, 2013y);
    EXPECT_EQ(s.teenth(std::chrono::Monday), 2013y/std::chrono::May/13d);
}

TEST(MeetupTest, First_monday_of_march_2013) {
    meetup::scheduler s(std::chrono::March, 2013y);
    EXPECT_EQ(s.first(std::chrono::Monday), 2013y/std::chrono::March/4d);
}
