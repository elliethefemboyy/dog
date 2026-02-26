#include <stdio.h>
int main(int argc, char **argv) {
    FILE *f;
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            if (i == 1 && argv[i][0] == '-') {
                fprintf(stderr, "Flags not implemented");
                return 1;
            }
            else {
                f = fopen(argv[i], "r");
                if (!f) {
                    perror(argv[i]);
                    return 1;
                }
                int ch;
                while ((ch = fgetc(f)) != EOF) {
                    putchar(ch);
                }
            }
        }
        return 0;
    }
    else {
        int ch;
        while ((ch = fgetc(stdin)) != EOF) {
            putchar(ch);
        }
        return 1;
    }
}