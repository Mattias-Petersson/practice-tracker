#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "practicegroup.h"
#include "../utils/namespaces.h"
#include "../practicesession/practicesession.h"

PracticeGroup::PracticeGroup(const std::string &name) : name{name} { this->save_to_file(); };
PracticeGroup::PracticeGroup(const json &data) : name{data["name"]}
{
    for (const auto &session : data["sessions"])
    {
        C::year_month_day date;
        std::istringstream stream(std::string{session["date"]});
        C::from_stream(stream, "%F", date);
        this->sessions.emplace(date, PracticeSession{date, C::seconds{session["duration"].get<int>()}, session["notes"]});
    }
    this->save_to_file();
};

void PracticeGroup::add_session(const PracticeSession &session)
{
    // TODO: Return something to indicate success/failure.
    sessions[session.date] = session;
    this->save_to_file();
}
void PracticeGroup::remove_session(const C::year_month_day date)
{
    auto to_remove = sessions.find(date);
    if (to_remove != sessions.end())
    {
        sessions.erase(to_remove);
        this->save_to_file();
    }
    else
    {
        throw std::invalid_argument("No such date to remove.");
    }
}
void PracticeGroup::print() const
{
    std::cout << "Group name: " << this->name << "\n\n";
    for (auto &session : sessions)
    {
        session.second.print();
        std::cout << "\n";
    }
}

std::string_view PracticeGroup::get_name() const
{
    return this->name;
}

std::filesystem::path PracticeGroup::get_path() const
{
    return path + name + ext;
}

void PracticeGroup::save_to_file() const
{
    json json_write = {{"name", name}, {"sessions", json::array()}};
    std::string full_path = get_path();
    std::ofstream file(full_path);
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
        std::cerr << "Error opening file with filename " << full_path << "\n";
    }
}
json PracticeGroup::read_from_file() const
{
    std::string full_path = get_path();
    std::ifstream f(full_path);
    return json::parse(f);
}
