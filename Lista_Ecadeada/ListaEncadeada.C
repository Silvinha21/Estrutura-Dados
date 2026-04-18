


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
        while (aux->prox && aux->prox->valor < nova->valor){
            aux = aux->prox;
        }
        nova->prox = aux->prox;
        aux->prox = nova;
    }
}

return cabeca;


}

int main(){

}