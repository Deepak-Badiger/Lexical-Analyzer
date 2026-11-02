#include<stdio.h>
#include "lexical.h"
#include<string.h>

int main()
{
    FILE *fp = fopen("test.c" , "r");
    if(fp == NULL)
    {
        perror("");
        return 1;
    }

    Lexical lexical;
    lexical.filecount = 0;

    while(fscanf(fp , " %[^\n]",lexical.details[lexical.filecount].file) == 1)
    {
        strcat(lexical.details[lexical.filecount].file , "\n");
        lexical.filecount++;
    }

    // fscanf(fp , "%[^\n]\n",lexical.file);
    //printf("size of file -> %lu\n", ftell(fp));

    // for(int i = 0 ; i < lexical.filecount ; i++)
    // {
    //     printf("%s",lexical.details[i].file);
    // }

    fclose(fp);


    lexical_analyzer(&lexical);
    print_the_output(&lexical);

    

}