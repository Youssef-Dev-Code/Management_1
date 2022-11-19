#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE_BUFF 256
/*This function returns 0*/
__uint8_t Print_Str(char *str)
{
    if (str == NULL)
    {return 1;}
    __uint8_t i = 0;
    while (str[i] != '\0')
    {
        fputc(str[i], stdout);
        i++;
    }
    return 0;
}
/*maximum of 256 character buff*/
__uint8_t Str_Len(const char *str)
{
    __uint8_t x = 0;
    while (str[x] != '\0')
    {x++;}
    return x;
}
/*This function returns 0 if no errors*/
__uint8_t Str_Cat(char **str1, const char *str2){
    if (*str1 == NULL)
    {return 1;}
    __uint8_t i, j = 0;
    for (i = Str_Len(*str1); i < Str_Len(*str1) + Str_Len(str2); i++)
    {
        (*str1)[i] = str2[j];
        j++;
    }
    return 0;
}
/*
Function variation for array of chars
Returns 1 if the array overflows
*/
__uint8_t Str_a_Cat(char str1[], const char *str2)
{
    if (sizeof(str1) < (Str_Len(str1) + Str_Len(str2)))
    {return 1;}
    __uint8_t i, j = 0;
    for (i = Str_Len(str1); i < Str_Len(str1) + Str_Len(str2); i++)
    {
        str1[i] = str2[j];
        j++;
    }
    return 0;
}
/*This function returns 0 if no errors*/
__uint8_t Str_Cpy(char **str1, const char *str2)
{
    if (*str1 == NULL)
    {return 1;}
    for (__uint8_t i = 0; i < Str_Len(str2); i++)
    {
        (*str1)[i] = str2[i];
    }
    return 0;
}
/*
Function variation for array of chars
Returns 1 if the array overflows
*/
__uint8_t Str_a_Cpy(char str1[], const char *str2)
{
    if (sizeof(str1) < Str_Len(str2))
    {return 1;}
    for (__uint8_t i = 0; i < Str_Len(str2); i++)
    {str1[i] = str2[i];}
    return 0;
}