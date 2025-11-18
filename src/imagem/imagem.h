#include "../paleta/paleta.h"
#include <iostream>

typedef Cor Pixel;

template <typename T>
class Matriz{
    int linhas, colunas, maximo;
    T *entradas;

    /*void incremento(){
        maximo *= 2;
        T *novo = new T[maximo];
        for (int i = 0; i < (linhas * colunas); i++){
            novo[i] = entradas[i];
        }
        delete[] entradas;
        entradas = novo;
    }*/

    public:
        Matriz(int l = 0, int c = 0){
            linhas = l;
            colunas = c;
            maximo = (l * c);
            entradas = new T[maximo];
        }
        T& operator()(int l, int c){
            if ((l < 0) or (c < 0) or (l >= linhas) or (c >= colunas)){
                cerr << "índice fora dos limites permitidos" << endl;
            }
            return (entradas[(l * colunas) + c]);
        }
        int getLinhas(){
            return linhas;
        }
        int getColunas(){
            return colunas;
        }
        ~Matriz(){
            delete[] entradas;
        }
        Matriz<T>& operator=(const Matriz<T>& outra) {
            if (this != &outra) { 
                delete[] entradas;
                linhas = outra.linhas;
                colunas = outra.colunas;
                maximo = outra.maximo;
                entradas = new T[maximo];
                for (int i = 0; i < maximo; i++) {
                    entradas[i] = outra.entradas[i];
                }
            }
            return *this;
        }
};

class Imagem{
    Matriz<Pixel> pixels;
    public:
        Imagem(int c = 0, int l = 0){
            pixels = Matriz<Pixel> (l, c);
        }
        int obterLargura(){
            return pixels.getColunas();
        }
        int obterAltura(){
            return pixels.getLinhas();
        }
        Pixel& operator()(int l, int c){
            return pixels(l,c);
        }
        void lerPPM(string arquivo){
            ifstream file(arquivo);
            if (file.is_open()){

            }
        }
};