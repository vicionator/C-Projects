#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int args, char *a[])
{
	char buffer[8192];
	int source;
	int destination;
	int contador;

	if(args != 2)
	{
		printf("Algo no esta bien con sus argumentos\n"); 
	}
	
	else
	{
		source = open(a[1], O_RDONLY);
	}

	if(source == -1)
	{
		printf("No se puede abrir el archivo\n");
	}

	else
	{
		unlink(a[1]);
	}
	close(source);
}
