#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8192

void process_file(FILE *f) {
    char buffer[MAX_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), f)) > 0) {
        fwrite(buffer, 1, bytesRead, stdout);
    }
}

int main(const int argc, char **argv) {
    if (argc >= 2) {
           for (int i = 1; i < argc; i++) { // main concat
                FILE *f = fopen(argv[i], "r");
               if (!f) {
                   perror(argv[i]);
               }
               process_file(f);
                fclose(f);
            }
        fflush(stdout);
        exit(0);
        }
    process_file(stdin);
        exit(0);
}