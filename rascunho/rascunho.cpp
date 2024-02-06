#include<iostream>
#include<cstdio>
#include "funcoes1.h"
#include "struct.h"
#include <cstdlib>
#include <fstream>
#include "funcoes2.h"
#include <limits>

using namespace std;

main()
{
    int tamanho, opcao , *ptTamanho = &tamanho;

    produto produtos[4];

    std:: ifstream arquivo("estoque.dat", std::ios::binary);

    if(!arquivo.is_open())
    {
        std :: cout << "\nFalha na abertura do arquivo!\n";
        return 0;
    }

    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(int));

    arquivo.read(reinterpret_cast<char*>(&produtos[0]), tamanho*sizeof(produto));

    arquivo.close();

    std :: cout << produtos[0].nome << "\n";
    std :: cout << produtos[1].nome << "\n";
    std :: cout << produtos[2].nome << "\n";
    std :: cout << produtos[3].nome << "\n";
    std :: cout << produtos[0].codigo << "\n";
    std :: cout << produtos[1].codigo << "\n";
    std :: cout << produtos[2].codigo << "\n";
    std :: cout << produtos[3].codigo << "\n";
    std :: cout << produtos[0].preco << "\n";
    std :: cout << produtos[1].preco << "\n";
    std :: cout << produtos[2].preco << "\n";
    std :: cout << produtos[3].preco << "\n";
    std :: cout << produtos[0].quantidade << "\n";
    std :: cout << produtos[1].quantidade << "\n";
    std :: cout << produtos[2].quantidade << "\n";
    std :: cout << produtos[3].quantidade << "\n"; 

    //consultar(produtos, tamanho);

    //recebe_inteiro(opcao);

    //cout << opcao;


    return 0;
}