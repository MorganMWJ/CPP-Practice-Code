#include "Date.h"

Date::Date(unsigned int day,
           unsigned int month,
           unsigned int year):
    m_day(day),
    m_month(month),
    m_year(year)
{
}


unsigned int Date::getDay(void) const
{
    return m_day;
}

void Date::setDay(unsigned int val)
{
    m_day = val;
}

unsigned int Date::getMonth(void) const
{
    return m_month;
}

void Date::setMonth(unsigned int val)
{
    m_month = val;
}

unsigned int Date::getYear(void) const
{
    return m_year;
}

void Date::setYear(unsigned int val)
{
    m_year = val;
}

const std::string Date::toString(void) const
{
    std::stringstream result;
    result << m_day;
    result << "/";
    result << m_month;
    result << "/";
    result << m_year;
    return result.str();
}
