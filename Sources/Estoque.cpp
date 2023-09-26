#include "Estoque.h"
#include <iostream>

using namespace std;

Estoque::Estoque() {}

void Estoque::inserirProduto(Produtos *prod){
    produto.push_back(prod);
}

void Estoque::listarTodos() {
    cout << "\nMedicamentos:\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Indice \tNome \t\tCusto \tLote \tQuantidade \tValidade \tMarca \tTipo \tTem prescrição? \tDosagem\n";
    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < produto.size(); i++) {
        if (produto[i]->getCategoriaProduto() == 1) {
            cout << i + 1 << "\t";
            produto[i]->listar();
        }
    }
    cout << endl;
    cout << "\nProdutos de beleza:\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Indice \tNome \t\tCusto \tLote \tQuantidade \tValidade \tMarca \tTipo \tConteudo\n";
    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < produto.size(); i++) {
        if (produto[i]->getCategoriaProduto() == 2) {
            cout << i + 1 << "\t";
            produto[i]->listar();
        }
    }
    cout << endl;
    cout << "\nHigiene pessoal:\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Indice \tNome \t\tCusto \tLote \tQuantidade \tValidade \tMarca \tTipo \tConteudo\n";
    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < produto.size(); i++) {
        if (produto[i]->getCategoriaProduto() == 3) {
            cout << i + 1 << "\t";
            produto[i]->listar();
        }
    }
    cout << endl;
}

void Estoque::exibirUm(int pos) {
    while (true) {
        if (pos >= 0 && pos < produto.size()) {
            cout << "\nAtributos desse produto:\n";
            produto[pos]->exibir();
            return;

        } else {
            string nome;
            cout << "\nNome inválido. O estoque não contém um produto com esse nome.\n";
            cout << "Digite 'exit' para sair da opção de exibir ou digite um nome válido: ";
            getline(cin, nome);

            if (nome == "exit") {
                return; // Sair do loop quando o usuário digitar "exit"
            }

            pos = pesquisar(nome); // Atualiza 'pos' com o novo resultado da pesquisa
        }
    }
    cout << endl;
}

void Estoque::alterarProduto(int pos) {
    while (true) {
        if (pos == -1) {
            cout << "\nNome inválido. O estoque não contém um produto com esse nome.\n";
            cout << "Digite 'exit' para sair da opção de alterar ou digite um nome válido: ";
            string nome;
            getline(cin, nome);

            if (nome == "exit") {
                return; // Sair do modo de alteração
            }

            pos = pesquisar(nome);
        } else {
            exibirUm(pos);
            produto[pos]->alterar();
            cout << endl;
            return; // Sai do modo de alteração após a alteração ser concluída
        }
    }
    cout << endl;
}

void Estoque::removerProduto(int pos) {
    while (true) {
        if (pos >= 0 && pos <= produto.size()) {
            exibirUm(pos);

            cout << "Remover o produto digitado? [s/n]: ";
            char resposta;

            while (1) {
                cin >> resposta;
                getchar();

                if (resposta == 'n') {
                    cout << "Sua remoção foi cancelada.\n\n";
                    return;
                } else if (resposta == 's') {
                    produto.erase(produto.begin() + pos);
                    cout << "Remoção de produto bem-sucedida.\n\n";
                    return;
                } else {
                    cout << "Resposta inadequada, insira s para SIM ou n para NÃO.\n";
                }
            }
            return;

        } else {
            string nome;
            cout << "\nNome inválido. O estoque não contém um produto com esse nome.\n";
            cout << "Digite 'exit' para sair da opção de remover ou digite um nome válido: ";
            getline(cin, nome);

            if (nome == "exit") {
                return; // Sair do loop quando o usuário digitar "exit"
            }

            pos = pesquisar(nome); // Atualiza 'pos' com o novo resultado da pesquisa
        }
    }
    cout << endl;
}


void Estoque::exibirRelatorio(){
    int somaM, somaB, somaH;
    float custoM, custoB, custoH, custoTotalM, custoTotalB, custoTotalH;

    somaM = somaB = somaH = 0;
    custoM = custoB = custoH  = custoTotalM = custoTotalB = custoTotalH = 0;

    system("cls");

    cout << "Existem " <<  produto.size() << " produtos cadastrados." << endl;

    for(Produtos *prod : produto){
        if(prod->getCategoriaProduto() == 1){
            somaM += prod->getQuantidade();
            custoM += (prod->getCusto()*prod->getQuantidade());
            custoTotalM += custoM;
        }else if (prod->getCategoriaProduto() == 2){
            somaB += prod->getQuantidade();
            custoB += (prod->getCusto()*prod->getQuantidade());
            custoTotalB += custoB;
        }else if (prod->getCategoriaProduto() == 3){
            somaH += prod->getQuantidade();
            custoH += (prod->getCusto()*prod->getQuantidade());
            custoTotalH += custoH;
        }
        custoM = custoB = custoH = 0;
    }

    cout << "Quantidade total de medicamentos: " << somaM << endl;
    cout << "Quantidade total de itens de beleza: " << somaB << endl;
    cout << "Quantidade total de itens de higiene pessoal: " << somaH << endl << endl;

    cout << "Custo total de medicamentos: R$ " << custoTotalM << endl;
    cout << "Custo total de itens de beleza: R$ " << custoTotalB << endl;
    cout << "Custo total de itens de higiene pessoal: R$ " << custoTotalH << endl;
    cout << endl;
}

int Estoque::pesquisar(string nome) {
    for (int i = 0; i < produto.size(); i++) {
        if (produto[i]->getNomeProduto().find(nome) != string::npos){
            return i; // Retorna o índice do objeto Produto encontrado
        }
    }
    return -1;
}

vector<Produtos *> Estoque::getProdutos() {
    return produto;
}