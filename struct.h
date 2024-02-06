#ifndef STRUCT_H
#define STRUCT_H

struct Produto
{
    int codigo;
    char nome[48] = "00000000000000000000000000000000000000000000000";
    double preco;
    int quantidade;
};

typedef Produto produto;

#endif