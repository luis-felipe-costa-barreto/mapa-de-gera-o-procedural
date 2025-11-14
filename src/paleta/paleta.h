#include "../sequencia/sequencia.h"
#include <string>
#include <cctype>
using namespace std;

struct Cor{
    int r, g, b;
};

int soma(string subparte){
    int retorno = 0;
    for(int i = 0; i < 2; i++){
        if((int(subparte[i]) - 48) >= 10){
            retorno += (int(subparte[i]) - 87);
        } else {
            retorno += (int(subparte[i]) - 48);
        }
        if (i == 0){
            retorno *= 16;
        }
    }
    return retorno;
}

Cor conversao(string hex){
    string parte1 = hex.substr(1,2);
    string parte2 = hex.substr(3,2);
    string parte3 = hex.substr(5,2);
    return Cor {soma(parte1), soma(parte2), soma(parte3)};
}

class Paleta{
    int quant;
    Sequencia<Cor> cores;
    public:
        Paleta(string arquivo = ""){
            ifstream file(arquivo);
            if(file.is_open()){
                string linha;
                while(getline(file, linha)){
                    cores.adicionar(conversao(linha));
                }
            }
            file.close();
        }
        int obterTamanho(){
            return cores.obterTamanho();
        }
        void adicionarCor(Cor cor){
            cores.adicionar(cor);
        }
        Cor obterCor(int i){
            if((i > cores.obterTamanho()) or (i < 0)){
                return Cor {0, 0, 0};
            }
            return cores.get(i);
        }
};