#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "Pool.h"




class PoolManager final
{
public:
	PoolManager();
	~PoolManager();
	void AddPool(std::type_index type, std::shared_ptr<IPool> pPool);
	template<class T>
	void AddComponent(T component, int entityId);
	std::shared_ptr<IPool> GetPool(std::type_index type);
private:
	std::unordered_map<std::type_index, std::shared_ptr<IPool>> m_Pools;
};

template<class T>
inline void PoolManager::AddComponent(T component, int entityId)
{
	std::type_index typeIndex = typeid(T);
	if (!m_Pools.contains(typeIndex))
	{
		AddPool(typeIndex, std::make_shared<Pool<T>>());
	}
	std::shared_ptr<IPool> pPool = m_Pools.at(typeIndex);

	if (!pPool)
	{
		return;
	}

	Pool<T>& typedPool = dynamic_cast<Pool<T>&>(*pPool);
	typedPool.AddComponent(component, entityId);
}
