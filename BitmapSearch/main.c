#include <stdio.h>
#include <stdlib.h>


int main()
{
    char arreglo [8]={'a','r',0,'g',0,0,'s',0};
    int bitmap=0b00000000;
    int counter=0;
    int i,j;
    for(j=0;j<8;j++)
    {
        if(arreglo[j]!=0)
        {
            bitmap = bitmap | 0b00000001<<j;
        }
    }
    printf("Valor decimal de bitmap %d",bitmap);
    for(i=0;i<8;i++)
    {
        if((bitmap & 0b00000001)==0b00000000)
        {
            counter++;
            printf("\nMemoria libre en posicion %d",i+1);
        }
        bitmap>>=1;
    }
}
