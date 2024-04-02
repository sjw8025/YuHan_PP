// 과제물 프로젝트명 : Lecture04_HW
// idel : 화면색 검정색으로 클리어
// 마우스 오른쪽 KeyDown : 빨간색 O
// 마우스 오른쪽 keyUp : 원상복구 O
// 마우스 왼쪽 key Down : 녹색 O
// 마우스 왼쪽 key up: 원상복구 O
// 마우스 오른쪽 keyDown 드래그중이면 : 파랑색 X
// 마우스 왼쪽 keyDown 드래그중이면 : 마젠타 X

#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

bool rightButtonPressed = false;
bool leftButtonPressed = false;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error : " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            rightButtonPressed = true;
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // 빨강
        }
        else if (action == GLFW_RELEASE && !leftButtonPressed)
        {
            rightButtonPressed = false;
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 검정
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            leftButtonPressed = true;
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // 녹색
        }
        else if (action == GLFW_RELEASE && !rightButtonPressed)
        {
            leftButtonPressed = false;
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 검정
        }
    }
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (rightButtonPressed)
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 파랑
    }
    else if (leftButtonPressed)
    {
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 마젠타
    }
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

