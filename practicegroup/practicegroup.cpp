#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "practicegroup.h"
#include "../practicesession/practicesession.h"

PracticeGroup::PracticeGroup(const S::string &name) : name{name} {};
PracticeGroup::PracticeGroup(const json &data) : name{data["name"]}
{
    for (const auto &session : data["sessions"])
    {
        C::year_month_day date;
        std::istringstream stream(S::string{session["date"]});
        C::from_stream(stream, "%F", date);
        this->sessions.emplace(date, PracticeSession{date, C::seconds{session["duration"].get<int>()}, session["notes"]});
    }
};

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
    json json_write = {{"name", name}, {"sessions", json::array()}};
    std::string full_path = path + name + ext;
    S::ofstream file(full_path);
    if (file.is_open())
    {
        for (auto &session : sessions)
        {
            json_write["sessions"].push_back(session.second.to_json());
        }
        file << json_write.dump(4);
    }
    else
    {
        S::cerr << "Error opening file with filename " << full_path << "\n";
    }
}
json PracticeGroup::read_from_file() const
{
    std::string full_path = path + name + ext;
    std::ifstream f(full_path);
    return json::parse(f);
}
