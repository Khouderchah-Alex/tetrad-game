#pragma once

#include <cassert>
#ifdef WIN32
//#include <Windows.h>
#endif

#include "GL/glew.h"
#include "glfw3.h"
#include "glm/glm.hpp"

#include "Config.h"
#include "core/ErrorSystem.h"
#include "core/LogSystem.h"
#include "core/Platform.h"
#include "core/Paths.h"
#include "core/Rand.h"
#include "core/Types.h"

const std::string VERSION_STRING = std::to_string(VERSION_MAJOR) + "." + std::to_string(VERSION_MINOR);

/** System Globals **/
class Entity;
extern const Entity nullEntity;

/**
 * @brief Set of classes to generate GUIDs for different purposes.
 *
 * @in - T - The GUID "purpose" (the set of classes (base class perhaps) that will use the GUID)
 * @in - IDType - The data type of the ID (most likely an integer type, although it could be specialized
 *	different types)
 *
 *	@note The base implementation only generates IDs, it does not reclaim them, even if an ID is no longer used.
 */
template <class T, class IDType>
class GUID
{
public:
	GUID() = delete;
	~GUID() = delete;

	static IDType GenerateID()
	{
		assert(s_currentID+1 > s_currentID);	// Check for overflow
		return s_currentID++;
	}

private:
	static IDType s_currentID;
};

/** Compile-time operations **/
template<int N, int M> struct CompiledSum{ enum { val = N + M }; };
template<int N, int M> struct CompiledMult{ enum { val = N * M }; };
