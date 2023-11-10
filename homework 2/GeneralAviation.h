#pragma once
#include "Plane.h"
#include <string>

class GeneralAviation : public Plane {
public: //public members
    GeneralAviation(string from, string to) : Plane(from, to) { //constructor
    }
    ~GeneralAviation(); //deconstructor
    double time_on_ground () { //overridden function
        double mean = 600; //given mean value
        double std = 60; //given standard deviation
        double wait_time = draw_from_normal_distribution(mean, std); //gettin wait time
        return wait_time; //returning wait time
    }
};

