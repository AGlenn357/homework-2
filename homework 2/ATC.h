#pragma once
#include "Plane.h"
#include "Airliner.h"
#include "GeneralAviation.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class ATC { //creating ATC class
private: //private members
    vector<Plane*> registered_planes; //container to store plane info
    unsigned int MAX_LANDED_PLANE_NUM = 2; //value given in assignment
    unsigned int AIRSPACE_DISTANCE = 50; //value given in assignment
public:
    ATC() {} //empty constructor
    ~ATC() {} //empty deconstructor
    void register_plane(Plane* x) {
        registered_planes.push_back(x);
    }
    void control_traffic() {
        int landed_planes = 0; //starting amount of landed planes
        int i = 0; //i is zero
        while (i < registered_planes.size()) {
            Plane x = *registered_planes[i];
            landed_planes += x.getat_SCE();
            i++;
        }
        if (landed_planes >= MAX_LANDED_PLANE_NUM) {
            i = 0;
            while (i < registered_planes.size()) {
                Plane x = *registered_planes[i];
                if (x.getat_SCE() == 0 && x.distance_to_SCE(x.getdistance(), x.getpos(), x.getdestination()) <= AIRSPACE_DISTANCE && x.getloiter_time() == 0) {
                    registered_planes[i]->setloiter_time(100);
                }
                else {
                    break;
                }
                i++;
            }
        }
    }
};
