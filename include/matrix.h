/* Include guard */
#ifndef ELM_MATRIX_H
#define ELM_MATRIX_H

/* Base */
#include "base.h"
/* Vectors */
#include "vector.h"

/* 4x4 matrix type */
typedef struct {
  /* Vals: 
   *  0  4  8 12
   *  1  5  9 13
   *  2  6 10 14
   *  3  7 11 15
   */
  f32 vals[16];
} mat4_t;

/* Generate an identity matrix */
extern mat4_t identity_m4(void);
/* Generate a translation matrix */
extern mat4_t translation_m4(vec3_t v);
/* Generate a scale matrix */
extern mat4_t scale_m4(f32 v);
/* Generate a rotation matrix */
extern mat4_t euler_rot_m4(vec3_t angles);
/* 
 * Generate a perspective projection matrix:
 * - fov = field of view, in degrees.
 * - aspect = aspect ratio (height/width)
 * - near_z = the near plane z value
 * - far_z = the far plane z value
 */
extern mat4_t projection(f32 fov, f32 aspect, f32 near_z, f32 far_z);

/* Multiply two matrices */
extern mat4_t mul_m4m4(mat4_t a, mat4_t b);
/* Multiply matrix with vector */
extern vec4_t mul_m4v4(mat4_t m, vec4_t v);

#endif /* ELM_MATRIX_H */
