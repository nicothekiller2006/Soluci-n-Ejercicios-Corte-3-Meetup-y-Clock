#include "clock.h"
#include <cstdio>

namespace date_independent {

clock::clock(int total_minutes) : total_minutes_(normalize(total_minutes)) {}

int clock::normalize(int minutes) {
    constexpr int minutes_per_day = 24 * 60;
    int normalized = minutes % minutes_per_day;
    if (normalized < 0) {
        normalized += minutes_per_day;
    }
    return normalized;
}

clock clock::at(int hours, int minutes) {
    return clock(hours * 60 + minutes);
}

clock clock::plus(int minutes) const {
    return clock(total_minutes_ + minutes);
}

clock clock::minus(int minutes) const {
    return clock(total_minutes_ - minutes);
}

clock::operator std::string() const {
    int hours = total_minutes_ / 60;
    int minutes = total_minutes_ % 60;
    char buffer[6];
    std::snprintf(buffer, sizeof(buffer), "%02d:%02d", hours, minutes);
    return std::string(buffer);
}

bool clock::operator==(const clock& other) const {
    return total_minutes_ == other.total_minutes_;
}

}  // namespace date_independent
