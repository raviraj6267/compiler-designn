%{
    #include <stdio.h>
    #include <string.h>
    
    void reverse(char *str) {
        int n = strlen(str);
        for (int i = 0; i < n / 2; i++) {
            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }
    }
    %}
    
    %%
    
    [a-zA-Z]+ {
        char word[100]; 
        strncpy(word, yytext, yyleng);
        word[yyleng] = '\0';
        reverse(word);
        printf("%s ", word);
    }
    
    [ \t\n]+ {
        printf("%s", yytext);
    }
    
    . {}
    
    %%
    
    int main(int argc, char **argv) {
        yylex();
        return 0;
    }