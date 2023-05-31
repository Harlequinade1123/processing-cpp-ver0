#include "sketch.h"

Sketch::Sketch() : PSketch()
{
    size(800, 800, P3D);
}

void Sketch::setup()
{
    stroke(255, 255, 255);
}

void Sketch::draw()
{
    background(200);
    /**
    fill(250);
    stroke(100, 100, 100);
    //strokeCap(SQUARE);
    //translate(WIDTH/2, HEIGHT/2);
    //rectMode(CENTER);
    //translate(200, 0);
    //rect(100,0,100,100);
    //ellipse(100, 500, 100, 100);
    //point(100, 10);
    point(10,10,100);
    stroke(0,255,0);
    line(10,50,0,MOUSEX,MOUSEY,100);
    stroke(20);
    line(10,50,MOUSEX,MOUSEY);
    **/
    strokeWeight(2);
    strokeCap(ROUND);
    stroke(20);
    line(0,0,MOUSEX,MOUSEY);
    line(0,0,0,MOUSEX,MOUSEY,100);
    point(150, 10,21);

    stroke(100);
    for (int i = -8; i <= 8; i++)
    {
        line(-400, 50 * i, 400, 50 * i);
        line(50 * i, -400, 50 * i, 400);
    }
    fill(255,0,0);
    stroke(10);
    rectMode(CENTER);
    //rect(0,0,100,100);
    translate(100,-100);
    rect(0,0,100,100);
    rotate(M_PI/6);
    box(100);

    for (int i = 0; i <= 360; i++)
    {
        point(100*cos(i * M_PI / 360), 100*sin(i * M_PI / 360));
    }
    //std::cout << MOUSEX << " " << MOUSEY << std::endl;
}

void Sketch::keyEvent(int key, int action)
{
    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_SPACE)
            std::cout << "Space Pressed" << std::endl;
        if (key == GLFW_KEY_LEFT)
            rotateCamera(M_PI / 36);
        if (key == GLFW_KEY_RIGHT)
            rotateCamera(-M_PI / 36);
    }
}

void Sketch::mouseButtonEvent(int button, int action)
{
    if (action == GLFW_PRESS)
    {
        std::cout << "Button Pressed" << std::endl;
    }
}

void Sketch::cursorPosEvent(double xpos, double ypos)
{
    if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        if (xpos < WIDTH/2)
        rotateCamera(M_PI / 36);
        if (xpos > WIDTH/2)
        rotateCamera(-M_PI / 36);
    }
}

void Sketch::scrollEvent(double xoffset, double yoffset)
{
    translateCamera(yoffset * 50, yoffset * 50);
}