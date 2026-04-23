#include <stdio.h>
#include <stdlib.h>


struct Celula{
int valor;
struct Celula *prox;
};

struct Celula * inserir(struct Celula *cabeca){
struct Celula *nova, *aux, *aux2;

nova = (struct Celula *)malloc(sizeof(struct Celula));

if(!nova){
    printf("Nao tem memoria disponivel!");

return cabeca;
}

printf("Comece a digitar...");
printf("Qual o valor? ");

scanf("%d", &(nova->valor));

nova->prox = 0;

if(!cabeca){
    printf("Lista vazia, inserindo o primeiro elemento...");
    return nova;
} else {
    aux = cabeca;
    if (aux->valor > nova->valor){
        nova->prox = aux;
        return nova;
    } else {
        // se pá que esse bagui tem algum buraco que eu não vi, mas como não consigo executar vai ficar assim mesmo
        while (aux->prox && aux->prox->valor < nova->valor){
            aux = aux->prox;
        }
        if(!aux->prox){
            nova->prox = 0;
            aux->prox = nova;
        } else {
            nova->prox = aux->prox;
            aux->prox = nova;
        }
    }
}
return cabeca;
}


struct Celula * remover(struct Celula *cabeca){
    struct Celula *aux;
    int valor;

    printf("Qual valor deseja remover? ");
    scanf("%d", &valor);

    if(!cabeca){
        printf("Lista vazia, nada para remover!");
        return cabeca;
    } else if (cabeca->valor == valor)
    {
        cabeca = cabeca->prox;
        return cabeca;
    }
    
    aux = cabeca;
    while(aux->prox && aux->prox->valor != valor){
        aux = aux->prox;
    } 
    if(!aux->prox){
        printf("Valor nao encontrado!");
        return cabeca;
    } else {
        aux->prox = aux->prox->prox;
        return cabeca;
    }
    
}



void imprimir(struct Celula *cabeca){
    struct Celula *aux;

    if(!cabeca){
        printf("Lista vazia!");
    } else {
        aux = cabeca;
        while(aux){
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }
}


int main(){
    struct Celula *cabeca = 0;
    int opcao;

    do{
        printf("\n1 - Inserir");
        printf("\n2 - Remover");
        printf("\n3 - Imprimir");
        printf("\n4 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cabeca = inserir(cabeca);
            break;
        
        case 2:
            cabeca = remover(cabeca);
            break;

        case 3:
            imprimir(cabeca);
            break;

        case 4:
            printf("Saindo...");
            break;

        default:
            printf("Opcao invalida!");
            break;
        }
    } while (opcao != 4);
}