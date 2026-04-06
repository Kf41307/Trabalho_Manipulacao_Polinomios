#include "Polinomios.hpp"

int main(){
    system("chcp 65001");
    system("cls");

    Polinomio a;
    inicializar(a);
    inserirFinal(a, 1, 3);
    inserirFinal(a, 2, 2);
 
    Polinomio b;
    inicializar(b);
    inserirFinal(b, 1, 1);
    inserirFinal(b, 1, 0);

    Polinomio c = multiplicarPolinomios(a, b);
    imprimirPolinomio(c);


    liberar(a);
    liberar(b);
    liberar(c);
    return 0;
}