#include "../imagem/imagem.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

class Terreno{
    float rugosidade;
    Matriz<int> entradas;
    void extremos(int x){
        entradas(0,0) = (rand()%((2*(x/2)) + 1) - (x/2));
        entradas((x-1),0) = (rand()%((2*(x/2)) + 1) - (x/2));
        entradas(0,(x-1)) = (rand()%((2*(x/2)) + 1) - (x/2));
        entradas((x-1),(x-1)) = (rand()%((2*(x/2)) + 1) - (x/2));
    }
    void formatar(int indice){
        int incremento, i_provisorio, limite = obterProfundidade();
        for(int i = 0; i < indice; i++){
            limite *= rugosidade;
            incremento = (obterProfundidade() - 1)/pow(2,i);
            for(int i = 0; i < ((obterProfundidade() - 1) / incremento); i++){
                i_provisorio = 0;
                while (i_provisorio != ((obterProfundidade() - 1) / incremento)){
                    diamond((incremento * i), incremento * (i + 1),(incremento * i_provisorio), incremento * (i_provisorio + 1), limite);
                    square((incremento * i), incremento * (i + 1),(incremento * i_provisorio), incremento * (i_provisorio + 1), limite);
                    i_provisorio++;
                }
            }
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
            for (int i = 0; i < x; i++){
                for (int j = 0; j < x; j++){
                    entradas(i,j) = 0;
                }
            }
            srand(time(0));
            extremos(x);
            formatar(n);
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
        int maior_pico(){
            int retorno = entradas(0, 0);
            for (int i = 0; i < obterProfundidade(); i++){
                for (int j = 0; j < obterLargura(); j++){
                    if (entradas(i, j) > retorno){
                        retorno = entradas(i, j);
                    }
                }
            }
            return retorno;
        }
        int menor_vale(){
            int retorno = entradas(0, 0);
            for (int i = 0; i < obterProfundidade(); i++){
                for (int j = 0; j < obterLargura(); j++){
                    if (entradas(i, j) < retorno){
                        retorno = entradas(i, j);
                    }
                }
            }
            return retorno;
        }
        void criarTerreno(string hex, int n, string ppm){
            Paleta paleta = {hex};
            int x = pow(2, n) + 1;
            entradas = Matriz<int>(x, x);
            for (int i = 0; i < x; i++){
                for (int j = 0; j < x; j++){
                    entradas(i,j) = 0;
                }
            }
            extremos(x);
            formatar(n);
            int intervalo = x / paleta.obterTamanho();
            Imagem imagem = {x, x};
            int divisao;
            for (int i = 0; i < x; i++){
                for(int j = 0; j < x; j++){
                    divisao = (entradas(i, j) + abs(menor_vale())) / intervalo;
                    if (divisao >= paleta.obterTamanho()){
                        divisao = paleta.obterTamanho() - 1;
                    }
                    imagem(j, i) = paleta.obterCor(divisao);
                    if ((i != 0) and (j != 0) and (entradas(i-1,j-1) > entradas(i,j))){
                        imagem(j,i).r *= 0.8;
                        imagem(j,i).g *= 0.8;
                        imagem(j,i).b *= 0.8;
                    }
                }
            }
            imagem.salvarPPM(ppm);
        }
};