#include<iostream>
#include<cstdio>
#include "funcoes1.h"
#include "struct.h"
#include <cstdlib>
#include <fstream>
#include "funcoes2.h"

using namespace std;

main()
{
    char nome1[] = "segundo", nome2[] = "primeiro", nome3[] = "quarto", nome4[] = "terceiro";

    int a = 4;

    std::ofstream arquivo("estoque.dat", std::ios::binary);

    arquivo.write(reinterpret_cast<char*>(&a), sizeof(int));

    produto produtos[4];

    produtos[0].codigo = 2;
    produtos[1].codigo = 1;
    produtos[2].codigo = 4;
    produtos[3].codigo = 3;
    strcpy(produtos[0].nome, nome1);
    strcpy(produtos[1].nome, nome2);
    strcpy(produtos[2].nome, nome3);
    strcpy(produtos[3].nome, nome4);
    produtos[0].preco = 20;
    produtos[1].preco = 10;
    produtos[2].preco = 40;
    produtos[3].preco = 30;
    produtos[0].quantidade = 200;
    produtos[1].quantidade = 100;
    produtos[2].quantidade = 400;
    produtos[3].quantidade = 300;

    arquivo.write(reinterpret_cast<char*>(&produtos[0]), 4*sizeof(produto));

    

    return 0;
}