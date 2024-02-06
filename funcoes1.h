#ifndef FUNCOES_H
#define FUNCOES_H

#include<iostream>
#include<cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include "struct.h"

int strlenString(char *string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        i += 1;
    }
    return i;
}

int strlenString(const char *string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        i += 1;
    }
    return i;
}

int strcmp(char *string1, char *string2)
{
    if(strlenString(string1) == strlenString(string2))
    {
        int tamanho = strlenString(string1);
        for(int i = 0; i < tamanho; i++)
        {
            if(string1[i] != string2[i])
            {
                return -1;
            }
        }
        return 0;
    }
    else
    {
        return -1;
    }

}

int strcmp(char *string1, const char *string2)
{
    if(strlenString(string1) == strlenString(string2))
    {
        int tamanho = strlenString(string1);
        for(int i = 0; i < tamanho; i++)
        {
            if(string1[i] != string2[i])
            {
                return -1;
            }
        }
        return 0;
    }
    else
    {
        return -1;
    }

}

void lower(char *palavra)
{
    int numero = strlenString(palavra);

    for(int i = 0; i < numero ; i++)
    {
        if((int)palavra[i] > 64 && (int)palavra[i] < 91)
        {
            palavra[i] += 32;
        }
    }
}

int teste_acesso(int num, const char *senha, char *tentativa )
{
    if(num > 1)
    {
        if(strcmp(tentativa, senha) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void ordenar(produto *produtos, int tamanho)
{
    int apoio_inteiro;
    float apoio_float;
    char apoio_string[48];

    for(int i = 0; i < tamanho - 1; i++)
    {
        for(int j = 0; j < tamanho - i - 1; j++)
        {
            if(produtos[j].codigo > produtos[j + 1].codigo)
            {
                apoio_inteiro = produtos[j].codigo;
                produtos[j].codigo = produtos[j + 1].codigo;
                produtos[j + 1].codigo = apoio_inteiro;

                apoio_inteiro = produtos[j].quantidade;
                produtos[j].quantidade = produtos[j + 1].quantidade;
                produtos[j + 1].quantidade = apoio_inteiro;

                apoio_float = produtos[j].preco;
                produtos[j].preco = produtos[j + 1].preco;
                produtos[j + 1].preco = apoio_float;

                strcpy(apoio_string, produtos[j].nome);
                strcpy(produtos[j].nome, produtos[j + 1].nome);
                strcpy(produtos[j + 1].nome, apoio_string);
                
            }
        }
    }
}

void aumenta_diminui(int &numero, char opcao)
{
    if(opcao == 'a')
    {
        numero += 1;
    }
    if(opcao == 'd')
    {
        numero -= 1;
    }
    else
    {   
    }
}

int binarsearch(produto *produtos, int tamanho, int alvo)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while(inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if(produtos[meio].codigo == alvo)
        {
            return meio;
        }
        if(produtos[meio].codigo > alvo)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return -1;
}

void recebe_inteiro(int &numero)
{
    while (true) 
    {
        std::cout << "Digite o codigo do produto: ";

        if((std :: cin >> numero) && (std::cin.peek()) == '\n') 
        {
            break;
        }
        else 
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n');
            std :: cout << "Digite um codigo valido" << std :: endl;
        }
    }
}

void recebe_int_quantidade(int &numero)
{
    while (true) 
    {
        std :: cout << "Digite a nova quantidade: ";

        if((std :: cin >> numero) && (std::cin.peek()) == '\n') 
        {
            if(numero >= 0)
            {
                break;
            }
            else
            {
                std :: cout << "Digite uma quantidade maior que 0.\n";
                continue;
            }
        }
        else 
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n');
            std :: cout << "Digite uma quantidade valida" << std :: endl;
        }
    }
}

void recebe_inteiro_main(int &numero)
{
    while (true) 
    {
        std::cout << "Digite sua opcao: ";

        if((std :: cin >> numero) && (std::cin.peek()) == '\n') 
        {
            break;
        }
        else 
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n');
            std :: cout << "Digite uma opcao valida.\n" << std :: endl;
        }
    }
}

void recebe_float(double &numero)
{
    while(true)
    {
        std :: cout << "Digite um numero: ";

        if(std :: cin >> numero && std :: cin.peek() == '\n')
        {
            break;
        }
        else
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits <std :: streamsize> :: max(), '\n');
            std :: cout << "Entrada invalida. Digite um numero valido." << std :: endl;
        }
    }
}

void recebe_float_preco(double &numero)
{
    while(true)
    {

        std :: cout << "Digite o novo preco: ";

        if(std :: cin >> numero && std :: cin.peek() == '\n' && numero)
        {
            if(numero >= 0)
            {
                break;
            }
            else
            {
                std :: cout << "Digite um preco maior que 0.\n";
                continue;
            }
        }
        else
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits <std :: streamsize> :: max(), '\n');
            std :: cout << "Digite um preco valido.\n" << std :: endl;
        }
    }
}

void recebe_string(produto *produtos, int pos)
{
    char string[48];

    std :: cout <<"Digite o nome do produto a ser adicionado:";

    while(true)
    {

        std :: cin >> string;

        if(strlenString(string) > 47)
        {
            std :: cout << "Entrada invalida. Digite algo valido: ";
            continue;
        }
        else
        {
            strcpy(produtos[pos].nome, string);
            break;
        }
    }
}

