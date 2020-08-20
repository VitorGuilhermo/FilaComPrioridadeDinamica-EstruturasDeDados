struct TpFilaPrioridadeDinamica{
    char elemento;
    int prioridade;
    TpFilaPrioridadeDinamica *prox;
};
struct TpDescritor{
    TpFilaPrioridadeDinamica *inicio, *fim;
};

void inicializar(TpDescritor &desc){
    desc.inicio = desc.fim = NULL;
}

TpFilaPrioridadeDinamica *novaCaixa(char elemento, int prioridade){
    TpFilaPrioridadeDinamica *caixa = new TpFilaPrioridadeDinamica;

    caixa->elemento = elemento;
    caixa->prioridade = prioridade;
    caixa->prox = NULL;
    return caixa;
}

void inserir(TpDescritor &desc, char elemento, int prioridade){
    TpFilaPrioridadeDinamica *nc, *aux;

    nc = novaCaixa(elemento, prioridade);

    if(desc.inicio == NULL)
        desc.inicio = desc.fim =nc;
    else if(prioridade < desc.inicio->prioridade){//insere no inicio
        nc->prox = desc.inicio;
        desc.inicio = nc;
    }
    else{
        //faz o remanejamento adequado
        aux = desc.inicio;
        while(aux->prox != NULL && prioridade >= aux->prox->prioridade)
            aux = aux->prox;

        nc->prox = aux->prox;
        aux->prox = nc;

        if(nc->prox == NULL)
            desc.fim = nc;
    }

}

void retirar(TpDescritor &desc){
    TpFilaPrioridadeDinamica *aux;
    if(desc.inicio != NULL){
        aux = desc.inicio;
        desc.inicio = desc.inicio->prox;
        delete(aux);
    }
}

void exibir(TpDescritor &desc){
    TpFilaPrioridadeDinamica *aux;

    aux = desc.inicio;
    while(aux != NULL){
        printf("\t%c - %d", aux->elemento, aux->prioridade);
        aux = aux->prox;
    }
}






