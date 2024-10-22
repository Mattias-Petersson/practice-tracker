#include <chrono>
#include <iostream>
#include <map>
#include <ctime>
#include "../nlohmann/json.hpp"
#include "../utils/namespaces.h"
#ifndef PRACTICESESSION
#define PRACTICESESSION

class PracticeSession
{
public:
    C::year_month_day date;
    C::seconds duration;
    std::string notes;
    PracticeSession();
    PracticeSession(const C::year_month_day &date, const C::seconds &duration, const std::string &notes = "");
    static PracticeSession create_from_input(std::istream &input);
    json to_json() const;
    void print() const;
};
#endif