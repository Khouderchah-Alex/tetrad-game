#pragma once

#include "Base.h"
#include "ISystem.h"
#include "DrawSystem.h"
#include "Timer.h"

class ObserverComponent;

/*
 * @brief struct filled by user to initialize the game engine with proper attributes
 */
struct GameAttributes
{
	GameAttributes(int32_t width = 1024, int32_t height = 768, std::string title = "Test Game", bool fullscreen = false, uint8_t samples = 4);

	uint32_t m_Width, m_Height;
	std::string m_WindowTitle;
	bool m_Fullscreen;
	uint8_t m_SampleCount;
};

/*
 * @brief - Highest-level abstraction of a game
 *
 * Should be used as a base class for specific games, but generally
 * contains window dimensions/attributes, global game data, game systems, etc.
 */
class Game
{
public:
	Game();
	~Game();

	/*
	 * @brief Initialize the game (starting with the underlying engine)
	 *
	 * Initializes the component system, creates any needed systems, allocates memory,
	 * creates the needed window(s), etc.
	 *
	 * A game object can call very few methods before being successfully initialized.
	 *
	 * Returns true unless the initialization fails, in which case the engine will
	 * be in an uninitialized state until a successful Initialize occurs.
	 */
	bool Initialize(const GameAttributes& attributes);
	
	/*
	 * @brief Shuts down the game engine
	 *
	 * Moves a game object from the initialized state to uninitialized.
	 * Only needs to be called for a Game object whose Initialize method returns true.
	 */
	void Shutdown();

	/*
	 * @brief Runs the game loop, which consists mainly of running systems as needed
	 */
	void Run();

	/*
	 * @brief Sets an initialized game object back to its initial state
	 *
	 * Acts as if someone called a Shutdown() followed by an Initialize() on
	 * the object (but can be implemented more efficiently if needed).
	 */
	void Reset();

private:
	bool CreatePrimaryWindow(const GameAttributes& attributes);

private:
	Timer m_Timer;
	GLFWwindow* m_pWindow;

	DrawSystem* m_pDrawSystem;
	std::vector<ISystem*> m_pSystems;
	ObserverComponent *m_pSystemObserver;
};
