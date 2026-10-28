#include "meetup.h"

namespace meetup {

scheduler::scheduler(std::chrono::month month, std::chrono::year year)
    : month_(month), year_(year) {}

std::chrono::year_month_day scheduler::find_day_in_range(std::chrono::weekday wd, int start_day, int end_day) const {
    for (int d = start_day; d <= end_day; ++d) {
        std::chrono::year_month_day ymd{year_, month_, std::chrono::day(static_cast<unsigned>(d))};
        if (ymd.ok() && std::chrono::weekday{ymd} == wd) {
            return ymd;
        }
    }
    return {};
}

std::chrono::year_month_day scheduler::first(std::chrono::weekday wd) const {
    return find_day_in_range(wd, 1, 7);
}

std::chrono::year_month_day scheduler::second(std::chrono::weekday wd) const {
    return find_day_in_range(wd, 8, 14);
}

std::chrono::year_month_day scheduler::third(std::chrono::weekday wd) const {
    return find_day_in_range(wd, 15, 21);
}

std::chrono::year_month_day scheduler::fourth(std::chrono::weekday wd) const {
    return find_day_in_range(wd, 22, 28);
}

std::chrono::year_month_day scheduler::teenth(std::chrono::weekday wd) const {
    // Los días "teenth" siempre corresponden estrictamente a los días 13 al 19
    return find_day_in_range(wd, 13, 19);
}

std::chrono::year_month_day scheduler::last(std::chrono::weekday wd) const {
    // El último día del mes estará en los últimos 7 días válidos del mes
    auto last_day_of_month = (year_ / month_ / std::chrono::last).day();
    unsigned last_d = static_cast<unsigned>(last_day_of_month);
    return find_day_in_range(wd, static_cast<int>(last_d) - 6, static_cast<int>(last_d));
}

}  // namespace meetup
