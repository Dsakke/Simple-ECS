#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
using ComponentType = std::type_index;

class IPool;

class PoolManager
{
public:
	PoolManager();
	void AddPool(ComponentType type, std::shared_ptr<IPool> pPool);
	std::shared_ptr<IPool> GetPool(ComponentType type);
private:
	std::unordered_map<ComponentType, std::shared_ptr<IPool>> m_Pools;
};