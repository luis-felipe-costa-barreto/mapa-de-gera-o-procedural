#include "../paleta/paleta.h"
#include <iostream>

typedef Cor Pixel;

template <typename T>
class Matriz{
    int linhas, colunas, maximo;
    T *entradas;

    void incremento(int parametro = 1){
        bool transfusao = parametro;
        maximo *= 20;
        T *novo = new T[maximo];
        if (transfusao){
            for (int i = 0; i < (linhas * colunas); i++){
                novo[i] = entradas[i];
            }
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
                incremento(0);
            }
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
        void adicionarLinha(){
            linhas++;
            if ((linhas * colunas) >= maximo){
                incremento();
            }
        }
        void adicionarColuna(){
            colunas++;
            if ((linhas * colunas) >= maximo){
                incremento();
            }
        }
        ~Matriz(){
            delete[] entradas;
        }
};

class Imagem{
    Matriz<Pixel> pixels;
    public:
        Imagem(int c = 0, int l = 0){
            for (int i = 0; i < l; i++){
                pixels.adicionarLinha();
            }
            for (int j = 0; j < c; j++){
                pixels.adicionarColuna();
            }
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
};