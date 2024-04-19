#include "stdafx.h"
#include "MList.h"

float verticalMoveFactor = 0.0f;
float horizontalMoveFactor = 0.0f;
float scaleFactor = 1.0f;
bool rightButtonPressed = false;
bool leftButtonPressed = false;
double prevMouseX = 0.0;
double prevMouseY = 0.0;


void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}


void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		rightButtonPressed = true;
		glfwGetCursorPos(window, &prevMouseX, &prevMouseY);
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		rightButtonPressed = false;
	}

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		leftButtonPressed = true;
		glfwGetCursorPos(window, &prevMouseX, &prevMouseY);
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		leftButtonPressed = false;
	}
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{

	double deltaX = xpos - prevMouseX;
	double deltaY = ypos - prevMouseY;

	prevMouseX = xpos;
	prevMouseY = ypos;

	if (leftButtonPressed)
	{
		verticalMoveFactor -= deltaY / 500.0f;
		horizontalMoveFactor += deltaX / 500.0f;

	}

	if (rightButtonPressed)
	{


		scaleFactor += deltaX / 500.0f;



	}
}



int intiallize()
{
	MList<int> list:
	

	return 0;
}

int initallize()
{

	return 0;
}

int release()
{

	return 0;
}

int update()
{

	return 0;
}

//별 그리기
int render() //화면에 뭔가 그림
{
	glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	return 0;
}


int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetCursorPosCallback(window, cursorPositionCallback);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render();

		glfwSwapBuffers(window);
	}


	glfwTerminate();
	return 0;

}