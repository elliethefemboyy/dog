#include <stdio.h>
int main(int argc, char **argv) {
    if (argc >= 3) {
        for (int i = 1; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[1]);
                return 1;
            }
            int ch;
            while ((ch = fgetc(f)) != EOF) {
                putchar(ch);
            }

        }
        return 0;
    }
    else if (argc == 1) {
        int ch;
        while ((ch = fgetc(stdin)) != EOF) {
            putchar(ch);
        }
        return 1;
    }
    else {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            perror(argv[1]);
            return 1;
        }
        int ch;
        while ((ch = fgetc(f)) != EOF) {
            putchar(ch);
        }
    }
}
