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

using namespace std; //using standard library

int main() { //main function to make program compile and run
    Airliner aircraft1("AA", "SCE", "PHL"); //instantiating aircraft 1
    Airliner aircraft2("UA", "SCE", "ORD"); //instantiating aircraft 2
    Airliner aircraft3("UA", "SCE", "EWR"); //instantiating aircraft 3
    Airliner aircraft4("AA", "SCE", "ORD"); //instantiating aircraft 4
    GeneralAviation aircraft5("SCE", "PHL"); //instantiating aircraft 5
    GeneralAviation aircraft6("SCE", "EWR"); //instantiating aircraft 6
    GeneralAviation aircraft7("SCE", "ORD"); //instantiating aircraft 7
    aircraft1.setvel(470); //aircraft 1 velocity
    aircraft2.setvel(515); //aircraft 2 velocity
    aircraft3.setvel(480); //aircraft 3 velocity
    aircraft4.setvel(500); //aircraft 4 velocity
    aircraft5.setvel(140); //aircraft 5 velocity
    aircraft6.setvel(160); //aircraft 6 velocity
    aircraft7.setvel(180); //aircraft 7 velocity

    return 0; //returning dummy 0
}

