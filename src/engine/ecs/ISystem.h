#pragma once

#include "IComponent.h"
#include "ComponentManager.h"

#include <cstddef>

/**
 * @brief Interface for all systems
 */
class ISystem
{
public:
	ISystem() : m_pGame(nullptr){}
	virtual ~ISystem(){};
	virtual bool Initialize(Game *pGame){ m_pGame = pGame; return true; }
	virtual void Shutdown() = 0;

	virtual void Tick(deltaTime_t dt) = 0;

protected:
	Game *m_pGame;
};

