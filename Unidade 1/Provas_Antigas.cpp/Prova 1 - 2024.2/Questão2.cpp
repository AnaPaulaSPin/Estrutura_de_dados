// Questão 2:
// Escreva uma função que receba o ponteiro de início para uma lista duplamente encadeada de números 
// inteiros. A função informará se a lista é ou não simétrica.
/// Considere uma lista simétrica aquela em que a sequência de números é idêntica em ambos 
// os sentidos: de início ao fim e vice-versa.


#include <iostream>
using namespace std;

struct node{
    int numero;
    struct node *prox, *antr;
};

class Lista{
    private:
     node *inicio;

    public:
    Lista(){
        inicio = nullptr; antr = nullptr;
    }


    void InserirElemento(int n){
        node *novo;
        novo = new node;
        if(novo == nullptr){
            cout <<"Nao foi possivel alocar memoria\n";
            return;
        } 
        novo->numero = n;
        if(inicio == nullptr){
            inicio = novo;
            novo->prox = nullptr;

        } else{
            node *atual = inicio, *ant = inicio;

            while(atual != nullptr){
                ant = atual;
                atual = atual->prox;

            }
                ant->prox = novo;
                novo->prox = nullptr;
            
        }
    }

    void mostrar(){
        node *atual = inicio;
        if(inicio == nullptr){
            cout << " Lista vazia, insira numeros!\n";
        } else{
            while(atual != nullptr){
                cout << atual->numero << " ";
                atual = atual->prox;

            }
            cout <<" \n";
        }
    }

    void ModificarLista(){
        node *atual = inicio, *aux= fim, *proximo, *antr, *temp;

        while (atual != nullptr){
            while(aux =! nullptr){

            }
       }

    }

    void mostrar(){
        node *atual = inicio;
        if(inicio == nullptr){
            cout << " Lista vazia, insira numeros!\n";
        } else{
            while(atual != nullptr){
                cout << atual->numero << " ";
                atual = atual->prox;

            }
            cout <<" \n";
        }
    }


};

int main(){
    Lista f1;

    f1.InserirElemento(7);
    f1.InserirElemento(2);
    f1.InserirElemento(1);
    f1.InserirElemento(3);
    f1.InserirElemento(9);
    f1.InserirElemento(1);
    f1.InserirElemento(4);

    cout << "Lista original: \n";
    f1.mostrar();

    node *inicio = f1.ModificarLista(1,2);
    
    cout << "Lista modificada: : \n";
    f1.mostrar(inicio);


    return 0;
}