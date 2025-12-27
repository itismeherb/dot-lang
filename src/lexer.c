#include "lexer.h"
#include "string.h"

void lexer_init(Lexer *lexer, const SourceFile *source) {
    lexer->source   = source;
    lexer->position = 0;
    lexer->line     = 1;
    lexer->column   = 1;
}

static char peek(Lexer *lexer) {
    if (lexer->position >= lexer->source->size) {
        return '\0';
    }
    return lexer->source->data[lexer->position];
}

static char advance(Lexer *lexer) {
    char c = peek(lexer);
    lexer->position++;

    if (c == '\n') {
        lexer->line++;
        lexer->column = 1;
    } else {
        lexer->column++;
    }

    return c;
}

static Token make_token(
    Lexer *lexer,
    TokenType type,
    size_t start,
    size_t length,
    size_t line,
    size_t column
) {
    return (Token){
        .type   = type,
        .lexeme = lexer->source->data + start,
        .length = length,
        .line   = line,
        .column = column,
    };
}

Token lexer_next(Lexer *lexer) {
    // Skip whitespace
    for (;;) {
        char c = peek(lexer);
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
            advance(lexer);
        } else {
            break;
        }
    }

    size_t start = lexer->position;
    size_t line  = lexer->line;
    size_t col   = lexer->column;

    char c = peek(lexer);

    if (c == '\0') {
        return make_token(lexer, TOKEN_EOF, start, 0, line, col);
    }

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
        advance(lexer);
        while (1) {
            c = peek(lexer);
            if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ||
                c == '_') {
                advance(lexer);
            } else {
                break;
            }
        }

        size_t length = lexer->position - start;
        TokenType type = TOKEN_IDENTIFIER;

        // Optional: recognize 'int' keyword
        if (length == 3 && strncmp(lexer->source->data + start, "int", 3) == 0) {
            type = TOKEN_KW_INT;
        }

        return make_token(lexer, type, start, length, line, col);
    }

    // Unknown character
    advance(lexer);
    return make_token(lexer, TOKEN_UNKNOWN, start, 1, line, col);
}
