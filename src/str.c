/* Implements str.h */
#include <str.h>

/* libc headers */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/* Create string from literal */
str_t string_from(const char* literal) {
  str_t string;
  string.size = strlen(literal);
  string.ptr = malloc(strlen(literal));
  memcpy(string.ptr, literal, strlen(literal));
  return string;
}
/* Create string from stdin with a maximum of max bytes */
str_t string_input(u32 max) {
  str_t string;
  char* res = malloc(max);
  u32 bytes_in = read(STDIN_FILENO, res, max);
  memcpy(string.ptr, res, bytes_in);
  string.size = strlen(string.ptr);
  return string;
}
/* Create string by reading full file */
str_t string_file(const char* path) {
  str_t string;
  u32 size;
  FILE* ptr = fopen(path, "r");
  string.size = 0;
  string.ptr = NULL;
  if (!ptr) return string;
  fseek(ptr, 0, SEEK_END);
  size = ftell(ptr);
  fseek(ptr, 0, SEEK_SET);
  string.ptr = malloc(size);
  string.size = size;
  fread(string.ptr, size, 1, ptr);
  fclose(ptr);
  return string;
}
/* Create string by reading size bytes of file */
str_t string_file_part(const char* path, u32 size) {
  str_t string;
  FILE* ptr = fopen(path, "r");
  string.size = 0;
  string.ptr = NULL;
  if (!ptr) return string;
  string.ptr = malloc(size);
  string.size = size;
  fread(string.ptr, size, 1, ptr);
  fclose(ptr);
  return string;
}
/* Create string by copying existing string */
str_t string_copy(const str_t string) {
  str_t str;
  str.size = string.size;
  str.ptr = malloc(string.size);
  str.ptr = strcpy(string.ptr, str.ptr);
  return str;
}
/* Create string by concatenating two other strings */
str_t string_concat(const str_t str1, const str_t str2) {
  str_t string;
  string.size = str1.size + str2.size;
  string.ptr = malloc(string.size);
  memcpy(string.ptr, str1.ptr, str1.size);
  memcpy(string.ptr+str1.size, str2.ptr, str2.size);
  return string;
}

/* Write string to file */
void file_write_string(const char* path, const str_t string) {
  FILE* ptr;
  char* str = malloc(string.size+1);
  memset(str, 0x00, string.size+1);
  memcpy(str, string.ptr, string.size);
  ptr = fopen(path, "w");
  fprintf(ptr, "%s", str);
  fclose(ptr);
}
/* Append string to file */
void file_append_string(const char* path, const str_t string) {
  FILE* ptr;
  char* str = malloc(string.size+1);
  memset(str, 0x00, string.size+1);
  memcpy(str, string.ptr, string.size);
  ptr = fopen(path, "a");
  fprintf(ptr, "%s", str);
  fclose(ptr);
}
/* Print a string */
void print_string(const str_t string) {
  char* str = malloc(string.size+1);
  memset(str, 0x00, string.size+1);
  memcpy(str, string.ptr, string.size);
  printf("%s", str);
  free(str);
}

/* Compare two strings bool is equal */
bool string_compare(const str_t str1, const str_t str2) {
  u32 i;
  bool res = true;
  if (str1.size != str2.size) return false;
  for (i = 0; i < str1.size; i++) {
    if (str1.ptr[i] != str2.ptr[i]) res = false;
  }
  return res;
}

/* Free a string */
void free_string(str_t* string) {
  free(string->ptr);
  string->ptr = NULL;
  string->size = 0;
}