void recebe_string_adcprod(produto *produtos, int tamanho)
{
    char string[48];

    bool existe = false;

    while(true)
    {
        std :: cout <<"Digite o nome:";
        std :: cin >> string;
        if(strlenString(string) > 47)
        {
            std :: cout << "Entrada invalida. Digite um nome valido.\n";
            continue;
        }
        else
        {

            for(int i = 0; i < tamanho - 1; i++)
            {

                char produto_min[48];
                strcpy(produto_min, produtos[i].nome);
                lower(produto_min);
                std :: cout << produto_min << "\n";

                char string_min[48];
                strcpy(string_min, string);
                lower(string_min);
                std :: cout << string_min << "\n";

                if(strcmp(string_min, produto_min) == 0)
                {
                    std :: cout << "Digite um nome novo.\n";
                    //std :: cout << string << produtos[i].nome << "\n";
                    //std :: cout << strcmp(string, produtos[i].nome) << "\n";
                    existe = true;
                }
            }
            if(existe)
            {
                existe = false;
                //std :: cout << "aqui";
                continue;
            }
            else
            {
                strcpy(produtos[tamanho - 1].nome,string);
                break;  
            }
        }
    }
}

void recebe_inteiro_adcprod_cod(produto *produtos, int tamanho)
{
    int numero;

    while (true) 
    {
        std::cout << "Digite o codigo do novo produto: ";

        if((std :: cin >> numero) && (std::cin.peek()) == '\n') 
        {
            if(numero >= 0)
            {
                if(binarsearch(produtos, tamanho - 1, numero) != -1)
                {
                    std :: cout << "Digite um codigo ainda nao inserido.\n";
                    continue;
                }
                else
                {
                    produtos[tamanho - 1].codigo = numero;
                    break;
                }
            }
            else
            {
                std :: cout << "Digite um codigo maior que 0\n";
                continue;
            }
            
        }
        else 
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n');
            std :: cout << "Digite um codigo valido" << std :: endl;
        }
    }
}

void recebe_float_preco_adcprod(produto *produtos, int tamanho)
{

    double numero;

    while(true)
    {

        std :: cout << "Digite o preco do novo produto: ";

        if(std :: cin >> numero && std :: cin.peek() == '\n' && numero)
        {
            if(numero >= 0)
            {
                produtos[tamanho - 1].preco = numero;
                break;
            }
            else
            {
                std :: cout << "Digite um preco maior que 0.\n";
                continue;
            }
        }
        else
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits <std :: streamsize> :: max(), '\n');
            std :: cout << "Digite um preco valido.\n" << std :: endl;
        }
    }
}

void recebe_int_quantidade_adcprod(produto *produtos, int tamanho)
{

    int numero;

    while (true) 
    {
        std :: cout << "Digite a quantidade do novo produto: ";

        if((std :: cin >> numero) && (std::cin.peek()) == '\n') 
        {
            if(numero >= 0)
            {
                produtos[tamanho - 1].quantidade = numero;
                break;
            }
            else
            {
                std :: cout << "Digite uma quantidade maior que 0.\n";
                continue;
            }
        }
        else 
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n');
            std :: cout << "Digite uma quantidade valida" << std :: endl;
        }
    }
}

void recebe_inteiro_removprod(produto *produtos, int tamanho)
{
    int numero;

    //int *apoio_codigo;
    //double *apoio_preco;
    //int *apoio_quantidade;
    //char *apoio_nome[48];

    while (true) 
    {
        std::cout << "Digite o codigo do produto: ";

        if((std :: cin >> numero) && (std::cin.peek()) == '\n') 
        {
            if(numero >= 0)
            {
                if(binarsearch(produtos, tamanho, numero) != -1)
                {
                    for(int i = binarsearch(produtos, tamanho, numero); i < tamanho - 1; i++)
                    {
                        produtos[i].codigo = produtos[i + 1].codigo;
                        produtos[i].preco = produtos[i + 1].preco;
                        produtos[i].quantidade = produtos[i + 1].quantidade;
                        strcpy(produtos[i].nome, produtos[i + 1].nome);
                    }

                    //apoio_codigo = &produtos[tamanho - 1].codigo = nullptr;
                    //apoio_preco = &produtos[tamanho - 1].preco = nullptr;
                    //apoio_quantidade = &produtos[tamanho - 1].quantidade = nullptr;
                    //apoio_nome = &produtos[tamanho - 1].nome = nullptr;

                    //produtos[tamanho - 1].codigo = 0;
                    //produtos[tamanho - 1].preco = 0;
                    //produtos[tamanho - 1].quantidade = 0;
                    //strcpy(produtos[tamanho - 1].nome, '\0');

                    break;
                }
                else
                {
                    std :: cout << "Digite um codigo existente.\n";
                    continue;
                }
            }
            else
            {
                std :: cout << "Digite um codigo maior que 0.\n";
                continue;
            }
        }
        else 
        {
            std :: cin.clear();
            std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n');
            std :: cout << "Digite um codigo valido" << std :: endl;
            continue;
        }
    }
}

#endif
