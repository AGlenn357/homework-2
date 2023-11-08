/*
Andrew Glenn
AERSP 424
Homework 2
Question 2: creating plane class
*/

#include <iostream> //including input output library
#include <map> //including map library
#include <string> //including string library

using namespace std; //using standard library

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
    void operate (double dt) { //operate function
    }
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
    bool getat_SCE() { //getting State College condtion
        return at_SCE; //return whether plane is at State College
    }
    void setvel(double x) { //setting velocity
        vel = x; //velocity is input
    }
    void setloiter_time(double x) { //setting loiter time
        loiter_time = x; //loiter time is input
    }
    double distance_to_SCE(double x) { //finding distance to State College
        return x; //returning distance (will fill in function in later question)
    }
    virtual void time_on_ground() { //virtual function for time on the ground
    }
    virtual string plane_type(string x) { //virtual function for plane type
        return x; //returning plane type
    }
    static double draw_from_normal_distribution (double mean, double std) { //function to get random number with set mean and standard deviation
        return mean; //returning solution (will fill in function in later question)
    }
};

int main() { //main function to make program compile and run
    return 0; //returning dummy 0
}
