/* 
 * File:   main.cpp
 * Author: Morgan
 *
 * Created on February 28, 2016, 1:56 PM
 */

#include <iostream>
#include <unistd.h>

#include "FileAccess.h"
#include "Grid.h"
#define DELAY_TIME 2000000

using namespace std;

/*
 Gets an integer to be used as the number of cells along an axis of the grid.
 * Takes a string message to print to the user asking for the desired input.
 * This method runs until a positive integer has been entered.
 */
int getInt(const string prompt){
    double input;
    
    while(true){
        cout << prompt << endl;
        cin >> input;
        //input is 0 when wrong type is entered
        //input cannot be less than zero
        //will never return if a decimal value is entered (with the exception of.0)
        if(input>0 && input == floor(input)){
            return input;
        }
        cin.clear();
        cin.ignore(80, '\n');
        cout << "***Incorrect Input***" << endl;
    }
}

/*
 Gets a decimal value that is the size of the individual cell sides.
 * Takes a string message to print to the user asking for the desired input.
 * This method runs until a positive decimal number has been entered.
 */
double getDouble(const string prompt){
    double input;
    
    while(true){
        cout << prompt << endl;
        cin >> input;
        //input is 0 when wrong type entered
        //input cannot be less than zero
        //also cannot be an integer i.e 6.0
        if(input>0.0 && (input != int(input))){
            return input;
        }
        cin.clear();
        cin.ignore(80, '\n');
        cout << "***Incorrect Input***" << endl;
    }
}

//////////////////////USER INPUT FUNCTIONS ABOVE////////////////////////////////

int main(int argc, char** argv) {
    
    double cellSize = getDouble("Please enter a decimal number (in meters) for the size of the cell square sides: ");
    
    int xDim = getInt("Please enter the integer number of cells along the x-axis of the grid: ");
    int yDim = getInt("Please enter the integer number of cells along the y-axis of the grid: ");
    
    Grid grid(cellSize, xDim, yDim);
    
    FileAccess fileAccess;
    
    while(!fileAccess.isEndOfFiles()){
        //delay for users to see updating grid
        usleep(DELAY_TIME);
        
        Robot * newRobot = fileAccess.readRobot();
        
        grid.update(newRobot);
        
        grid.displayGridState();
        
    }
    cout << "\n\t---Program Finished!---" << endl;
    
    return 0;
}