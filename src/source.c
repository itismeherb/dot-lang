#include "source.h"

int load_source_file(const char *path, SourceFile *out) {
    FILE *source = fopen(path, "rb");
    if (!source) {
        return -1;
    }

    if (fseek(source, 0, SEEK_END) != 0) {
        fclose(source);
        return -1;
    }

    long len = ftell(source);
    if (len < 0) {
        fclose(source);
        return -1;
    }

    if (fseek(source, 0, SEEK_SET) != 0) {
        fclose(source);
        return -1;
    }

    size_t size = (size_t)len;
    char *buffer = malloc(size + 1);
    if (!buffer) {
        fclose(source);
        return -1;
    }

    size_t read = fread(buffer, 1, size, source);
    buffer[read] = '\0';

    fclose(source);

    out->data = buffer;
    out->size = read;
    return 0;
}

void free_source_file(SourceFile *file) {
    if (!file) return;
    free(file->data);
    file->data = NULL;
    file->size = 0;
}
