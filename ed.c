#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<unistd.h>
// essa ultima biblioteca serve somente pra tirar o warning do "sleep"
typedef struct {
  int codigo;
  char nome[20];
  float preco;
}produto;

typedef struct nodo{
  produto info;
  struct nodo *next;
  struct nodo *prev;
}nodo;

typedef struct lista{
  int nItens;
  nodo *first;
  nodo *last;
}lista;

nodo *inserir(int *j,nodo *n,lista *hue){
  nodo *u;
  u=(nodo *)calloc(1,sizeof(nodo));
  printf("Digite o código do produto :\n");
  scanf("%d",&u->info.codigo);
  getchar();
  printf("Digite o nome do produto :\n");
  fgets(u->info.nome,20,stdin);
  printf("Digite o preço do produto :\n");
  scanf("%f",&u->info.preco);
  if(*j == 0){
    u->next=NULL;
    u->prev=NULL;
    hue->first=u;
    hue->last=u;
    (*j)++;

  }else{
    u->next=NULL;
    u->prev=n;
    n->next=u;
    hue->last=u;
    (*j)++;
  }
  system("clear");
  printf("Produto cadastrado!\n");
  sleep(3);
  system("clear");
  return(u);

}
void exibir(nodo *j,int *x){
  system("clear");
  if(*x == 0){
    printf("Lista vazia!\n");
  }else{
    for(;j != NULL;j=j->prev){
      printf("Código : %d\n",j->info.codigo);
      printf("Nome : %s",j->info.nome);
      printf("Preço : %.3f\n\n",j->info.preco);
    }
    sleep(3);
    system("clear");
  }
}
nodo *excluir(int *j,nodo *n,lista *hue){
  system("clear");
  if(*j == 0){
    printf("Lista Vazia!\n");
    sleep(3);
    n=NULL;
    return(n);
  }
  if(*j == 1){
    n=NULL;
    printf("Excluido!\n");
    sleep(3);
    system("clear");
    (*j)--;
    hue->last=NULL;
    hue->first=NULL;
    return(n);
  }
  if(*j == 2){
    int x,contador=0;
    printf("Digite o código do produto para excluir:\n");
    scanf("%d",&x);
    for(;n->info.codigo != x;n=n->next){
      contador++;
    }//o erro começa aqui
    if(contador == 0){
      n=n->next;
      hue->first=n;
      hue->last=n;
      (*j)--;
      n->prev=NULL;
      printf("Excluido!\n");
      return(n);
    }else{
       n=n->prev;
       n->prev=NULL;
       n->next=NULL;
       hue->first=n;
       hue->last=n;
       (*j)--;
       printf("Excluido!\n");
       return(n);

    }
  }
}
int main(){
  lista cabeca;
  cabeca.nItens=0;
  int *j;
  lista *hue;
  hue=&cabeca;
  j=&cabeca.nItens;
  nodo *n,*u;
  int x;
  do{
    printf("\t\tMENU\nInserir : 1\nExcluir : 2\nExibir : 3\nSair : 0\n");
    scanf("%d",&x);
    switch (x) {
      case 1:
        n=inserir(j,n,hue);
        break;
      case 2:
        n=excluir(j,n,hue);
        break;
      case 3:
        exibir(n,j);
        break;
      case 0:
        break;
      default:
        printf("Opção invalida\n");
        break;
    }

  }while(x != 0);



}
