#pragma once
#include <vector>
#define EMPTY -1 

class IPool
{
public:
	virtual ~IPool() = default;
};

template <class ComponentType>
class Pool final : public IPool
{
public:
#pragma region Deleted Functions
	Pool(Pool&&) = delete;
	Pool(const Pool&) = delete;
	Pool& operator=(Pool&&) = delete;
	Pool& operator=(const Pool&) = delete;
#pragma endregion

	Pool();
	void AddComponent(const ComponentType& component, int entityId);
	ComponentType* GetComponent(int entityId);
	std::vector<ComponentType>& GetComponents();
	const std::vector<ComponentType>& GetComponents() const;


private:
	std::vector<int> m_EnitityIndexes;
	std::vector<ComponentType> m_Components;
};

template<class ComponentType>
inline Pool<ComponentType>::Pool()
	: m_EnitityIndexes{}
	, m_Components{}
{
}

template<class ComponentType>
inline void Pool<ComponentType>::AddComponent(const ComponentType& component, int entityId)
{
	if (m_EnitityIndexes.size() < entityId)
	{
		m_EnitityIndexes.resize(entityId + 1, EMPTY);
	}

	m_Components.push_back(component);
	m_EnitityIndexes[entityId] = m_Components.size() - 1;
}

template<class ComponentType>
inline ComponentType* Pool<ComponentType>::GetComponent(int entityId)
{
	if (entityId >= m_EnitityIndexes.size())
	{
		return nullptr;
	}

	if (m_EnitityIndexes[entityId] == EMPTY)
	{
		return nullptr;
	}

	return m_Components[m_EnitityIndexes[entityId]];
}

template<class ComponentType>
inline std::vector<ComponentType>& Pool<ComponentType>::GetComponents()
{
	return m_Components;
}

template<class ComponentType>
inline const std::vector<ComponentType>& Pool<ComponentType>::GetComponents() const
{
	return m_Components;
}

