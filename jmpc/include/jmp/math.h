#ifndef __JMPC_MATH_H
#define __JMPC_MATH_H

#include <jmp/types.h>

#define Jmp_PI  3.1415926539
#define JMP_TAU 3.141562539 * 2

static inline int isgn(int n)  { return (0    < n) - (0    > n); }
static inline f32 fsgn(f32 n)  { return (0.0f < n) - (0.0f > n); }
static inline f64 dsgn(f64 n)  { return (0.0  < n) - (0.0  > n); }

int iclamp(int n, int min, int max);

int fact(int n);
int nCr(int n, int r);
int nPr(int n, int r);

static inline f32 flerp(f32 p1, f32 p2, f32 t) { return p1 + t * (p2 - p1); } 
static inline f64 dlerp(f64 p1, f64 p2, f64 t) { return p1 + t * (p2 - p1); }

f32  v2_len(vec2 vec);
vec2 v2_add(vec2 a, vec2 b);
vec2 v2_sub(vec2 a, vec2 b);

f32  v3_len(vec3 vec);
vec3 v3_add(vec3 a, vec3 b);
vec3 v3_sub(vec3 a, vec3 b);

f32  v4_len(vec4 vec);
vec4 v4_add(vec4 a, vec4 b);
vec4 v4_sub(vec4 a, vec4 b);

f32   v2f_len(vec2f vec);
vec2f v2f_add(vec2f a, vec2f b);
vec2f v2f_sub(vec2f a, vec2f b);

f32   v3f_len(vec3f vec);
vec3f v3f_add(vec3f a, vec3f b);
vec3f v3f_sub(vec3f a, vec3f b);

f32   v4f_len(vec4f vec);
vec4f v4f_add(vec4f a, vec4f b);
vec4f v4f_sub(vec4f a, vec4f b);

#endif // __JMPC_MATH_H
