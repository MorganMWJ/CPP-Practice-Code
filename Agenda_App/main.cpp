#include <iostream>
#include <memory>
#include <limits>
#include <regex>
#include "Date.h"
#include "Task.h"
#include "TaskList.h"

using namespace std;

void printMenu(void)
{
    cout << "Agenda App" << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Display Complete Tasks" << endl;
    cout << "2. Display Incomplete Tasks" << endl;
    cout << "3. Add New Task" << endl;
    cout << "4. Quit" << endl;

}

int userChoice(int limit)
{
	cout << "Action: ";
	int x = 0;
	while(!(cin >> x) || limit>4 || x<0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, Try again.\nAction: ";
	}
	return x;
}

int main()
{
    TaskList tl;

    while(true)
    {
        printMenu();

        cout << "*******************************" << endl;
        switch(userChoice(4))
        {
            case 1:
                tl.displayCompleteTasks();
                break;
            case 2:
                tl.displayIncompleteTasks();
                break;
            case 3:
                tl.addTask();
                break;
            case 4:
                return 0;
        }
        cout << "*******************************" << endl;
    }
}
