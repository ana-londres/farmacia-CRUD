#pragma once

#include "Produtos.h"

class Beleza : public Produtos { //especificação 4
    private:
        std::string conteudo;

    public:
        Beleza();
        Beleza(std::string nomeProduto, float custo, std::string lote, int quantidade, Data validade,
               int categoriaProduto, std::string marca, std::string tipo, std::string conteudo);
        std::string getConteudo();
        void setConteudo(std::string conteudo);

        void exibir();
        void listar();
        void alterar();
        void lerAtributos();
        std::string toString(); //especificação 5
};