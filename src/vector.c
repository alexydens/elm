/* Implements vector.h */
#include <vector.h>

/* libc headers */
#include <math.h>
#include <stdio.h>

/* Add vectors */
vec2_t add_v2(vec2_t a, vec2_t b) {
  vec2_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  return v;
}
vec2i_t add_v2i(vec2i_t a, vec2i_t b) {
  vec2i_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  return v;
}
vec3_t add_v3(vec3_t a, vec3_t b) {
  vec3_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  return v;
}
vec3i_t add_v3i(vec3i_t a, vec3i_t b) {
  vec3i_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  return v;
}
vec4_t add_v4(vec4_t a, vec4_t b) {
  vec4_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  v.w = a.w + b.w;
  return v;
}
vec4i_t add_v4i(vec4i_t a, vec4i_t b) {
  vec4i_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  v.w = a.w + b.w;
  return v;
}
/* Subtract vectors */
vec2_t sub_v2(vec2_t a, vec2_t b) {
  vec2_t v;
  v.x = a.x - b.x;
  v.y = a.y - b.y;
  return v;
}
vec2i_t sub_v2i(vec2i_t a, vec2i_t b) {
  vec2i_t v;
  v.x = a.x - b.x;
  v.y = a.y - b.y;
  return v;
}
vec3_t sub_v3(vec3_t a, vec3_t b) {
  vec3_t v;
  v.x = a.x - b.x;
  v.y = a.y - b.y;
  v.z = a.z - b.z;
  return v;
}
vec3i_t sub_v3i(vec3i_t a, vec3i_t b) {
  vec3i_t v;
  v.x = a.x - b.x;
  v.y = a.y - b.y;
  v.z = a.z - b.z;
  return v;
}
vec4_t sub_v4(vec4_t a, vec4_t b) {
  vec4_t v;
  v.x = a.x - b.x;
  v.y = a.y - b.y;
  v.z = a.z - b.z;
  v.w = a.w - b.w;
  return v;
}
vec4i_t sub_v4i(vec4i_t a, vec4i_t b) {
  vec4i_t v;
  v.x = a.x - b.x;
  v.y = a.y - b.y;
  v.z = a.z - b.z;
  v.w = a.w - b.w;
  return v;
}
/* Dot product of vectors */
f32 dot_v2(vec2_t a, vec2_t b) {
  return (a.x * b.x + a.y * b.y);
}
i32 dot_v2i(vec2i_t a, vec2i_t b) {
  return (a.x * b.x + a.y * b.y);
}
f32 dot_v3(vec3_t a, vec3_t b) {
  return (a.x * b.x + a.y * b.y + a.z * b.z);
}
i32 dot_v3i(vec3i_t a, vec3i_t b) {
  return (a.x * b.x + a.y * b.y + a.z * b.z);
}
f32 dot_v4(vec4_t a, vec4_t b) {
  return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}
i32 dot_v4i(vec4i_t a, vec4i_t b) {
  return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}
/* Cross product of vectors */
f32 cross_v2(vec2_t a, vec2_t b) {
  return (a.x * b.y) - (a.y * b.x);
}
i32 cross_v2i(vec2i_t a, vec2i_t b) {
  return (a.x * b.y) - (a.y * b.x);
}
vec3_t cross_v3(vec3_t a, vec3_t b) {
  vec3_t res;
  res.x = (a.y * b.z) - (a.z * b.y);
  res.y = (a.z * b.x) - (a.x * b.z);
  res.z = (a.x * b.y) - (a.y * b.x);
  return res;
}
vec3i_t cross_v3i(vec3i_t a, vec3i_t b) {
  vec3i_t res;
  res.x = (a.y * b.z) - (a.z * b.y);
  res.y = (a.z * b.x) - (a.x * b.z);
  res.z = (a.x * b.y) - (a.y * b.x);
  return res;
}
/* Scale vectors */
vec2_t scale_v2(vec2_t v, f32 a) {
  vec2_t res = v;
  res.x *= a;
  res.y *= a;
  return res;
}
vec2i_t scale_v2i(vec2i_t v, f32 a) {
  vec2i_t res = v;
  res.x *= a;
  res.y *= a;
  return res;
}
vec3_t scale_v3(vec3_t v, f32 a) {
  vec3_t res = v;
  res.x *= a;
  res.y *= a;
  res.z *= a;
  return res;
}
vec3i_t scale_v3i(vec3i_t v, f32 a) {
  vec3i_t res = v;
  res.x *= a;
  res.y *= a;
  res.z *= a;
  return res;
}
vec4_t scale_v4(vec4_t v, f32 a) {
  vec4_t res = v;
  res.x *= a;
  res.y *= a;
  res.z *= a;
  res.w *= a;
  return res;
}
vec4i_t scale_v4i(vec4i_t v, f32 a) {
  vec4i_t res = v;
  res.x *= a;
  res.y *= a;
  res.z *= a;
  res.w *= a;
  return res;
}
/* Length of vectors */
f32 len_v2(vec2_t a) {
  return sqrt(dot_v2(a, a));
}
f32 len_v3(vec3_t a) {
  return sqrt(dot_v3(a, a));
}
f32 len_v4(vec4_t a) {
  return sqrt(dot_v4(a, a));
}
/* Normalize vectors */
vec2_t normalize_v2(vec2_t v) {
  vec2_t res;
  f32 len = len_v2(v);
  res = scale_v2(v, 1.0 / len);
  return res;
}
vec3_t normalize_v3(vec3_t v) {
  vec3_t res;
  f32 len = len_v3(v);
  res = scale_v3(v, 1.0 / len);
  return res;
}
vec4_t normalize_v4(vec4_t v) {
  vec4_t res;
  f32 len = len_v4(v);
  res = scale_v4(v, 1.0 / len);
  return res;
}
/* Linear interpolation of vectors */
vec2_t lerp_v2(vec2_t a, vec2_t b, f32 v) {
  vec2_t res;
  res.x = LERP(a.x, b.x, v);
  res.y = LERP(a.y, b.y, v);
  return res;
}
vec3_t lerp_v3(vec3_t a, vec3_t b, f32 v) {
  vec3_t res;
  res.x = LERP(a.x, b.x, v);
  res.y = LERP(a.y, b.y, v);
  res.z = LERP(a.z, b.z, v);
  return res;
}
vec4_t lerp_v4(vec4_t a, vec4_t b, f32 v) {
  vec4_t res;
  res.x = LERP(a.x, b.x, v);
  res.y = LERP(a.y, b.y, v);
  res.z = LERP(a.z, b.z, v);
  res.w = LERP(a.w, b.w, v);
  return res;
}
