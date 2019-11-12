#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){//retornar o maior dos dois parâmetros
    if(a > b)
        return a;    
    else
        return b;
}


int LCS(int m, int n, char *X, char *Y){//função p/ retornar a maior sequência comum
    int L[m + 1][n + 1], i, j;
    for(i = 0; i < m + 1; i++){
        for(j = 0; j < n + 1; j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }else if(X[i - 1] == Y[j - 1]){
                L[i][j] = L[i - 1][j- 1] + 1;
            }else{
                L[i][j] = max(L[i -1][j], L[i][j - 1]);
            }    
        }
    }
    return L[m][n];
}
    /*int index = L[m][n];
    LCS = [index - 1];
    i = m;
    j = n;
    while(i > 0 && j > 0){
       if(dna[i - 1] == dna2[j - 1]){
            LCS[index - 1] = dna1[i - 1]
            index--;
            j--;
            i--;
        }else if(L[i - 1][j] > L[i][j - 1]){
            i--;
        }else{
            j--;
        }
    }*/// ainda não sei como funciona essa parte, suponho que seja o merge


int main(){
    char dna1[] = "ATTCTTTAGCAGGCAGGCAGGTGGCAGGTGACGATGGGGATGGAAAAG";
    char dna2[] = "ATACTTTAGCATGCGGGCAGGAGGCGAGACGATGTCGGTATGAATG";
    int m = strlen(dna1), n = strlen(dna2);
    printf("Tamanho da maior sequencia comum: %d\n", LCS(m, n, dna1, dna2));
     
    system("PAUSE");
    return 0;
}
