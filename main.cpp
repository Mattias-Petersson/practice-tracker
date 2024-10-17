#include <iostream>
#include <map>
#include "practicesession/practicesession.h"
#include "practicegroup/practicegroup.h"
#include "nlohmann/json.hpp"
#include "utils/namespaces.cpp"
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

std::map<std::string, PracticeGroup> get_groups()
{
  std::map<std::string, PracticeGroup> practice_groups;
  for (auto const &t : std::filesystem::directory_iterator("data/"))
  {
    std::filesystem::path path = t.path();
    std::string name = path.stem().string();
    std::ifstream f(path);
    json data = json::parse(f);
    practice_groups.emplace(name, PracticeGroup{data});
  }
  return practice_groups;
}

int main(void)
{

  std::map<std::string, PracticeGroup> practice_groups = get_groups();
  bool hasChanged = false;
  while (true)
  {
    std::cout << "1. Show all groups\n";
    std::cout << "2. View sessions in group\n";
    std::cout << "3. Create group\n";
    std::cout << "4. Exit\n";
    int selection;
    std::cin >> selection;

    switch (selection)
    {
    case 1:
    {
      for (auto const &group : practice_groups)
      {
        std::cout << group.first << "\n";
      }
      break;
    }
    case 2:
    {
      size_t len{practice_groups.size()};
      if (len == 0)
      {
        std::cout << "No groups to show, exiting\n";
        break;
      }
      else if (len == 1)
      {
        auto only_element = practice_groups.begin();
        std::cout << std::format("Only one group exists, showing group with name {}\n", only_element->first);
        only_element->second.print();
        break;
      }
      std::cout << "Enter the name of the group you want to view.\n";
      std::string groupName;
      std::cin >> groupName;
      if (practice_groups.contains(groupName))
      {
        practice_groups.find(groupName)->second.print();
      }
      else
      {
        std::cout << "A group with the name " << groupName << " does not exist.\n";
      }
      break;
    }
    case 3:
    {
      std::cout << "Enter the name of the new group.\n";
      while (true)
      {
        std::string groupName;
        std::cin >> groupName;
        if (practice_groups.contains(groupName))
        {
          std::cout << "Group with that name already exists, try again.\n";
        }
        else
        {
          PracticeGroup{groupName}.save_to_file();
          std::cout << std::format("Group named {} created\n", groupName);
          hasChanged = true;
          break;
        }
      }
      break;
    }
    default:
      return 0; // A number for exiting is given, but any input that's not valid will do.
    }
    if (hasChanged)
    {
      practice_groups = get_groups();
    }
  }
}
