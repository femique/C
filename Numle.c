/* Um programa em C (versão númerica do jogo Wordle) no qual o objetivo do usuário é acertar um número inteiro positivo com entre
0 e 99999 gerado aleatoriamente pelo programa. Utilizou-se o básico da lingugem C (sem a utilização de vetores, por exemplo)*/


#include <stdio.h>


int main()
 {
     int semente, senha, t, chute, dsenha1, dsenha2, dsenha3, dsenha4, dsenha5, dchute1, dchute2, dchute3, dchute4, dchute5, senhamod, chutemod, dcerto1 = 11, dcerto2 = 12 , dcerto3 = 13 , dcerto4 = 14, dcerto5 ;
     printf("Bem vinda(o) ao Numle\n");
     printf("Digite a semente para sortear a senha (0 a 10000):");
     scanf("%d", &semente);
     semente = semente % 134456;
     senha = ((8121 * semente + 28411) % 134456) % 100000;
     printf("Quantidade de tentativas (1 a 10):");
     scanf("%d", &t);
     senhamod = senha;
     dsenha5 = senhamod % 10;
     senhamod = senhamod / 10;
     dsenha4 = senhamod % 10;
     senhamod = senhamod / 10;
     dsenha3 = senhamod % 10;
     senhamod = senhamod / 10;
      dsenha2 = senhamod % 10;
      senhamod = senhamod / 10;
      dsenha1 = senhamod % 10;

     while (t-- > 0) {
        printf ("\nDigite a tentativa (0 a 99999):");
        scanf("%d", &chute);
       chutemod = chute;
        dchute5 = chutemod % 10;
        chutemod = chutemod / 10;
        dchute4 = chutemod % 10;
        chutemod = chutemod / 10;
        dchute3 = chutemod % 10;
        chutemod = chutemod / 10;
        dchute2 = chutemod % 10;
        chutemod = chutemod / 10;
        dchute1 = chutemod % 10;

        if ( dchute1 == dsenha1 && dchute2 == dsenha2 && dchute3 == dsenha3 && dchute4 == dsenha4 && dchute5 == dsenha5 ) {
            printf("Voce acertou! A senha eh de fato %d.", senha);
            return 0;
        }

        if ( dchute1 == dsenha1 ) {
            printf("Primeiro digito certo!\n");
            dcerto1 = dchute1;
        }
        if ( dchute2 == dsenha2 ) {
            printf("Segundo digito certo!\n");
            dcerto2 = dchute2;
        }
        if ( dchute3 == dsenha3 ) {
            printf("Terceiro digito certo!\n");
            dcerto3 = dchute3;

        }
        if ( dchute4 == dsenha4 ) {
            printf("Quarto digito certo!\n");
            dcerto4 = dchute4;

        }
        if ( dchute5 == dsenha5 ) {
            printf("Quinto digito certo!\n");
            dcerto5 = dchute5;
        }

        if ( dchute1 != dsenha1 && dchute1 != dcerto2 && dchute1 != dcerto3 && dchute1 != dcerto4 && dchute1 != dcerto5 ){
                 if ( dchute1 == dsenha2 || dchute1 == dsenha3 || dchute1 == dsenha4 || dchute1 == dsenha5 ) {
                 printf("Primeiro digito em posicao incorreta.\n");
                 }
        }
        if ( dchute2 != dsenha2 && dchute2 != dchute1 && dchute2 != dcerto1 && dchute2 != dcerto3 && dchute2 != dcerto4 && dchute2 != dcerto5 ) {
                 if ( dchute2 == dsenha1 || dchute2 == dsenha3 || dchute2 == dsenha4 || dchute2 == dsenha5 ) {
                 printf("Segundo digito em posicao incorreta.\n");
                 }
        }
        if (dchute3 != dsenha3 && dchute3 != dchute2 && dchute3 != dchute1 && dchute3 != dcerto2 && dchute3 != dcerto1 && dchute3 != dcerto4 && dchute3 != dcerto5){
                 if ( dchute3 == dsenha1 || dchute3 == dsenha2 || dchute3 == dsenha4 || dchute3 == dsenha5 ) {
                 printf("Terceiro digito em posicao incorreta.\n");
                 }
        }
        if (dchute4 != dsenha4 && dchute4 != dchute1 && dchute4 != dchute2 && dchute4 != dchute3 && dchute4 != dcerto2 && dchute4 != dcerto3 && dchute4 != dcerto1 && dchute4 != dcerto5) {
                 if ( dchute4 == dsenha1 || dchute4 == dsenha3 || dchute4 == dsenha2 || dchute4 == dsenha5 ) {
                 printf("Quarto digito em posicao incorreta.\n");
                 }
        }
        if (dchute5 != dsenha5 && dchute5 != dchute1 && dchute5 != dchute2 && dchute5 != dchute3 && dchute5 != dchute4 && dchute5 != dcerto2 && dchute5 != dcerto3 && dchute5 != dcerto4 && dchute5 != dcerto1){
                 if ( dchute5 == dsenha1 || dchute5 == dsenha2 || dchute5 == dsenha3 || dchute5 == dsenha4 ) {
                 printf("\nQuinto digito em posicao incorreta.\n");
                 }
        }

        }
        printf("Vc perdeu! A senha era %d.", senha);
        return 0;

     }




