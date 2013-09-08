#include <stdio.h>
#include <stdlib.h>


int main()
{
int c,i,n=0;
char na[8192];
FILE *archivo;
archivo = fopen("Text.txt", "r");
if (archivo)
{
    while ((c = fgetc(archivo)) != EOF)
    {
       na[n]=c;
       n++;
    }
    }
    for(i =0; i<n; i++)
    {
        if(na[i]=='/')
        {
            i++;
            if(na[i]=='*')
            {
                i++;
                while(na[i] != '/')
                {
                    i++;
                }
            }
            else if(na[i]=='/')
            {
                i++;
                while(na[i] != '\n')
                {
                    i++;
                }
            }
            else
            {
            i--;
            putchar(na[i]);
            }
        }
        else{
        putchar(na[i]);
        }
    }
    return 0;

}
