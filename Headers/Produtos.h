#pragma once

#include <string>
#include "Data.h"

class Produtos {
    protected:
        std::string nomeProduto;
        float custo;
        std::string lote;
        int quantidade;
        Data validade; //especificação 3
        int categoriaProduto;
        std::string marca;
        std::string tipo;

    public:
        Produtos();
        Produtos(std::string nomeProduto, float custo, std::string lote, int quantidade, Data validade, int categoriaProduto, std::string marca, std::string tipo);

        std::string getNomeProduto();
        float getCusto();
        std::string getLote();
        int getQuantidade();
        Data getValidade();
        int getCategoriaProduto();
        std::string getMarca();
        std::string getTipo();
        void setNomeProduto(std::string nomeProduto);
        void setCusto(float custo);
        void setLote(std::string lote);
        void setQuantidade(int quantidade);
        void setValidade(Data validade);
        void setCategoriaProduto(int categoriaProduto);
        void setMarca(std::string marca);
        void setTipo(std::string tipo);

        virtual void exibir();
        virtual void listar();
        virtual void alterar();
        virtual void lerAtributos();
        virtual std::string toString();
};