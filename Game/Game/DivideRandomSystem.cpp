#include "DivideRandomSystem.h"

void DivideRandom::Execute(Vector3Component& vec3, Vector2Component& vec2)
{
	vec3.x /= rand() + 1;
	vec3.y /= rand() + 1;
	vec3.z /= rand() + 1;
	vec2.x /= rand() + 1;
	vec2.y /= rand() + 1;
}
