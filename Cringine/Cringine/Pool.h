#pragma once
#include <vector>
#define EMPTY -1 

class IPool
{
public:
	virtual ~IPool() = default;
};

template <class stdtype_index>
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
	void AddComponent(const stdtype_index& component, int entityId);
	stdtype_index* GetComponent(int entityId);
	std::vector<stdtype_index>& GetComponents();
	const std::vector<stdtype_index>& GetComponents() const;


private:
	std::vector<int> m_EnitityIndexes;
	std::vector<stdtype_index> m_Components;
};

template<class stdtype_index>
inline Pool<stdtype_index>::Pool()
	: m_EnitityIndexes{}
	, m_Components{}
{
}

template<class stdtype_index>
inline void Pool<stdtype_index>::AddComponent(const stdtype_index& component, int entityId)
{
	if (static_cast<int>(m_EnitityIndexes.size()) <= entityId)
	{
		m_EnitityIndexes.resize(entityId + 1, EMPTY);
	}

	m_Components.push_back(component);
	m_EnitityIndexes[entityId] = m_Components.size() - 1;
}

template<class stdtype_index>
inline stdtype_index* Pool<stdtype_index>::GetComponent(int entityId)
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

template<class stdtype_index>
inline std::vector<stdtype_index>& Pool<stdtype_index>::GetComponents()
{
	return m_Components;
}

template<class stdtype_index>
inline const std::vector<stdtype_index>& Pool<stdtype_index>::GetComponents() const
{
	return m_Components;
}

