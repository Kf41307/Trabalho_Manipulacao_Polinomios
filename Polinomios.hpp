#include <iostream>
using namespace std;

struct No{
    float coefNum;
    int expoente;
    No* proximo;
};

struct Polinomio{
    No* primeiro;
    No* ultimo;
};

void inicializar(Polinomio &lista){
    lista.primeiro=NULL;
    lista.ultimo=NULL;
}

bool inserirFinal(Polinomio &lista, float coefNum, int expoente){
    No *novoMonomio = new No;
    
    novoMonomio->proximo = NULL;
    novoMonomio->coefNum = coefNum;
    novoMonomio->expoente = expoente;
    
    if(lista.primeiro == NULL){ //Caso a lista não tenha nenhum elemento
        lista.primeiro = novoMonomio;
        lista.ultimo = novoMonomio;
        return true;
    }else{ //Se ja tiver algum elemento coloca depois de onde o ponteiro ultimo aponta e aponta o antigo ultimo para o novo ultimo
        lista.ultimo->proximo = novoMonomio;
        lista.ultimo = novoMonomio;
        return true;
    }
    return false;
}

bool inserirOrdem(Polinomio &lista, float coefNum, int expoente){ //Falta adicionar o caso de inserir monomio de mesmo grau
    No* atual = lista.primeiro;
    No* anterior = NULL;
    

    if(lista.primeiro == NULL){ // Se a lista nao tiver nenhum elemento
        return inserirFinal(lista, coefNum, expoente);
    }else if(expoente > lista.primeiro->expoente){ //Se o expoente do adicionado for maior que o primeiro
        No* novoMonomio = new No;

        novoMonomio->expoente = expoente;
        novoMonomio->coefNum = coefNum;
        
        novoMonomio->proximo = lista.primeiro;
        lista.primeiro = novoMonomio;

        return true;
    }else if(expoente < lista.ultimo->expoente){ // Se o expoente for menor que o ultimo coloca ele no final
            return inserirFinal(lista, coefNum, expoente);
    }else{ //Se nao entrou em nenhuma das condições acima significa que a inserção será no meio de dois elementos
        while(atual != NULL){
            if((expoente < anterior->expoente) && (expoente > atual->expoente)){
                No* novoMonomio = new No;
            
                novoMonomio->expoente = expoente;
                novoMonomio->coefNum = coefNum;   
                 
                anterior->proximo = novoMonomio;
                novoMonomio->proximo = atual;
                return true;
            }else if(expoente == atual->expoente){
                // funcao SOMAR(auxliar.coef, coefNum)
            }

            anterior = atual;
            atual = atual->proximo;
        }
    }
    return false;
}

void liberar(Polinomio &lista){
    No* auxiliar = lista.primeiro;

    while(auxiliar != NULL){
        No* temp = auxiliar; //Guarda o que tem em auxiliar em temp, passa o auxiliar para o proximo e libera a posicao que temp guarda (antigo auxiliar)
        auxiliar = auxiliar->proximo;
        delete temp;
    }
    inicializar(lista);
}

