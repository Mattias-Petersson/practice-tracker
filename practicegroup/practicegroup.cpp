#include <iostream>
#include <fstream>
#include <vector>
#include "../practicesession/practicesession.h"
#include <chrono>
#include <map>
using namespace std::chrono;
class PracticeGroup
{
private:
    std::string name;
    std::map<year_month_day, PracticeSession> sessions;

public:
    PracticeGroup(const std::string &name) : name{name} {};

    void add_session(PracticeSession &session)
    {
        // TODO: Return the element that was input or an int showing that it was a success.
        sessions[session.date] = session;
    }
    size_t remove_session(const year_month_day date)
    {
        return sessions.erase(date);
    }
    void print() const
    {
        std::cout << "Group name: " << this->name;
        for (auto &session : sessions)
        {
            session.print();
        }
    }

    void save_to_file() const
    {
        std::ofstream file(name);
        if (file.is_open())
        {
        }
        else
        {
            std::cerr << "Error writing to file with filename " << name << "\n";
        }
    }
};