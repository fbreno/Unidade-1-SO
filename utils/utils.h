#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <iostream>
#include <vector>

std::ifstream abrirArquivo(std::string nome);
void lerMatriz(std::vector < std::vector<int>>& matriz,std::ifstream& arquivo,int& n,int& m);
void criarArquivoMatrizResultante(std::vector < std::vector<int>> matrizResultado, int n,int m, std::string origem);


#endif