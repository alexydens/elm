/* Implements arena_alloc.h */
#include <arena_alloc.h>

/* libc headers */
#include <stdlib.h>

/* Create an arena allocator at start (if no start, allocate new) */
arena_alloc_t create_arena(void* start, u32 size) {
  arena_alloc_t arena;
  if (start) {
    arena.start = start;
    arena.own_alloc = false;
  } else {
    arena.start = malloc(size);
    arena.own_alloc = true;
  }
  arena.current = arena.start;
  arena.size = size;
  return arena;
}
/* Destroy an arena allocator, freeing all memory */
void destroy_arena(arena_alloc_t* arena) {
  if (arena->own_alloc) free(arena->start);
  arena->start = NULL;
  arena->current = NULL;
  arena->size = 0;
  arena->own_alloc = false;
}
/* Allocate size bytes on the arena - will return NULL if not enough space */
void* arena_alloc(arena_alloc_t* arena, u32 size) {
  if (arena->current+size > arena->start+arena->size)
    return NULL;
  void* res = (void*)arena->current;
  arena->current += size;
  return res;
}
