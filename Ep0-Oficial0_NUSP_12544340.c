/***************************************************************/
/**                                                           **/
/**  Fernando F. Miqueletti N�mero USP:12544340               **/
/**   Exerc�cio-Programa 0                                    **/
/**   Professor:Yoshiharu Kohayakawa                          **/
/**   Turma: 3                                                **/
/**                                                           **/
/***************************************************************/







#include <stdio.h>

int main()
{
    int senha, semente, chute, tentativas;
    printf("Bem vinda(o) ao Numle\n");
    printf("Digite a semente para sortear a senha (0 a 10000):");
    scanf("%d", &semente);
    semente = semente % 134456;
    senha = ((8121 * semente + 28411) % 134456) % 10;
    printf("Quantidade de tentativas (1 a 10):");
    scanf("%d", &tentativas);
    while (tentativas-- > 0) {
        printf("Digite a tentativa (0 a 9):");
        scanf("%d", &chute);
        if (chute == senha) {
            printf("Voce acertou! A senha eh de fato %d", senha);
            return 0;
        }
    }
    printf("Voce perdeu! A senha era %d", senha);
    return 0;
}
