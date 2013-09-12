#include <stdio.h>
#include <stdlib.h>


unsigned char memoria[8192];

typedef struct Nodo
{
    struct Nodo *siguiente;

    unsigned Tam;
}Node;



static Node *root;

void *memalloc(size_t ta)
{
  void *L;
  if(root==0)
 {
     root = (Node*) &memoria[0];
     root->Tam = ta;
     L=(void*)((unsigned)root+sizeof(Node));
 }
 else
 {
     Node *temp=root;
     int cambio = 0;

     while(temp->siguiente != 0)
     {
         if(temp->Tam == 0 && ((unsigned)temp->siguiente-((unsigned)temp + sizeof(Node) == ta)))
         {
            //printf("%d\n",temp->siguiente);
            //printf("%d\n",ta);
            //printf("%d\n",sizeof(Node));
             cambio=1;
             break;
         }
          temp=temp->siguiente;
          //printf("%d\n",temp->Tam);
          if(temp->Tam == 0)
          {
              //printf("%d\n",temp);
              //printf("HOLA\n");
              cambio=1;
              break;
          }

    }
     if(cambio==1)
     {
        //printf("%d\n",temp);
        temp->Tam=ta;
        //printf("%d\n",temp->siguiente);

         L=(void*)((unsigned)temp+sizeof(Node));
     }
     else
     {
     unsigned nuevo =((unsigned)temp+sizeof(Node)+ temp->Tam);

     if((nuevo+sizeof(Node)+ta-1)<((unsigned)root+sizeof(memoria)))
     {
      temp->siguiente = (Node*) nuevo;
      temp->siguiente->Tam=ta;
      L=(void*)((unsigned)temp->siguiente+sizeof(Node));
     }
     else
     {
        L=NULL;
     }
     }
}
 return L;
}
void *mefree(void *punt)
{
    Node *T=root;
    //printf("%d\n", T);
    while(T != punt)
    {
        T=(Node*)((unsigned)T+sizeof(Node));
            //printf("%d\n", T);
            //printf("%d\n", punt);
        if(T != punt)
        {
			T = (Node*) ((unsigned)T-sizeof(Node));
			T = T->siguiente;
        }
    }
    //printf("%d\n",T);
    T = (Node*) ((unsigned)T-sizeof(Node));
	T->Tam = 0;
	//printf("%d\n",T);
}
int main()
{
    int *P = memalloc(sizeof(int));
    *P=4;
    printf("%d %d\n",(unsigned) P, *P);
    int *X = memalloc(sizeof(int));
    *X=10;
    printf("%d %d\n",(unsigned) X, *X);
    int *R = memalloc(sizeof(int));
    *R=6;
    printf("%d %d\n",(unsigned) R, *R);

    mefree(P);
    mefree(R);

    int *Y = memalloc(sizeof(int));
    *Y=1;
    int *J= memalloc(sizeof(int));
    *J=5;

    printf("\n");
    printf("Nuevos Valores\n");
    printf("%d %d\n",(unsigned) P, *P);
    printf("%d %d\n",(unsigned) X, *X);
    printf("%d %d\n",(unsigned) R, *R);
    printf("\n");
    printf("Valores sustituido en memoria = %d, %d\n",*Y,*J);

    return 0;
}
