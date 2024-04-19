//과제물
// 1. 이클래스 숙지하고 프로젝트를 생성하시오
// 2. #include <vector>    대신에 #include "MSList.h" 를 만드시오. (MSList.h, MSList.cpp)
//    ( Musoen(무소은엔진용) Struct(자료구조) List(리스트) )
//    ( vector는 절대 쓰지 마시오)
// 3. MSList 헤더파일 참조해서 cpp 만들것.
// 4. cpp파일에 함수 구현 내용을 작성하시오. ( ObjectTest처럼 )
// 
// 5. 게임에 5주차 과제였던 별을 손톱크기로 조그맣게 그릴 수 있도록 star.hpp의 크리스탈 수정.
// 6. 랜덤하게 화면에 위치와 색을 바꿔가며 별 300 개를 그릴 수 있도록 작성하시오.
//    (List에 모든 Star객체들을 담아주세요)
//    (화면에 알록달록한 별이 가득하게 random 이라는 stl을 사용해서 만들어주세요.)



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
		//랜덤 엔진
		std::mt19937 mt(rd());
		//균일 분산
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