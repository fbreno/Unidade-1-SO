//#include <iostream>
//#include <chrono>
//#include <vector>
//#include <fstream>
//#include "../utils/utils.h"
//
//
//using namespace std;
//
//
//// Multiplicação de matrizes
//int main(int argc,char const* argv[]){
//
//    string strM1(argv[1]);
//    string strM2(argv[2]);
//
//
//    ifstream arquivoMatrizA = abrirArquivo(strM1);
//    ifstream arquivoMatrizB = abrirArquivo(strM2);
//
//    int aN = 0,aM = 0,bN = 0,bM = 0;
//    arquivoMatrizA >> aN >> aM;
//    arquivoMatrizB >> bN >> bM;
//
//    vector < vector<int>> matrizA;
//    vector < vector<int>> matrizB;
//    vector < vector<int>> matrizResultado;
//
//    lerMatriz(matrizA,arquivoMatrizA,aN,aM);
//    lerMatriz(matrizB,arquivoMatrizB,bN,bM);
//
//    //inicio da contagem de tempo
//    auto start = chrono::steady_clock::now();
//    for(int i =0; i < aN; ++i){
//        vector<int> linha;
//        for(int j=0; j < bM; ++j){
//            int soma = 0;
//            for(int k=0; k < aM; ++k){
//                soma += matrizA[i][k] * matrizB[k][j];
//            }
//            linha.push_back(soma);
//        }
//        matrizResultado.push_back(linha);
//    }
//    //fim da contagem de tempo
//    auto end = chrono::steady_clock::now();
//    auto diff = end - start;
//    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
//
//    return 0;
//}
