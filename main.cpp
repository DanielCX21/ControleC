#include<iostream>
#include<cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include "struct.h"
#include "funcoes1.h"
#include "funcoesmain.h"


int main(int argc, char *argv[])
{
    const char senha[] = "admin";

    char teste[30] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    int opcao, tamanho;

    produto *produtos;

    std:: ifstream arquivo("estoque.dat", std::ios::binary);

    if(!arquivo.is_open())
    {
        std :: cout << "\nFalha na abertura do arquivo!\n";
        return 0;
    }

    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(int));

    produtos = (produto *) malloc(tamanho * sizeof(produto));

    if(produtos == NULL)
    {
        std :: cout << "Falha na alocacao de memoria.";
        return 0;
    }

    arquivo.read(reinterpret_cast<char*>(&produtos[0]), tamanho * sizeof(produto));

    arquivo.close();

    ordenar(produtos, tamanho);

    if(argc == 2)
    {
        strcpy(teste, argv[1]);
    }


    if(teste_acesso(argc, senha, teste) == 1)
    {
        while(1)
        {
            std :: cout <<"1-Listar todos os produtos." << "\n";
            std :: cout <<"2-Consultar individualmente. "<< "\n";
            std :: cout <<"3-Alterar quantidades individualmente." << "\n";
            std :: cout <<"4-Alterar preco individualmente." << "\n";
            std :: cout <<"5-Adicionar produto" << "\n";
            std :: cout <<"6-Remover produto" << "\n";
            std :: cout <<"7-Salvar e sair." << "\n";
            std :: cout <<"8-Sair sem salvar." << "\n";
            
            recebe_inteiro_main(opcao);
            
            switch (opcao)
            {
                case 1: {  
                    ordenar(produtos, tamanho);  
                    //std :: cout << tamanho;
                    listar(produtos, tamanho);
                        }break;
                case 2: {
                    ordenar(produtos, tamanho);
                    consultar(produtos, tamanho);
                        }break;   
                case 3: {
                    ordenar(produtos, tamanho);
                    alterar_quantidade(produtos, tamanho);
                        }break;    
                case 4: {
                    ordenar(produtos, tamanho);
                    alterar_preco(produtos, tamanho);
                        }break; 
                case 5: {
                    aumenta_diminui(tamanho, 'a');
                    adicionar_produto(produtos, tamanho);
                    ordenar(produtos, tamanho);
                        }break; 
                case 6: {
                    aumenta_diminui(tamanho, 'd');
                    remover_produto(produtos, tamanho);
                        }break; 
                case 7: {
                    ordenar(produtos, tamanho);

                    std::ofstream arquivo("estoque.dat", std::ios::binary);

                    if(!arquivo.is_open())
                    {
                        std :: cout << "\nFalha na abertura do arquivo!\n";
                        return 0;
                    }

                    arquivo.write(reinterpret_cast<char*>(&tamanho), sizeof(int));
                    arquivo.write(reinterpret_cast<char*>(&produtos[0]), tamanho*sizeof(produto));
                    arquivo.close();

                    std :: cout << "Ate mais\n";

                    free(produtos);
                    return 0;

                        }break; 
                case 8: {
                    free(produtos);
                    std :: cout << "\nAte mais.";
                    return 0;
                        }break;          
                default:{
                    std :: cout << "Digite opcao valida.\n";
                        }
                    break;
            }
        }
    }
    else
    {
        if(argc == 2)
        {
            //senha errada
            std :: cout << "\n\nSENHA INCORRETA!!!\n\n";
            while(1)
            {
                std :: cout <<"1-Listar todos os produtos." << "\n";
                std :: cout <<"2-Consultar individualmente. "<< "\n";
                std :: cout <<"3-Sair." << "\n";
            
                recebe_inteiro_main(opcao);

                switch(opcao)
                {
                    case 1: { 
                        ordenar(produtos, tamanho);   
                        listar(produtos, tamanho);
                            }break;
                    case 2: {
                        ordenar(produtos, tamanho);
                        consultar(produtos, tamanho);
                            }break;   
                    case 3: {
                        std :: cout << "\nAte mais!\n\n";
                        free(produtos);
                        return 0;
                            }break;              
                    default:{
                        std :: cout << "Digite opcao valida.\n\n";
                            }
                        break;
                }
            }
        }
        else
        {
        //nem tentou senha
        while(1)
            {
                std :: cout <<"1-Listar todos os produtos." << "\n";
                std :: cout <<"2-Consultar individualmente. "<< "\n";
                std :: cout <<"3-Sair." << "\n";
            
                recebe_inteiro_main(opcao);

                switch(opcao)
                {
                    case 1: { 
                        ordenar(produtos, tamanho);   
                        listar(produtos, tamanho);
                            }break;
                    case 2: {
                        ordenar(produtos, tamanho);
                        consultar(produtos, tamanho);
                            }break;   
                    case 3: {
                        std :: cout << "\nAte mais!\n\n";
                        free(produtos);
                        return 0;
                            }break;              
                    default:{
                        std :: cout << "Digite opcao valida.\n\n";
                            }
                        break;
                }
            }
        }  
    }

    return 0;
}

