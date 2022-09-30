#include "EntityGenerator.h"
int EntityGenerator::m_NextID{ 0 };


int EntityGenerator::GenerateEntity()
{
	return m_NextID++;
}
