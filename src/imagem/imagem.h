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
        Matriz(int c = 0, int l = 0){
            linhas = l;
            colunas = c;
            maximo = (l * c);
            entradas = new T[maximo];
        }
        T& operator()(int c, int l){
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
                for (int i = 0; i < (linhas * colunas); i++) {
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
            pixels = Matriz<Pixel> (c, l);
        }
        int obterLargura(){
            return pixels.getColunas();
        }
        int obterAltura(){
            return pixels.getLinhas();
        }
        Pixel& operator()(int c, int l){
            return pixels(c, l);
        }
        bool lerPPM(string arquivo){
            bool sucesso = true;
            ifstream file(arquivo);
            if (file.is_open()){
                string formato;
                file >> formato;
                if (formato == "P3"){
                    int colunas, linhas, maximo;
                    file >> colunas >> linhas >> maximo;
                    if((obterAltura() != linhas) or (obterLargura() != colunas)){
                        pixels = Matriz<Pixel> (colunas, linhas);
                    }
                    int r, g, b;
                    for (int i = 0; i < linhas; i++){
                        for(int j = 0; j < colunas; j++){
                            file >> r >> g >> b;
                            if((r <= maximo) and (g <= maximo) and (b <= maximo)){
                                pixels(j, i) = Pixel {r, g, b};
                            } else{
                                sucesso = false;
                                cerr << "Valores superiores ao máximo permitido" << endl;
                            }
                        }
                    }
                }else{
                    sucesso = false;
                    cerr << "Formato errado" << endl;
                }
                file.close();
            }
            return sucesso;
        }
};