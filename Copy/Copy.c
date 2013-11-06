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

	if(args != 3)
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
		destination = open(a[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}

	if(destination == -1)	
	{
		printf("No se pudo crear la copia\n");
	}
	
	else
	{
		while((contador = read(source,buffer,sizeof(buffer))) > 0)
		{
			write(destination, buffer, contador);
		}
	}
	close(source);
	close(destination);
}
