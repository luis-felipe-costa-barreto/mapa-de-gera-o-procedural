#include "../imagem/imagem.h"

class Terreno{
    float rugosidade;
    Matriz<int> entradas;
    public:
        Terreno(int n = 0, float rug = 0.5){
            rugosidade = rug;
            entradas = Matriz<int> ((n * n) + 1, (n * n) + 1);
        }
        int obterLargura(){
            return entradas.getColunas();
        }
        int obterProfundidade(){
            return entradas.getLinhas();
        }
};