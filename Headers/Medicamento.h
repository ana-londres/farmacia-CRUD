#pragma once

#include "Produtos.h"

class Medicamento : public Produtos { //especificação 4
    private:
        bool temPrescricao;
        std::string dosagem;

    public:
        Medicamento();
        Medicamento(std::string nomeProduto, float custo, std::string lote, int quantidade, Data validade,
                    int categoriaProduto, std::string marca, std::string tipo, bool temPrescricao, std::string dosagem);
        bool getTemPrescricao();
        std::string getDosagem();
        void setTemPrescricao(bool temPrescricao);
        void setDosagem(std::string dosagem);

        void exibir();
        void listar();
        void alterar();
        void lerAtributos();
        std::string toString(); //especificação 5
};