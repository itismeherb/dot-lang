#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Please specify the file you want to compile.\n");
        return -1;
    }

    FILE* source = fopen(argv[1], "r");
    if (!source) {
        fprintf(stderr, "Couldn't open the %s source file\n", argv[1]);
        return -1;
    }

    printf("Reading source file: %s\n", argv[1]);

    fseek(source, 0, SEEK_END);
    size_t length = (size_t)ftell(source);

    if (length < 0) {
        fprintf(stderr, "Failed to determine file size\n");
        fclose(source);
        return -1;
    }

    fseek(source, 0, SEEK_SET);
    char *string = malloc(sizeof(char) * (length+1));
    if (!string) {
        fprintf(stderr, "Out of memory\n");
        fclose(source);
        return -1;
    }

    size_t read = fread(string, 1, length, source);
    string[read] = '\0';

    fclose(source);

    printf("%s", string);
    free(string);

    return 0;
}
