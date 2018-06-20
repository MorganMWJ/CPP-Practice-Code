#include "Task.h"

Task::Task(std::string name, std::shared_ptr<Date> dueDate,
              std::string desc, bool done) :
    m_name(name),
    mp_dueDate(dueDate),
    m_desc(desc),
    m_done(done)
{
}

const std::string& Task::getName(void) const
{
    return m_name;
}

void Task::setName(const std::string& name)
{
    m_name = name;
}

const std::shared_ptr<Date> Task::getDueDate(void) const
{
    return mp_dueDate;
}

void Task::setDueDate(const std::shared_ptr<Date> dueDate)
{
    mp_dueDate = dueDate;
}

const std::string& Task::getDesc(void) const
{
    return m_desc;
}

void Task::setDesc(const std::string& desc)
{
    m_desc = desc;
}

bool Task::getDone(void) const
{
    return m_done;
}

void Task::setDone(bool done)
{
    m_done = done;
}

const std::string Task::toString(void) const
{
    std::stringstream ss;
    ss << "Task Name: ";
    ss << m_name;
    ss << "\nDue Date: ";
    ss << mp_dueDate->toString();
    ss << "\nTask Description: ";
    ss << m_desc;
    return ss.str();
}
