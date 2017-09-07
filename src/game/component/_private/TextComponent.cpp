#include "TextComponent.h"
#include "TransformComponent.h"
#include "UIComponent.h"

LinkedList<TextComponent> TextComponent::s_FreeTextComps;

TextComponent::TextComponent(Entity entity) :
	IComponent(entity), m_pFont(nullptr),
	m_pTransformComp(nullptr), m_pUIComp(nullptr),
	m_Scale(1.f)
{
}

TextComponent::~TextComponent()
{
}

void TextComponent::Refresh()
{
	m_pTransformComp = EntityManager::GetComponent<TransformComponent>(m_Entity);

	UIComponent *pComp = EntityManager::GetComponent<UIComponent>(m_Entity);
	if(m_pUIComp && m_pUIComp->GetID() == 0 && pComp->GetID() != 0)
	{
		s_FreeTextComps.Remove(m_FreeTextNode);
	}
	else if((!m_pUIComp || m_pUIComp->GetID() != 0) && pComp->GetID() == 0)
	{
		s_FreeTextComps.PushBack(m_FreeTextNode);
	}

	m_pUIComp = pComp;
}
