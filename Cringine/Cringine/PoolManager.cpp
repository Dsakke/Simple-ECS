#include "PoolManager.h"
#include "Pool.h"
PoolManager::PoolManager()
{
}

void PoolManager::AddPool(ComponentType type, std::shared_ptr<IPool> pPool)
{
	m_Pools[type] = pPool;
}

std::shared_ptr<IPool> PoolManager::GetPool(ComponentType type)
{
	if (m_Pools.contains(type))
	{
		return m_Pools[type];
	}
	return std::shared_ptr<IPool>();	
}
