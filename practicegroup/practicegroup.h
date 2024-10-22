#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <map>
#include "../practicesession/practicesession.h"
#include "../utils/namespaces.h"

#ifndef PRACTICEGROUP
#define PRACTICEGROUP

class PracticeGroup
{
private:
    std::string name;
    std::map<C::year_month_day, PracticeSession> sessions;
    constexpr static std::string path = "data/";
    constexpr static std::string ext = ".json";
    json read_from_file() const;

public:
    PracticeGroup(const std::string &name);
    PracticeGroup(const json &data);
    void add_session(const PracticeSession &session);
    void remove_session(const C::year_month_day date);
    void print() const;
    std::string_view get_name() const;
    void save_to_file() const;
    std::filesystem::path get_path() const;
};

#endif