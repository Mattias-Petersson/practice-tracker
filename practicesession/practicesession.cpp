#include "practicesession.h"

using namespace std::chrono;
PracticeSession::PracticeSession(const year_month_day &date, minutes &duration, const std::string &notes) : date(date), duration(duration), notes(notes) {}

void PracticeSession::print()
{
    std::cout << "Date: " << (int)date.year();
}
