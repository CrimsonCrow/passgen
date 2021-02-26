#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void usage() {
    printf("Usage:\t./passgen -L 12 -l -u -n -s\n\n");
    printf("options:\n\t-L : length of the password to generate : default to 12\n");
    printf("\t-l : lower case\n");
    printf("\t-u : upper case\n");
    printf("\t-n : numbers\n");
    printf("\t-s : special characters\n");

    printf("\nexamples:\n");
    printf("\t./passgen -lu : will generate password of length 12 with lower case and upper case.\n");
    printf("\t./passgen -L 48 -ns : will generate password of length 48 with numbers and special characters.\n");
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if(argc <= 1) {
        usage();
        return -1;
    }

    char* lower = "qwertyuiopasdfghjklzxcvbnm";
    char* upper = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char* number = "1234567890";
    char* special = "-=!@#$%^&*()_+[]{}\\;':\",./<>?";

    char alpha[101];
    size_t pass_len = 12;

    char ch;

    while((ch = getopt(argc, argv, "lunsL:")) != EOF) {
        switch(ch) {
            case 'l': {
                strcat(alpha, lower);
            } break;
            case 'u': {
                strcat(alpha, upper);
            } break;
            case 'n': {
                strcat(alpha, number);
            } break;
            case 's': {
                strcat(alpha, special);
            } break;
            case 'L': {
                sscanf(optarg, "%zd", &pass_len);
            } break;
            default: {
                fprintf(stderr, "Unknown options: %s\n", optarg);
                usage();
                return -1;
            } break;
        }
    }

    size_t alpha_len = strlen(alpha);
    char pass[pass_len];

    for(size_t i = 0; i < pass_len; ++i) {
        pass[i] = alpha[rand() % alpha_len];
        printf("%c", pass[i]);
    }

    printf("\n");

    return 0;
}
