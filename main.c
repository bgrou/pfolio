#include <stdio.h>

#define MAX_JOGADAS 20
int Primo(int n)
{
    int divisor = 2;
    while (divisor * divisor <= n) {
        if (n % divisor == 0)
            return 0;
        divisor++;
    }
    return 1;
}

int JPLanceValido(int k, int w) {
    int i;
    if (k < w)
        return 0;
    for(i = 2; i <= k; i++) {
        if (Primo(i) && k%i == 0 && (k - i == w || k/i == w))
            return 1;
    }
    return 0;
}

int JPJogadas(int k, int* jogadas) {
    int posJogadas = 0;
    for (int i = 0; i < k; i++)
    {
        if(JPLanceValido(k, i)) {
            jogadas[posJogadas] = i;
            posJogadas++;
        }
    }
    return posJogadas;
}

void mostrarJogadas(int* jogadas, int k){
    int i, n = JPJogadas(k, jogadas);
    printf("\nJogadas (%d): ", n);
    for (i = 0; i < n; i++)
        printf("%d ", jogadas[i]);
}

void mostrarVencedor(int numLance) {
    printf("Ganha jogador %s.", (numLance%2 == 0) ? "ímpar" : "par");
}

int checkInputValido(int num) {
    if(num > 1) {
        return 1;
    } else {
        printf("Input inválido, tente novamente.");
        return 0;
    }
}
void cicloJogo(int* jogadas, int k) {
    int numLance = 1, jogada;
    while(k > 1) {
        mostrarJogadas(jogadas, k);
        printf("\nLance %d: ", numLance);
        scanf("%d", &jogada);
        if(JPLanceValido(k, jogada)) {
            k = jogada;
            numLance++;
        }
        else
            k = 0;
    }
    mostrarVencedor(numLance);
}
int main()
{
    int k, numJogador = 0;
    int jogadas[MAX_JOGADAS];
    do {
        printf("\nIndique Posicao (um numero): ");
        scanf("%d", &k);
    } while(!checkInputValido(k));
    cicloJogo(jogadas, k);
}
