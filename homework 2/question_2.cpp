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

class Plane {
protected:
    double wait_time;
private:
    double pos;
    double vel;
    double distance;
    double loiter_time;
    bool at_SCE;
    string origin;
    string destination;
    map <string,int> airport;
public:
    Plane(string from, string to);
    ~Plane();
    void operate (double dt) {
    }
    double getpos() {
        return pos;
    }
    double getvel() {
        return vel;
    }
    double getloiter_time() {
        return loiter_time;
    }
    string getorigin() {
        return origin;
    }
    string getdestination(){
        return destination;
    }
    bool getat_SCE() {
        return at_SCE;
    }
    void setvel(double x) {
        vel = x;
    }
    void setloiter_time(double x) {
        loiter_time = x;
    }
    double distance_to_SCE(double x) {
        return x;
    }
    virtual void time_on_ground() {
        
    }
    virtual string plane_type(string x) {
        return x;
    }
    static double draw_from_normal_distribution (double mean, double std) {
        return mean;
    }
};

int main() {
    return 0;
}
