//#include <iostream>
//#include <random>
//#include <fstream>
//
//using namespace std;
//
//int main(int argc, char const *argv[]){
//    //Definindo dimensões das matrizes
//    string n1 = argv[1];
//    string m1 = argv[2];
//    string n2 = argv[3];
//    string m2 = argv[4];
//    int dim_n1 = atoi(argv[1]);
//    int dim_m1 = atoi(argv[2]);
//    int dim_n2 = atoi(argv[3]);
//    int dim_m2 = atoi(argv[4]);
//
//    if(dim_n1 != dim_m2){
//        cout<<("Não é possível multiplicar essas matrizes\n");
//        return 0;
//    }
//
//
//    ofstream matrizA;
//    ofstream matrizB;
//
//    matrizA.open("../matrizes/matriz_A_"+n1+"X"+m1+".txt");
//    matrizB.open("../matrizes/matriz_B_"+n2+"X"+m2+".txt");
//
//    matrizA << dim_n1 << " " << dim_m1 << endl;
//    matrizB << dim_n2 << " " << dim_m2 << endl;
//
//    //Gerando números aleatórios
//    for(int i = 0; i < dim_n1; i++){
//        vector<int> linha;
//        for(int j = 0; j < dim_m1; j++){
//            matrizA << rand() % 10 + 1 << " ";
//        };
//        matrizA << endl;
//    };
//    matrizA.close();
//
//    for(int i = 0; i < dim_n2; i++){
//        vector<int> linha;
//        for(int j = 0; j < dim_m2; j++){
//            matrizB << rand() % 10 + 1 << " ";
//        };
//        matrizB << endl;
//    };
//    matrizB.close();
//
//    cout << "Matrizes geradas com sucesso!" << endl;
//    return 0;
//}