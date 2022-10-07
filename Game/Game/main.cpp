#include "Engine.h"
#include "PoolManager.h"
#include "SystemManager.h"
#include "EntityGenerator.h"
#include "AddRandomSystem.h"
#include "DivideRandomSystem.h"
#include "Vector2Component.h"
#include "Vector3Component.h"

int main()
{
	Engine* pEngine = new Engine{};
	pEngine->Initialize();
	PoolManager& poolManager = pEngine->GetPoolManager();
	SystemManager& systemManager = pEngine->GetSystemManager();
	for (int i{}; i < 1; ++i)
	{
		int id = EntityGenerator::GenerateEntity();

		Vector2Component vec2{};
		poolManager.AddComponent(vec2, id);
		Vector3Component vec3{};
		poolManager.AddComponent(vec3, id);

	}

	systemManager.AddSystem(std::make_unique<AddRandomSystem>());
	systemManager.AddSystem(std::make_unique<DivideRandom>());
	pEngine->Run();
	
	return 0;
}