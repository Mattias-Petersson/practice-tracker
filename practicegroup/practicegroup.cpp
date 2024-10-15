#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "practicegroup.h"
#include "../practicesession/practicesession.h"

PracticeGroup::PracticeGroup(const S::string &name) : name{name} {};

void PracticeGroup::add_session(const PracticeSession &session)
{
    // TODO: Return something to indicate success/failure.
    sessions[session.date] = session;
}
size_t PracticeGroup::remove_session(const C::year_month_day date)
{
    return sessions.erase(date);
}
void PracticeGroup::print() const
{
    S::cout << "Group name: " << this->name << "\n\n";
    for (auto &session : sessions)
    {
        session.second.print();
        S::cout << "\n";
    }
}

void PracticeGroup::save_to_file() const
{
    S::ofstream file(name);
    if (file.is_open())
    {
    }
    else
    {
        S::cerr << "Error writing to file with filename " << name << "\n";
    }
}
