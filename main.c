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

int main(const int argc, const char *argv[]) {
    if (argc >= 2) {
        int failures = 0;
           for (int i = 1; i < argc; i++) { // main concat
                FILE *f = fopen(argv[i], "r");
               if (!f) {
                   perror(argv[i]);
                   failures++;
                   fclose(f);
                   continue;
               }
               process_file(f);
                fclose(f);
            }
        if (failures > 0) {
          exit(0);
        }
       exit(1);
        }
    process_file(stdin);
        exit(0);
}