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
    strokeWeight(1.5);
    stroke(100);
    strokeCap(ROUND);
    for (int i = -8; i <= 8; i++)
    {
        line(-400, 50 * i, 400, 50 * i);
        line(50 * i, -400, 50 * i, 400);
    }
    
    float robot_size   = 100;
    float wheel_radius = 20;
    float wheel_width  = 10;
    stroke(50);
    translate(this->robot_x, this->robot_y, robot_size / 4 + wheel_radius);
    rotateZ(this->robot_yaw);
    fill(150);
    box(robot_size, robot_size, robot_size / 2);
    fill(100);
    pushMatrix();
    translate(robot_size / 2, wheel_width / 2 + robot_size / 2,-robot_size / 4);
    rotateX(M_PI_2);
    cylinder(wheel_radius, wheel_width);
    popMatrix();
    pushMatrix();
    translate(robot_size / 2,-wheel_width / 2 - robot_size / 2,-robot_size / 4);
    rotateX(M_PI_2);
    cylinder(wheel_radius, wheel_width);
    popMatrix();
    pushMatrix();
    translate(-robot_size / 2, wheel_width / 2 + robot_size / 2,-robot_size / 4);
    rotateX(M_PI_2);
    cylinder(wheel_radius, wheel_width);
    popMatrix();
    pushMatrix();
    translate(-robot_size / 2,-wheel_width / 2 - robot_size / 2,-robot_size / 4);
    rotateX(M_PI_2);
    cylinder(wheel_radius, wheel_width);
    popMatrix();

}

void Sketch::keyEvent(int key, int action)
{
    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_SPACE)
            std::cout << "Space Pressed" << std::endl;
        if (key == GLFW_KEY_W)
            robot_x += 10.0;
            //rotateCamera(M_PI / 36);
        if (key == GLFW_KEY_S)
            robot_x -= 20.0;
        if (key == GLFW_KEY_A)
            robot_y += 20.0;
        if (key == GLFW_KEY_D)
            robot_y -= 20.0;
        if (key == GLFW_KEY_E)
            robot_yaw -= M_PI / 18.0;
        if (key == GLFW_KEY_Q)
            robot_yaw += M_PI / 18.0;
        if (key == GLFW_KEY_RIGHT)
            rotateCamera(M_PI / 18);
        if (key == GLFW_KEY_LEFT)
            rotateCamera(-M_PI / 18);
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