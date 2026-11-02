#include<stdio.h>
#include "lexical.h"
#include<string.h>
#include<ctype.h>

int error_checking_of_numeric_constant(char *buffer)
{
    if(*buffer == '0' && (*(buffer+1) == 'x' || *(buffer+1) == 'X'))
    {
        buffer += 2;
        while(*buffer)
        {
            if(isxdigit(*buffer))
             buffer++;
            else
            {
                //printf("invalid hex number");
                return 1;
            }
        }
        return 0;
    } 

    else if(*buffer == '0' && (*(buffer+1) == 'b' || *(buffer+1) == 'B'))
    {
        buffer += 2;
        while(*buffer)
        {
            if(*buffer == '0' || *buffer == '1')
             buffer++;
            else
            {
                //printf("invalid binary number");
                return 1;
            }
        }

        return 0;
    }
    
    else if(*buffer == '0')
    {
        while(*buffer)
        {
            if(*buffer >= '0' && *buffer <= '7')
             buffer++;
            else
            {
                //printf("invalid octal number");
                return 1;
            }
        }

        return 0;
    }

    else if(*buffer >= '0' && *buffer <= '9')
    {
        while(*buffer)
        {
            if(*buffer >= '0' && *buffer <= '9')
             buffer++;
            else
            {
                //printf("invalid number\n");
                return 1;
            }
        }
        return 0;
    }
}

int error_checking_of_float_constant(char *buffer)
{
    while(*buffer)
    {
        if((*buffer >= '0' && *buffer <= '9') || *buffer == 'f' || *buffer == 'F' || *buffer == '.')
        buffer++;
        else
        return 1;
    }

    return 0;
}
