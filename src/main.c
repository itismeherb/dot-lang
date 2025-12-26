#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Please specify the file you want to compile.\n");
        return -1;
    }

    FILE* source = fopen(argv[1], "r");
    if (source) {
        printf("Reading from: %s file\n", argv[1]);
        fclose(source);
    } else {
        fprintf(stderr, "Couldn't open the %s source file\n", argv[1]);
        return -1;
    }

    return 0;
}
