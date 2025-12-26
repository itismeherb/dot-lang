#include <stdio.h>
#include "source.h"

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

    printf("%s", file.data);
    free_source_file(&file);

    return 0;
}
