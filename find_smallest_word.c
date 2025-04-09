%{
    #include <stdio.h>
    #include <string.h>
    
    #define MAX_WORD_LENGTH 100
    
    char smallest_word[MAX_WORD_LENGTH];
    int smallest_length = MAX_WORD_LENGTH;
    
    %}
    
    %%
    
    [a-zA-Z]+ {
        int len = strlen(yytext);
        if (len < smallest_length) {
            smallest_length = len;
            strncpy(smallest_word, yytext, MAX_WORD_LENGTH - 1);
            smallest_word[MAX_WORD_LENGTH - 1] = '\0';  
        }
    }
    
    .|\n { }
    
    %%
    
    int main() {
        smallest_word[0] = '\0';
        smallest_length = MAX_WORD_LENGTH;
    
        yylex();
    
        if (smallest_length < MAX_WORD_LENGTH) {
            printf("Smallest word: %s\n", smallest_word);
        } else {
            printf("No words found.\n");
        }
    
        return 0;
    }