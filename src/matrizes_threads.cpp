#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <fstream>
#include "../utils/utils.h"

using namespace std;

vector<vector<int>> resultado;

void calculaLinha(vector<int> linhaMatrizA,int numLinha,vector<vector<int>> matrizB,int aM,int bM){
    for(int i=0; i < aM; ++i){
        int soma = 0;
        resultado.emplace_back();
        for(int j=0; j < bM; ++j) {
            soma += linhaMatrizA[j] * matrizB[j][i];
        }
        resultado[numLinha].push_back(soma);
    }
}

void multiplicaMatrizes(vector<vector<int>> matriz1,vector<vector<int>> matriz2,int aN,int aM,int bN,int bM){
    thread threads[aN];
    for(int i=0; i < aN; ++i){
        //Instancia e inicia as threads para calcular as linhas da matriz produto
        threads[i] = thread(calculaLinha,matriz1[i],i,matriz2,aM,bM);
    }

    //Espera as threads finalizarem
    for(int i=0; i < aN; ++i){
        threads[i].join();
    }
}


int main(int argc,char const* argv[]){

    string strM1(argv[1]);
    string strM2(argv[2]);


    ifstream arquivoMatrizA = abrirArquivo(strM1);
    ifstream arquivoMatrizB = abrirArquivo(strM2);

    int aN = 0,aM = 0,bN = 0,bM = 0;
    arquivoMatrizA >> aN >> aM;
    arquivoMatrizB >> bN >> bM;

    vector < vector<int>> matrizA;
    vector < vector<int>> matrizB;
    vector < vector<int>> matrizResultado;

    lerMatriz(matrizA,arquivoMatrizA,aN,aM);
    lerMatriz(matrizB,arquivoMatrizB,bN,bM);

    //Inicio da contagem de tempo
    //====================================================================================
    auto start = chrono::steady_clock::now();

    multiplicaMatrizes(matrizA,matrizB,aN,aM,bN,bM);

    auto end = chrono::steady_clock::now();
    //Fim da contagem de tempo
    //====================================================================================
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    criarArquivoMatrizResultante(resultado,aN,bM, "matriz_resultado_threads");


    return 0;
}

