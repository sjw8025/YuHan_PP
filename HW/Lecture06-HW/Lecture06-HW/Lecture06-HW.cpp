//������
// 1. ��Ŭ���� �����ϰ� ������Ʈ�� �����Ͻÿ�
// 2. #include <vector>    ��ſ� #include "MSList.h" �� ����ÿ�. (MSList.h, MSList.cpp)
//    ( Musoen(������������) Struct(�ڷᱸ��) List(����Ʈ) )
//    ( vector�� ���� ���� ���ÿ�)
// 3. MSList ������� �����ؼ� cpp �����.
// 4. cpp���Ͽ� �Լ� ���� ������ �ۼ��Ͻÿ�. ( ObjectTestó�� )
// 
// 5. ���ӿ� 5���� �������� ���� ����ũ��� ���׸İ� �׸� �� �ֵ��� star.hpp�� ũ����Ż ����.
// 6. �����ϰ� ȭ�鿡 ��ġ�� ���� �ٲ㰡�� �� 300 ���� �׸� �� �ֵ��� �ۼ��Ͻÿ�.
//    (List�� ��� Star��ü���� ����ּ���)
//    (ȭ�鿡 �˷ϴ޷��� ���� �����ϰ� random �̶�� stl�� ����ؼ� ������ּ���.)



#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Star.h"


float moveFactor = 0.0f;
float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
	std::cerr << "\033[1;31mGLFW Error: " << description << "\033[0m" << std::endl;
}

LinkedList<Star*>* starList = new LinkedList<Star*>();

int initialize()
{
	for (int i = 0; i < 300; i++)
	{
		std::random_device rd;
		//���� ����
		std::mt19937 mt(rd());
		//���� �л�
		std::uniform_real_distribution<float> rand_real(-1, 1);
		Star* star = new Star();

		star->position = Vector2(rand_real(mt), rand_real(mt));

		star->r = abs(rand_real(mt));
		star->g = abs(rand_real(mt));
		star->b = abs(rand_real(mt));
		starList->push_back(star);
	}
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

int render()
{
	for (int i = 0; i < starList->get_size(); i++)
		(*starList)[i]->render();
	return 0;
}

int main(void)
{
	//glfw���̺귯�� �ʱ�ȭ
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);


	initialize();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render();
		glfwSwapBuffers(window);
	}

	release();

	glfwTerminate();
	return 0;

}