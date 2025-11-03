#include <stdio.h>

//RETURNERA STRÄNGAR!

typedef enum {
    ENGLISH,
    SWEDISH
} LANG;  


int *add(){
    int result;
    result = 12;
    return &result;
}


// RETURNERA DYNAMISKT ALLOKERAD STRÄNG (HEAP)
char *greetheap(const char *name, LANG lang) {
    char *texten = malloc(100 * sizeof(char));
    if(lang == SWEDISH)
        sprintf(texten, "Hej, %s!", name);
    else
        sprintf(texten, "Hello, %s!", name);
}

 
// OM DET ÄR EN STACKALLOKERAD STRÄNG KOMMER DEN FÖRSTÖRAS NÄR FUNKTIONEN AVSLUTAS
// ALDRIG RETURNERA EN POINTER TILL EN STACKALLOKERAD STRÄNG!
void greet(const char *name, LANG lang, char *texten) {

    if(lang == SWEDISH)
        sprintf(texten, "Hej, %s!", name);
    else
        sprintf(texten, "Hello, %s!", name);
}

typedef enum {
    ERROR_OK,
    ERROR_INVALID_LANGUAGE,
    ERROR_NAME_TOO_LONG
} ERRORS;

char *getErrorString(ERRORS err) {
    switch(err) {
        case ERROR_OK:
            return "No error."; // LIGGER I KONSTANT DATA SEGMENTET  - EJ I STACKWN
        case ERROR_INVALID_LANGUAGE:
            return "Invalid language specified.";
        case ERROR_NAME_TOO_LONG:
            return "The provided name is too long.";
        default:
            return "Unknown error.";
    }
}


int main() {
    char *errorMsg = getErrorString(ERROR_NAME_TOO_LONG);
    printf("Error message: %s\n", errorMsg);

    // char *heapstr = greetheap("Stefan", ENGLISH);
    // printf("%s\n", heapstr);
    // free(heapstr);

    char texten[100];
    greet("Stefan", ENGLISH, texten);
    printf("%s\n", texten);

    greet("Stefan", SWEDISH,texten);
    printf("%s\n", texten);

    return 0;
}

