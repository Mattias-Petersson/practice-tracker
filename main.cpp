#include <iostream>
#include <map>
#include "practicesession/practicesession.h"
#include "practicegroup/practicegroup.h"
#include "nlohmann/json.hpp"
#include "utils/namespaces.cpp"
#include "cliversion.cpp"
#include <format>

/**
 * Test function to make some sample data. Will overwrite any existing data.
 */
void make_data()
{
  C::year_month_day date{C::year(2024), C::October, C::day(14)};
  C::seconds duration{3605};
  S::string notes{"Violin scales"};
  PracticeSession Session{date, duration, notes};

  PracticeGroup Group{std::string{"Violin"}};
  Group.add_session(Session);
  Group.add_session(PracticeSession(C::year_month_day{C::year(2024), C::September, C::day(14)}, C::seconds{301}));
  Group.save_to_file();
}

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    std::string arg{argv[1]};
    if (arg == "--cli-mode")
      return cli_version();
  }
  std::cout << "No argument.";
}
