#include "Data.h"

#include <iostream>

using namespace std;

Data::Data(){}

Data::Data(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

int Data::getDia(){
    return dia;
}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}

string Data::getDataString(){
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
}