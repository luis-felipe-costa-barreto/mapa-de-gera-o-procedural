#include "./terreno/terreno.h"
using namespace std;

int main(){
    string hex, ppm;
    int n;
    cin >> hex >> n >> ppm;
    Terreno terreno;
    terreno.criarTerreno(hex, n, ppm);
    return 0;
}