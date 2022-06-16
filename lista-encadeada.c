#include<stdio.h>

struct lista
{
	int valor;
	struct lista *prox; /*prox é o ponteiro que aponta para dados do tipo struct lista*/
};

typedef struct lista TLista; /*define a variavel struct lista como TLista*/
typedef struct {TLista *inicio; TLista *final; int qtde;} TDescritor;

void ImprimeLista(TDescritor d)
{
	TLista *aux;

	printf("\n\n\nConteudo da lista:\n");
	aux=d.inicio;
	
	while(aux!=NULL)
	{
		printf("%d\n", aux->valor);
		aux=aux->prox;
	}

	printf("\n\t%d Elemento(s)", d.qtde);
}

void ExcluiElemento(TDescritor *d, TLista *aux, TLista *ant)
{
	if (ant == NULL)
		d->inicio=aux->prox;
	else
		ant->prox=aux->prox;
		
	free(aux);
	d->qtde=d->qtde-1;
}

int IncluirElemento(int valor, TDescritor *d)
{
	TLista *aux;
		
	aux=(TLista*)malloc(sizeof(TLista));/*aloca quantidade de bytes do mesmo tamanho de TLista e passa o endereço p aux*/
	
	aux->valor = valor;
	aux->prox = NULL;
	
	if(d->inicio==NULL)
		d->inicio=aux;
	else
		d->final->prox=aux;

	d->final = aux;
	d->qtde++;
	
	return aux;
}


int main (void)
{
	int valorinfo=0, elementos=1,Maior=0;
	TDescritor descritor;
	TLista *aux, *ant;
	descritor.inicio=NULL;
	descritor.final=NULL;
	descritor.qtde=0;

	
	while (valorinfo != -999)
	{
		printf("Informe o valor: \n");
		scanf("%d", &valorinfo);
		
		if (valorinfo != -999)
			if (IncluirElemento(valorinfo, &descritor) == NULL)
				printf("Memoria insuficiente");
	}
	if (descritor.qtde>0)
		ImprimeLista(descritor);
	else
		printf("\n\nLista Vazia");
	valorinfo = 0;	

	while(valorinfo!= -999)
	{
		printf("\n\nInforme o valor a excluir: ");
		scanf("%d", &valorinfo);
		
		if(valorinfo != -999)
		{
			aux = descritor.inicio;
			ant = NULL;
			
			while(aux!=NULL && aux->valor != valorinfo)
			{
				ant=aux;
				aux=aux->prox;
			}
			
			if (aux==NULL)
			{
				printf("\nValor nao existe na lista");
				if (descritor.qtde>0)
					ImprimeLista(descritor);
				else
					printf("\n\nLista Vazia");
			}
			else
			{
				ExcluiElemento(&descritor, aux, ant);
				if (descritor.qtde>0)
					ImprimeLista(descritor);
				else
					printf("\n\nLista Vazia");
			}
		}
	}
	return 0;
}