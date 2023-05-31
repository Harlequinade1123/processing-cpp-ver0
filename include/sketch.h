#pragma once
#include "psketch.h"

class Sketch : public PSketch
{
    private:
    float robot_x = 0.0;
    float robot_y = 0.0;
    float robot_yaw = 0.0;
    public:
    Sketch();
    void setup();
    void draw();
    void keyEvent(int key, int action);
    void mouseButtonEvent(int button, int action);
    void cursorPosEvent(double xpos, double ypos);
    void scrollEvent(double xoffset, double yoffset);
};