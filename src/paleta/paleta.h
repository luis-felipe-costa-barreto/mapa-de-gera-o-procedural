#include "../sequencia/sequencia.h"

struct Cor{
    int r, g, b;
};

class Paleta{
    int quant;
    Sequencia<Cor> cores;
    public:
        Paleta(){
            quant = 0;
        }
        int obterTamanho(){
            return quant;
        }
        void adicionarCor(Cor cor){
            cores.set(quant,cor);
            quant++;
        }
        Cor obterCor(int i){
            if((i >= quant) or (i < 0)){
                return Cor {0, 0, 0};
            }
            return cores.get(i);
        }
};