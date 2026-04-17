


struct Celula{
int valor;
struct Celula *prox;
};

struct Celula * inserir(struct Celula *a){
struct Celula *nova, *aux, *aux2;

nova = (struct Celula *)malloc(sizeof(struct Celula));

if(!nova){
printf("Nao tem memoria disponivel!");

return a;
}

printf("Comece a digitar...");
printf("Qual o valor? ");

scanf("%d", &(nova->valor));

nova->prox = NULL;

if(!a){
    printf("Lista vazia, inserindo o primeiro elemento...");
    return nova;
} else {
    aux = a;
    while(aux->prox <= nova->valor){
        aux = aux->prox;
    }
    nova->prox = aux->prox;
    aux->prox = nova;
}

return a;




int main(){
}