#pragma once
#include "ISystem.h"
#include "Vector3Component.h"
#include "Vector2Component.h"

class AddRandomSystem final : public ISystem<Vector3Component, Vector2Component>
{
public:

protected:
	void Execute(Vector3Component& vector3, Vector2Component& Vector2) override;
};