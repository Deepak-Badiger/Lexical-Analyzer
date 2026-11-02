#include<stdio.h>
#include "lexical.h"
#include<string.h>
#include<ctype.h>

void print_the_output(Lexical *lexical)
{
    if(lexical->errorcount != 0)
    {
        for(int i = 0 ; i < lexical->errorcount ; i++)
        {
            printf("%s\n",lexical->details[i].error);
        }
    }
    else
    {
        for(int i = 0 ; i < lexical->tokencount ; i++)
        {
            printf("%s\n",lexical->details[i].tokens);
        }
    }
    
}