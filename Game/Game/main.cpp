#include "Engine.h"
#include "PoolManager.h"
#include "SystemManager.h"
#include "EntityGenerator.h"
#include "CounterComponent.h"
#include "CounterSystem.h"

int main()
{
	Engine* pEngine = new Engine{};
	pEngine->Initialize();
	PoolManager& poolManager = pEngine->GetPoolManager();
	SystemManager& systemManager = pEngine->GetSystemManager();
	for (int i{}; i < 10000; ++i)
	{
		CounterComponent counter{EntityGenerator::GenerateEntity()};
		poolManager.AddComponent(counter, counter.m_EntityID);
	}

	systemManager.AddSystem(std::type_index(typeid(CounterComponent)), std::make_unique<CounterSystem>());
	pEngine->Run();
	
	return 0;
}