#include "Produtos.h"
#include <iostream>

using namespace std;

Produtos::Produtos() {}

Produtos::Produtos(string nomeProduto, float custo, string lote, int quantidade, Data validade, int categoriaProduto, string marca, string tipo)
{
        this->nomeProduto = nomeProduto;
        this->custo = custo;
        this->lote = lote;
        this->quantidade = quantidade;
        this->validade = validade;
        this->categoriaProduto = categoriaProduto;
        this->marca = marca;
        this->tipo = tipo;
}

string Produtos::getNomeProduto(){
    return nomeProduto;
}

float Produtos::getCusto(){
    return custo;
}

string Produtos::getLote(){
    return lote;
}

int Produtos::getQuantidade(){
    return quantidade;
}

Data Produtos::getValidade(){
    return validade;
}

int Produtos::getCategoriaProduto(){
    return categoriaProduto;
}

string Produtos::getMarca(){
    return marca;
}

string Produtos::getTipo(){
    return tipo;
}

void Produtos::setNomeProduto(string nomeProduto) {
    this->nomeProduto = nomeProduto;
}

void Produtos::setCusto(float custo){
    this->custo = custo;
}

void Produtos::setLote(string lote){
    this->lote = lote;
}

void Produtos::setQuantidade(int quantidade){
    this->quantidade = quantidade;
}

void Produtos::setValidade(Data validade){
    this->validade = validade;
}

void Produtos::setCategoriaProduto(int categoriaProduto){
    this->categoriaProduto = categoriaProduto;
}

void Produtos::setMarca(string marca){
    this->marca = marca;
}

void Produtos::setTipo(string tipo){
    this->tipo = tipo;
}

void Produtos::exibir(){
    cout << "\tCategoria: ";

    switch (categoriaProduto){
    case 1:
        cout << "Medicamento\n";
        break;

    case 2:
        cout << "Beleza\n";
        break;

    case 3:
        cout << "Higiene Pessoal\n";
        break;
    }

    cout << "\tNome do produto: " << nomeProduto << endl;
    cout << "\tCusto: " << custo << endl;
    cout << "\tLote: " << lote << endl;
    cout << "\tQuantidade disponível: " << quantidade << endl;
    cout << "\tData de validade: " << validade.getDataString() << endl;
    cout << "\tMarca: " << marca << endl;
    cout << "\tTipo: " << tipo << endl;
}

void Produtos::listar(){
    cout << nomeProduto << "\t" << custo << "\t" << lote << "\t" << quantidade
    << "\t" << validade.getDataString() << "\t" << marca << "\t" << tipo << "\t";
}

void Produtos::alterar(){
    //system("cls");

    cout << "Selecione o atributo para ser alterado:\n"
            "1- Nome do produto\n"
            "2- Custo\n"
            "3- Lote\n"
            "4- Quantidade disponível\n"
            "5- Validade\n"
            "6- Marca\n"
            "7- Tipo\n";
}

void Produtos::lerAtributos(){
    cout << "Digite o nome do produto: ";
    getline(cin, nomeProduto);

    cout << "Custo desse produto(R$): ";
    cin >> custo;

    cout << "Lote desse produto: ";
    cin >> lote;

    cout << "Quantidade de produtos recebidos: ";
    cin >> quantidade;

    cout << "Validade desses produtos:\n";
    int dia, mes, ano;

    cout << "\tDigite o dia: ";
    cin >> dia;
    cout << "\tDigite o mês: ";
    cin >> mes;
    cout << "\tDigite o ano: ";
    cin >> ano;
    validade = Data(dia, mes, ano);
    cin.ignore();

    cout << "Marca desse produto: ";
    getline(cin, marca);

    cout << "Digite o tipo desse produto: ";
    getline(cin, tipo);
}

string Produtos::toString(){
   return nomeProduto + ";" + to_string(custo) + ";" + lote + ";" + to_string(quantidade) +
          ";" + to_string(validade.getDia()) + ";" + to_string(validade.getMes()) +
          ";" + to_string(validade.getAno()) + ";" + to_string(categoriaProduto) +
          ";" + marca + ";" + tipo + ";";
}