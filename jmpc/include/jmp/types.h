#ifndef __JMPC_TYPES_H
#define __JMPC_TYPES_H

#include <stdint.h>
#include <stdlib.h>

// === INTEGER TYPES ===
typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef size_t sz;

// === FLOATING POINT TYPES ===
typedef float  f32;
typedef double f64;

// === VECTOR TYPES ===
typedef struct Vector2 {
  i32 x, y;
} vec2;

typedef struct Vector3 {
  union { i32 x, r; };
  union { i32 y, g; };
  union { i32 z, b; };
} vec3;

typedef struct Vector4 {
  union { i32 x, r; };
  union { i32 y, g; };
  union { i32 z, b; };
  union { i32 w, a; };
} vec4;

typedef struct Vector2f {
  f32 x, y;
} vec2f;

typedef struct Vector3f {
  union { f32 x, r; };
  union { f32 y, g; };
  union { f32 z, b; };
} vec3f;

typedef struct Vector4f {
  union { f32 x, r; };
  union { f32 y, g; };
  union { f32 z, b; };
  union { f32 w, a; };
} vec4f;

// TODO - matricies

#endif // __JMPC_TYPES_H
