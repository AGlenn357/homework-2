#pragma once
#include "Plane.h"
#include <string>

class Airliner : public Plane {
private: //private members
    string Airline; //airline string
public: //public members
    Airliner(string airline, string from, string to) : Plane(from, to) { //constructor
        Airline = airline; //setting Airline variable to value
    }
    ~Airliner() {} //deconstructor
    string plane_type() { //overridden function for plane type
        return Airline; //returning Airline
    }
    double time_on_ground () { //overridden function
        double mean = 1800; //given mean value
        double std = 600; //given standard deviation
        wait_time = draw_from_normal_distribution(mean, std); //gettin wait time
        return wait_time; //returning wait time
    }
};

