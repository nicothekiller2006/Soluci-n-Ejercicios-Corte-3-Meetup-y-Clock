#ifndef MEETUP_H
#define MEETUP_H

#include <chrono>

namespace meetup {

class scheduler {
public:
    scheduler(std::chrono::month month, std::chrono::year year);

    std::chrono::year_month_day first(std::chrono::weekday wd) const;
    std::chrono::year_month_day second(std::chrono::weekday wd) const;
    std::chrono::year_month_day third(std::chrono::weekday wd) const;
    std::chrono::year_month_day fourth(std::chrono::weekday wd) const;
    std::chrono::year_month_day teenth(std::chrono::weekday wd) const;
    std::chrono::year_month_day last(std::chrono::weekday wd) const;

private:
    std::chrono::month month_;
    std::chrono::year year_;

    std::chrono::year_month_day find_day_in_range(std::chrono::weekday wd, int start_day, int end_day) const;
};

}  // namespace meetup

#endif
