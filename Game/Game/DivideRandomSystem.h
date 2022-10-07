#pragma once
#include "ISystem.h"
#include "Vector3Component.h"
#include "Vector2Component.h"

class DivideRandom final : public ISystem<Vector3Component, Vector2Component>
{
public:

protected:
	void Execute(Vector3Component& vec3, Vector2Component& vec2) override;
};