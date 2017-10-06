#include "DrawComponent.h"
#include "EntityManager.h"
#include "TransformComponent.h"
#include "MaterialComponent.h"

using glm::vec4; using glm::vec3; using glm::vec2;

DrawComponent::DrawComponent(Entity entity) :
	IComponent(entity), m_pTransformComp(nullptr),
	m_VBO(0), m_IBO(0), m_Tex(0), m_IndexCount(0)
{
}

DrawComponent::~DrawComponent()
{
}

void DrawComponent::SetGeometry(ShapeType shape)
{
	auto model = ResourceManager::LoadShape(shape);
	m_VBO = model.m_VBO;
	m_IBO = model.m_IBO;
	m_IndexCount = model.m_IndexCount;
}

void DrawComponent::SetGeometry(std::string path)
{
	auto model = ResourceManager::LoadModel(path);
	m_VBO = model.m_VBO;
	m_IBO = model.m_IBO;
	m_IndexCount = model.m_IndexCount;
}

void DrawComponent::SetTexture(std::string texture, TextureType type)
{
	m_Tex = ResourceManager::LoadTexture(texture, type);
}

const vec4 &DrawComponent::GetAddColor() const
{
	return m_pMaterialComp->m_AddColor;
}

const vec4 &DrawComponent::GetMultColor() const
{
	return m_pMaterialComp->m_MultColor;
}

float DrawComponent::GetTime() const
{
	return m_pMaterialComp->m_Time;
}

void DrawComponent::Refresh()
{
	m_pTransformComp = EntityManager::GetComponent<TransformComponent>(m_Entity);
	m_pMaterialComp = EntityManager::GetComponent<MaterialComponent>(m_Entity);
}
