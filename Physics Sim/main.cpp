#include <iostream>
#include <cmath>

using namespace std;

/** Declaring variables and constants **/

float s = 0, u = 0, v = 0, a = 0, t = 0;
float g = 9.807;

/** SUVAT equations **/

class MotionEquations {
    public:
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
        float suvatT3(float ,float ,float ) {
            t = 0;
            return t;
        }
        float suvatT4(float ,float ,float ) {
            t = 0;
            return t;
        }
};

int main() {
    MotionEquations MEObject;
    cout << "What value are you trying to find?" << endl;
    cout << "1. Distance \n" << "2. Initial Velocity \n" << "3. Final Velocity \n" << "4. Acceleration \n" << "5. Time" << endl << endl;
    string answer;
    cin >> answer;

    if(answer == "1") {
        cout << endl << "What values do you have?" << endl;
        cout << "1. Time, Initial Velocity, Acceleration \n" << "2. Time, Initial Velocity, Final Velocity \n" << "3. Time, Final Velocity, Acceleration \n" << "4. Initial Velocity, Final Velocity, Acceleration" << endl << endl;;
        string distanceCheck;
        cin >> distanceCheck;
        if(distanceCheck == "1") {
            cout << endl << "Value for Time: ";
            cin >> t;
            cout << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << endl << "Distance: " << MEObject.suvatS1(u,t,a) << " m";
        }
        else if(distanceCheck == "2") {
            cout << endl << "Value for Time: ";
            cin >> t;
            cout << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Final Velocity: ";
            cin >> v;
            cout << endl << "Distance: " << MEObject.suvatS2(u,v,t) << " m";
        }
        else if(distanceCheck == "3") {
            cout << endl << "Value for Time: ";
            cin >> t;
            cout << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << endl << "Distance: " << MEObject.suvatS3(v,t,a) << " m";
        }
        else if(distanceCheck == "4") {
            cout << endl << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << endl << "Distance: " << MEObject.suvatS4(v,u,a) << " m";
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }
    else if(answer == "2") {
        cout << endl << "What values do you have?" << endl;
        cout << "1. Final Velocity, Time, Acceleration \n" << "2. Final Velocity, Time, Distance \n" << "3. Final Velocity, Acceleration, Distance \n" << "4. Time, Acceleration, Distance" << endl << endl;;
        string initCheck;
        cin >> initCheck;
            if(initCheck == "1") {
            cout << endl << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Time: ";
            cin >> t;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << endl << "Initial Velocity: " << MEObject.suvatU1(v,a,t) << " ms^-1";
        }
        else if(initCheck == "2") {
            cout << endl << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Time: ";
            cin >> t;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Initial Velocity: " << MEObject.suvatU2(s,t,v) << " ms^-1";
        }
        else if(initCheck == "3") {
            cout << endl << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Initial Velocity: " << MEObject.suvatU3(v,a,s) << " ms^-1";
        }
        else if(initCheck == "4") {
            cout << endl << "Value for Time: ";
            cin >> t;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Initial Velocity: " << MEObject.suvatU4(s,a,t) << " ms^-1";
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }
    else if(answer == "3") {
        cout << endl << "What values do you have?" << endl;
        cout << "1. Initial Speed, Time, Acceleration \n" << "2. Initial Speed, Time, Distance \n" << "3. Initial Speed, Acceleration, Distance \n" << "4. Time, Acceleration, Distance" << endl << endl;;
        string finalCheck;
        cin >> finalCheck;
            if(finalCheck == "1") {
            cout << endl << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Time: ";
            cin >> t;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << endl << "Final Velocity: " << MEObject.suvatV1(u,a,t) << " ms^-1";
        }
        else if(finalCheck == "2") {
            cout << endl << "Value for Initial Velocity: ";
            cin >> v;
            cout << "Value for Time: ";
            cin >> t;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Final Velocity: " << MEObject.suvatV2(s,t,u) << " ms^-1";
        }
        else if(finalCheck == "3") {
            cout << endl << "Value for Initial Velocity: ";
            cin >> v;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Final Velocity: " << MEObject.suvatV3(u,a,s) << " ms^-1";
        }
        else if(finalCheck == "4") {
            cout << endl << "Value for Time: ";
            cin >> t;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Final Velocity: " << MEObject.suvatV4(s,a,t) << " ms^-1";
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }
    else if(answer == "4") {
        cout << endl << "What values do you have?" << endl;
        cout << "1. Time, Initial Speed, Final Velocity \n" << "2. Time, Initial Speed, Distance \n" << "3. Initial Speed, Final Speed, Distance \n" << "4. Time, Final Velocity, Distance" << endl << endl;;
        string accelCheck;
        cin >> accelCheck;
        if(accelCheck == "1") {
            cout << endl << "Value for Time: ";
            cin >> t;
            cout << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Final Velocity: ";
            cin >> v;
            cout << endl << "Acceleration: " << MEObject.suvatA1(v,u,t) << " ms^-2";
        }
        else if(accelCheck == "2") {
            cout << endl << "Value for Time: ";
            cin >> t;
            cout << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Acceleration: " << MEObject.suvatA2(s,u,t) << " ms^-2";
        }
        else if(accelCheck == "3") {
            cout << endl << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Acceleration: " << MEObject.suvatA3(v,u,s) << " ms^-2";
        }
        else if(accelCheck == "4") {
            cout << endl << "Value for Time: ";
            cin >> t;
            cout << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Acceleration: " << MEObject.suvatA4(s,v,t) << " ms^-2";
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }
    else if(answer == "5") {
        cout << endl << "What values do you have?" << endl;
        cout << "1. Initial Speed, Final Speed, Acceleration \n" << "2. Initial Speed, Final Speed, Distance \n" << "3.  \n" << "4. " << endl << endl;;
        string timeCheck;
        cin >> timeCheck;
        if(timeCheck == "1") {
            cout << endl << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Acceleration: ";
            cin >> a;
            cout << endl << "Time: " << MEObject.suvatT1(v,u,a) << " s";
        }
        else if(timeCheck == "2") {
            cout << endl << "Value for Initial Velocity: ";
            cin >> u;
            cout << "Value for Final Velocity: ";
            cin >> v;
            cout << "Value for Distance: ";
            cin >> s;
            cout << endl << "Time: " << MEObject.suvatT2(s,u,v) << " s";
        }
        else if(timeCheck == "3") {
            return 0;
        }
        else if(timeCheck == "4") {
            return 0;
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }
    else {
        cout << "Invalid Choice" << endl;
    }
}







