/* 
 * File:   main.cpp
 * Author: Morgan
 *
 * Created on February 28, 2016, 1:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "FileAccess.h"
#include "Grid.h"
#define DELAY_TIME 2000000 

using namespace std;

/*
 * 
 */


/*
 Gets an integer to be used as the number of cells along an axis of the grid.
 */
int getInt(const string prompt){
    int input;
    
    while(true){
        cout << prompt << endl;
        cin >> input;
        //input is 0 when incorrect input is entered
        if(input>0){
            return input;
        }
        cout << "***Incorrect Input***" << endl;
        cin.clear();
        cin.ignore(80, '\n');
    }
}

/*
 Gets a decimal value that is the size of the individual cell sides.
 */
double getDouble(const string prompt){
    double input;
    
    while(true){
        cout << prompt << endl;
        cin >> input;
        //input is 0 when incorrect input is entered
        if(input>0.0){
            return input;
        }
        cout << "***Incorrect Input***" << endl;
        cin.clear();
        cin.ignore(80, '\n');
    }
}

//////////////////////USER INPUT FUNCTIONS ABOVE////////////////////////////////

int main(int argc, char** argv) {
    
    double cellSize = getDouble("Please enter a decimal number (in meters) for the size of the cell square sides: ");
    
    int xDim = getInt("Please enter the integer number of cells along the x-axis of the grid: ");
    int yDim = getInt("Please enter the integer number of cells along the y-axis of the grid: ");
    
    Grid grid(cellSize, xDim, yDim);
    
    //Display initial empty state
    grid.displayGridState();
    
    FileAccess fileAccess;
    
    while(!fileAccess.isEndOfFiles()){
        //delay for users to see updating grid
        usleep(DELAY_TIME);
        
        Robot * newRobot = fileAccess.readRobot();
        
        grid.update(newRobot);
        
        grid.displayGridState();
        
    }
    cout << "Program Finished!" << endl;
    
    return 0;
}