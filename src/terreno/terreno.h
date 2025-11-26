#include "../imagem/imagem.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

class Terreno{
    float rugosidade;
    int limite;
    Matriz<int> entradas;
    void formatar(int inicio, int fim, float novo_l){
        if(((fim - inicio) > 1) or ((inicio - fim) > 1)){
            novo_l *= rugosidade;
            diamond(inicio, fim);
            square(inicio, fim);
            formatar(inicio, (inicio + fim)/2, novo_l);
            formatar((inicio+fim)/2, fim, novo_l);
            formatar((inicio+fim)/2, inicio, novo_l);
            formatar(fim, (inicio+fim)/2, novo_l);
        }else{
            return;
        }
    }
    void diamond(int inicio, int fim){
        int valor = (rand()%((2*limite) + 1) - limite);
        int media = ((entradas(inicio,inicio)+entradas(inicio,fim)+entradas(fim,inicio)+entradas(fim,fim))/4);
        entradas((fim+inicio)/2,(fim+inicio)/2) = media + valor;
    }
    void square(int inicio, int fim){
        int valor, media, centro = entradas((fim+inicio)/2, (fim+inicio)/2);
        valor = (rand()%((2*limite) + 1) - limite);
        media = ((entradas(inicio, inicio) + entradas(inicio,fim) + centro)/3);
        entradas(inicio,(fim+inicio)/2) = media + valor;
        valor = (rand()%((2*limite) + 1) - limite);
        media = ((entradas(inicio, inicio) + entradas(fim, inicio) + centro)/3);
        entradas((fim+inicio)/2, inicio) = media + valor;
        valor = (rand()%((2*limite) + 1) - limite);
        media = ((entradas(fim, inicio) + entradas(fim,fim) + centro)/3);
        entradas(fim, (fim+inicio)/2) = media + valor;
        valor = (rand()%((2*limite) + 1) - limite);
        media = ((entradas(inicio, fim) + entradas(fim,fim) + centro)/3);
        entradas((fim+inicio)/2, fim) = media + valor;
    }
    public:
        Terreno(int n = 0, float rug = 0.5){
            rugosidade = rug;
            int x = pow(2, n) + 1;
            entradas = Matriz<int> (x, x);
            limite = x * 2;
            srand(time(0));
            entradas(0,0) = (rand()%((2*limite) + 1) - limite);
            entradas((x-1),0) = (rand()%((2*limite) + 1) - limite);
            entradas(0,(x-1)) = (rand()%((2*limite) + 1) - limite);
            entradas((x-1),(x-1)) = (rand()%((2*limite) + 1) - limite);
            formatar(0, x-1, limite);
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