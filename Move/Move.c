#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int args, char *a[])
{
	char buffer[8192];
	char path[8192];
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
		strcat(path,a[2]);
		strcat(path,"/");
		strcat(path,a[1]);
		destination = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}

	if(destination == -1)	
	{
		printf("No se pudo mover el archivo\n");
	}
	
	else
	{
		while((contador = read(source,buffer,sizeof(buffer))) > 0)
		{
			write(destination, buffer, contador);
		}
		unlink(a[1]);
	}
	close(source);
	close(destination);
}
