/* Include guard */
#ifndef ELM_STR_H
#define ELM_STR_H

/* Base */
#include "base.h"

/* Length-based string structure */
typedef struct {
  char* ptr;
  u32 size;
} str_t;

/* Create string from literal */
extern str_t string_from(const char* literal);
/* Create string from stdin with a maximum of max bytes */
extern str_t string_input(u32 max);
/* Create string by reading full file */
extern str_t string_file(const char* path);
/* Create string by reading size bytes of file */
extern str_t string_file_part(const char* path, u32 size);
/* Create string by copying existing string */
extern str_t string_copy(const str_t string);
/* Create string by concatenating two other strings */
extern str_t string_concat(const str_t str1, const str_t str2);

/* Write string to file */
extern void file_write_string(const char* path, const str_t string);
/* Append string to file */
extern void file_append_string(const char* path, const str_t string);
/* Print a string */
extern void print_string(const str_t string);

/* Compare two strings bool is equal */
extern bool string_compare(const str_t str1, const str_t str2);

/* Free a string */
extern void free_string(str_t* string);

#endif /* ELM_STR_H */
