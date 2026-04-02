#include "Polinomios.hpp"

int main(){
    system("chcp 65001");
    system("cls");

    Polinomio x;
    inicializar(x);
    inserirOrdem(x, 2, 2);
    inserirOrdem(x, -2, 0);
    inserirOrdem(x, -2, 5);
    // ERRO:  inserirOrdem(x, 1, 1);
    
    Polinomio y;
    inicializar(y);
    inserirOrdem(y, 1, 2);
    inserirOrdem(y, 7, 5);
    inserirOrdem(y, 2, 0);
    inserirOrdem(y, 1, 7);


    Polinomio z;
    inicializar(z);
    z = somarPolinomios(x, y);
    imprimirPolinomio(z);

    cout<<endl<<endl;

    Polinomio o;
    inicializar(o);
    o = subtrairPolinomios(x, y);
    imprimirPolinomio(o);

    cout<<endl<<"Valor numerico do polinomio x (com x = 1):"<<valorNumerico(y, 1);


    Polinomio a;
    inicializar(a);
    inserirOrdem(a, 1, 3);
    inserirFinal(a, 1, 1);
    inserirOrdem(a, 2, 2);

    imprimirPolinomio(a);
    // Polinomio b;
    // inicializar(b);
    // inserirOrdem(b, 1, 1);
    // inserirOrdem(b, 1, 0);

    // Polinomio c;
    // inicializar(c);
    // c = multiplicarPolinomios(a, b);
    // imprimirPolinomio(c);


    return 0;
}