#ifndef MOTIONEQUATIONS_H
#define MOTIONEQUATIONS_H

class MotionEquations {
    private:
        float s, u, v, a, t;

    public:
        MotionEquations(): s(0), u(0), v(0), a(9.807), t(0){}

        // Distance
        float suvatS1(float u,float t,float a);
        float suvatS2(float u,float v,float t);
        float suvatS3(float v,float t,float a);
        float suvatS4(float v,float u,float a);

        // Initial Velocity
        float suvatU1(float v,float a,float t);
        float suvatU2(float s,float t,float v);
        float suvatU3(float v,float a,float s);
        float suvatU4(float s,float a,float t);

        // Final Velocity
        float suvatV1(float u,float a,float t);
        float suvatV2(float s,float t,float u);
        float suvatV3(float u,float a,float s);
        float suvatV4(float s,float a,float t);

        // Acceleration
        float suvatA1(float v,float u,float t);
        float suvatA2(float s,float u,float t);
        float suvatA3(float v,float u,float s);
        float suvatA4(float s,float v,float t);

        // Time
        float suvatT1(float v,float u,float a);
        float suvatT2(float s,float u,float v);
        float suvatT3();
        float suvatT4();
};

#endif // MOTIONEQUATIONS_H
