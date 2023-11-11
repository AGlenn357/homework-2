#include "Plane.h"
#include <random>
#include <iostream>

using namespace std;

Plane::Plane(string from, string to) { //Plane constructor
    origin = from; //orgin of plane
    destination = to; //destination of plane
    map<string, int> airport; //creating map airport
    airport.insert(pair<string,int>("SCE-ORD",640)); //inserting Chicago airport data
    airport.insert(pair<string,int>("SCE-PHL",160)); //inserting Philadelphia airport data
    airport.insert(pair<string,int>("SCE-EWR",220)); //inserting Newark airport data
    airport.insert(pair<string,int>("ORD-SCE",640)); //inserting Chicago airport data
    airport.insert(pair<string,int>("PHL-SCE",160)); //inserting Philadelphia airport data
    airport.insert(pair<string,int>("EWR-SCE",220)); //inserting Newark airport data
    distance = airport[from+"-"+to]; //distance of flight
    pos = 0; //initializing position to 0
    vel = 0; //initializing velocity to 0
    wait_time = 0; //initializing wait time to 0
    loiter_time = 0; //initializing loiter time to 0
    at_SCE = 0; //initializing at_SCE to 0
}

Plane::~Plane() {} //Plane deconstructor

void Plane::operate (double dt) {
    if (loiter_time != 0) { //if loiter time doesn't equal 0
        loiter_time -= dt; //changing loiter time value
    }
    else if (wait_time != 0) { //if wait time doesn't equal o
        wait_time -= dt; //changing wait time value
    }
    else if (pos < distance) { //if position is less than distance
        pos += vel*dt; //changind position value
        at_SCE = 0; //plane is not at State College
    }
    else {
        if (destination == "SCE") { //if destination in State College
            at_SCE = 1; //plane is at State College
        }
        time_on_ground(); //time on ground
        string temp = origin; //temporary variable set to origin
        origin = destination; //setting origin to destination
        destination = temp; //setting destination to old origin (temp);
        pos = 0; //resetting position to zero
    }
    if (wait_time < 0) {
        wait_time = 0;
    }
    if (loiter_time < 0) {
        loiter_time = 0;
    }
}

double Plane::distance_to_SCE(double distance, double pos, string destination) { //finding distance to State College
        if (destination == "SCE") {
            return distance-pos; //returning distance minus position
        }
        else { //in case condition is not met
            return -1; //returning dummy -1 if condition is not met
        }
}

string Plane::plane_type() { //plane type function
    return "GA"; //returning GA
}

double Plane::draw_from_normal_distribution(double mean, double std) { //function to get random number with set mean and standard deviation
    random_device rd{}; //random device
    mt19937 gen{rd()}; //from homework assignment
    normal_distribution<> d{mean, std}; //getting normal distribution
    return d(gen); //returning answer
}
