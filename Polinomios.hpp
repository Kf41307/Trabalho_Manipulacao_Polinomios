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
    }else if((expoente > lista.primeiro->expoente)){ //Se o expoente do adicionado for maior que o primeiro
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
                // funcao SOMAR(atual.coef, coefNum) coefNum do expoente
            }

            anterior = atual;
            atual = atual->proximo;
        }
    }
    return false;
}

bool removerMonomio(Polinomio &lista, int expoente){
    No* atual = lista.primeiro;
    No* anterior = NULL;

    if(lista.primeiro == NULL) return false;
    
    while(atual != NULL){
        if(atual->expoente == expoente){

            if((atual == lista.primeiro) && (atual == lista.ultimo)){
                inicializar(lista);
            }else if(atual == lista.primeiro){ //&& (atual != lista.ultimo)
                lista.primeiro = atual->proximo;
            }else if(atual == lista.ultimo){
                lista.ultimo = anterior;
                anterior->proximo = NULL;
            }else{
                anterior->proximo = atual->proximo;
            }
            delete atual;
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

bool buscarExpoente(Polinomio lista, int expoente){
    No* atual = lista.primeiro;

    while(atual != NULL){
        if(atual->expoente == expoente) return true;
        atual = atual->proximo;
    }

    return false;
}

void imprimirPolinomio(Polinomio lista){ //Falta espaco no exp == 0 e coef < 0 antes do numero
    No* atual = lista.primeiro;

    while(atual != NULL){
        if((atual == lista.primeiro) && (atual->coefNum > 0)){
            cout<<atual->coefNum<<"x^"<<atual->expoente<<" ";
        }else if((atual->expoente == 0) && atual->coefNum > 0){
            cout<<"+ "<<atual->coefNum<<" ";
        }else if(atual->expoente == 0){
            cout<<atual->coefNum<<" ";
        }else if(atual->expoente == 1){
            cout<<atual->coefNum<<"x"<<" ";
        }else if(atual->coefNum > 0){
            cout<<"+ "<<atual->coefNum<<"x^"<<atual->expoente<<" ";
        }else{
            cout<<atual->coefNum<<"x^"<<atual->expoente<<" ";
        }

        atual = atual->proximo;
    }
}

Polinomio somarPolinomios(Polinomio lista1, Polinomio lista2){

    Polinomio soma;
    inicializar(soma);

    No* atual1 = lista1.primeiro;
    No* atual2 = lista2.primeiro;

    while(atual1 != NULL){

        atual2 = lista2.primeiro;
        bool jaSomou = false;

        while(atual2 != NULL){
            if(atual1->expoente == atual2->expoente){
                float somaCoef = atual1->coefNum + atual2->coefNum;

                if(somaCoef != 0){
                    inserirOrdem(soma, somaCoef, atual1->expoente); //(5x^4 + 2x) +  2x^4 + x^2 =  7x^4 + 2x + x^2
                }
                jaSomou = true;
            }
            atual2 = atual2->proximo;
        }

        if(!jaSomou){
            inserirOrdem(soma, atual1->coefNum, atual1->expoente);
        }
        atual1 = atual1->proximo;
    }

    atual2 = lista2.primeiro;
    while(atual2 != NULL){
        if(!buscarExpoente(lista1, atual2->expoente)){
            inserirOrdem(soma, atual2->coefNum, atual2->expoente);
        }
        atual2 = atual2->proximo;
    }

    return soma;
}

void multiplicarPorEscalar(Polinomio &lista, float escalar){
    No* atual = lista.primeiro;

    if(lista.primeiro == NULL) return;

    while(atual != NULL){
        atual->coefNum *= escalar;

        atual = atual->proximo;
    }
}

Polinomio subtrairPolinomios(Polinomio lista1, Polinomio lista2){
    multiplicarPorEscalar(lista2, -1);
    Polinomio subtracao = somarPolinomios(lista1, lista2);
    multiplicarPorEscalar(lista2, -1);

    return subtracao;
}

Polinomio multiplicarPolinomios(Polinomio lista1, Polinomio lista2){
 
    No* atual1 = lista1.primeiro;
    No* atual2 = lista2.primeiro;

    Polinomio multiplicacao;
    inicializar(multiplicacao);

    while(atual1 != NULL){
          
        atual2 = lista2.primeiro;

        while(atual2 != NULL){
            int somaExp = atual1->expoente + atual2->expoente;
            float multCoef = atual1->coefNum * atual2->coefNum;

            inserirOrdem(multiplicacao, multCoef, somaExp);
        }
        
        atual1 = atual1->proximo;
    }

    //somarMonomiosMesmoGrau
    return multiplicacao;
}   

float valorNumerico(Polinomio lista, float valorX){
    No* atual = lista.primeiro;

    float valorNumerico = 0;

    while(atual != NULL){
        float potencia = 1;
        for(int i = 0; i < atual->expoente; i++){
            potencia *= valorX;
        }
        
        valorNumerico += atual->coefNum * potencia;

        atual = atual->proximo;
    }

    return valorNumerico;
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