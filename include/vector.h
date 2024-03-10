/* Include guard */
#ifndef ELM_VECTOR_H
#define ELM_VECTOR_H

/* Base */
#include "base.h"

/* Vector types */
typedef struct { f32 x, y; } vec2_t;        /* A 2D float vector */
typedef struct { i32 x, y; } vec2i_t;       /* A 2D int vector */
typedef struct { f32 x, y, z; } vec3_t;     /* A 3D float vector */
typedef struct { i32 x, y, z; } vec3i_t;    /* A 3D int vector */
typedef struct { f32 x, y, z, w; } vec4_t;  /* A 4D float vector */
typedef struct { i32 x, y, z, w; } vec4i_t; /* A 4D int vector */

/* Add vectors */
extern vec2_t add_v2(vec2_t a, vec2_t b);     /* Add 2D vectors (float) */
extern vec2i_t add_v2i(vec2i_t a, vec2i_t b); /* Add 2D vectors (int) */
extern vec3_t add_v3(vec3_t a, vec3_t b);     /* Add 3D vectors (float) */
extern vec3i_t add_v3i(vec3i_t a, vec3i_t b); /* Add 3D vectors (int) */
extern vec4_t add_v4(vec4_t a, vec4_t b);     /* Add 4D vectors (float) */
extern vec4i_t add_v4i(vec4i_t a, vec4i_t b); /* Add 4D vectors (int) */
/* Subtract vectors */
extern vec2_t sub_v2(vec2_t a, vec2_t b);     /* Subtract 2D vectors (float) */
extern vec2i_t sub_v2i(vec2i_t a, vec2i_t b); /* Subtract 2D vectors (int) */
extern vec3_t sub_v3(vec3_t a, vec3_t b);     /* Subtract 3D vectors (float) */
extern vec3i_t sub_v3i(vec3i_t a, vec3i_t b); /* Subtract 3D vectors (int) */
extern vec4_t sub_v4(vec4_t a, vec4_t b);     /* Subtract 4D vectors (float) */
extern vec4i_t sub_v4i(vec4i_t a, vec4i_t b); /* Subtract 4D vectors (int) */
/* Dot product of vectors */
extern f32 dot_v2(vec2_t a, vec2_t b);        /* Dot product (2D, float) */
extern i32 dot_v2i(vec2i_t a, vec2i_t b);     /* Dot product (2D, int) */
extern f32 dot_v3(vec3_t a, vec3_t b);        /* Dot product (3D, float) */
extern i32 dot_v3i(vec3i_t a, vec3i_t b);     /* Dot product (3D, int) */
extern f32 dot_v4(vec4_t a, vec4_t b);        /* Dot product (4D, float) */
extern i32 dot_v4i(vec4i_t a, vec4i_t b);     /* Dot product (4D, int) */
/* Cross product of vectors */
extern f32 cross_v2(vec2_t a, vec2_t b);      /* Z component of cross product
                                                 of 2D vectors (float) */
extern i32 cross_v2i(vec2i_t a, vec2i_t b);   /* Z component of cross product
                                                 of 2D vectors (int) */
extern vec3_t cross_v3(vec3_t a, vec3_t b);   /* Cross product (3D, float) */
extern vec3i_t cross_v3i(vec3i_t a, vec3i_t b);/* Cross product (3D, int) */
/* Scale vectors */
extern vec2_t scale_v2(vec2_t v, f32 a);      /* Scale 2D vector (float) */
extern vec2i_t scale_v2i(vec2i_t v, f32 a);   /* Scale 2D vector (float) */
extern vec3_t scale_v3(vec3_t v, f32 a);      /* Scale 3D vector (float) */
extern vec3i_t scale_v3i(vec3i_t v, f32 a);   /* Scale 3D vector (float) */
extern vec4_t scale_v4(vec4_t v, f32 a);      /* Scale 4D vector (float) */
extern vec4i_t scale_v4i(vec4i_t v, f32 a);   /* Scale 4D vector (float) */
/* Length of vectors */
extern f32 len_v2(vec2_t a);                  /* Length of 2D vector (float) */
extern f32 len_v3(vec3_t a);                  /* Length of 3D vector (float) */
extern f32 len_v4(vec4_t a);                  /* Length of 4D vector (float) */
/* Normalize vectors */
extern vec2_t normalize_v2(vec2_t v);         /* Normalize 2D vector (float) */
extern vec3_t normalize_v3(vec3_t v);         /* Normalize 3D vector (float) */
extern vec4_t normalize_v4(vec4_t v);         /* Normalize 4D vector (float) */
/* Linear interpolation of vectors */
/* Linear interpolation between two 2D vectors (float) */
extern vec2_t lerp_v2(vec2_t a, vec2_t b, f32 v);
/* Linear interpolation between two 3D vectors (float) */
extern vec3_t lerp_v3(vec3_t a, vec3_t b, f32 v);
/* Linear interpolation between two 4D vectors (float) */
extern vec4_t lerp_v4(vec4_t a, vec4_t b, f32 v);

#endif /* ELM_VECTOR_H */
