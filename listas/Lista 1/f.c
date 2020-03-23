#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int a[1000];
    int cont = 0;
    int j; 

    while(scanf("%d", &n) != EOF){
        a[cont] = n;
        ++cont;
    }
    for (int i = 1; i < cont; ++i){
         n = a[i];
         j = i-1; 
        while (j >= 0 && a[j] > n){ 
            a[j+1] = a[j]; 
            --j; 
        } 
        a[j+1] = n; 
    } 

    for (int i = 0; i < cont; ++i){
        printf("%d", a[i]);
        if(i != cont-1){
            printf(" ");
        }
    }
    printf("\n");
}