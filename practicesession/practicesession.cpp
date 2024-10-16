#include "practicesession.h"

PracticeSession::PracticeSession() {};
PracticeSession::PracticeSession(const C::year_month_day &date, const C::seconds &duration, const S::string &notes) : date(date), duration(duration), notes(notes) {}

void PracticeSession::print() const
{
    C::minutes minutes = C::duration_cast<C::minutes>(duration);
    C::seconds seconds = C::duration_cast<C::seconds>(duration - minutes);
    std::cout << std::format("Date: {:%Y-%m-%d}\n", date);
    std::cout << std::format("Duration: {:02} minutes, {:02} seconds\n", minutes.count(), seconds.count());
    std::cout << std::format("Notes: {}\n", notes);
}
json PracticeSession::to_json() const
{
    return json{
        {"date", std::format("{:%Y-%m-%d}", date)},
        {"duration", duration.count()},
        {"notes", notes}};
}
