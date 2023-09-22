#pragma once
#include <string>

class Data {
    private:
        int dia, mes, ano;

    public:
        Data();
        Data(int dia, int mes, int ano);
        int getDia();
        int getMes();
        int getAno();

        std::string getDataString();
};