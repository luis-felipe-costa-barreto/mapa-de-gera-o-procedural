#include "../imagem/imagem.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

class Terreno{
    float rugosidade;
    Matriz<int> entradas;
    void formatar(int inicio_l, int fim_l, int inicio_c, int fim_c, int novo_lim){
        if((fim_l - inicio_l) > 1){
            novo_lim *= rugosidade;
            diamond(inicio_l, fim_l, inicio_c, fim_c, novo_lim);
            square(inicio_l, fim_l, inicio_c, fim_c, novo_lim);
            formatar(inicio_l, (inicio_l + fim_l)/2, inicio_c, (inicio_c + fim_c)/2, novo_lim); //Q2
            formatar((inicio_l + fim_l)/2, fim_l, (inicio_c + fim_c)/2, fim_c, novo_lim); //Q4
            formatar(inicio_l, (inicio_l + fim_l)/2, (inicio_c + fim_c)/2, fim_c, novo_lim); //Q1
            formatar((inicio_l + fim_l)/2, fim_l, inicio_c, (inicio_c + fim_c)/2, novo_lim); //Q3
        }
    }
    void diamond(int inicio_l, int fim_l, int inicio_c, int fim_c, int novo_lim){
        int valor = (rand()%((2*novo_lim) + 1) - novo_lim);
        int media = ((entradas(inicio_c,inicio_l)+entradas(inicio_c,fim_l)+entradas(fim_c,inicio_l)+entradas(fim_c,fim_l))/4);
        entradas((fim_c+inicio_c)/2,(fim_l+inicio_l)/2) = media + valor;
    }
    void square(int inicio_l, int fim_l, int inicio_c, int fim_c, int novo_lim){
        int valor, media, centro = entradas((fim_c+inicio_c)/2, (fim_l+inicio_l)/2);
        valor = (rand()%((2*novo_lim) + 1) - novo_lim);
        media = ((entradas(inicio_c, inicio_l) + entradas(inicio_c,fim_l) + centro)/3);
        entradas(inicio_c,(fim_l+inicio_l)/2) = media + valor;
        valor = (rand()%((2*novo_lim) + 1) - novo_lim);
        media = ((entradas(inicio_c, inicio_l) + entradas(fim_c, inicio_l) + centro)/3);
        entradas((fim_c+inicio_c)/2, inicio_l) = media + valor;
        valor = (rand()%((2*novo_lim) + 1) - novo_lim);
        media = ((entradas(fim_c, inicio_l) + entradas(fim_c,fim_l) + centro)/3);
        entradas(fim_c, (fim_l+inicio_l)/2) = media + valor;
        valor = (rand()%((2*novo_lim) + 1) - novo_lim);
        media = ((entradas(inicio_c, fim_l) + entradas(fim_c,fim_l) + centro)/3);
        entradas((fim_c+inicio_c)/2, fim_l) = media + valor;
    }
    public:
        Terreno(int n = 0, float rug = 0.5){
            rugosidade = rug;
            int x = pow(2, n) + 1;
            entradas = Matriz<int> (x, x);
            int limite = x / 2;
            srand(time(0));
            entradas(0,0) = (rand()%((2*limite) + 1) - limite);
            entradas((x-1),0) = (rand()%((2*limite) + 1) - limite);
            entradas(0,(x-1)) = (rand()%((2*limite) + 1) - limite);
            entradas((x-1),(x-1)) = (rand()%((2*limite) + 1) - limite);
            formatar(0, x-1, 0, x-1, limite);
        }
        int obterLargura(){
            return entradas.getColunas();
        }
        int obterProfundidade(){
            return entradas.getLinhas();
        }
        int& operator()(int l, int c){
            if ((l < 0) or (c < 0) or (l >= obterProfundidade()) or (c >= obterLargura())){
                cerr << "Índice inválido" << endl;
            }
            return entradas(c, l);
        }
};