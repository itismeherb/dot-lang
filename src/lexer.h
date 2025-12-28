#ifndef LEXER_H
#define LEXER_H

#include "source.h"
#include "token.h"
#include "ctype.h"
#include "string.h"

/*
 * Maintains the state required to tokenize a source file.
 * The lexer does not own the source buffer; it only holds
 * a reference to the loaded SourceFile.
 */
typedef struct {
    const SourceFile *source;   /* Source file being tokenized */
    size_t            position; /* Current byte offset in source */
    size_t            line;     /* Current 1-based line number */
    size_t            column;   /* Current 1-based column number */
} Lexer;

/*
 * Initializes a lexer to begin tokenizing the given source file.
 * The lexer starts at the beginning of the file with line and
 * column numbers set to 1.
 */
void lexer_init(Lexer *lexer, const SourceFile *source);

/*
 * Returns the next token from the source file and advances the
 * lexer state. Whitespace is skipped automatically.
 *
 * When the end of the source file is reached, a TOKEN_EOF token
 * is returned. Repeated calls after EOF will continue to return
 * TOKEN_EOF.
 */
Token lexer_next(Lexer *lexer);

#endif /* LEXER_H */
