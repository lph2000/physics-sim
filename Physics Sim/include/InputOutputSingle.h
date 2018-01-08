#ifndef INPUTOUTPUTSINGLE_H
#define INPUTOUTPUTSINGLE_H
#include <MotionEquations.h>
#include <string>

using namespace std;

class InputOutputSingle {
    private:
        double s,u,v,a,t,temp;
        string sString,uString,vString,aString,tString;
        char unknownChoice;
        MotionEquations MEObject;
    public:
        InputOutputSingle();
        ~InputOutputSingle();
        string equationFinder(string sString,string uString,string vString,string aString,string tString);
        double distanceEquationDecider(char unknownChoice, double u,double v,double a,double t);
        double initvelEquationDecider(char unknownChoice, double s,double v,double a,double t);
        double finalvelEquationDecider(char unknownChoice, double s,double u,double a,double t);
        double accelEquationDecider(char unknownChoice, double s,double u,double v,double t);
        double timeEquationDecider(char unknownChoice, double s,double u,double v,double a);
};

#endif // INPUTOUTPUTSINGLE_H
