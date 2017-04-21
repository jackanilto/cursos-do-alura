#include <stdio.h>

// int main(){
//   int operacao;
//   int a;
//   int b;
//   scanf("%d", &operacao);
//   scanf("%d", &a);
//   scanf("%d", &b);
//   if(operacao == 1){
//     printf("%d + %d = %d\n", a, b, a+b);
//   }else if(operacao == 2){
//     printf("%d + %d = %d\n", a, b, a-b);
//   }else if(operacao == 3){
//     printf("%d + %d = %d\n", a, b, a*b);
//   }else if(operacao == 4){
//     printf("%d + %d = %d\n", a, b, a/b);
//   }
// }

int main(){
  int numero;
  scanf("%d", &numero);
  for(int i = 1; i<= 10; i++){
    printf("%dx%d=%d\n", numero, i, numero*i);
  }
}
