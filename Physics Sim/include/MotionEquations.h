#ifndef MOTIONEQUATIONS_H
#define MOTIONEQUATIONS_H

class MotionEquations {
    private:
        double s, u, v, a, t;

    public:
        MotionEquations();
        ~MotionEquations();

        // Distance
        double suvatS1(double u,double t,double a);
        double suvatS2(double u,double v,double t);
        double suvatS3(double v,double t,double a);
        double suvatS4(double v,double u,double a);

        // Initial Velocity
        double suvatU1(double v,double a,double t);
        double suvatU2(double s,double t,double v);
        double suvatU3(double v,double a,double s);
        double suvatU4(double s,double a,double t);

        // Final Velocity
        double suvatV1(double u,double a,double t);
        double suvatV2(double s,double t,double u);
        double suvatV3(double u,double a,double s);
        double suvatV4(double s,double a,double t);

        // Acceleration
        double suvatA1(double v,double u,double t);
        double suvatA2(double s,double u,double t);
        double suvatA3(double v,double u,double s);
        double suvatA4(double s,double v,double t);

        // Time
        double suvatT1(double v,double u,double a);
        double suvatT2(double s,double u,double v);
};

#endif // MOTIONEQUATIONS_H
