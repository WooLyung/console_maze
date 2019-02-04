#include "Player.h"
#include "Triangle.h"
#include "Engine.h"
#include "Matrix.h"

Player::Player(Vector _pos)
	: IObject(_pos)
{
	rot = 0;
}

Player::~Player()
{
}

void Player::Update()
{
	if (Engine::instance->keyState['w'] == Enter || Engine::instance->keyState['w'] == Stay)
	{
		pos.x += Engine::instance->deltaTime * 80 * sin(Engine::instance->nowScene->cam->angle.z);
		pos.y += Engine::instance->deltaTime * 80 * cos(Engine::instance->nowScene->cam->angle.z);
	}
	if (Engine::instance->keyState['s'] == Enter || Engine::instance->keyState['s'] == Stay)
	{
		pos.x -= Engine::instance->deltaTime * 80 * sin(Engine::instance->nowScene->cam->angle.z);
		pos.y -= Engine::instance->deltaTime * 80 * cos(Engine::instance->nowScene->cam->angle.z);
	}
	if (Engine::instance->keyState['a'] == Enter || Engine::instance->keyState['a'] == Stay)
	{
		rot += Engine::instance->deltaTime * PI / 6;
	}
	if (Engine::instance->keyState['d'] == Enter || Engine::instance->keyState['d'] == Stay)
	{
		rot -= Engine::instance->deltaTime * PI / 6;
	}
}

void Player::Render()
{
	if ((Engine::instance->nowScene->cam->pos - pos).ScaleSq() <= pow(5000, 2))
	{
		Triangle* triangles[6] = {
			new Triangle(Vector(-20, -20, 70), Vector(20, -20, 70), Vector(-20, 20, 70), DarkGreen),
			new Triangle(Vector(20, 20, 70), Vector(20, -20, 70), Vector(-20, 20, 70), DarkGreen),
			new Triangle(Vector(20, 20, 70), Vector(20, -20, 70), Vector(0, 0, 20), DarkYellow),
			new Triangle(Vector(20, 20, 70), Vector(-20, 20, 70), Vector(0, 0, 20), DarkRed),
			new Triangle(Vector(-20, -20, 70), Vector(20, -20, 70), Vector(0, 0, 20), Purple),
			new Triangle(Vector(-20, -20, 70), Vector(-20, 20, 70), Vector(0, 0, 20), Gray),
		};
		for (int i = 0; i < 6; i++)
		{
			Matrix rotationMatrix = Matrix::GetRotationMatrix(Vector::GetAxisZ(), rot);
			triangles[i]->point1 = triangles[i]->point1 * rotationMatrix + pos;
			triangles[i]->point2 = triangles[i]->point2 * rotationMatrix + pos;
			triangles[i]->point3 = triangles[i]->point3 * rotationMatrix + pos;

			rotationMatrix = Matrix::GetRotationMatrix3Axis(Engine::instance->nowScene->cam->angle.x, Engine::instance->nowScene->cam->angle.y, Engine::instance->nowScene->cam->angle.z);
			triangles[i]->point1 = triangles[i]->point1 - Engine::instance->nowScene->cam->pos;
			triangles[i]->point1 = triangles[i]->point1 * rotationMatrix;
			triangles[i]->point2 = triangles[i]->point2 - Engine::instance->nowScene->cam->pos;
			triangles[i]->point2 = triangles[i]->point2 * rotationMatrix;
			triangles[i]->point3 = triangles[i]->point3 - Engine::instance->nowScene->cam->pos;
			triangles[i]->point3 = triangles[i]->point3 * rotationMatrix;
			Engine::PushPolygon(triangles[i]);
		}
	}
}