#include <chrono>
#include <iostream>
#include <map>
#include <ctime>
#include "../nlohmann/json.hpp"
#include "../utils/namespaces.cpp"
#ifndef PRACTICESESSION
#define PRACTICESESSION

class PracticeSession
{
public:
    C::year_month_day date;
    C::seconds duration;
    S::string notes;
    PracticeSession();
    PracticeSession(const C::year_month_day &date, const C::seconds &duration, const S::string &notes = "");
    static PracticeSession create_from_input(std::istream &input);
    json to_json() const;
    void print() const;
};
#endif