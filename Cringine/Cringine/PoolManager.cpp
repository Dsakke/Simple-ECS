#include "PoolManager.h"
#include "Pool.h"
PoolManager::PoolManager()
{
}

void PoolManager::AddPool(ComponentType type, std::unique_ptr<IPool>&& pPool)
{
	m_Pools[type] = std::move(pPool);
}
