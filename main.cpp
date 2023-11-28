#include <iostream>
using namespace std;

// Definição da estrutura do nó da lista
class No {
public:
    string nome;
    long contato;
    string email;
    No* proximo;

    No(string nome, long contato, string email) {
        this->nome = nome;
        this->contato = contato;
        this->email = email;
        this->proximo = nullptr;
    }
};

// Classe da lista encadeada
class ListaEncadeadaContatos {
public:
    No* cabeca;

    ListaEncadeadaContatos() {
        cabeca = nullptr;
    }

    void adicionarContato(string nome, long contato, string email) {
        No* novoNo = new No(nome, contato, email);
        if (cabeca == nullptr) {
            cabeca = novoNo;
        } else {
            No* temp = cabeca;
            while (temp->proximo != nullptr) {
                temp = temp->proximo;
            }
            temp->proximo = novoNo;
        }
    }

    void mostrarContatos() {
        No* temp = cabeca;
        while (temp != nullptr) {
            cout << "Nome: " << temp->nome << ", Contato: " << temp->contato << ", Email: " << temp->email << endl;
            temp = temp->proximo;
        }
    }

    void removerContato(string nome) {
        No* atual = cabeca;
        No* anterior = nullptr;

        while (atual != nullptr && atual->nome != nome) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == nullptr) {
            cout << "Contato com nome '" << nome << "' nao encontrado na lista." << endl;
            return;
        }

        if (anterior == nullptr) {
            cabeca = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }

        delete atual;
        cout << "Contato com nome '" << nome << "' removido da lista." << endl;
    }
};

// Função principal
int main() {
    ListaEncadeadaContatos lista;

    // Adicionando contatos à lista
    lista.adicionarContato("Maria", 1234567890, "maria@example.com");
    lista.adicionarContato("Joao", 9876543210, "joao@example.com");
    lista.adicionarContato("Ana", 11112222333, "ana@example.com");

    // Mostrando os contatos da lista
    cout << "Lista de Contatos:" << endl;
    lista.mostrarContatos();

    // Removendo um contato da lista
    lista.removerContato("Maria");

    // Mostrando os contatos após a remoção
    cout << "\nLista de Contatos apos a remocao:" << endl;
    lista.mostrarContatos();

    return 0;
}
