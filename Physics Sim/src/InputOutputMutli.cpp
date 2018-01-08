#include "InputOutputMutli.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

InputOutputMutli::InputOutputMutli(void){

}

InputOutputMutli::~InputOutputMutli(void){

}

string InputOutputMutli::equationFinder(string s1, string u1, string v1, string a1, string t1) {
    string intChoice;
    string transfer;

    cout << endl << endl << "Are you trying to find: ";
    if(s1 == "?" && v1 == "?") {
        cout << "1. Distance OR 2. Final Velocity?: ";
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
        cout << "1. Distance OR 2. Acceleration?: " << endl;
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
        cout << "1. Distance OR 2. Initial Velocity?: " << endl;
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
        cout << "1. Distance OR 2. Time?: " << endl;
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
        cout << "1. Initial Velocity OR 2. Acceleration?: " << endl;
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
        cout << "1. Initial Velocity OR 2. Time?: " << endl;
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
        cout << "1. Initial Velocity OR 2. Final Velocity?: " << endl;
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
        cout << "1. Final Velocity OR 2. Acceleration?: " << endl;
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
        cout << "1. Final Velocity OR 2. Time?: " << endl;
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
        cout << "1. Acceleration OR 2. Time?: " << endl;
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

double InputOutputMutli::distanceEquationDecider(char unknownChoice, double u,double v,double a,double t) {
    ofstream outputFile;
    outputFile.open("results.csv");
    outputFile << "Results Sheet\n\n";
    outputFile << "Distance,Initial Velocity,Final Velocity,Acceleration,Time\n";

    if(unknownChoice == 'v') {
        v = MEObject.suvatV1(u,a,t);
        cout << endl << "Distance per second: " << endl;
        for (double i=0;i<=t;++i) {
            double temp = MEObject.suvatS1(u,i,a);
            cout << i << ": " << temp << "m" << endl;
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'a') {
        a = MEObject.suvatA1(v,u,t);
        cout << endl << "Distance per second: " << endl;
        for (double i=0;i<=t;++i) {
            double temp = MEObject.suvatS2(u,v,i);
            cout << i << ": " << temp << "m" << endl;
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'u') {
        u = MEObject.suvatU1(v,a,t);
        cout << endl << "Distance per second: " << endl;
        for (double i=0;i<=t;++i) {
            double temp = MEObject.suvatS3(v,i,a);
            cout << i << ": " << temp << "m" << endl;
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 't') {
        t = MEObject.suvatT1(v,u,a);
        cout << endl << "Distance per second: " << endl;
        for (double i=0;i<=t;++i) {
            double temp = MEObject.suvatS4(v,u,a);
            cout << i << ": " << temp << "m" << endl;
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}

double InputOutputMutli::initvelEquationDecider(char unknownChoice, double s,double v,double a,double t) {
    ofstream outputFile;
    outputFile.open("results.csv");
    outputFile << "Results Sheet\n\n";
    outputFile << "Distance,Initial Velocity,Final Velocity,Acceleration,Time\n";

    if(unknownChoice == 's') {
        cout << endl << "Initial Velocity: " << MEObject.suvatU1(v,a,t) << "ms-1" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS3(v,i,a);
            double temp = MEObject.suvatU1(v,a,i);
            outputFile << s << "," << temp << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'v') {
        v = MEObject.suvatV4(s,a,t);
        cout << endl << "Initial Velocity: " << MEObject.suvatU4(s,a,t) << "ms-1" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS3(v,i,a);
            double temp = MEObject.suvatU4(s,a,i);
            outputFile << s << "," << temp << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'a') {
        a = MEObject.suvatA4(s,v,t);
        cout << endl << "Initial Velocity: " << MEObject.suvatU2(s,t,v) << "ms-1" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS3(v,i,a);
            double temp = MEObject.suvatU4(s,a,i);
            outputFile << s << "," << temp << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 't') {
        u = MEObject.suvatU3(v,a,s);
        t = MEObject.suvatT1(v,u,a);
        cout << endl << "Initial Velocity: " << MEObject.suvatU3(v,a,s) << "ms-1" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS3(v,i,a);
            double temp = MEObject.suvatU3(v,a,s);
            outputFile << s << "," << temp << "," << v << "," << a << "," << i << endl;
        }
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}

double InputOutputMutli::finalvelEquationDecider(char unknownChoice, double s,double u,double a,double t) {
    ofstream outputFile;
    outputFile.open("results.csv");
    outputFile << "Results Sheet\n\n";
    outputFile << "Distance,Initial Velocity,Final Velocity,Acceleration,Time\n";

    if(unknownChoice == 's') {
        s = MEObject.suvatS1(u,t,a);
        cout << endl << "Final Velocity: " << MEObject.suvatV1(u,a,t) << "ms-1" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS1(u,i,a);
            double temp = MEObject.suvatV1(v,a,i);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'u') {
        u = MEObject.suvatU4(s,a,t);
        cout << endl << "Final Velocity: " << MEObject.suvatU4(s,a,t) << "ms-1" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS1(u,i,a);
            double temp = MEObject.suvatU4(s,a,i);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'a') {
        a = MEObject.suvatA2(s,u,t);
        cout << endl << "Final Velocity: " << MEObject.suvatU4(s,a,t) << "ms-1" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS1(u,i,a);
            double temp = MEObject.suvatU4(s,a,i);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 't') {
        v = MEObject.suvatV3(u,a,s);
        t = MEObject.suvatT1(v,u,a);
        cout << endl << "Final Velocity: " << MEObject.suvatU3(v,a,s) << "ms-1" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS1(u,i,a);
            double temp = MEObject.suvatU3(v,a,s);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}

double InputOutputMutli::accelEquationDecider(char unknownChoice, double s,double u,double v,double t) {
    ofstream outputFile;
    outputFile.open("results.csv");
    outputFile << "Results Sheet\n\n";
    outputFile << "Distance,Initial Velocity,Final Velocity,Acceleration,Time\n";

    if(unknownChoice == 's') {
        s = MEObject.suvatS2(u,v,t);
        cout << endl << "Acceleration: " << MEObject.suvatA1(v,u,t) << "ms-2" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS2(u,v,i);
            double temp = MEObject.suvatA1(v,u,i);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'u') {
        u = MEObject.suvatU2(s,t,v);
        cout << endl << "Acceleration: " << MEObject.suvatA4(s,v,t) << "ms-2" << endl;
        for (float i=0;i<=t;++i) {
            s = MEObject.suvatS2(u,v,i);
            float temp = MEObject.suvatA4(s,v,i);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'v') {
        v = MEObject.suvatV2(s,t,u);
        cout << endl << "Acceleration: " << MEObject.suvatA2(s,u,t) << "ms-2" << endl;
        for (float i=0;i<=t;++i) {
            s = MEObject.suvatS2(u,v,i);
            float temp = MEObject.suvatA2(s,u,i);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 't') {
        t = MEObject.suvatT2(s,u,v);
        cout << endl << "Acceleration: " << MEObject.suvatA3(v,u,s) << "ms-2" << endl;
        for (float i=0;i<=t;++i) {
            s = MEObject.suvatS2(u,v,i);
            float temp = MEObject.suvatA3(v,u,s);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}

double InputOutputMutli::timeEquationDecider(char unknownChoice, double s,double u,double v,double a) {
    ofstream outputFile;
    outputFile.open("results.csv");
    outputFile << "Results Sheet\n\n";
    outputFile << "Distance,Initial Velocity,Final Velocity,Acceleration,Time\n";

    if(unknownChoice == 's') {
        s = MEObject.suvatS4(v,u,a);
        t = MEObject.suvatT1(v,u,a);
        cout << endl << "Time: " << MEObject.suvatT1(v,u,a) << "ms-2" << endl;
        for (double i=0;i<=t;++i) {
            s = MEObject.suvatS2(u,v,i);
            double temp = MEObject.suvatT1(v,u,a);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else if(unknownChoice == 'a') {
        a = MEObject.suvatA3(v,u,s);
        t = MEObject.suvatT2(s,u,v);
        cout << endl << "Time: " << MEObject.suvatT2(s,u,v) << "ms-2" << endl;
        for (float i=0;i<=t;++i) {
            s = MEObject.suvatS2(u,v,i);
            float temp = MEObject.suvatT1(v,u,a);
            outputFile << temp << "," << u << "," << v << "," << a << "," << i << endl;
        }
    } else {
        cout << "Something is look ver broke, yes?";
    }
    return temp;
}
