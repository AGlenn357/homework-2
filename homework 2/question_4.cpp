/*
Andrew Glenn
AERSP 424
Homework 2
Question 4: creating airliner and general aviation classes
*/

#include <iostream> //including input output library
#include <map> //including map library
#include <string> //including string library
#include <random> //including random library

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
    void operate (double dt) { //operate function
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
        }
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
    double distance_to_SCE(double distance, double pos, string destination) { //finding distance to State College
        if (destination == "SCE") {
            return distance-pos; //returning distance minus position
        }
        else { //in case condition is not met
            return -1; //returning dummy -1 if condition is not met
        }
    }
    virtual double time_on_ground() { //virtual function for time on the ground
        return 0; //dummy return value
    }
    virtual string plane_type(string x) { //virtual function for plane type
        string type = "GA"; //plane type
        return type; //returning plane type "GA"
    }
    static double draw_from_normal_distribution (double mean, double std) { //function to get random number with set mean and standard deviation
        random_device rd{}; //random device
        mt19937 gen { rd() }; //from homework assignment
        normal_distribution<> d{mean, std}; //getting normal distribution
        return d(gen); //returning answer
    }
};

class Airliner : public Plane {
private: //private members
    string Airline; //airline string
public: //public members
    Airliner(string airline, string from, string to) : Plane(from, to) {
        Airline = airline; //setting Airline variable to value
    }
    ~Airliner();
    double time_on_ground () {
        double mean = 600; //given mean value
        double std = 60; //given standard deviation
        double wait_time = draw_from_normal_distribution(mean, std); //gettin wait time
        return wait_time; //returning wait time
    }
};


int main() { //main function to make program compile and run
    return 0; //returning dummy 0
}
