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