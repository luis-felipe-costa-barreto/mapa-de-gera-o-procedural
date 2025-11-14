#include <iostream>


template <typename T>
class Sequencia{
   int capacidade, tamanho;
   T *dados;


   void aumentaCapacidade(){
       capacidade *= 2;
       T *novo = new T[capacidade];
       for (int i = 0; i < tamanho; i++){
           novo[i] = dados[i];
       }
       delete[] dados;
       dados = novo;
   }


   public:
       Sequencia(int t = 0, int c = 2){
           tamanho = t;
           capacidade = c;
           dados = new T[capacidade];
       }
       int obterTamanho(){
           return tamanho;
       }
       void adicionar(T valor){
           if (tamanho >= capacidade){
               aumentaCapacidade();
           }
           dados[tamanho] = valor;
           tamanho++;
       }
       T get(int i){
           if ((i < 0) or (i >= tamanho)){
               std::cerr << "Erro: índice inválido";
           }
           return dados[i];
       }
       void set(int i, T valor){
           if ((i < 0) or (i >= tamanho)){
               std::cerr << "Erro: índice inválido";
           }
           dados[i] = valor;
       }
       void removerUltimo(){
           if (tamanho <= 0){
               std::cerr << "Erro: Lista vazia";
           }
           tamanho--;
       }
       ~Sequencia(){
           delete[] dados;
       }
};