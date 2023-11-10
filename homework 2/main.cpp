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
#include "ATC.h"

using namespace std; //using standard library

int main() { //main function to make program compile and run
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
    
    for (int i = 0; i < 1000; i++) {
        aircraft1.operate(time_step);
        cout << aircraft1.getpos() << endl;
        
    }
    
    return 0; //returning dummy 0
}

