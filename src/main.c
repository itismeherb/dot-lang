#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Please specify the file you want to compile.\n");
        return -1;
    }
    return 0;
}
