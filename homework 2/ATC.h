#pragma once
#include "Plane.h"
#include "Airliner.h"
#include "GeneralAviation.h"
#include <vector>

class ATC { //creating ATC class
private: //private members
    vector<int*> registered_planes; //container to store plane info
    unsigned int MAX_LANDED_PLANE_NUM = 2; //value given in assignment
    unsigned in AIRSPACE_DISTANCE = 50; //value given in assignment
public:
    ATC() {} //empty constructor
    ~ATC() {} //empty deconstructor
    void register_plane(Plane x) {
        registered_planes.push_back(&x);
    }
    void control_traffic() {
        int landed_planes = 0; //starting amount of landed planes
        int i = 0; //i is zero
        while (i < registered_planes.size()) {
            Plane x = *registered_planes[i];
            landed_planes += x.getat_SCE();
            i++;
        }
        if (landed_planes >= MAX_LANDED_PLANE_NUMBER) {
            i = 0;
            if (i < registered_planes.size()) {
                if (x.getat_SCE == 0 && distance_to_SCE(x.distance))
            }
        }
        
        
        
    }
}
