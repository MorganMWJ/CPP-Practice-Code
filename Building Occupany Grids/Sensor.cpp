/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Sensor.h"

int Sensor::getDegree(){
    return degree;
}
    
double Sensor::getRange(){
    return range;
}

void Sensor::setDegree(int degree){
    this->degree=degree;
}

void Sensor::setRange(double range){
    this->range=range;
}

bool Sensor::hasInfiniteRange(){
    const double infinity = 2.5;
    
    return range >= infinity;
}