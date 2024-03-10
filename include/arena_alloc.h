/* Include guard */
#ifndef ELM_ARENA_ALLOC_H
#define ELM_ARENA_ALLOC_H

/* Base */
#include "base.h"

/* Linear allocator */
typedef struct {
  u8* start;
  u8* current;
  u32 size;
  bool own_alloc;
} arena_alloc_t;

/* Create an arena allocator at start (if no start, allocate new) */
extern arena_alloc_t create_arena(void* start, u32 size);
/* Destroy an arena allocator, freeing all memory */
extern void destroy_arena(arena_alloc_t* arena);
/* Allocate size bytes on the arena - will return NULL if not enough space */
extern void* arena_alloc(arena_alloc_t* arena, u32 size);

#endif /* ELM_ARENA_ALLOC_H */
