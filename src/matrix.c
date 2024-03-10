/* Implements matrix.h */
#include <matrix.h>

/* libc headers */
#include <math.h>

/* Generate an identity matrix */
mat4_t identity_m4(void) {
  mat4_t res;
  u8 i;
  for (i = 0; i < 16; i++) {
    res.vals[i] = 0;
  }
  res.vals[0] = 1.0f;
  res.vals[5] = 1.0f;
  res.vals[10] = 1.0f;
  res.vals[15] = 1.0f;
  return res;
}
/* Generate a translation matrix */
mat4_t translation_m4(vec3_t v) {
  mat4_t res = identity_m4();
  res.vals[12] = v.x;
  res.vals[13] = v.y;
  res.vals[14] = v.z;
  return res;
}
/* Generate a scale matrix */
mat4_t scale_m4(f32 v) {
  mat4_t res = identity_m4();
  res.vals[0] = v;
  res.vals[5] = v;
  res.vals[10] = v;
  res.vals[15] = v;
  return res;
}
/* Generate a rotation matrix */
mat4_t euler_rot_m4(vec3_t angles) {
  mat4_t res = identity_m4();
  f32 sin_alpha = sin(angles.x);
  f32 cos_alpha = cos(angles.x);
  f32 sin_beta = sin(angles.y);
  f32 cos_beta = cos(angles.y);
  f32 sin_gamma = sin(angles.z);
  f32 cos_gamma = cos(angles.z);
  res.vals[0] = cos_beta * cos_gamma;
  res.vals[4] = sin_alpha * sin_beta * cos_gamma - cos_alpha * sin_gamma;
  res.vals[8] = cos_alpha * sin_beta * cos_gamma + sin_alpha * sin_gamma;
  res.vals[1] = cos_beta * sin_gamma;
  res.vals[5] = sin_alpha * sin_beta * sin_gamma + cos_alpha * cos_gamma;
  res.vals[9] = cos_alpha * sin_beta * sin_gamma - sin_alpha * cos_gamma;
  res.vals[2] = -sin_beta;
  res.vals[6] = sin_alpha * cos_beta;
  res.vals[10] = cos_alpha * cos_beta;
  return res;
}
/* 
 * Generate a perspective projection matrix:
 * - fov = field of view, in degrees.
 * - aspect = aspect ratio (height/width)
 * - near_z = the near plane z value
 * - far_z = the far plane z value
 */
mat4_t projection(f32 fov, f32 aspect, f32 near_z, f32 far_z) {
  mat4_t res;
  f32 projection_a, projection_b;
  u8 i;
  for (i = 0; i < 16; i++) {
    res.vals[i] = 0;
  }
  projection_a = 1.0 / tan((fov*CONST_DEGRAD)/2);
  projection_b = far_z / (far_z-near_z);
  res.vals[0] = aspect * projection_a;
  res.vals[5] = projection_a;
  res.vals[10] = projection_b;
  res.vals[14] = 1.0;
  res.vals[11] = projection_b * (-near_z);
  res.vals[15] = 0.0;
  return res;
}

/* Multiply two matrices */
mat4_t mul_m4m4(mat4_t a, mat4_t b) {
  mat4_t res;
  vec4_t x, y;
  y.x = b.vals[0];
  y.y = b.vals[1];
  y.z = b.vals[2];
  y.w = b.vals[3];
  x.x = a.vals[0];
  x.y = a.vals[4];
  x.z = a.vals[8];
  x.w = a.vals[12];
  res.vals[0] = dot_v4(x, y);
  x.x = a.vals[1];
  x.y = a.vals[5];
  x.z = a.vals[9];
  x.w = a.vals[13];
  res.vals[1] = dot_v4(x, y);
  x.x = a.vals[2];
  x.y = a.vals[6];
  x.z = a.vals[10];
  x.w = a.vals[14];
  res.vals[2] = dot_v4(x, y);
  x.x = a.vals[3];
  x.y = a.vals[7];
  x.z = a.vals[11];
  x.w = a.vals[15];
  res.vals[3] = dot_v4(x, y);
  y.x = b.vals[4];
  y.y = b.vals[5];
  y.z = b.vals[6];
  y.w = b.vals[7];
  x.x = a.vals[0];
  x.y = a.vals[4];
  x.z = a.vals[8];
  x.w = a.vals[12];
  res.vals[4] = dot_v4(x, y);
  x.x = a.vals[1];
  x.y = a.vals[5];
  x.z = a.vals[9];
  x.w = a.vals[13];
  res.vals[5] = dot_v4(x, y);
  x.x = a.vals[2];
  x.y = a.vals[6];
  x.z = a.vals[10];
  x.w = a.vals[14];
  res.vals[6] = dot_v4(x, y);
  x.x = a.vals[3];
  x.y = a.vals[7];
  x.z = a.vals[11];
  x.w = a.vals[15];
  res.vals[7] = dot_v4(x, y);
  y.x = b.vals[8];
  y.y = b.vals[9];
  y.z = b.vals[10];
  y.w = b.vals[11];
  x.x = a.vals[0];
  x.y = a.vals[4];
  x.z = a.vals[8];
  x.w = a.vals[12];
  res.vals[8] = dot_v4(x, y);
  x.x = a.vals[1];
  x.y = a.vals[5];
  x.z = a.vals[9];
  x.w = a.vals[13];
  res.vals[9] = dot_v4(x, y);
  x.x = a.vals[2];
  x.y = a.vals[6];
  x.z = a.vals[10];
  x.w = a.vals[14];
  res.vals[10] = dot_v4(x, y);
  x.x = a.vals[3];
  x.y = a.vals[7];
  x.z = a.vals[11];
  x.w = a.vals[15];
  res.vals[11] = dot_v4(x, y);
  y.x = b.vals[12];
  y.y = b.vals[13];
  y.z = b.vals[14];
  y.w = b.vals[15];
  x.x = a.vals[0];
  x.y = a.vals[4];
  x.z = a.vals[8];
  x.w = a.vals[12];
  res.vals[12] = dot_v4(x, y);
  x.x = a.vals[1];
  x.y = a.vals[5];
  x.z = a.vals[9];
  x.w = a.vals[13];
  res.vals[13] = dot_v4(x, y);
  x.x = a.vals[2];
  x.y = a.vals[6];
  x.z = a.vals[10];
  x.w = a.vals[14];
  res.vals[14] = dot_v4(x, y);
  x.x = a.vals[3];
  x.y = a.vals[7];
  x.z = a.vals[11];
  x.w = a.vals[15];
  res.vals[15] = dot_v4(x, y);
  return res;
}
/* Multiply matrix with vector */
vec4_t mul_m4v4(mat4_t m, vec4_t v) {
  vec4_t res;
  res.x =
    m.vals[0] * v.x
    + m.vals[4] * v.y
    + m.vals[8] * v.z
    + m.vals[12] * v.w;
  res.y =
    m.vals[1] * v.x
    + m.vals[5] * v.y
    + m.vals[9] * v.z
    + m.vals[13] * v.w;
  res.z =
    m.vals[2] * v.x
    + m.vals[6] * v.y
    + m.vals[10] * v.z
    + m.vals[14] * v.w;
  res.w =
    m.vals[3] * v.x
    + m.vals[7] * v.y
    + m.vals[11] * v.z
    + m.vals[15] * v.w;
  return res;
}
