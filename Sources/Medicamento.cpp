//Medicamento.cpp

#include "Medicamento.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Medicamento::Medicamento(){}

Medicamento::Medicamento(string nomeProduto, float custo, string lote, int quantidade,
                         Data validade, int categoriaProduto, string marca, string tipo,
                         bool temPrescricao, string dosagem)
                        : Produtos(nomeProduto, custo, lote, quantidade, validade, 1,
                                marca, tipo){
    this->temPrescricao = temPrescricao;
    this->dosagem = dosagem;
}

bool Medicamento::getTemPrescricao(){
    return temPrescricao;
}

string Medicamento::getDosagem(){
    return dosagem;
}

void Medicamento::setTemPrescricao(bool temPrescricao){
    this->temPrescricao = temPrescricao;
}

void Medicamento::setDosagem(string dosagem){
    this->dosagem = dosagem;
}

void Medicamento::exibir(){
    string escolha;

    if(temPrescricao == true){
        escolha = "Sim, necessita de prescrição médica.";
    }else{
        escolha = "Não necessita de prescrição médica.";
    }

    //cout << "\nMedicamento\n";
    Produtos::exibir();
    cout << "\tTem prescrição? " << escolha << endl;
    cout << "\tDosagem: " << dosagem << endl << endl;
}

void Medicamento::listar(){
    string escolha;

    if(temPrescricao == true){
        escolha = "Sim";
    }else{
        escolha = "Não";
    }

    Produtos::listar();
    cout << escolha << "\t" << dosagem << endl;

}

void Medicamento::alterar(){
    Produtos::alterar();

    cout << "8- Necessidade de prescrição\n";
    cout << "9- Dosagem\n";

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
                cin.ignore();
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
                cout << "Insira a nova necessidade de prescrição (digite [s] para SIM ou [n] para NÃO): ";

                char escolha;
                bool entrada = false;

                cin >> escolha;
                cin.ignore();

                while(!entrada){
                    if (escolha == 's' || escolha == 'S') {
                        temPrescricao = true;
                        entrada = true;
                    } else if (escolha == 'n' || escolha == 'N') {
                        temPrescricao = false;
                        entrada = true;
                    } else {
                        cout << "Resposta inválida. Use [s] para SIM ou [n] para NÃO." << endl;
                    }
                }
                break;
            }

            case 9:{
                cout << "Insira a nova dosagem: ";
                getline(cin, dosagem);
                break;
            }

            default:{
                cout << "Opção inválida. Selecione outra: ";
                entrou = 1;
            }
        }
    }
    cout << "Produto alterado com sucesso!\n";
}

void Medicamento::lerAtributos(){
    Produtos::lerAtributos();

    char escolha;
    bool entrada = false;

    while(!entrada){
        cout << "O medicamento inserido necessita de receita médica? Digite [s] para SIM ou [n] para NÃO: ";
        cin >> escolha;
        cin.ignore();

        if (escolha == 's' || escolha == 'S') {
            temPrescricao = true;
            entrada = true;
        } else if (escolha == 'n' || escolha == 'N') {
            temPrescricao = false;
            entrada = true;
        } else {
            cout << "Resposta inválida. Use [s] para SIM ou [n] para NÃO." << endl;
        }
    }

    cout << "Insira a dosagem: ";
    getline(cin, dosagem);
}

string Medicamento::toString(){
    return Produtos::toString() + (temPrescricao ? "Tem prescrição." : "Não tem prescrição.") + ";" + dosagem;
}