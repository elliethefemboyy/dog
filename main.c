#include <stdio.h>
int main(int argc, char **argv) {
    int ch;
    if (argc >= 2) {
        FILE *f;
        for (int i = 1; i < argc; i++) {
            if (argv[i] && argv[i][0] == '-') {
                fprintf(stderr, "Flags not implemented\n");
                return 1;
            }
            else {
                f = fopen(argv[i], "r");
                if (!f) {
                    perror(argv[i]);
                    return 1;
                }
                while ((ch = fgetc(f)) != EOF) {
                    putchar(ch);
                }
                fclose(f);
            }
        }
        return 0;
    }
    // fallback for no args
        while ((ch = fgetc(stdin)) != EOF) {
            putchar(ch);
        }
        return 0;
}