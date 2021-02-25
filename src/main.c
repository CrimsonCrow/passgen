#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

void usage() {
    printf("Usage:\t./passgen --length 12\n\n");
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    size_t pass_len = 12;

    if(argc <= 1) {
        usage();
        printf("This will generate a secure password with a default length of 12\n\n");
    } else if(!(strcmp(argv[1], "--length"))) {
        /*pass_len = atoi(argv[2]);*/
        sscanf(argv[2], "%zd", &pass_len);
    } else {
        usage();
        return -1;
    }

    /*
    char* lower = "qwertyuiopasdfghjklzxcvbnm";
    char* upper = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char* number = "1234567890";
    char* special = "-=!@#$%^&*()_+";
    */

    char* alpha = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890-=!@#$%^&*()_+[]{}\\;':\",./<>?";
    size_t alpha_len = strlen(alpha);

    char pass[pass_len];

    for(size_t i = 0; i < pass_len; ++i) {
        pass[i] = alpha[rand() % alpha_len];
        printf("%c", pass[i]);
    }

    printf("\n");

    return 0;
}
