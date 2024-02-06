#ifndef FUNCOESMAIN_H
#define FUNCOESMAIN_H

#include<iostream>
#include<cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include "struct.h"
#include "funcoes1.h"

void listar(produto *produtos, int tamanho)
{
    std :: cout << "Codigo       Nome         Preco        Quantidade\n";
    for(int i = 0; i < tamanho; i++)
    {
        printf("  %d          %s         %.2f          %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

void consultar(produto *produtos, int tamanho)
{
    int tentativa_codigo;

    while(true)
    {
        recebe_inteiro(tentativa_codigo);
        
        if(binarsearch(produtos, tamanho, tentativa_codigo) == -1)
        {
            std :: cout << "Digite um codigo existente: ";
            continue;
        }
        else
        {
            std :: cout << produtos[binarsearch(produtos, tamanho, tentativa_codigo)].nome << "\n";
            std :: cout << produtos[binarsearch(produtos, tamanho, tentativa_codigo)].preco << "\n";
            std :: cout << produtos[binarsearch(produtos, tamanho, tentativa_codigo)].quantidade << "\n";
            break;
        }
    }
}

void alterar_preco(produto *produtos, int tamanho)
{
    int tentativa_codigo;

    double preco;

    while(true)
    {
        recebe_inteiro(tentativa_codigo);
        
        if(binarsearch(produtos, tamanho, tentativa_codigo) == -1)
        {
            std :: cout << "Digite um codigo existente.\n";
            continue;
        }
        else
        {
            recebe_float_preco(preco);
            produtos[binarsearch(produtos, tamanho, tentativa_codigo)].preco = preco;
            break;
        }
    }
}

void alterar_quantidade(produto *produtos, int tamanho)
{
    int tentativa_codigo;

    int quantidade;

    while(true)
    {
        recebe_inteiro(tentativa_codigo);
        
        if(binarsearch(produtos, tamanho, tentativa_codigo) == -1)
        {
            std :: cout << "Digite um codigo existente.\n";
            continue;
        }
        else
        {
            recebe_int_quantidade(quantidade);
            produtos[binarsearch(produtos, tamanho, tentativa_codigo)].quantidade = quantidade;
            break;
        }
    }
}

void adicionar_produto(produto *produtos, int tamanho)
{

    //std :: cout << tamanho;

    produtos = (produto *) realloc(produtos, tamanho * sizeof(produto));

    if(produtos == NULL)
    {
        std :: cout << "Falha na alocacao de memoria!\n";
    }

    recebe_string_adcprod(produtos, tamanho);

    recebe_inteiro_adcprod_cod(produtos, tamanho);

    recebe_float_preco_adcprod(produtos, tamanho);

    recebe_int_quantidade_adcprod(produtos, tamanho);

}

void remover_produto(produto *produtos, int tamanho)
{
    //std :: cout << tamanho << "\n";

    recebe_inteiro_removprod(produtos, tamanho + 1);

    produtos = (produto *) realloc(produtos, tamanho * sizeof(produto));

    if(produtos == NULL)
    {
        std :: cout << "Falha na alocacao de memoria!\n";
    }
    else
    {
        std :: cout << "Produto removido\n";
    }
}

#endif