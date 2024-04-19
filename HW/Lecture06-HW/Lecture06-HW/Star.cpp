#include "Star.h"
#include "GLFW/glfw3.h"
#include "Vector2.h"

void Star::update()
{

}

void Star::render()
{
	const int starDrawSequence[3][3] =
	{
		{0, 3, 4},
		{0, 5, 3},
		{3, 2, 1}
	};

	const Vector2 starPoints[6] =
	{
		Vector2(0.f, .6f),
		Vector2(-.5f, .25f),
		Vector2(.5f, .25f),
		Vector2(0.f, -.25f),
		Vector2(-.4, -.5f),
		Vector2(.4f, -.5f)
	};

	glColor3f(r, g, b);
	for (int i = 0; i < 3; i++)
	{
		glBegin(GL_TRIANGLES);
		for (int j = 0; j < 3; j++)
		{
			Vector2 star = starPoints[starDrawSequence[i][j]];

			star._x = star._x * 0.1f;
			star._y = star._y * 0.1f;

			star = star + position;

			glVertex2d(star._x, star._y);
		}
		glEnd();

	}
}
