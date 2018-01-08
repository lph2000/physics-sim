#include <iostream>
#include <cmath>
#include <cstdlib> // Used for ::atof
#include <utility>
#include "MotionEquations.h"
#include "InputOutputSingle.h"
#include "InputOutputMutli.h"

using namespace std;

/** TO DO: Create two new .cpp/.h files to place the single/continuous sections in to tidy up main() **/

// Declaring variables, constants and additional functions
double s,u,v,a,t;
string sString,uString,vString,aString,tString;

// This function is used for converting strings to doubles, used at /**/
double stringToDouble(string number) {
    double temp = ::atof(number.c_str());
    return temp;
}

int main() {
    // Title
    cout << "Physics Sim" << endl << endl;

    // Having the user input the values for the equations/equation decider
    cout << "Please enter your known values below. \nIf you don't know a value, type '?'." << endl << endl;
    cout << "Distance: ";
    cin >> sString;
    cout << "Initial Velocity: ";
    cin >> uString;
    cout << "Final Velocity: ";
    cin >> vString;
    cout << "Acceleration: ";
    cin >> aString;
    cout << "Time: ";
    cin >> tString;

    // Converting the responses from a string to a double for use in equations
    s = stringToDouble(sString);
    u = stringToDouble(uString);
    v = stringToDouble(vString);
    a = stringToDouble(aString);
    t = stringToDouble(tString);

    // Having the user choose whether they want one result or a stream of it
    cout << endl << "Select an option: " << endl;
    cout << "1. Single Result \n" << "2. Data Stream \n" << endl;
    string choice;
    cin >> choice;

    // Section for single piece of data
    if(choice == "1") {
        InputOutputSingle IOSObject;

        // Finds which value is to be found
        string transfer = IOSObject.equationFinder(sString,uString,vString,aString,tString);
        char typeChoice = transfer[0];
        char unknownChoice = transfer[1];

        double temp;

        // Finds which formula to use to find the desired value, and returns an answer
        if(typeChoice == 's') {
            temp = IOSObject.distanceEquationDecider(unknownChoice,u,v,a,t);
        } else if(typeChoice == 'u') {
            temp = IOSObject.initvelEquationDecider(unknownChoice,s,v,a,t);
        } else if(typeChoice == 'v') {
            temp = IOSObject.finalvelEquationDecider(unknownChoice,s,u,a,t);
        } else if(typeChoice == 'a') {
            temp = IOSObject.accelEquationDecider(unknownChoice,s,u,v,t);
        } else if(typeChoice == 't') {
            temp = IOSObject.timeEquationDecider(unknownChoice,s,u,v,a);
        } else {
            cout << ":/ Congrats, you broke something you fuckwit";
        }
    }

    // Section for data stream
    else if(choice == "2") {
        InputOutputMutli IOMObject;

        string transfer = IOMObject.equationFinder(sString,uString,vString,aString,tString);
        char typeChoice = transfer[0];
        char unknownChoice = transfer[1];

        double temp;

        // Finds which formula to use to find the desired value, and returns an answer
        if(typeChoice == 's') {
            temp = IOMObject.distanceEquationDecider(unknownChoice,u,v,a,t);
        } else if(typeChoice == 'u') {
            temp = IOMObject.initvelEquationDecider(unknownChoice,s,v,a,t);
        } else if(typeChoice == 'v') {
            temp = IOMObject.finalvelEquationDecider(unknownChoice,s,u,a,t);
        } else if(typeChoice == 'a') {
            temp = IOMObject.accelEquationDecider(unknownChoice,s,u,v,t);
        } else if(typeChoice == 't') {
            temp = IOMObject.timeEquationDecider(unknownChoice,s,u,v,a);
        } else {
            cout << ":/ Congrats, you broke something you fuckwit";
        }
    } else {
        cout << "Invalid Choice you tit";
    }
}
