#include <jmp/math.h>
#include <jmp/types.h>

#include <math.h> 

int fact(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) { res *= i; }
	return res;
}

int nCr(int n, int r) {
	return fact(n) / (fact(r) * fact(n - r));
}

int nPr(int n, int r) {
	return fact(n) / fact(r);
}

f32 v2_len(vec2 vec) {
  return sqrtf((f32)(
    (vec.x * vec.x) +
    (vec.y * vec.y)
  ));
}

vec2 v2_add(vec2 a, vec2 b) {
  return (vec2) {
    .x = a.x + b.x,
    .y = a.y + b.y,
  };
}

vec2 v2_sub(vec2 a, vec2 b) {
  return (vec2) {
    .x = a.x - b.x,
    .y = a.y - b.y,
  };
}

f32 v3_len(vec3 vec) {
  return sqrtf((f32)(
    (vec.x * vec.x) +
    (vec.y * vec.y) +
    (vec.z * vec.z)
  ));
}

vec3 v3_add(vec3 a, vec3 b) {
  return (vec3) {
    .x = a.x + b.x,
    .y = a.y + b.y,
    .z = a.z + b.z,
  };
}

vec3 v3_sub(vec3 a, vec3 b) {
  return (vec3) {
    .x = a.x - b.x,
    .y = a.y - b.y,
    .z = a.z - b.z,
  };
}

f32 v4_len(vec4 vec) {
  return sqrtf((f32)(
    (vec.x * vec.x) +
    (vec.y * vec.y) +
    (vec.z * vec.z) + 
    (vec.w * vec.w)
  ));
}

vec4 v4_add(vec4 a, vec4 b) {
  return (vec4) {
    .x = a.x + b.x,
    .y = a.y + b.y,
    .z = a.z + b.z,
    .w = a.w + b.w,
  };
}

vec4 v4_sub(vec4 a, vec4 b) {
  return (vec4) {
    .x = a.x - b.x,
    .y = a.y - b.y,
    .z = a.z - b.z,
    .w = a.w - b.w,
  };
}

f32 v2f_len(vec2f vec) {
  return sqrtf(
    (vec.x * vec.x) +
    (vec.y * vec.y)
  );
}

vec2f v2f_add(vec2f a, vec2f b) {
  return (vec2f) {
    .x = a.x + b.x,
    .y = a.y + b.y,
  };
}

vec2f v2f_sub(vec2f a, vec2f b) {
  return (vec2f) {
    .x = a.x - b.x,
    .y = a.y - b.y,
  };
}

f32 v3f_len(vec3f vec) {
  return sqrtf(
    (vec.x * vec.x) +
    (vec.y * vec.y) +
    (vec.z * vec.z)
  );
}

vec3f v3f_add(vec3f a, vec3f b) {
  return (vec3f) {
    .x = a.x + b.x,
    .y = a.y + b.y,
    .z = a.z + b.z,
  };
}

vec3f v3f_sub(vec3f a, vec3f b) {
  return (vec3f) {
    .x = a.x - b.x,
    .y = a.y - b.y,
    .z = a.z - b.z,
  };
}

f32 v4f_len(vec4f vec) {
  return sqrtf(
    (vec.x * vec.x) +
    (vec.y * vec.y) +
    (vec.z * vec.z) + 
    (vec.w * vec.w)
  );
}

vec4f v4f_add(vec4f a, vec4f b) {
  return (vec4f) {
    .x = a.x + b.x,
    .y = a.y + b.y,
    .z = a.z + b.z,
    .w = a.w + b.w,
  };
}

vec4f v4f_sub(vec4f a, vec4f b) {
  return (vec4f) {
    .x = a.x - b.x,
    .y = a.y - b.y,
    .z = a.z - b.z,
    .w = a.w - b.w,
  };
}
