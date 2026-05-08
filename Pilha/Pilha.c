#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int push(int *pilha, int topo){
    if(topo >= MAX){
        printf("Pilha cheia! Impossível empilhar mais elementos.\n");
        return topo;
    }
    printf("Digite um valor para empilhar: ");
    scanf("%d", &pilha[topo]);
    topo++;
    return topo;
}

int pop(int *pilha, int topo){
    if(topo <= 0){
        printf("Pilha vazia! Impossível desempilhar elementos.\n");
        return topo;
    }
    topo--;
    printf("Valor desempilhado: %d\n", pilha[topo]);
    return topo;
}

void imprimirPilha(int *pilha, int topo){
    if(topo<=0){
        printf("Pilha vazia! Impossível imprimir elementos.\n");
    } else {
        printf("===== Elementos =====\n");
        for(int i=topo-1 ; i==0 ; i--){
            printf("%d\n", pilha[i]);
        }
    }
}

int main(){
    int pilha[MAX];
    int t = 0;
    int opcao;
    
    do{
        printf("\n===== Menu =====\n");
        printf("1. Pôr na pilha\n");
        printf("2. Tirar da pilha\n");
        printf("3. imprimir pilha\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            t = push(pilha, t);
            break;
        case 2:
            t = pop(pilha, t);
            break;
        case 3:
            imprimirPilha(pilha, t);
            break;
        case 4:
            printf("Saindo do programa...\n");
            break;
        }
    } while (opcao != 4);
}