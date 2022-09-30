#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "Pool.h"
using ComponentType = std::type_index;



class PoolManager final
{
public:
	PoolManager();
	~PoolManager();
	void AddPool(ComponentType type, std::shared_ptr<IPool> pPool);
	template<class T>
	void AddComponent(T component, int entityId);
	std::shared_ptr<IPool> GetPool(ComponentType type);
private:
	std::unordered_map<ComponentType, std::shared_ptr<IPool>> m_Pools;
};

template<class T>
inline void PoolManager::AddComponent(T component, int entityId)
{
	if (!m_Pools.contains(ComponentType(typeid(component))))
	{
		AddPool(ComponentType(typeid(T)), std::make_shared<Pool<T>>());
	}
	std::shared_ptr<IPool> pPool = m_Pools.at(ComponentType(typeid(component)));

	if (!pPool)
	{
		return;
	}

	Pool<T>& typedPool = dynamic_cast<Pool<T>&>(*pPool);
	typedPool.AddComponent(component, entityId);

	
}
