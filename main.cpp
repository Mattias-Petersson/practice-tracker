#include <iostream>
#include "practicesession/practicesession.h"

int main(void)
{
    std::chrono::year_month_day date{std::chrono::year(2024), std::chrono::October, std::chrono::day(14)};
    std::chrono::minutes duration{60};
    std::string notes{"Violin scales"};
    PracticeSession session{{std::chrono::year(2024), std::chrono::October, std::chrono::day(14)}, duration, notes};
    session.print();
}