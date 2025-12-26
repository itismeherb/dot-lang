#ifndef  SOURCE_H
#define SOURCE_H

#include <stdlib.h>
#include <stdio.h>

/*
 * Represents a file fully loaded into memory.
 * The buffer is null-terminated for convenience, but size
 * does not include the terminating null byte.
 */
typedef struct {
    char *data;     /* Source file contents */
    size_t size;    /* Size in bytes */
} SourceFile;

/*
 * Loads the file at path into memory.
 * Initializes SourceFile on success, but returns a non-zero on failure.
 * The caller owns the returned buffer and must call
 * free_source_file when done.
 */
int load_source_file(const char* path, SourceFile *out);

/*
 * Frees resources owned by a SourceFile and resets it
 * to an empty state
 */
void free_source_file(SourceFile *file);

#endif /* SOURCE_H */
