#include <stdio.h>

//RETURNERA STRÄNGAR!

typedef enum {
    EN,
    SE
} LANG; 

// how NOT to do it:
char *greet(const char *name, LANG lang) {

    char buffer[50];
    if(lang == SE)
        sprintf(buffer, "Hej, %s!", name);
    else
        sprintf(buffer, "Hello, %s!", name);
    return buffer;
}

int main() {
    char *text = greet("Stefan", EN);
    printf("%s\n", text);

    char *text = greet("Stefan", SE);
    printf("%s\n", text);

    return 0;
}

