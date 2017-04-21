#include <stdio.h>
//Biblioteca para usar o absoluto
#include <stdlib.h>
//Biblioteca para usar o random
#include <time.h>

int main() {

  // imprime o cabeçalho do nosso jogo!
  printf("  /$$$$$$$                                           /$$                 /$$                 /$$\n");
  printf(" | $$__  $$                                         |__/                | $$                | $$\n");
  printf(" | $$  \\ $$  /$$$$$$  /$$$$$$/$$$$        /$$    /$$ /$$ /$$$$$$$   /$$$$$$$  /$$$$$$       | $$\n");
  printf(" | $$$$$$$  /$$__  $$| $$_  $$_  $$      |  $$  /$$/| $$| $$__  $$ /$$__  $$ /$$__  $$      | $$\n");
  printf(" | $$__  $$| $$$$$$$$| $$ \\ $$ \\ $$       \\  $$/$$/ | $$| $$  \\ $$| $$  | $$| $$  \\ $$      |__/\n");
  printf(" | $$  \\ $$| $$_____/| $$ | $$ | $$        \\  $$$/  | $$| $$  | $$| $$  | $$| $$  | $$          \n");
  printf(" | $$$$$$$/|  $$$$$$$| $$ | $$ | $$         \\  $/   | $$| $$  | $$|  $$$$$$$|  $$$$$$/       /$$\n");
  printf(" |_______/  \\_______/|__/ |__/ |__/          \\_/    |__/|__/  |__/ \\_______/ \\______/       |__/\n");


  //Função para conseguir um número aleatório
  int segundos = time(0);
  srand(segundos);
  int numeroGrande = rand();

  int numeroSecreto = numeroGrande % 100;
  int chute;
  int tentativas = 1;
  double pontos = 1000;
  int acertou = 0;
  int nivel;
  printf("Qual o nível de dificuldade?\n");
  printf("(1) Fácil (2) Médio (3)Difícil\n\n");
  printf("Escolha: ");
  scanf("%d", &nivel);

  int numeroTentativas;
  switch (nivel) {
    case 1:
      numeroTentativas = 20;
      break;
    case 2:
      numeroTentativas = 15;
      break;
    default:
      numeroTentativas = 6;
      break;
  }

  for(int i = 1; i <= numeroTentativas; i++) {
    printf("Tentativa %d\n", tentativas);
    printf("Qual é o seu chute? ");
    // lê o número do jogador! na variável sempre deve haver um & comercial
    scanf("%d", &chute);
    printf("Seu chute foi %d\n", chute);

    if(chute < 0){
      printf("Você não pode chutar números negativos!\n");
      continue;
    }

    acertou = (chute == numeroSecreto);
    int maior = chute > numeroSecreto;

    if(acertou){
      break;
    }
    else if(maior){
        printf("Seu chute foi maior que o número secreto!\n");
      }
    else{
        printf("Seu chute foi menor que o número secreto!\n");
    }
    tentativas+=1;
    double pontosPerdidos = abs(chute - numeroSecreto) / (double)2;
    pontos = pontos - pontosPerdidos;


  }

  printf("Fim de jogo!\n");

  if(acertou){
    printf("  __      __        //\\    _____             _                   _ \n");
    printf("  \\ \\    / /       |/ \\|  / ____|           | |                 | |\n");
    printf("   \\ \\  / /__   ___ ___  | |  __  __ _ _ __ | |__   ___  _   _  | |\n");
    printf("    \\ \\/ / _ \\ / __/ _ \\ | | |_ |/ _` | '_ \\| '_ \\ / _ \\| | | | | |\n");
    printf("     \\  / (_) | (_|  __/ | |__| | (_| | | | | | | | (_) | |_| | |_|\n");
    printf("      \\/ \\___/ \\___\\___|  \\_____|\\__,_|_| |_|_| |_|\\___/ \\__,_| (_)\n");
    printf("Você acertou em %d tentativas\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos);
  }else{
    printf("__      __        //\\   _____             _              _\n");
    printf("\\ \\    / /       |/ \\| |  __ \\           | |            | |\n");
    printf(" \\ \\  / /__   ___ ___  | |__) |__ _ __ __| | ___ _   _  | |\n");
    printf("  \\ \\/ / _ \\ / __/ _ \\ |  ___/ _ \\ '__/ _` |/ _ \\ | | | | |\n");
    printf("   \\  / (_) | (_|  __/ | |  |  __/ | | (_| |  __/ |_| | |_|\n");
    printf("    \\/ \\___/ \\___\\___| |_|   \\___|_|  \\__,_|\\___|\\__,_| (_)\n");
  }

}
