#include "MotionEquations.h"
#include <iostream>
#include <cmath>

using namespace std;

MotionEquations::MotionEquations(void){

}

MotionEquations::~MotionEquations(void){

}

// Distance
double MotionEquations::suvatS1(double u,double t,double a) {
    s = (u*t) + (a*(t*t))*0.5;
    return s;
}
double MotionEquations::suvatS2(double u,double v,double t) {
    s = ((u+v) * t)*0.5;
    return s;
}
double MotionEquations::suvatS3(double v,double t,double a) {
    s = (v*t) - (a*(t*t))*0.5;
    return s;
}
double MotionEquations::suvatS4(double v,double u,double a) {
    s = ((v*v) - (u*u)) / (2*a);
    return s;
}

// Initial Velocity
double MotionEquations::suvatU1(double v,double a,double t) {
    u = v - (a*t);
    return u;
}
double MotionEquations::suvatU2(double s,double t,double v) {
    u = 2*(s/t) - v;
    return u;
}
double MotionEquations::suvatU3(double v,double a,double s) {
    u = sqrt((v*v) - (2*a*s));
    return u;
}
double MotionEquations::suvatU4(double s,double a,double t) {
    u = (s/t) - (a*t)/2;
    return u;
}

// Final Velocity
double MotionEquations::suvatV1(double u,double a,double t) {
    v = u + (a*t);
    return v;
}
double MotionEquations::suvatV2(double s,double t,double u) {
    v = 2*(s/t) - u;
    return v;
}
double MotionEquations::suvatV3(double u,double a,double s) {
    v = sqrt((u*u) + (2*a*s));
    return v;
}
double MotionEquations::suvatV4(double s,double a,double t) {
    v = (s/t) + (a*t)/2;
    return v;
}

// Acceleration
double MotionEquations::suvatA1(double v,double u,double t) {
    a = (v-u) / t;
    return a;
}
double MotionEquations::suvatA2(double s,double u,double t) {
    a = 2*(s-(u*t)) / 2;
    return a;
}
double MotionEquations::suvatA3(double v,double u,double s) {
    a = ((v*v) - (u*u)) / (2*s);
    return a;
}
double MotionEquations::suvatA4(double s,double v,double t) {
    a = 2*(s+(v*t)) / 2;
    return a;
}

// Time
double MotionEquations::suvatT1(double v,double u,double a) {
    t = (v-u) / a;
    return t;
}
double MotionEquations::suvatT2(double s,double u,double v) {
    t = (2*s) / (u+v);
    return t;
}
