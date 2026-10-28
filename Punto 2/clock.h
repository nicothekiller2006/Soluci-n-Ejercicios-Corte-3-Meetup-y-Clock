#ifndef CLOCK_H
#define CLOCK_H

#include <string>

namespace date_independent {

class clock {
public:
    static clock at(int hours, int minutes);

    clock plus(int minutes) const;
    clock minus(int minutes) const;

    operator std::string() const;
    bool operator==(const clock& other) const;

private:
    explicit clock(int total_minutes);
    int total_minutes_;

    static int normalize(int minutes);
};

}  // namespace date_independent

#endif
