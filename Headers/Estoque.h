#pragma once

#include <vector>
#include "Produtos.h"
#include "Medicamento.h"
#include "Beleza.h"
#include "HigienePessoal.h"

class Estoque{
    private:
        std::vector<Produtos *> produto; //especificação 5

    public:
        Estoque();

        void inserirProduto(Produtos *prod);
        void listarTodos();
        void exibirUm(int pos);
        void alterarProduto(int pos);
        void removerProduto(int pos);
        void exibirRelatorio(); //especificação 8
        int pesquisar(std::string nome);
        std::vector<Produtos *> getProdutos();
};//especificação 6 //especificação 10