#pragma once
#include "psketch.h"

class Sketch : public PSketch
{
    public:
    Sketch();
    void setup();
    void draw();
    void keyEvent(int key, int action);
    void mouseButtonEvent(int button, int action);
    void cursorPosEvent(double xpos, double ypos);
    void scrollEvent(double xoffset, double yoffset);
};