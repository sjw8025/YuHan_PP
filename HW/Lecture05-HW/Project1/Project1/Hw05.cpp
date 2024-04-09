
#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>

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

//별 그리기
int render() //화면에 뭔가 그림
{
	//삼각형을 그림
	glBegin(GL_TRIANGLES);
	//흰색
	glColor3f(1.0f, 1.0f, 1.0f);
	//2d 는 double 2f 는 float
	glVertex2f((0.5f + horizontalMoveFactor) * scaleFactor, (0.3f + verticalMoveFactor) * scaleFactor);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f((-0.5f + horizontalMoveFactor) * scaleFactor, (0.3f + verticalMoveFactor) * scaleFactor);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f((0.0f + horizontalMoveFactor) * scaleFactor, (-0.2f + verticalMoveFactor) * scaleFactor);
	glEnd();

	//삼각형을 그림
	glBegin(GL_TRIANGLES);
	//흰색
	glColor3f(1.0f, 1.0f, 1.0f);
	//2d 는 double 2f 는 float
	glVertex2f((0.0f + horizontalMoveFactor) * scaleFactor, (0.7f + verticalMoveFactor) * scaleFactor);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f((0.2f + horizontalMoveFactor) * scaleFactor, (-0.1f + verticalMoveFactor) * scaleFactor);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f((-0.4f + horizontalMoveFactor) * scaleFactor, (-0.5f + verticalMoveFactor) * scaleFactor);

	glEnd();

	//삼각형을 그림
	glBegin(GL_TRIANGLES);
	//흰색
	glColor3f(1.0f, 1.0f, 1.0f);
	//2d 는 double 2f 는 float
	glVertex2f((0.0f + horizontalMoveFactor) * scaleFactor, (0.7f + verticalMoveFactor) * scaleFactor);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f((0.4f + horizontalMoveFactor) * scaleFactor, (-0.5f + verticalMoveFactor) * scaleFactor);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f((-0.2f + horizontalMoveFactor) * scaleFactor, (-0.1f + verticalMoveFactor) * scaleFactor);

	glEnd();

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
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}