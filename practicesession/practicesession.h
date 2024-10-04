#include <chrono>
#include <iostream>

#ifndef PRACTICESESSION
#define PRACTICESESSION
class PracticeSession
{
public:
    std::chrono::year_month_day date;
    std::chrono::minutes duration;
    std::string notes;
    PracticeSession(const std::chrono::year_month_day &date, std::chrono::minutes &duration, const std::string &notes);
    void print();
};
#endif