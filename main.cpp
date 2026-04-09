//Trabalho: Manipulação de Polinômios 
//Disciplina: Estrutura de Dados - Professor: Marcos Cesar Cardoso Carrard
//Autores: Guilherme Krieger Ferreira, Thifany Ribeiro Rodrigues

#include "Polinomios.hpp"

void menuInicial(){
    cout<<"--- Manipulação de Polinômios ---"<<endl;
    cout<<"1. Adicionar dois polinomios"<<endl;
    cout<<"2. Resetar polinômios"<<endl;
    cout<<"3. Mostrar polinômios"<<endl;
    cout<<"4. Mostrar menu de operações"<<endl;
    cout<<"0. Sair"<<endl;
}

void menuOperacoes(){
    cout<<"---------------- Operações ----------------"<<endl;
    cout<<"1. Somar dois polinômios"<<endl;
    cout<<"2. Subtrair dois polinômios"<<endl;
    cout<<"3. Multiplicar um pilinômio por um escalar"<<endl;
    cout<<"4. Multiplicar dois polinômios"<<endl;
    cout<<"5. Valor numérico de um polinômio"<<endl;
    cout<<"0. Voltar para o menu principal"<<endl;
}

bool validarOpcaoInicial(int opcao){
    if(opcao == 0 || opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4) return true;
    return false;
}

bool validarOpcaoOper(int opcao){
    if(opcao == 0 || opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5) return true;
    return false;
}

