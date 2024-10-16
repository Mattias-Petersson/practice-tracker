#include <iostream>
#include <map>
#include "practicesession/practicesession.h"
#include "practicegroup/practicegroup.h"
#include "nlohmann/json.hpp"
#include "utils/namespaces.cpp"
#include <format>

int main(void)
{
  C::year_month_day date{C::year(2024), C::October, C::day(14)};
  C::seconds duration{3605};
  S::string notes{"Violin scales"};
  PracticeSession Session{date, duration, notes};

  C::year_month_day date2{C::year(2024), C::September, C::day(14)};

  PracticeGroup Group{"Violin"};
  Group.add_session(Session);
  Group.add_session(PracticeSession(C::year_month_day{C::year(2024), C::September, C::day(14)}, C::seconds{300}));
  Group.print();
  Group.save_to_file();
}