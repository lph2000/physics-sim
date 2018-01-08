#include "InputOutputSingle.h"
#include "MotionEquations.h"
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

InputOutputSingle::InputOutputSingle(void) {

}

InputOutputSingle::~InputOutputSingle(void) {

}

string InputOutputSingle::equationFinder(string s1, string u1, string v1, string a1, string t1) {
    string intChoice;
    string transfer;
    cout << endl << "Are you trying to find: ";
    if(s1 == "?" && v1 == "?") {
        cout << "1. Distance OR 2. Final Velocity?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "sv";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "vs";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(s1 == "?" && a1 == "?") {
        cout << "1. Distance OR 2. Acceleration?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "sa";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "as";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(s1 == "?" && u1 == "?") {
        cout << "1. Distance OR 2. Initial Velocity?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "su";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "us";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(s1 == "?" && t1 == "?") {
        cout << "1. Distance OR 2. Time?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "st";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "ts";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(u1 == "?" && a1 == "?") {
        cout << "1. Initial Velocity OR 2. Acceleration?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "ua";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "au";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(u1 == "?" && t1 == "?") {
        cout << "1. Initial Velocity OR 2. Time?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "ut";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "tu";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(u1 == "?" && v1 == "?") {
        cout << "1. Initial Velocity OR 2. Final Velocity?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "uv";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "vu";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(v1 == "?" && a1 == "?") {
        cout << "1. Final Velocity OR 2. Acceleration?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "va";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "av";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(v1 == "?" && t1 == "?") {
        cout << "1. Final Velocity OR 2. Time?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "vt";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "tv";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else if(a1 == "?" && t1 == "?") {
        cout << "1. Acceleration OR 2. Time?" << endl;
        cin >> intChoice;
        if(intChoice == "1") {
            transfer = "at";
            return transfer;
        } else if(intChoice == "2") {
            transfer = "ta";
            return transfer;
        } else {
            cout << "Invalid Choice";
        }
    } else {
        cout << "Unable to find a suitable formula to use." << endl;
    }

    return transfer;
}

double InputOutputSingle::distanceEquationDecider(char unknownChoice,double u,double v,double a,double t) {
    if(unknownChoice == 'v') {
        temp = MEObject.suvatS1(u,t,a);
        cout << "Distance: " << temp << "m";
    } else if(unknownChoice == 'a') {
        temp = MEObject.suvatS2(u,v,t);
        cout << "Distance: " << temp << "m";
    } else if(unknownChoice == 'u') {
        temp = MEObject.suvatS3(v,t,a);
        cout << "Distance: " << temp << "m";
    } else if(unknownChoice == 't') {
        temp = MEObject.suvatS4(v,u,a);
        cout << "Distance: " << temp << "m";
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}

double InputOutputSingle::initvelEquationDecider(char unknownChoice,double s,double v,double a,double t) {
    if(unknownChoice == 's') {
        temp = MEObject.suvatU1(v,a,t);
        cout << "Initial Velocity: " << temp << "ms-1";
    } else if(unknownChoice == 'a') {
        temp = MEObject.suvatU2(s,t,v);
        cout << "Initial Velocity: " << temp << "ms-1";
    } else if(unknownChoice == 't') {
        temp = MEObject.suvatU3(v,a,s);
        cout << "Initial Velocity: " << temp << "ms-1";
    } else if(unknownChoice == 'v') {
        temp = MEObject.suvatU4(s,a,t);
        cout << "Initial Velocity: " << temp << "ms-1";
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}

double InputOutputSingle::finalvelEquationDecider(char unknownChoice,double s,double u,double a,double t) {
    if(unknownChoice == 's') {
        temp = MEObject.suvatV1(u,a,t);
        cout << "Final Velocity: " << temp << "ms-1";
    } else if(unknownChoice == 'a') {
        temp = MEObject.suvatV2(s,t,u);
        cout << "Final Velocity: " << temp << "ms-1";
    } else if(unknownChoice == 't') {
        temp = MEObject.suvatV3(u,a,s);
        cout << "Final Velocity: " << temp << "ms-1";
    } else if(unknownChoice == 'u') {
        temp = MEObject.suvatV4(s,a,t);
        cout << "Final Velocity: " << temp << "ms-1";
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}

double InputOutputSingle::accelEquationDecider(char unknownChoice,double s,double u,double v,double t) {
    if(unknownChoice == 's') {
        temp = MEObject.suvatA1(v,u,t);
        cout << "Acceleration: " << temp << "ms-2";
    } else if(unknownChoice == 'v') {
        temp = MEObject.suvatA2(s,u,t);
        cout << "Acceleration: " << temp << "ms-2";
    } else if(unknownChoice == 't') {
        temp = MEObject.suvatA3(v,u,s);
        cout << "Acceleration: " << temp << "ms-2";
    } else if(unknownChoice == 'u') {
        temp = MEObject.suvatA4(s,v,t);
        cout << "Acceleration: " << temp << "ms-2";
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}

double InputOutputSingle::timeEquationDecider(char unknownChoice,double s,double u,double v,double a) {
    if(unknownChoice == 's') {
        temp = MEObject.suvatT1(v,u,a);
        cout << "Time: " << temp << "s";
    } else if(unknownChoice == 'a') {
        temp = MEObject.suvatT2(s,u,v);
        cout << "Time: " << temp << "s";
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}
