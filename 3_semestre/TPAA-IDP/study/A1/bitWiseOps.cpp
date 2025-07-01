#include <bits/stdc++.h>
using namespace std;

void ops(){
    /*Operaçãoes bit a bit:
        ~x op binária complementar
        x & y op E bit a bit entre x e y
        x | y op OU bit a bit entre x e y
        x ^ y op XOR bit a bit entre x e y
        x << int op SHIFT LEFT de i posições
        x >> int op SHIFT RIGHT de i posições
    */
 // OPERAÇÃO BITWISE NOT (~) - Inversão dos bits


    // uint8_t define uma variável inteira com 8 bits sem sinal 
    //armazena números de 0 a 255 (apenas positivos)

    uint8_t a = 170; // a = 0b1010'1010 
    uint8_t b = ~a; // b = 0b0101'0101 (85)
    /*a primeira operação binária é a complementar 
    ela inverte o binário da variável, assim como
    mostrado nos comentários ao lado das vars

    ! a inversão não é troca de lugar. o que é zero vira um
    e vice e versa 
    */
    /* O operador ~ inverte os bits:
       1010 1010 (170)
       ↓↓↓↓ ↓↓↓↓
       0101 0101 (85)

       Como uint8_t é um número SEM SINAL, o valor final é 85.
    */

    // int8_t define uma variável inteira com 8 bits com sinal
    //armazena números de -128 a 127

    int8_t c = 5; // 0b0000'0101
    int8_t d = ~c; // 0b11111010 (-6)
    /* essa é a operação binária complementar de 1
    nela, invertemos os bits mas, ao inverter, não 
    obtemos um valor muito distinto.
    essa inversão causa um efeito chamado de 
    complemento de 1. nela, sendo N a variável C,
    a operação executada é a seguinte: (N * -1) - 1
    */
    /* Aqui o operador ~ também inverte os bits:
       0000 0101 (5)
       ↓↓↓↓ ↓↓↓↓
       1111 1010 (isto NÃO é -5!)

       O valor 1111 1010 é interpretado como um número negativo no formato
       **complemento de dois**.
       Para entender esse número, aplicamos a conversão de complemento de dois:

       1. Inverte os bits:
          0000 0101
       2. Soma 1:
          0000 0110 (6 em decimal)

       O resultado é -6, pois 1111 1010 representa -6 em complemento de dois.
    */

    // OPERAÇÃO AND (&) - compara dois valores bit a bit:

    /*
      Nesse caso, a comparação de bits resulta 1 apenas quando os dois bits comparados forem 1.

      0b1100'1100 (204)
      0b1010'1010 (170)
      ___________
      0b1000'1000 (136)
    */

    uint8_t a = 204;
    uint8_t b = 170;
    uint8_t c = a & b; // vai retornar 136

    //OPERAÇÃO OR (|) - retorna 1 apenas quando pelo menos 1 dos bits for = a 1:
   /*
      0b1100'1100
      0b1010'1010
      ___________
      0b1110'1110
   */

   //OPERADOR XOR (^) - retorna 1 apenas quando os bits forem diferentes:
   /*
      0b1100'1100
      0b1010'1010
      ___________
      0b0110'0110
   */


   //OPERADOR SHIFT LEFT (<<) - desloca bits para a esquerda e multiplica por 2ⁿ
   uint8_t x = 5;      // 0000 0101
   uint8_t y = x << 1; // 0000 1010 = 10
   //em termos de multiplicação, seria 2¹
   //outro exemplo:
   int x = 3;
   int y = x << 4; // 3 * 2⁴ = 3 * 16 = 48


   //OPERADOR SHIFT RIGHT (<<) - desloca bits para a direita e divide por 2ⁿ
   uint8_t x = 20;     // 0001 0100
   uint8_t y = x >> 2; // 0000 0101 = 5

}
   // ————————————————————————————————————————————————
// Funções auxiliares “de alta ordem” para manipulação de bits
// ————————————————————————————————————————————————

/**
 * Retorna um valor igual a 'value' com o bit 'pos' forçado a 1.
 */
uint32_t setBit(uint32_t value, unsigned pos) {
   return value | (1u << pos);
}

/**
* Retorna um valor igual a 'value' com o bit 'pos' forçado a 0.
*/
uint32_t clearBit(uint32_t value, unsigned pos) {
   return value & ~(1u << pos);
}

/**
* Retorna um valor igual a 'value' com o bit 'pos' invertido.
*/
uint32_t toggleBit(uint32_t value, unsigned pos) {
   return value ^ (1u << pos);
}

/**
* Testa se o bit 'pos' de 'value' está a 1 (true) ou 0 (false).
*/
bool testBit(uint32_t value, unsigned pos) {
   return (value >> pos) & 1u;
}

/**
* Conta quantos bits 1 existem em 'value' (32 bits).
* Em compiladores GCC/Clang, __builtin_popcount está disponível.
*/
unsigned popcount32(uint32_t value) {
   return __builtin_popcount(value);
}

/**
* Imprime a representação binária de um valor de 32 bits,
* do bit 31 (MSB) até o bit 0 (LSB).
*/
void printBinary(uint32_t value) {
   for (int i = 31; i >= 0; --i) {
       cout << ((value >> i) & 1u);
       if (i % 8 == 0 && i != 0) cout << ' ';  // deixa um espaço a cada byte
   }
}

void printBinary8(uint8_t value) {
   for (int i = 7; i >= 0; --i) {
       cout << ((value >> i) & 1u);
       if (i == 4) cout << '\''; // separa os dois nibbles (4 bits)
   }
}

// ————————————————————————————————————————————————
// Demonstração de uso
// ————————————————————————————————————————————————

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   uint32_t x = 0b0101'0011;  // 83 decimal

   cout << "Valor original:         ";
   printBinary(x);
   cout << "  (" << x << ")\n";

   // 1) Set bit 5
   uint32_t a = setBit(x, 5);
   cout << "setBit(x, 5):           ";
   printBinary(a);
   cout << "  (" << a << ")\n";

   // 2) Clear bit 1
   uint32_t b = clearBit(x, 1);
   cout << "clearBit(x, 1):         ";
   printBinary(b);
   cout << "  (" << b << ")\n";

   // 3) Toggle bit 2
   uint32_t c = toggleBit(x, 2);
   cout << "toggleBit(x, 2):        ";
   printBinary(c);
   cout << "  (" << c << ")\n";

   // 4) Test bit 7
   bool bit7 = testBit(x, 7);
   cout << "testBit(x, 7):          ";
   cout << (bit7 ? "1 (true)\n" : "0 (false)\n");

   // 5) Popcount: quantos bits 1?
   unsigned cnt = popcount32(x);
   cout << "popcount32(x):          " << cnt << "\n";

   // 6) Exemplos de máscaras prontas
   constexpr uint32_t MASK_LO = 0x0F;       // 0000 0000 0000 0000 0000 0000 0000 1111
   constexpr uint32_t MASK_HI = 0xF0000000; // 1111 0000 ... zeros
   cout << "Máscara MASK_LO (0x0F): ";
   printBinary(MASK_LO);
   cout << "\n";
   cout << "Máscara MASK_HI (0xF0..): ";
   printBinary(MASK_HI);
   cout << "\n";

   // 7) Extração de campo (isolar bits 4 a 7):
   uint32_t field = (x >> 4) & 0x0F;
   cout << "Campo bits [7:4] de x:   ";
   printBinary(field);
   cout << "  (" << field << ")\n";

   return 0;
}