#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <map>
#include "../practicesession/practicesession.h"
#include "../utils/namespaces.cpp"

#ifndef PRACTICEGROUP
#define PRACTICEGROUP

class PracticeGroup
{
private:
    S::string name;
    S::map<C::year_month_day, PracticeSession> sessions;
    constexpr static S::string path = "data/";
    constexpr static S::string ext = ".json";
    json read_from_file() const;

public:
    PracticeGroup(const S::string &name);
    PracticeGroup(const json &data);
    void add_session(const PracticeSession &session);
    void remove_session(const C::year_month_day date);
    void print() const;
    std::string_view get_name() const;
    void save_to_file() const;
    std::filesystem::path get_path() const;
};

#endif