int main(){
    system("chcp 65001");
    system("cls");

    bool fim = false;
    float coef;
    int exp;
    Polinomio polinomio1;
    Polinomio polinomio2;
    inicializar(polinomio1);
    inicializar(polinomio2);
    bool temPolinomios = false;


    while(fim == false){
        int opcao;
        do{
            menuInicial();
            cout<<"Informe uma opção: ";
            cin>>opcao;

            if(!validarOpcaoInicial(opcao)){
                cout<<"Opção inválida, as opções vão de 0 a 4."<<endl;
                system("pause");
                system("cls");
            }
        }while(!validarOpcaoInicial(opcao));

        
        switch(opcao){
            case 0:
                if(temPolinomios){
                    liberar(polinomio1);
                    liberar(polinomio2);
                }   
                cout<<endl<<"Fechando o programa."<<endl;
                fim = true;
                break;

            case 1:
                do{
                    cout<<endl<<"Coeficiente para adicionar no polinômio 1 (0 para parar): ";
                    cin>>coef;

                    if(coef != 0){
                        cout<<"Expoente para adicionar no polinômio 1: ";
                        cin>>exp;
                        inserirOrdem(polinomio1, coef, exp);
                    }
                }while(coef != 0);

                cout<<endl<<"Polinômio 1 adicionado"<<endl;;

                do{
                    cout<<endl<<"Coeficiente para adicionar no polinômio 2 (0 para parar): ";
                    cin>>coef;

                    if(coef != 0){
                        cout<<"Expoente para adicionar no polinômio 2: ";
                        cin>>exp;
                        inserirOrdem(polinomio2, coef, exp);
                    }
                }while(coef != 0);

                cout<<endl<<"Polinomio 2 adicionado."<<endl;
                
                temPolinomios = true;
                system("pause");
                system("cls");
                break;
            
            case 2:
                if(!temPolinomios) cout<<"Nenhum polinômio para resetar."<<endl;   
                else{
                    liberar(polinomio1);
                    liberar(polinomio2);
                    cout<<"Polinômios liberados."<<endl;
                    temPolinomios = false;
                }
                cout<<endl;

                system("pause");
                system("cls");
                break;
            
            case 3:
                if(!temPolinomios) cout<<"Nenhum polinômio adicionado. Nada para mostrar"<<endl;
                else{
                    cout<<"Polinomio 1:  ";
                    imprimirPolinomio(polinomio1);
                    cout<<endl<<"Polinômio 2:  ";
                    imprimirPolinomio(polinomio2);
                }
                cout<<endl;
                
                system("pause");
                system("cls");
                break;
            
            case 4:
                system("cls");
                do{
                    menuOperacoes();
                    cout<<"Informe uma opção: ";
                    cin>>opcao;

                    if(!validarOpcaoOper(opcao)){
                        cout<<"Opção inválida, as opções vão de 0 a 5."<<endl;
                        system("pause");
                        system("cls");
                    }
                }while(!validarOpcaoOper(opcao));

                Polinomio polinomio3;
                inicializar(polinomio3);

                switch(opcao){
                    case 0: 
                        liberar(polinomio3);
                        system("pause");
                        system("cls");
                        break;

                    case 1: //Soma polinomios
                        polinomio3 = somarPolinomios(polinomio1, polinomio2);    
                        
                        cout<<"\nResultado = ( ";
                        imprimirPolinomio(polinomio1);
                        cout<<") + ( ";
                        imprimirPolinomio(polinomio2);
                        cout<<") = ";
                        imprimirPolinomio(polinomio3);
                        cout<<endl;

                        liberar(polinomio3);
                        system("pause");
                        system("cls");
                        break;

                    case 2: //Subtracao polinomios
                        cout<<"\nPolinômios disponiveis: "<<endl;
                        cout<<"Polinômio 1: ";
                        imprimirPolinomio(polinomio1);
                        cout<<endl<<"Polinômio 2: ";
                        imprimirPolinomio(polinomio2);
                        
                        int ordemSub;
                        do{
                            cout<<endl<<"Qual a ordem para a subtração ? (1 = P1 - P2 / 2 = P2 - P1): ";
                            cin>>ordemSub;

                            if(ordemSub != 1 && ordemSub != 2) cout<<"Opção inválida. Digite 1 ou 2 para escolher a ordem da subtração."<<endl;
                        }while(ordemSub != 1 && ordemSub != 2);
                        

                        if(ordemSub == 1){
                            polinomio3 = subtrairPolinomios(polinomio1, polinomio2);
                            cout<<"Resultado = ( ";
                            imprimirPolinomio(polinomio1);
                            cout<<") - ( ";
                            imprimirPolinomio(polinomio2);
                            cout<<") = ";
                            imprimirPolinomio(polinomio3);
                            cout<<endl;
                        }else{ 
                            polinomio3 = subtrairPolinomios(polinomio2, polinomio1);
                            cout<<"Resultado = ( ";
                            imprimirPolinomio(polinomio2);
                            cout<<") - ( ";
                            imprimirPolinomio(polinomio1);
                            cout<<") = ";
                            imprimirPolinomio(polinomio3);
                            cout<<endl;
                        }
                        
                        liberar(polinomio3);
                        system("pause");
                        system("cls");
                        break;
                    
                    case 3: //Multiplicacao por escalar
                        int escolha;
                        float escalar;
                        
                        cout<<"\nPolinômios disponiveis: "<<endl;
                        cout<<"Polinômio 1: ";
                        imprimirPolinomio(polinomio1);
                        cout<<endl<<"Polinômio 2: ";
                        imprimirPolinomio(polinomio2);
                    
                        do{
                            cout<<endl<<"Qual você quer multiplicar por um escalar? (1 ou 2): ";
                            cin>>escolha;

                            if(escolha != 1 && escolha != 2) cout<<"Opção inválida. Escolha 1 para o pilinômio 1 e 2 para o polinômio 2."<<endl;
                        }while(escolha != 1 && escolha != 2);

                        cout<<"Escolha o escalar para a multiplicação: ";
                        cin>>escalar;

                        if(escolha == 1){
                            cout<<"Resultado = ( ";
                            imprimirPolinomio(polinomio1);
                            cout<<") * "<<escalar<<" = ";
                            
                            multiplicarPorEscalar(polinomio1, escalar);
                            imprimirPolinomio(polinomio1);
                        }else{
                            cout<<"Resultado = ( ";
                            imprimirPolinomio(polinomio2);
                            cout<<") * "<<escalar<<" = ";
                            
                            multiplicarPorEscalar(polinomio2, escalar);
                            imprimirPolinomio(polinomio2);
                        }
                        
                        cout<<endl;
                        liberar(polinomio3);
                        system("pause");
                        system("cls");
                        break;
                    
                    case 4: //Multiplicar dois polinomios
                        polinomio3 = multiplicarPolinomios(polinomio1, polinomio2);
                        
                        cout<<"\nResultado = ( ";
                        imprimirPolinomio(polinomio1);
                        cout<<") * ( ";
                        imprimirPolinomio(polinomio2);
                        cout<<") = ";
                        imprimirPolinomio(polinomio3);
                        cout<<endl;
                        
                        liberar(polinomio3);
                        system("pause");
                        system("cls");
                        break;
                    
                    case 5: //Valor numerico do polinomio
                        float valorX;
                        
                        cout<<"\nPolinômios disponiveis: "<<endl;
                            cout<<"Polinômio 1: ";
                            imprimirPolinomio(polinomio1);
                            cout<<endl<<"Polinômio 2: ";
                            imprimirPolinomio(polinomio2);
                        
                            do{
                                cout<<endl<<"Qual você quer pegar o valor numérico? (1 ou 2): ";
                                cin>>escolha;

                                if(escolha != 1 && escolha != 2) cout<<"Opção inválida. Escolha 1 para o pilinômio 1 e 2 para o polinômio 2."<<endl;
                            }while(escolha != 1 && escolha != 2);

                        cout<<"Informe o valor de X: ";    
                        cin>>valorX;

                        if(escolha == 1){
                            cout<<"Resultado = ( ";
                            imprimirPolinomio(polinomio1);
                            cout<<") -> Substituindo X por "<<valorX<<" temos -> ";

                            No* atual = polinomio1.primeiro;
                            while(atual != NULL){
                                if(atual != polinomio1.primeiro && atual->coefNum > 0) cout << " + ";
                                cout<<atual->coefNum<<"*"<<valorX<<"^"<<atual->expoente;
                                atual = atual->proximo;
                            }

                            cout<<" = "<<valorNumerico(polinomio1, valorX)<<endl;
                        }else{
                            cout<<"Resultado = ( ";
                            imprimirPolinomio(polinomio2);
                            cout<<") -> Substituindo X por "<<valorX<<" temos -> ";

                            No* atual = polinomio2.primeiro;
                            while(atual != NULL){
                                if(atual != polinomio2.primeiro && atual->coefNum > 0) cout << " + ";
                                cout << atual->coefNum << "*" << valorX << "^" << atual->expoente;
                                
                                atual = atual->proximo;
                            }

                            cout<<" = "<<valorNumerico(polinomio2, valorX)<<endl;
                        }

                        system("pause");
                        system("cls");
                        break;
                }
        }

    }
    return 0;
}