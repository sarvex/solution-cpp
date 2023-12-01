#include <functional>
#include <iostream>
#include <variant>

using std::bad_variant_access;
using std::function;
using std::get;
using std::holds_alternative;
using std::ostream;
using std::variant;

class Date {
public:
  int year;
  int month;
  int day;
};

class Period {
public:
  int days;
};

using AbsoluteOrRelativeDate = variant<Date, Period>;

template <typename T>
static T dispatch(const AbsoluteOrRelativeDate &date,
                  const function<T(Date)> &dateGetter,
                  const function<T(Period)> &periodGetter) {
  if (holds_alternative<Date>(date)) {
    return dateGetter(get<Date>(date));
  } else if (holds_alternative<Period>(date)) {
    return periodGetter(get<Period>(date));
  } else {
    throw bad_variant_access();
  }
}

ostream &operator<<(ostream &out, const AbsoluteOrRelativeDate &date) {
  return dispatch<ostream &>(
      date,
      [&](Date d) -> ostream & {
        return out << d.year << "-" << d.month << "-" << d.day;
      },
      [&](Period p) -> ostream & { return out << p.days << " days"; });
}
