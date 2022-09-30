#include "SystemManager.h"
#include "ISystem.h"

void SystemManager::AddSystem(std::type_index componentType, std::unique_ptr<ISystemBase>&& pSystem)
{
	m_Systems.insert(std::pair<std::type_index, std::unique_ptr<ISystemBase>>(componentType, std::move(pSystem)));
}

void SystemManager::Update(std::unique_ptr<PoolManager>& pPoolManager)
{
	for (auto& pair : m_Systems)
	{
		pair.second->BaseExecute(pPoolManager);
	}
}

SystemManager::~SystemManager()
{
}
