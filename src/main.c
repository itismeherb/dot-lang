#include <stdio.h>
#include "source.h"
#include "lexer.h"
#include "token.h"

const char* token_type_to_string(TokenType type) {
    switch(type) {
        case TOKEN_EOF:        return "TOKEN_EOF";
        case TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
        case TOKEN_NUMBER:     return "TOKEN_NUMBER";
        case TOKEN_KW_INT:     return "TOKEN_KW_INT";
        case TOKEN_UNKNOWN:    return "TOKEN_UNKNOWN";
        default:               return "TOKEN_UNKNOWN";
    }
}


int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Please specify the file you want to compile.\n");
        return -1;
    }

    SourceFile file;
    if (load_source_file(argv[1], &file) != 0) {
        fprintf(stderr, "failed to load source file\n");
        return 1;
    }

    printf("File data:\n%s\n", file.data);

    Lexer lexer;
    lexer_init(&lexer, &file);
    for (;;) {
        Token tok = lexer_next(&lexer);

        printf("%s %.*s\n", token_type_to_string(tok.type), (int)tok.length, tok.lexeme);

        if (tok.type == TOKEN_EOF) {
            break;
        }
    }

    free_source_file(&file);

    return 0;
}
