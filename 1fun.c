#include<stdio.h>
#include "lexical.h"
#include<string.h>
#include<ctype.h>


void lexical_analyzer(Lexical *lexical)
{
    strcpy(lexical->keywords ,"auto break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while");
    strcpy(lexical->symbols ,"{}[]():;,");
    strcpy(lexical->operater ,"=+-*/++--||&&~+=-=/=");
    lexical->errorcount = 0;
    char buffer[20];
    int i , flowerbraces = 0 , squarbraket = 0 , bracess = 0 , single = 0;
    for(i = 0 ; i < lexical->filecount ; i++)
    {
        int filecount = 0;
         
        while(lexical->details[i].file[filecount] != '\n')
        {
            if(lexical->details[i].file[filecount] == '{')
               flowerbraces++;
            if(lexical->details[i].file[filecount] == '}')
                flowerbraces--;
            if(lexical->details[i].file[filecount] == '[')
               squarbraket++;
            if(lexical->details[i].file[filecount] == ']')
                squarbraket--;
            if(lexical->details[i].file[filecount] == '(')
               bracess++;
            if(lexical->details[i].file[filecount] == ')')
                bracess--;

             //to check the single coates or open and closed correctly
            if(lexical->details[i].file[filecount] == '\'')
                single++;

            if(lexical->details[i].file[filecount] == '#') // to skip the #include<stdio.h>
                break;
        
            if(lexical->details[i].file[filecount] == '/' && lexical->details[i].file[filecount + 1] == '/')  // to skip the single line comments
                break;
            
            int bcount = 0;
            //if there is space skip the iteration and continue the operation 
            if(lexical->details[i].file[filecount] == ' ' )
            {
                filecount++;
                continue;
            }
      
            // to check it is character constant or not
            else if(lexical->details[i].file[filecount - 1] == '\'' && lexical->details[i].file[filecount + 1] == '\'')
            {
                sprintf(lexical->details[lexical->tokencount].tokens,"Char const : %c",lexical->details[i].file[filecount]);
                lexical->tokencount++;   
                filecount++;
            }
            // to check it is a keyworld or identifiers
            else if( isalpha(lexical->details[i].file[filecount]))
            {   
                while(isalnum(lexical->details[i].file[filecount]))
                {
                    buffer[bcount] = lexical->details[i].file[filecount];
                    filecount++;
                    bcount++;
                }
                if(bcount)
                {
                    buffer[bcount] = '\0';
                    if(strstr(lexical->keywords , buffer) != NULL)
                        sprintf(lexical->details[lexical->tokencount].tokens,"Keyworld : %s",buffer);
                    else
                        sprintf(lexical->details[lexical->tokencount].tokens,"Identifier : %s",buffer);
                    lexical->tokencount++;
                }
            }
             // to check it is a numeric conatant or float constant 
            else if((lexical->details[i].file[filecount] >= '0' && lexical->details[i].file[filecount] <= '9') || lexical->details[i].file[filecount] == '.' || isalpha(lexical->details[i].file[filecount]))
            {
                bcount = 0;    
                while((lexical->details[i].file[filecount] >= '0' && lexical->details[i].file[filecount] <= '9') || lexical->details[i].file[filecount] == '.' || isalpha(lexical->details[i].file[filecount]))
                {
                    buffer[bcount] = lexical->details[i].file[filecount];
                    filecount++;
                    bcount++;
                }
                buffer[bcount] = '\0';
                if(strchr(buffer , '.'))
                {
                    if(error_checking_of_float_constant(buffer))
                    {
                        sprintf(lexical->details[lexical->errorcount].error,"\033[1;33mtest.c\033[0m line %d:\033[1;31m error \033[0m :\033[1;34m %s \033[0m invalid float constant",i+1,buffer);
                        lexical->errorcount++;
                    }
                    sprintf(lexical->details[lexical->tokencount].tokens,"Float const : %s",buffer);
                }
                else
                {
                    if(error_checking_of_numeric_constant(buffer))
                    {
                        sprintf(lexical->details[lexical->errorcount].error,"\033[1;33mtest.c\033[0m line %d:\033[1;31m error \033[0m :\033[1;34m %s \033[0m invalid numeric constant",i+1,buffer);
                        lexical->errorcount++;
                    }
                    sprintf(lexical->details[lexical->tokencount].tokens,"Numeric const : %s",buffer);
                }
                    
                
                lexical->tokencount++;
            }
            // to check it is a symbols or not
            else if((strchr(lexical->symbols , lexical->details[i].file[filecount])) != NULL)
            {
                sprintf(lexical->details[lexical->tokencount].tokens,"Symbols : %c",lexical->details[i].file[filecount]);
                lexical->tokencount++;
                filecount++;
            }
            
            // to check it is a operator or not
            else if(strchr(lexical->operater,lexical->details[i].file[filecount]))
            {
                bcount = 0;
                while(strchr(lexical->operater,lexical->details[i].file[filecount]))
                {
                    buffer[bcount] = lexical->details[i].file[filecount];
                    filecount++;
                    bcount++;
                }
                buffer[bcount] = '\0';
                sprintf(lexical->details[lexical->tokencount].tokens,"Operator : %s",buffer);
                lexical->tokencount++;
                
            }
            // to check it is a Literal or not
            else if(lexical->operater,lexical->details[i].file[filecount] == '\"')
            {
                bcount = 0;
                buffer[bcount] = lexical->details[i].file[filecount];
                bcount++;   
                filecount++;
                while(lexical->details[i].file[filecount] != '\"' && lexical->details[i].file[filecount] != ';')
                {
                    buffer[bcount] = lexical->details[i].file[filecount];
                    bcount++;   
                    filecount++;
                }
                if(lexical->details[i].file[filecount] == ';')
                {
                    buffer[bcount] = '\0';
                    sprintf(lexical->details[lexical->errorcount].error,"\033[1;33mtest.c\033[0m line %d:\033[1;31m error \033[0m :\033[1;34m %s \033[0m missing terminating \" character",i+1,buffer);
                    lexical->errorcount++;
                    continue;  
                }
                buffer[bcount] = lexical->details[i].file[filecount];
                bcount++;   
                filecount++;
                buffer[bcount] = '\0';
                sprintf(lexical->details[lexical->tokencount].tokens,"Litaral : %s",buffer);
                lexical->tokencount++;
            }
            else
                filecount++;

            


            
        }
        if(squarbraket != 0)
        {
                sprintf(lexical->details[lexical->errorcount].error,"\033[1;33mtest.c\033[0m line %d:\033[1;31m error \033[0m :\033[1;34m '%c' \033[0m expected indentifier ",i+1,']');
                lexical->errorcount++;
                squarbraket = 0;
        }
        if(bracess != 0)
        {
            sprintf(lexical->details[lexical->errorcount].error,"\033[1;33mtest.c\033[0m line %d:\033[1;31m error \033[0m :\033[1;34m '%c' \033[0m expected indentifier",i+1,')');
            lexical->errorcount++;
            bracess = 0;
        }

         //to check the single coates or open and closed correctly
        if(single % 2 != 0 && single != 0)
        {
            sprintf(lexical->details[lexical->errorcount].error,"\033[1;33mtest.c\033[0m line %d:\033[1;31m error \033[0m : missing terminating ' character",i+1);
            lexical->errorcount++;
            filecount++;
            single = 0;
        }
        

       
    }

     if(flowerbraces != 0)
    {
        sprintf(lexical->details[lexical->errorcount].error,"\033[1;33mtest.c\033[0m line %d:\033[1;31m error \033[0m :\033[1;34m '%c' \033[0m expected indentifier ",i+1,'}');
        lexical->errorcount++;
    }

    
        
        
        
}