#include "AddRandomSystem.h"

void AddRandomSystem::Execute(Vector3Component& vector3, Vector2Component& Vector2)
{
	vector3.x += rand();
	vector3.y += rand();
	vector3.z += rand();
	Vector2.x += rand();
	Vector2.y += rand();
}
