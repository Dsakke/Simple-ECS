#pragma once
class EntityGenerator final
{
public:
	static int GenerateEntity();
private:
	static int m_NextID;
};