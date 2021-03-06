#pragma once

#include <cstdint>
#include "jonoondb_exceptions.h"
#include "jonoondb_api_export.h"

namespace jonoondb_api {
enum class SchemaType
    : std::int32_t {
  FLAT_BUFFERS = 1
};
extern SchemaType ToSchemaType(std::int32_t type);


enum class IndexType
    : std::int32_t {
  EWAH_COMPRESSED_BITMAP = 1,
  VECTOR = 2,
};
JONOONDB_API_EXPORT extern IndexType ToIndexType(std::int32_t type);


enum class FieldType
    : std::int8_t {
  BASE_TYPE_INT8,
  BASE_TYPE_INT16,
  BASE_TYPE_INT32,
  BASE_TYPE_INT64,
  BASE_TYPE_FLOAT32,
  BASE_TYPE_DOUBLE,
  BASE_TYPE_STRING,
  BASE_TYPE_VECTOR,
  BASE_TYPE_COMPLEX,
  BASE_TYPE_UNION,
  BASE_TYPE_BLOB
};

// TODO: Come up with better management of enum to string functionality
static const char* FieldTypeStrings[] = {
  "BASE_TYPE_INT8",
  "BASE_TYPE_INT16",
  "BASE_TYPE_INT32",
  "BASE_TYPE_INT64",
  "BASE_TYPE_FLOAT32",
  "BASE_TYPE_DOUBLE",
  "BASE_TYPE_STRING",
  "BASE_TYPE_VECTOR",
  "BASE_TYPE_COMPLEX",
  "BASE_TYPE_UNION",
  "BASE_TYPE_BLOB" };

static const char* GetFieldString(FieldType fieldType) {
  return FieldTypeStrings[static_cast<int32_t>(fieldType)];
}

enum class IndexConstraintOperator
    : std::int8_t {
  EQUAL,
  LESS_THAN,
  LESS_THAN_EQUAL,
  GREATER_THAN,
  GREATER_THAN_EQUAL,
  MATCH,
  LIKE,
  GLOB,
  REGEX
};

enum class SqlType : std::int32_t {
  INTEGER = 1,
  DOUBLE = 2,
  TEXT = 3,
  DB_NULL = 4
};
}  // namespace jonoondb_api
