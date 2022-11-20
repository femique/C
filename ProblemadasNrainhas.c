/*Neste programa foi implementado  um programa para encontrar
todas as possibilidades de posicionar N “rainhas especiais” em um tabuleiro
de xadrez generalizado, com N linhas e N colunas. A condição exigida é que
nenhuma das N rainhas especiais ataque outra. Além disso, foi preciso
computar, dentre todas as configurações possíveis, quantas vezes cada rainha
especial aparece em cada posição do tabuleiro.*/


#include <stdio.h>
#include <stdlib.h>
#define NMAX 100
#define MMAX 100
#define TRUE 1
#define FALSE 0

void generate(int N, int b, int c, int r, int f, int v);
int valid(int a[], int y, int w, int N, int b, int c, int r);
int ptorre(int a[], int y, int w);
int pbispo(int a[], int y, int w, int N, int b);
int pcavalo(int a[], int y, int w, int N, int c);
int prei (int a[], int y, int w, int N, int r);
void print(int a[], int N, int f, int v, double t[][NMAX]);
int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int r = atoi(argv[4]);
    int f = atoi(argv[5]);
    int v = atoi(argv[6]);
    generate(N, b, c, r, f, v);
    return 0;
}

void generate(int N, int b, int c, int r, int f, int v)
{
  int a[NMAX];
  int y = 0, w = 0, m, n;
  int nsolu = 0;
  double t[MMAX][NMAX];
  for (m = 0; m < N; ++m){
    for (n = 0; n < N; ++n){
        t[m][n] = 0;
    }
  }
  while (TRUE){
    if (w == N)
      if (y == 0) break;
      else w = a[--y] + 1;
  else {
      if (!valid(a, y, w, N, b, c, r)) {
	w++;
	continue;
      }
      a[y++] = w;
      w = 0;
      if (y == N) {
	  nsolu++;
	  print(a, N, f, v, t);
	  w = a[--y] + 1;

      }
    }
  }
    if (nsolu != 0) printf("Total de solucoes: %d\n\n", nsolu);
    if ((f == 1) && (nsolu > 0)){
        int mv, nv;
        printf("Mapa de frequencias\n");
            for (mv = 0; mv < N; ++mv){
                for (nv = 0; nv < N; ++nv){
                    t[mv][nv] = t[mv][nv] / nsolu;
                    printf("%.4f ", t[mv][nv]);
                }
                printf("\n");
            }
    }
    if (nsolu ==  0) printf("Nao ha solucoes\n");
    if ((nsolu == 0) && (f == 1)) printf("Mapa de frequencia indefinido (nao ha solucao)");

}


int valid(int a[], int y, int w, int N, int b, int c, int r)
{
    if (!ptorre(a, y, w)) return FALSE;
    if (!pbispo(a, y, w, N, b)) return FALSE;
    if (!pcavalo(a, y, w, N, c)) return FALSE;
    if (!prei(a, y, w, N, r)) return FALSE;
    return TRUE;
}

int ptorre(int a[], int y, int w)
{
    int j;
    for (j = 0; j < y; ++j){
        if (a[j] == w) return FALSE;
    }
    return TRUE;
}

int pbispo(int a[], int y, int w, int N, int b)
{
    if (b == 1){
        int j, gg = y - 1;
        int k = 1;
        if (gg < 0) return TRUE;
        for (j = gg; j >= 0; --j){
            if ((a[j] == w + k) || (a[j] == w - k)) return FALSE;
            k++;
            }
        }
        return TRUE;
}

int pcavalo(int a[], int y, int w, int N, int c)
{
    if (c == 1){
        int j =  y - 1;
        if (j < 0) return TRUE;
        if ((a[j] == w + 2) || (a[j] == w - 2)) return FALSE;
        if (j > 0) {
            j--;
            if ((a[j] == w + 1) || (a[j] == w - 1)) return FALSE;
        }
    }
    return TRUE;
}

int prei (int a[], int y, int w, int N, int r)
{
     if (r ==1) {
        int j = y - 1;
        if (j < 0) return TRUE;
        if ((a[j] == w - 1) || (a[j] == w + 1)) return FALSE;
        }
     return TRUE;
}
void print(int a[], int N, int f, int v, double t[][NMAX])
{
        char s[MMAX][NMAX];
        int ns, ms, p, PP = N - 1;
        for (ms = 0; ms < N; ms++)
            for (ns = 0; ns < N; ns++)
                    s[ms][ns] = '-';
        for(p = PP; p >= 0; --p){
            s[a[p]][p] = 'X';
            t[a[p]][p] = t[a[p]][p] + 1;
        }
        if (v == 1){
            int mv, nv;
            for (mv = 0; mv < N; ++mv){
                for ( nv = 0; nv < N; ++nv){
                    printf("%c ", s[mv][nv]);
                }
                printf("\n");
            }
            printf("\n");
        }
}



