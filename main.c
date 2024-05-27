#include <stdio.h>

#define MAX_HOMARI 100 // Definim o constanta pentru numarul maxim de homari

int max(int a, int b) { // Definim o functie pentru a returna maximul dintre doua numere
    return (a > b) ? a : b; // Returnam a daca este mai mare decat b, altfel returnam b
}

void afisare_homari(int dp[MAX_HOMARI][MAX_HOMARI], int marime[MAX_HOMARI], int val[MAX_HOMARI], int n, int x) {
    printf("Homarii inclusi in plasa sunt:\n"); // Afisam mesaj
    int i = n, j = x;
    while (i > 0 && j > 0) { // Parcurgem matricea dp pentru a determina homarii inclusi in plasa
        if (dp[i][j] != dp[i - 1][j]) { // Daca valoarea de pe pozitia curenta difera de cea de pe linia anterioara
            printf("Homar %d: Dimensiune = %d, Valoare = %d\n", i, marime[i], val[i]); // Afisam detalii despre homar
            j -= marime[i]; // Scadem dimensiunea homarului din capacitatea curenta a plasei
        }
        i--; // Trecem la homarul anterior
    }
}

int main() {
    int n, x; // Declarare variabile pentru numarul de homari si capacitatea plasei
    printf("Numarul de homari si capacitatea plasei: "); // Afisam mesaj de introducere a datelor
    scanf("%d %d", &n, &x); // Citim numarul de homari si capacitatea plasei
    int marime[MAX_HOMARI], val[MAX_HOMARI]; // Declarare vectori pentru marimea si valoarea homarilor
    int dp[MAX_HOMARI][MAX_HOMARI]; // Declarare matrice pentru programare dinamica

    printf("Introdu marimea homarilor: "); // Afisam mesaj de introducere a dimensiunilor homarilor
    for (int i = 1; i <= n; i++) { // Parcurgem homarii
        scanf("%d", &marime[i]); // Citim dimensiunea homarului
    }
    printf("Introdu valoarea homarilor: "); // Afisam mesaj de introducere a valorilor homarilor
    for (int i = 1; i <=n; i++) { // Parcurgem homarii
        scanf("%d", &val[i]); // Citim valoarea homarului
    }

    for (int i = 0; i <= n; i++) { // Parcurgem numarul de homari
        for (int j = 0; j <= x; j++) { // Parcurgem capacitatea plasei
            if (i == 0 || j == 0) { // Daca nu avem homari sau plasa nu are capacitate
                dp[i][j] = 0; // Initializam dp cu 0
            } else if (marime[i] <= j) { // Daca dimensiunea homarului este mai mica sau egala cu capacitatea plasei
                dp[i][j] = max(val[i] + dp[i - 1][j - marime[i]], dp[i - 1][j]); // Calculam valoarea maxima a homarilor
            } else { // Altfel
                dp[i][j] = dp[i - 1][j]; // Copiem valoarea de pe linia anterioara
            }
        }
    }

    printf("Valoarea maxima este: %d\n", dp[n][x]); // Afisam valoarea maxima a homarilor care incap in plasa
    afisare_homari(dp, marime, val, n, x); // Apeleaza functia pentru afisarea homarilor inclusi in plasa

    return 0; // Returnam 0 pentru a indica ca programul s-a incheiat cu succes
}
