#include "../paleta/paleta.h"
#include <iostream>

typedef Cor Pixel;

template <typename T>
class Matriz{
    int linhas, colunas, maximo;
    T *entradas;
    void incremento(){
        maximo *= 2;
        T *novo = new T[maximo];
        for (int i = 0; i < (linhas * colunas); i++){
            novo[i] = entradas[i];
        }
        delete[] entradas;
        entradas = novo;
    }

    public:
        Matriz(int l = 0, int c = 0){
            linhas = l;
            colunas = c;
            maximo = 4;
            entradas = new T[maximo];
            while ((linhas * colunas) >= maximo){
                incremento();
            }
        }
        

};

class Imagem{
    Sequencia<Sequencia<Pixel>> pixels;
    public:
        
};