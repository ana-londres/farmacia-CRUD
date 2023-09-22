#include "HigienePessoal.h"

#include <iostream>
#include <cstdlib>

using namespace std;

HigienePessoal::HigienePessoal(){}

HigienePessoal::HigienePessoal(string nomeProduto, float custo, string lote, int quantidade,
               Data validade, int categoriaProduto, string marca, string tipo,
               string conteudo)
               : Produtos(nomeProduto, custo, lote, quantidade, validade, 3,
                          marca, tipo){
        this->conteudo = conteudo;
}

string HigienePessoal::getConteudo(){
    return conteudo;
}

void HigienePessoal::setConteudo(string conteudo){
    this->conteudo = conteudo;
}

void HigienePessoal::exibir(){
    Produtos::exibir();

    cout << "\tConteúdo: " << conteudo << endl << endl;
}
void HigienePessoal::listar(){
    Produtos::listar();

    cout << conteudo << endl;
}
void HigienePessoal::alterar(){
    Produtos::alterar();

    cout << "8- Conteúdo\n";

    int altera;
    char entrou = 1;

    while(entrou){
        entrou = 0;
        cin >> altera;
        cin.ignore();

        switch (altera){
            case 1:{
                cout << "Insira o novo nome do produto: ";
                getline(cin, nomeProduto);
                break;
            }

            case 2:{
                cout << "Insira o novo valor desse produto(R$): ";
                cin >> custo;
                cin.ignore(); //é bom fazer isso toda vez???
                break;
            }

            case 3:{
                cout << "Insira o novo lote desse produto: ";
                cin >> lote;
                cin.ignore();
                break;
            }

            case 4:{
                cout << "Insira a nova quantidade de produtos recebidos: ";
                cin >> quantidade;
                cin.ignore();
                break;
            }

            case 5:{
                cout << "Insira a nova validade desses produtos:\n";
                int dia, mes, ano;

                cout << "\tDia: ";
                cin >> dia;
                cout << "\tMês: ";
                cin >> mes;
                cout << "\tAno: ";
                cin >> ano;
                validade = Data(dia, mes, ano);
                cin.ignore();
                break;
            }

            case 6:{
                cout << "Insira a nova marca desse produto: ";
                getline(cin, marca);
                break;
            }

            case 7:{
                cout << "Insira o novo tipo desse produto: ";
                getline(cin, tipo);
                break;
            }

            case 8:{
                cout << "Insira o novo conteúdo desse produto: ";
                getline(cin, conteudo);
                break;
            }

            default:{
                cout << "Opção inválida. Selecione outra: ";
                entrou = 1;
            }
        }
    }
    cout << "Novo produto alterado com sucesso.\n";
}

void HigienePessoal::lerAtributos(){
    Produtos::lerAtributos();

    cout << "Digite o conteúdo do produto: ";
    getline(cin, conteudo);
}

string HigienePessoal::toString(){
    return Produtos::toString() + conteudo;
}