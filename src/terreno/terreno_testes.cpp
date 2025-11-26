#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "terreno.h"
#include <iostream>

TEST_CASE("Testa a criação de um terreno de uma única célula") {
  Terreno terreno(0); // 2^0 + 1 = 1
  CHECK(terreno.obterLargura() == 2);
  CHECK(terreno.obterProfundidade() == 2);
}

TEST_CASE("Testa a geração aleatória de altitudes") {
  Terreno terreno(2);
  CHECK(terreno.obterLargura() == 5);
  CHECK(terreno.obterProfundidade() == 5);
}

TEST_CASE("Aleatórios"){
  Terreno terreno(2);
  for(int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      cout << terreno(j,i) << ' ';
    }
    cout << endl;
  }
}

// Você precisará criar testes adicionais para cobrir os métodos privados da classe.
// Por exemplo, você pode criar testes para os métodos das etapas Square e Diamond
// Você pode torná-los públicos temporariamente para fins de teste ou usar técnicas como "friend testing".