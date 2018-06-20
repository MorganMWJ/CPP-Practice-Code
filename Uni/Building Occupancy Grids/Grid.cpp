#include "Grid.h"

Grid::Grid(double cellSize, int xDim, int yDim){
    Grid::cellSize = cellSize;
    Grid::xDim = xDim;
    Grid::yDim = yDim;
    Grid::isFirstUpdate = true;
    
    //get memory for grid on heap
    grid = new char*[xDim];
    for(int i = 0; i < xDim; ++i){
       grid[i] = new char[yDim]; 
    }
    
    //start grid with free space
    initialize();
    //Display initial empty state
    displayGridState();
}

void Grid::update(Robot * newRobot){
    //free up memory held by previous robot if there is a previous robot.
    if(!isFirstUpdate){
        delete robot;
    }
    else{
        isFirstUpdate = false;
    }
    //have robot now point at new robot memory
    robot = newRobot;
    
    //update cells from the new 8 sensors
    for(int i=0;i<Robot::NUM_OF_SENSORS;i++){
        //get x position of an obstacle
        int xPos = distanceToIndex(robot->getObsPos(i, 'X'));
        //get y position of an obstacle
        int yPos = distanceToIndex(robot->getObsPos(i, 'Y'));
        
        if(xPos != -1 && yPos != -1){
            grid[xPos][yPos] = OCCUPIED_SYBMOL;
        }
        //no obstacle(infinity) was read from this sensor
    }
}

void Grid::displayGridState(){ 
    for(int i=0;i<xDim;i++){
        cout << "-";
    }
    
    for(int y=yDim-1;y>=0;y--){
        for(int x=0;x<xDim;x++){
            cout << grid[x][y];
        }
        cout << endl;
    }
    
    displayGridProperties();
}

void Grid::displayGridProperties(){
    for(int i=0;i<xDim;i++){
        cout << "-";
    }
    cout << "\nGrid is " << xDim << " X " << yDim << " cells" << endl;
    cout << "Each Cell: ";
    cout << "("  << cellSize << "M x " << cellSize << "M)  ";
    cout << "Total Grid: ";
    cout << "("  << xDim*cellSize << "M x " << yDim*cellSize << "M)" << endl;
}

void Grid::initialize(){
    for(int y=0;y<yDim;y++){
        for(int x=0;x<xDim;x++){
            grid[x][y] = FREE_SYMBOL;
        }
    }
}

int Grid::distanceToIndex(double distance){
    if(distance < 0.0){
       return -1; 
    }
    
    //divide the distance(M) by the size of each cell(M)
    double indexDecimal = distance / cellSize;
    
    return floor(indexDecimal);
}