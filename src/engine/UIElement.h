#pragma once

/**
 * @brief Base case for all UI element classes
 *
 * Provides the interface through which UI elements can be informed of
 * various user actions
 */
class UIElement
{
public:
	virtual ~UIElement(){}

	virtual void OnHoverEnter() = 0;
	virtual void OnHoverLeave() = 0;

	virtual void OnTouchEnter() = 0;
	virtual void OnTouchLeave() = 0;
};