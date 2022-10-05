#include "utils.h"
#include <fstream>
#include <iostream>
#include <vector>

std::ifstream abrirArquivo(std::string nome){
    std::ifstream arquivo(nome);

    //Se não foi possível abrir o arquivo
    if(!arquivo){
        throw std::ios_base::failure("Erro ao abrir arquivo " + nome);
    }
    return arquivo;
}


void lerMatriz(std::vector < std::vector<int>>& matriz,std::ifstream& arquivo,int& n,int& m){
    std::string str;
    std::vector<int> aux;
    for(int i=0; i < n; ++i){
        for (int j=0; j < m; ++j) {
            arquivo >> str;
            aux.push_back(std::stoi(str));
        }
        matriz.push_back(aux);
    }
    arquivo.close();
}

void criarArquivoMatrizResultante(std::vector < std::vector<int>> matrizResultado, int n,int m, std::string origem){
    //Abrindo aquivo dos resultados de tempo
    std::string nomeArquivoResultados = "../resultados/"+origem+"_" + std::to_string(n) + "x" + std::to_string(m) + "_resultados" + ".txt";
    std::ofstream arquivo(nomeArquivoResultados);

    //Se não foi possível abrir o arquivo
    if(!arquivo){
        std::cerr << "Erro ao abrir arquivo " + nomeArquivoResultados << std::endl;

        //Imprimindo resultado no terminal
        std::cout << "Resultado: " << std::endl;
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                std::cout << matrizResultado[i][j] << " ";
            }
            std::cout << std::endl;
        }

        throw std::ios_base::failure("Erro ao abrir arquivo " + nomeArquivoResultados);
    }

    //Escrevendo matriz no arquivo
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            arquivo << matrizResultado[i][j] << " ";
        }
        arquivo << std::endl;
    }

    arquivo.close();
}

