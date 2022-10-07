#include "SystemManager.h"
#include "ISystem.h"

void SystemManager::AddSystem(std::unique_ptr<ISystemBase>&& pSystem)
{
	m_Systems.push_back(std::move(pSystem));
}

void SystemManager::Update(std::unique_ptr<PoolManager>& pPoolManager)
{
	for (auto& pair : m_Systems)
	{
		pair->BaseExecute(pPoolManager);
	}
}

SystemManager::~SystemManager()
{
}
