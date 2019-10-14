#pragma once

#include <cstddef>

#include "engine/event/Event.h"

namespace tetrad
{

/**
 * @brief Queue filled by callback functions and consumed
 * by the InputSystem.
 *
 * Implemented as a circular buffer, where behavior when the
 * buffer is full is determined by the EOverflowBehavior value
 * passed to the constructor.
 */
class EventQueue
{
 public:
  EventQueue();

  // Removes the next Event from the queue and returns a pointer
  // to it. Returns a "null" Event otherwise (event.event == EGE_None).
  Event& Consume();
  bool PushEvent(const Event& event);

 private:
  EventQueue(const EventQueue& queue);
  EventQueue& operator=(const EventQueue& queue);

 private:
  // Ring size (how many spaces the buffer has)
  static const size_t N = 10;  // @TODO - determine a suitable size here
  Event m_Events[N + 1];

  size_t m_ReadIndex;
  size_t m_WriteIndex;
};

}  // namespace tetrad
