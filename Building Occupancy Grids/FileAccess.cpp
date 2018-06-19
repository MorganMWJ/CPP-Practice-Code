#include "FileAccess.h"

const string FileAccess::posesFileName = "poses_data.txt";
const string FileAccess::rangesFileName = "ranges_data.txt";

FileAccess::FileAccess(){
    posesFile.open(posesFileName.c_str()); 
    rangesFile.open(rangesFileName.c_str());
}

FileAccess::~FileAccess(){
    posesFile.close();
    rangesFile.close();
}

bool FileAccess::isEndOfFiles(){
    return posesFile.eof() && rangesFile.eof();
}

Robot * FileAccess::readRobot(){
    double x;
    double y;
    int orientation;
    
    //read a line from poses 
    posesFile >> x >> y >> orientation;
    
    double ranges[8];
    //read a line from ranges
    rangesFile >> ranges[0] >> ranges[1] >> ranges[2] >> ranges[3] >> ranges[4] >> ranges[5] >> ranges[6] >> ranges[7];
    
    
    Robot * newRobot = new Robot(x, y, orientation, ranges);
    
    return newRobot;
}
