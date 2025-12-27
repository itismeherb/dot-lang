#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

/*
 * Enumerates all possible token kinds produced by the lexer.
 */
typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_UNKNOWN,
    TOKEN_NUMBER,
    TOKEN_KW_INT,
} TokenType;

/*
 * Represents a lexical token produced by the lexer.
 * The lexeme points directly into the source buffer and is not
 * null-terminated. The length field specifies the number of bytes.
 */
typedef struct {
    TokenType   type;       /* Kind of token */
    const char *lexeme;     /* Pointer into source buffer */
    size_t      length;     /* Length of lexeme in bytes */
    size_t      line;       /* 1-based line number */
    size_t      column;     /* 1-based column number */
} Token;

#endif /* TOKEN_H */
