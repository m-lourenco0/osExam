#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#include <string.h>

void esperar()
{
    system("sleep 0.5");
}

void tutorial()
{
    system("clear || cls");
    printf("\t\t---------------------------------------------------------------------------------\n");
    printf("\t\t-- Ao iniciar o jogo, você deverá escolher uma dificuldade.                    --\n");
    printf("\t\t-- Feito isso, você deverá escolher o intervalo dos números a serem sorteados. --\n");
    printf("\t\t-- Exemplo: se quiser sortear entre os números 0 e 10, digite: 0 10            --\n");
    printf("\t\t-- A partir dai se inicia o jogo, e você deve tentar acertar o numero secreto  --\n");
    printf("\t\t---------------------------------------------------------------------------------\n\n");
    esperar();
}

void sair()
{
    printf("\n\nSaindo do jogo...\n");
}

int definirDificuldade()
{
    int dif=1;

    do
    {
        printf("\nEscolha a dificuldade: \n");
        printf("1 - Facil (10 tentativas)\n");
        printf("2 - Medio (7 tentativas)\n");
        printf("3 - Dificil (3 tentativas)\n");
        printf("4 - Impossivel (1 tentativa)\n\n");

        printf("Dificuldade: ");
        scanf("%d", &dif);
        printf("\n");

        switch(dif)
        {
            case 1:
                printf("Dificuldade escolhida: %d\n\n", dif);
                return 10;

            case 2:
                printf("Dificuldade escolhida: %d\n\n", dif);
                return 7;

            case 3:
		        printf("Dificuldade escolhida: %d\n\n", dif);
                return 3;
            
            case 4:
		        printf("Dificuldade escolhida: %d\n\n", dif);
                return 1;

            default:
                printf("Digite uma opcao valida\n\n");
        }
    } while(dif);

}

int tentativa(int dificuldade, int sorteado)
{
    int i;
    int tentativa;

    for(i = 1; i <= dificuldade; i++) 
    {
        printf("%d# - Tentativa: ", i);
        scanf("%d", &tentativa);
        if(tentativa == sorteado)
        {
            system("clear || cls");
            printf("\t\t---------------------------------------------------------------------------------\n");
            printf("\t\t--         Parabens, você venceu o desafio! O numero sorteado era: %d          --\n", sorteado);
            printf("\t\t---------------------------------------------------------------------------------\n");
            return 1;
        }
    } 
    return 0;
}

void jogar()
{
    int sorteado, x, y, dif, venceu;

    printf("\t\t---------------------------------------------------------------------------------\n");
    printf("\t\t--                             QUE COMECE O JOGO!                              --\n");
    printf("\t\t---------------------------------------------------------------------------------\n");

    dif = definirDificuldade();

    printf("Digite um intervalo de número a ser sorteado (inteiros): ");
    x = 0;
    y = 0;
    scanf("%d %d", &x, &y);

    printf("Sorteando o numero secreto...\n\n");
    esperar();

    sorteado = aleatorio(x, y);
    venceu = tentativa(dif, sorteado);

    if(venceu == 0)
    {
        system("clear || cls");
        printf("\t\t---------------------------------------------------------------------------------\n");
        printf("\t\t--              Que pena, voce perdeu! O numero sorteado era: %d               --\n", sorteado);
        printf("\t\t---------------------------------------------------------------------------------\n");
    }
}

void validarTutorial()
{ 
    system("clear || cls");
    printf("\nEssa é sua primeira vez jogando, nao é melhor ler o tutorial antes? (s/n): ");
    char a[2] = "  ";
    char b[2] = "s";
    scanf("%s", a);
    printf("\n");
    if(strcmp(a, "s") == 0)
    {
        tutorial();
    }
    else if(strcmp(a, "n") == 0)
    {

    }
    else
    {
        validarTutorial();
    }
}

int main()
{
    int cont=1;
    int visu=0;

    do
    {
        printf("\nEscolha uma opcao: \n\n");
        printf("1 - Jogar\n");
        printf("2 - Tutorial\n");
        printf("0 - Sair\n");
	    printf("\nOpcao: ");

        scanf("%d", &cont);

        switch(cont)
        {
            case 1:
                if(visu == 0)
                {
                    validarTutorial(visu);
                    jogar();
                    break;
                }
                else
                {
                    system("clear || cls");
                    jogar();
                    break;
                }

            case 2:
                tutorial();
                break;

            case 0:
                sair();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
        visu = visu + 1;
    } while(cont);
}