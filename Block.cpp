#include "Block.h"
#include "Triangle.h"
#include "Engine.h"
#include "Matrix.h"

Block::Block(Vector _pos)
	: IObject(_pos)
{
}

Block::~Block()
{
}

void Block::Update()
{

}

void Block::Render()
{
	if ((Engine::instance->nowScene->cam->pos - pos).ScaleSq() <= pow(5000, 2))
	{
		Triangle* triangles[12] = {
			new Triangle(Vector(-50, -50, -70) + pos, Vector(50, -50, -70) + pos, Vector(-50, 50, -70) + pos, DarkGreen),
			new Triangle(Vector(50, 50, -70) + pos, Vector(50, -50, -70) + pos, Vector(-50, 50, -70) + pos, DarkGreen),
			new Triangle(Vector(-50, -50, 70) + pos, Vector(50, -50, 70) + pos, Vector(-50, 50, 70) + pos, DarkYellow),
			new Triangle(Vector(50, 50, 70) + pos, Vector(50, -50, 70) + pos, Vector(-50, 50, 70) + pos, DarkYellow),
			new Triangle(Vector(-50, -50, -70) + pos, Vector(50, -50, -70) + pos, Vector(-50, -50, 70) + pos, DarkRed),
			new Triangle(Vector(50, -50, 70) + pos, Vector(50, -50, -70) + pos, Vector(-50, -50, 70) + pos, DarkRed),
			new Triangle(Vector(50, -50, -70) + pos, Vector(50, -50, 70) + pos, Vector(50, 50, 70) + pos, DarkBlue),
			new Triangle(Vector(50, -50, -70) + pos, Vector(50, 50, -70) + pos, Vector(50, 50, 70) + pos, DarkBlue),
			new Triangle(Vector(50, 50, 70) + pos, Vector(-50, 50, 70) + pos, Vector(-50, 50, -70) + pos, Purple),
			new Triangle(Vector(50, 50, 70) + pos, Vector(50, 50, -70) + pos, Vector(-50, 50, -70) + pos, Purple),
			new Triangle(Vector(-50, -50, -70) + pos, Vector(-50, -50, 70) + pos, Vector(-50, 50, 70) + pos, Gray),
			new Triangle(Vector(-50, -50, -70) + pos, Vector(-50, 50, -70) + pos, Vector(-50, 50, 70) + pos, Gray)
		};
		for (int i = 0; i < 12; i++)
		{
			Matrix rotationMatrix = Matrix::GetRotationMatrix3Axis(Engine::instance->nowScene->cam->angle.x, Engine::instance->nowScene->cam->angle.y, Engine::instance->nowScene->cam->angle.z);
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