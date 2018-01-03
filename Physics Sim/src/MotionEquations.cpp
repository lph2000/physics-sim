#include "MotionEquations.h"
#include <iostream>
#include <cmath>

using namespace std;

MotionEquations::MotionEquations(void){
    cout << "Program Initialising" << endl;
}

MotionEquations::~MotionEquations(void){
    cout << endl << endl <<"Program Terminating" << endl;
}

// Distance
float MotionEquations::suvatS1(float u,float t,float a) {
    s = (u*t) + (a*(t*t))*0.5;
    return s;
}

float MotionEquations::suvatS2(float u,float v,float t) {
    s = ((u+v) * t)*0.5;
    return s;
}

float MotionEquations::suvatS3(float v,float t,float a) {
    s = (v*t) - (a*(t*t))*0.5;
    return s;
}

float MotionEquations::suvatS4(float v,float u,float a) {
    s = ((v*v) - (u*u)) / (2*a);
    return s;
}

// Initial Velocity
float MotionEquations::suvatU1(float v,float a,float t) {
    u = v - (a*t);
    return u;
}
float MotionEquations::suvatU2(float s,float t,float v) {
    u = 2*(s/t) - v;
    return u;
}
float MotionEquations::suvatU3(float v,float a,float s) {
    u = sqrt((v*v) - (2*a*s));
    return u;
}
float MotionEquations::suvatU4(float s,float a,float t) {
    u = (s/t) - (a*t)/2;
    return u;
}

// Final Velocity
float MotionEquations::suvatV1(float u,float a,float t) {
    v = u + (a*t);
    return v;
}

float MotionEquations::suvatV2(float s,float t,float u) {
    v = 2*(s/t) - u;
    return v;
}

float MotionEquations::suvatV3(float u,float a,float s) {
    v = sqrt((u*u) + (2*a*s));
    return v;
}

float MotionEquations::suvatV4(float s,float a,float t) {
    v = (s/t) + (a*t)/2;
    return v;
}

// Acceleration
float MotionEquations::suvatA1(float v,float u,float t) {
    a = (v-u) / t;
    return a;
}

float MotionEquations::suvatA2(float s,float u,float t) {
    a = 2*(s-(u*t)) / 2;
    return a;
}

float MotionEquations::suvatA3(float v,float u,float s) {
    a = ((v*v) - (u*u)) / (2*s);
    return a;
}

float MotionEquations::suvatA4(float s,float v,float t) {
    a = 2*(s+(v*t)) / 2;
    return a;
}

// Time
float MotionEquations::suvatT1(float v,float u,float a) {
    t = (v-u) / a;
    return t;
}

float MotionEquations::suvatT2(float s,float u,float v) {
    t = (2*s) / (u+v);
    return t;
}
