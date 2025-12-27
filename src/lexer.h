#ifndef LEXER_H
#define LEXER_H

#include "source.h"
#include "token.h"

/*
 *
 */
typedef struct {
    const SourceFile *source;   /* */
    size_t           position;  /* */
    size_t           line;      /* */
    size_t           column;    /* */
} Lexer;

/*
 *
 */
void lexer_init(Lexer *lexer, const SourceFile *source);

/*
 *
 */
Token lexer_next(Lexer *lexer);

#endif /* LEXER_H */
