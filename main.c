#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1048576
int main(const int argc, char **argv) {
    int ch;
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            // flag check
            if (argv[i] && argv[i][0] == '-' || !argv[i+1]) {
                if (argv[i+1] && argv[i+1][0] == '-') {
                    fprintf(stderr, "Usage: %s [options] [file] [options] [file]\n", argv[0]);
                    exit(1);
                }

            }
        }
           for (int i = 1; i < argc; i++) { // main concat
               if (argv[i] && argv[i][0] == '-') {
                    continue;
               }
                FILE *f = fopen(argv[i], "r");
               if (!f) {
                   perror(argv[i]);
                   exit(1);
               }
               char buffer[MAX_SIZE];

               if (setvbuf(f, buffer, _IOFBF, sizeof(buffer)) != 0) {
                   perror("Error setting buffer mode");
                   return 1;
               }
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

    while ((ch = fgetc(stdin)) != EOF) {
            putchar(ch);
        }
        exit(0);
}