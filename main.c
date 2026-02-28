#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8192

void process_file(FILE *f) {
    char *buffer = malloc(MAX_SIZE);
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, MAX_SIZE, f)) > 0) {
        fwrite(buffer, 1, bytesRead, stdout);
    }
    free(buffer);
}

int main(const int argc, const char *argv[]) {
    if (argc >= 2) {
        int failures = 0;
        for (int i = 1; i < argc; i++) { // main concat
            FILE *f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[i]);
                failures++;
                continue;
            }
            process_file(f);
            fclose(f);
        }
        if (failures > 0) {
            return 1;
        }
        return 0;
    }
    process_file(stdin);
        return 0;
}