#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8192
int main(const int argc, char **argv) {
    if (argc >= 2) {
           for (int i = 1; i < argc; i++) { // main concat
                FILE *f = fopen(argv[i], "r");
               if (!f) {
                   perror(argv[i]);
                   exit(1);
               }
               char buffer[MAX_SIZE];
               size_t bytesRead;

               while ((bytesRead = fread(buffer, 1, sizeof(buffer), f)) > 0) {
                   fwrite(buffer, 1, bytesRead, stdout);
               }
               fflush(stdout);
                fclose(f);
            }
        exit(0);
        }
    // fallback for no args
    int ch;
    while ((ch = fgetc(stdin)) != EOF) {
            putchar(ch);
        }
        exit(0);
}