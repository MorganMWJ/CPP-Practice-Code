#include "TaskList.h"
#include <iostream>
#include <string>
#include <regex>

TaskList::TaskList()
{
    //ctor
}

void TaskList::displayCompleteTasks(void) const
{
    bool nothingToDisplay = true;
    for(auto iter = taskList.begin(); iter!=taskList.end(); iter++)
    {
        if((*iter)->getDone())
        {
            std::cout << (*iter)->toString() << std::endl;
            nothingToDisplay = false;
        }
    }

    if(nothingToDisplay || taskList.empty())
    {
        std::cout << "CURRENTLY NO INCOMPLETE TASKS" << std::endl;
    }
}

void TaskList::displayIncompleteTasks(void) const
{
    bool nothingToDisplay = true;
    for(auto iter = taskList.begin(); iter!=taskList.end(); iter++)
    {
        if((*iter)->getDone() == false)
        {
            std::cout << (*iter)->toString() << std::endl;
            nothingToDisplay = false;
        }
    }

    if(nothingToDisplay || taskList.empty())
    {
        std::cout << "CURRENTLY NO INCOMPLETE TASKS" << std::endl;
    }
}

void TaskList::addTask(void)
{
    std::cin.ignore();

    std::string name;
    std::cout << "Enter the name of the task: " << std::endl;
    std::getline(std::cin, name);

    std::string desc;
    std::cout << "Enter the task description: " << std::endl;
    std::getline(std::cin, desc);

    std::shared_ptr<Date> date = readDate();

    taskList.push_back(std::shared_ptr<Task>(new Task(name,date,desc,false)));
}

std::shared_ptr<Date> TaskList::readDate(void)
{
    int d,m,y;
    std::regex dateExp("\\d{2}[/]\\d{2}[/]\\d{4}");
    while(true)
    {
        std::string date;
        std::cout << "Enter the due date of the task (dd/mm/yyyy): " << std::endl;
        std::getline(std::cin, date);

        //if regex matches
        if(std::regex_match(date,dateExp))
        {
            //break apart string and return date

            return std::shared_ptr<Date>(new Date(1,2,3));
        }
        else
        {
            std::cout << "Incorrect date input." << std::endl;
        }
    }

}
