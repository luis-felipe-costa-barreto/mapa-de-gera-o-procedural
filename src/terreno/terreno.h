#include "../imagem/imagem.h"
#include <cstdlib>
#include <ctime>

class Terreno{
    float rugosidade;
    int limite;
    Matriz<int> entradas;
    void formatar(){
        srand(time(0));
        int valor = (rand()%((2*limite) + 1) - limite);
    }
    void diamond(){}
    void square(){}
    public:
        Terreno(int n = 0, float rug = 0.5){
            rugosidade = rug;
            entradas = Matriz<int> ((n * n) + 1, (n * n) + 1);
            limite = 100;
            formatar();
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