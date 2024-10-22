#include "practicesession.h"
#include "../utils/namespaces.h"

PracticeSession::PracticeSession() {};
PracticeSession::PracticeSession(const C::year_month_day &date, const C::seconds &duration, const std::string &notes) : date(date), duration(duration), notes(notes) {}

PracticeSession PracticeSession::create_from_input(std::istream &input)
{
    C::year_month_day date;
    std::string notes;
    std::invalid_argument err{"Test"};
    std::string test;
    std::cout << "Enter the date\n";
    if (!C::from_stream(getline(input, test), "%F", date))
    {
        throw err;
    }
    std::cout << "Duration of session (seconds)\n";
    int dur;
    if (!(input >> dur))
    {
        throw err;
    }
    C::seconds duration{dur};
    input.ignore();
    std::cout << "Notes for the session.\n";
    std::getline(input, notes);
    return PracticeSession(date, duration, notes);
}

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
