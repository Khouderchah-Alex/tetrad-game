#pragma once

#include "Base.h"
#include "Entity.h"
#include "ResourceManager.h"

/**
 * @brief Base class for all components
 */
class IComponent
{
public:
	virtual ~IComponent(){}

	/**
	 * @brief Method to refresh ptrs to other components
	 *
	 * In order to keep the entity system efficent, components will cache
	 * pointers to components they need. This method provides the entity
	 * manager with the ability to clear these cached pointers as needed
	 * and force components to use the EntityManager to re-acquire other
	 * component pointers.
	 */
	virtual void Refresh() = 0;

	/**
	 * @brief Shutdown method for component
	 *
	 * Called by the EntityManager right before the component is destroyed.
	 * Can be overridden in order to provide extra behavior before destruction.
	 */
	virtual void OnDestroy(){}

	/**
	 * @brief Method to get the Entity associated with this component
	 */
	Entity GetEntity() const{ return m_Entity; }

	/**
	 * @brief Method to retrieve the ID portion of the associated entity
	 *
	 * Only needed by the underlying entity system.
	 */
	ObjHandle::ID_t GetID() const{ return ((ObjHandle)m_Entity).GetID(); }

protected:
	IComponent(Entity entity) : m_Entity(entity){}

	friend void InitNullEntity(IComponent *pObj);

	Entity m_Entity;
};
