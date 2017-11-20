#include "MotionEquations.h"
#include <iostream>
#include <cmath>

using namespace std;

// Code for classes goes here

MotionEquations::MotionEquations(){
    // Distance
    float suvatS1(float u,float t,float a) {
        s = (u*t) + (a*(t*t))*0.5;
        return s;
    }
    float suvatS2(float u,float v,float t) {
        s = ((u+v) * t)*0.5;
        return s;
    }
    float suvatS3(float v,float t,float a) {
        s = (v*t) - (a*(t*t))*0.5;
        return s;
    }
    float suvatS4(float v,float u,float a) {
        s = ((v*v) - (u*u)) / (2*a);
        return s;
    }

    // Initial Velocity
    float suvatU1(float v,float a,float t) {
        u = v - (a*t);
        return u;
    }
    float suvatU2(float s,float t,float v) {
        u = 2*(s/t) - v;
        return u;
    }
    float suvatU3(float v,float a,float s) {
        u = sqrt((v*v) - (2*a*s));
        return u;
    }
    float suvatU4(float s,float a,float t) {
        u = (s/t) - (a*t)/2;
        return u;
    }

    // Final Velocity
    float suvatV1(float u,float a,float t) {
        v = u + (a*t);
        return v;
    }
    float suvatV2(float s,float t,float u) {
        v = 2*(s/t) - u;
        return v;
    }
    float suvatV3(float u,float a,float s) {
        v = sqrt((u*u) + (2*a*s));
        return v;
    }
    float suvatV4(float s,float a,float t) {
        v = (s/t) + (a*t)/2;
        return v;
    }

    // Acceleration
    float suvatA1(float v,float u,float t) {
        a = (v-u) / t;
        return a;
    }
    float suvatA2(float s,float u,float t) {
        a = 2*(s-(u*t)) / 2;
        return a;
    }
    float suvatA3(float v,float u,float s) {
        a = ((v*v) - (u*u)) / (2*s);
        return a;
    }
    float suvatA4(float s,float v,float t) {
        a = 2*(s+(v*t)) / 2;
        return a;
    }

    // Time
    float suvatT1(float v,float u,float a) {
        t = (v-u) / a;
        return t;
    }
    float suvatT2(float s,float u,float v) {
        t = (2*s) / (u+v);
        return t;
    }
    float suvatT3() {
        t = 0;
        return t;
    }
    float suvatT4() {
        t = 0;
        return t;
    }
}
