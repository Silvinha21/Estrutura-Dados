struct Celula{
    int valor;
    struct Celula *prox;
    struct Celula *ant;
};

struct Celula * inserir(struct Celula *cabeca){
    struct Celula *nova, *aux;

    nova = (struct Celula *)malloc(sizeof(struct Celula));

    if(!nova){
        printf("Nao tem memoria disponivel!");
        return cabeca;
    }

    printf("Comece a digitar...");
    printf("Qual o valor? ");
    scanf("%d", &(nova->valor));
    nova->prox = 0;
    nova->ant = 0;

    if(!cabeca){
        printf("Lista vazia, inserindo cabeça...");
        return nova;
    }
    aux = cabeca;
    while(aux->prox){
        aux = aux->prox;
    }
    nova->ant = aux;
    aux->prox = nova;
}