#pragma once

#include "core/BaseTypes.h"

namespace tetrad {

/** @brief Defines the handle used for the component system.
 *
 * Can refer to either an entity or a component.
 *
 * Current format is laid out as such. Entities have a type 0,
 * and components have a non-zero type. The ID 0 is reserved for
 * error codes (think of it as nullptr).
 * +---------------------+-----------+------------+
 * |        ID:32        |  type:16  | version:16 |
 * +---------------------+-----------+------------+
 */
class ObjectHandle
{
 public:
  typedef uint64_t handle_t;
  typedef uint32_t ID_t;
  typedef uint16_t type_t;
  typedef uint16_t version_t;

  ObjectHandle();

  static handle_t constructRawHandle(ID_t ID, type_t type, version_t version);
  static ObjectHandle constructHandle(ID_t ID, type_t type, version_t version);

  ID_t GetID() const;
  type_t GetType() const;
  version_t GetVersion() const;

 public:
  static const ObjectHandle null;
  static const ID_t MAX_ID;

 private:
  ObjectHandle(handle_t handleVal);
  handle_t m_Handle;
};

}  // namespace tetrad
