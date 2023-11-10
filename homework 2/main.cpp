/*
Andrew Glenn
AERSP 424
Homework 2
main file
*/

#include <iostream> //including input output library
#include <map> //including map library
#include <string> //including string library
#include <random> //including random library
#include "Plane.h"
#include "Airliner.h"
#include "GeneralAviation.h"
#include <stdio.h>
#include "ATC.h"
#include "SDL.h"
#include "HW2_Visualizer.h"

using namespace std; //using standard library

int main(int argc, char** argv) { //main function to make program compile and run
    HW2_VIZ viz;
    Airliner aircraft1("AA", "SCE", "PHL"); //instantiating aircraft 1
    Airliner aircraft2("UA", "SCE", "ORD"); //instantiating aircraft 2
    Airliner aircraft3("UA", "SCE", "EWR"); //instantiating aircraft 3
    Airliner aircraft4("AA", "SCE", "ORD"); //instantiating aircraft 4
    GeneralAviation aircraft5("SCE", "PHL"); //instantiating aircraft 5
    GeneralAviation aircraft6("SCE", "EWR"); //instantiating aircraft 6
    GeneralAviation aircraft7("SCE", "ORD"); //instantiating aircraft 7
    
    double x = 3600;
    double conversion = 1/x;
    
    aircraft1.setvel(470*conversion); //aircraft 1 velocity
    aircraft2.setvel(515*conversion); //aircraft 2 velocity
    aircraft3.setvel(480*conversion); //aircraft 3 velocity
    aircraft4.setvel(500*conversion); //aircraft 4 velocity
    aircraft5.setvel(140*conversion); //aircraft 5 velocity
    aircraft6.setvel(160*conversion); //aircraft 6 velocity
    aircraft7.setvel(180*conversion); //aircraft 7 velocity
    
    double time_step = 10; //time step
    
    ATC atc;
    atc.register_plane(aircraft1);
    atc.register_plane(aircraft2);
    atc.register_plane(aircraft3);
    atc.register_plane(aircraft4);
    atc.register_plane(aircraft5);
    atc.register_plane(aircraft6);
    atc.register_plane(aircraft7);
    
    while (true) {
        aircraft1.operate(time_step);
        aircraft2.operate(time_step);
        aircraft3.operate(time_step);
        aircraft4.operate(time_step);
        aircraft5.operate(time_step);
        aircraft6.operate(time_step);
        aircraft7.operate(time_step);
        atc.control_traffic();
        viz.visualize_plane(aircraft1.plane_type(), aircraft1.getorigin(), aircraft1.getdestination(), aircraft1.getpos());
        viz.visualize_plane(aircraft2.plane_type(), aircraft2.getorigin(), aircraft2.getdestination(), aircraft2.getpos());
        viz.visualize_plane(aircraft3.plane_type(), aircraft3.getorigin(), aircraft3.getdestination(), aircraft3.getpos());
        viz.visualize_plane(aircraft4.plane_type(), aircraft4.getorigin(), aircraft4.getdestination(), aircraft4.getpos());
        viz.visualize_plane(aircraft5.plane_type(), aircraft5.getorigin(), aircraft5.getdestination(), aircraft5.getpos());
        viz.visualize_plane(aircraft6.plane_type(), aircraft6.getorigin(), aircraft6.getdestination(), aircraft6.getpos());
        viz.visualize_plane(aircraft7.plane_type(), aircraft7.getorigin(), aircraft7.getdestination(), aircraft7.getpos());
        cout << aircraft1.getpos() << ", " << aircraft2.getpos() << ", " << aircraft3.getpos() << ", " << aircraft4.getpos() << ", " << aircraft5.getpos() << ", " << aircraft6.getpos() << ", " << aircraft7.getpos() << endl;
        
        viz.update(time_step);
    }
    
    return 0; //returning dummy 0
}

