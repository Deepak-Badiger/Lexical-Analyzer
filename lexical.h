#ifndef LEXICAL_H
#define LEXICAL_H


typedef struct {
    char file[100];
    char tokens[1000];
    char error[200];
    int filecount;
}Details;

typedef struct {
    Details details[100];
    char keywords[300];
    char symbols[30]; 
    char operater[50];
    int filecount;
    int tokencount;
    int errorcount;
}Lexical;

void lexical_analyzer(Lexical *lexical);
int error_checking_of_numeric_constant(char *buffer);
int error_checking_of_float_constant(char *buffer);
void error_checking_of__identifiers(char *buffer);
void print_the_output(Lexical *lexical);

#endif
