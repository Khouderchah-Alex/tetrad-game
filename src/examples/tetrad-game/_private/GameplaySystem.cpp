#include "GameplaySystem.h"
#include "EntityManager.h"
#include "Game.h"

#include "ObstacleFactoryComponent.h"

GameplaySystem::GameplaySystem()
{
}

bool GameplaySystem::Initialize(Game *pGame)
{
	if(!ISystem::Initialize(pGame))
	{
		return false;
	}

	return true;
}

void GameplaySystem::Shutdown()
{
}

void GameplaySystem::Tick(deltaTime_t dt)
{
	if(m_pGame->GetCurrentState() == EGameState::STARTED)
	{
		// Update ObstacleFactoryComponent time
		LinkedNode<ObstacleFactoryComponent> *pNode;

		deltaTime_t timeLeft = -dt;
		while((pNode = ObstacleFactoryComponent::s_TimeList.Begin()))
		{
			ObstacleFactoryComponent *pComp =
				linked_node_owner(pNode,
								  ObstacleFactoryComponent,
								  m_Node);

			timeLeft = (pComp->m_TimeRemaining += timeLeft);
			if(timeLeft <= 0)
			{
				if(!pComp->GenerateObstacle())
				{
					LOG("ObstacleFactoryComponent failed to generate obstacle!\n");
				}
				pComp->Disable();
				pComp->Enable();
			}
			else
			{
				break;
			}
		}
	}
}