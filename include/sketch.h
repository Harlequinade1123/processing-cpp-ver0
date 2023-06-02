#pragma once
#include "psketch.h"

class Sketch : public PSketch
{
    private:
    float robot_x = 0.0;
    float robot_y = 0.0;
    float robot_yaw = 0.0;
    
    float robot_vx = 0.0;
    float robot_vy = 0.0;
    float robot_w  = 0.0;

    float robot_tread  = 270;
    float robot_depth  = 250;
    float robot_height = 200;
    float wheel_radius = 50;
    float wheel_width  = 20;

    float old_MOUSEX = 0;
    float old_MOUSEY = 0;

    float camera_angle    =   0.0;
    float camera_distance = 600.0;
    float camera_height   = 250.0;

    public:
    Sketch();
    void setup();
    void draw();
    void drawRobot();
    void keyEvent(int key, int action);
    void mouseButtonEvent(int button, int action);
    void cursorPosEvent(double xpos, double ypos);
    void scrollEvent(double xoffset, double yoffset);
    void parallelTask1();
};