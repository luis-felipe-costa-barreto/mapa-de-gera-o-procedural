#include "../paleta/paleta.h"
#include <iostream>

typedef Cor Pixel;

//teste
class Imagem{
    Sequencia<Sequencia<Pixel>> pixels;
    public:
        Imagem(int c = 0, int l = 0){
            for (int i = 0; i < l; i++){
                Sequencia<Pixel> seq;
                for (int j = 0; j < c; j++){
                    seq.adicionar(Pixel {0,0,0});
                }
                pixels.adicionar(seq);
                cout << pixels.obterTamanho() << endl;
        
            }
        }
        int obterLargura(){
            return pixels.get(0).obterTamanho();
        }
        int obterAltura(){
            return pixels.obterTamanho();
        }
};