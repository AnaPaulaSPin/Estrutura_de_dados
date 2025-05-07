#include <iostream>
using namespace std;

struct node{
    string palavra;
    struct node *prox, *ant;
};

class Editor{
    private:
     node *inicio, *atual, *fim;

    public:
    Editor(){
        inicio = nullptr; 
        atual = nullptr;
        
    }

    void InserirElemento(string n){
        node *novo;
        novo = new node;
        if(novo == nullptr){
            cout <<"Nao foi possivel alocar memoria\n";
            return;
        } 
        novo->palavra = n;

      //Primeiro elemento a ser digitado:
        if(inicio == nullptr){
            inicio = novo;
            novo->prox = novo;
            novo->ant = novo;
            fim = novo;

          // Caso o elemento seja digitado no "fim' da lista: (aponta pro fim) |Ed| <- |Aula| -> |de|-> |Ed| -> |aula| (aponta para o inicio)
        } else if(atual->prox == inicio){
           novo->prox = inicio;
           novo->ant = atual;
          inicio->ant = novo;
           fim = novo;
       }
        //Caso o elemento seja digitado no meio da lista:
      else{
            novo->prox = atual->prox;
            novo->ant = atual;
            atual->prox->ant = novo;
      }
    }

    void retirarPalavra(){
        node *temp;
      
        if(inicio == nullptr){
            cout << "Lista sem elementos para retirar!\n"; 
            return;
          // Caso o elemento que vamos retirar esteja no inicio da lista:
        } else{
          temp = atual;
          if(atual ->ant == fim){
            atual->prox->ant = fim;
            fim->prox = atual->prox;
            atual = atual->prox;
            inicio = atual;
            delete temp;

            // Caso o elemento que vamos retirar esteja no "fim" da lista:
          } else if(atual->prox == inicio){
            atual->prox->ant = atual->ant;
            atual->ant->prox = inicio;
            atual = atual->prox;
            fim = atual;
            delete temp;

            // Caso o elemento que vamos retirar esteja no meio da lista:
          } else{
            
          }

          
            
        }
    }


    void mostrar(){
        node *pos = inicio;
        if(inicio == nullptr){
            cout << " Lista vazia, insira as palavras o frases!\n";
        } else{
            while(atual != nullptr){
              if(pos->palavra == atual->palavra){
                cout << "\033[1;32m" << atual->palavra << "\033[0m " " ";

              } else{
                cout << atual->palavra << " ";
              }
                atual = atual->prox;
            }
            cout <<" \n";
          cout<< " A palavra em vermelho eh a sua atual!";
        }
    }

};

int main(){
    int r; 
    Editor f1;

    while(1){
        cout << "Menu do Editor de Texto:\n";
        cout << "1 - Inserir (depois da palavra atual)\n";
        cout << "2- Eliminar palavra\n";
        cout << "3 - Mostrar seu texto \n";
        cout << "4 - Encerrar\n";
        cout << "Escolha: ";
        cin >> r;

        switch (r)
        {
        case 1:{
            string n;
            cout << "Digite a palavra que vc quer adicionar: ";
            cin >> n;
            cout <<"\n";
          
            f1.mostrar();
            cout <<"\n";
            f1.InserirElemento(n);
            cout <<"\n";
          
            break;

        }
        case 2:{
            int n;
            cout << "Digite o numero que deseja retirar da Lista: ";
            cin >> n;
            cout <<"\n";
          
            f1.mostrar();
            cout <<"\n";
            f1.retirarPalavra();
            cout <<"\n";

            break;
        }
        case 3:{
            f1.mostrar();
            cout <<"\n";
            break;
        }
        case 4:{
            cout << "Finalizando o programa!\n";
            break;
        }

        default:
        cout << "Digite uma opcao valida! /n";
            break;
        }

        if(r == 4){
            break;
        }

      

    }

    return 0;
}
