#pragma once
#include <string>
#include <map>

using namespace std;

class Plane { //creating plane class
protected: //protected members
    double wait_time; //wait time variable
private: //private members
    double pos; //position variable
    double vel; //velocity variable
    double distance; //distance variable
    double loiter_time; //loiter time variable
    bool at_SCE; //whether place is at State College airport
    string origin; //starting point for plane
    string destination; //destination of plane
    map <string,int> airport; //map of airport code to distance from State College
public: //public members
    Plane(string from, string to); //constructor
    ~Plane(); //deconstructor
    void operate (double dt); //operate function
    double getpos() { //getting position function
        return pos; //return position from private section
    }
    double getvel() { //getting velocity function
        return vel; //return velocity from private section
    }
    double getloiter_time() { //getting loiter time
        return loiter_time; //return loiter time from private section
    }
    string getorigin() { //getting origin
        return origin; //return origin from private section
    }
    string getdestination(){ //getting destination
        return destination; //return destination from private section
    }
    double getdistance() {
        return distance;
    }
    bool getat_SCE() { //getting State College condtion
        return at_SCE; //return whether plane is at State College
    }
    void setvel(double x) { //setting velocity
        vel = x; //velocity is input
    }
    void setloiter_time(double x) { //setting loiter time
        loiter_time = x; //loiter time is input
    }
    double distance_to_SCE(double distance, double pos, string destination); //finding distance to State College
    virtual double time_on_ground() { //virtual function for time on the ground
        return 0; //dummy return value
    }
    virtual string plane_type(); //virtual function for plane type
    static double draw_from_normal_distribution (double mean, double std); //function to get random number with set mean and
};
