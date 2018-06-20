/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Robot.h"

Robot::Robot(double xPos, double yPos, int orientation, double * ranges){
    Robot::xPos=xPos;
    Robot::yPos=yPos;
    Robot::orientation=orientation;
    
    sensors = new Sensor[NUM_OF_SENSORS];
    for(int i=0, a=0;i<NUM_OF_SENSORS;i++, a+=45){
        sensors[i].setDegree(a);
        (sensors+i)->setRange(ranges[i]);
    }
    
}

double Robot::getObsPos(int sensor, char axis){
    if(sensors[sensor].hasInfiniteRange()){
        return -1.0;
    }
    
    //get range of obstacle
    double range = sensors[sensor].getRange();
    //get orientation of sensor and convert to radians
    double alpha = toRadians(sensors[sensor].getDegree());
    //get orientation of robot and convert to radians
    double beta = toRadians(orientation);
    
    if(axis == 'X'){
        return xPos + (range * cos(alpha + beta));    
    }
    else{
        return yPos + (range * sin(alpha + beta)); 
    }
}

double Robot::toRadians(int degrees){
    const int degreesInRadian = 180;
    return degrees * (M_PI/degreesInRadian);
}