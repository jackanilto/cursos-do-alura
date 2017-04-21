#include <stdio.h>

int main(){
  int x;
  int y;
  printf("Digite o x: ");
  scanf("%d", &x);
  printf("Digite o y: ");
  scanf("%d", &y);

  printf("O resultado da multiplicação de %d vezes %d é igual a %d\n", x, y, (x*y));

}
