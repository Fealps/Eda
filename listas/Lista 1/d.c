#include <stdio.h>
#include <stdlib.h>

int main(){
    int l;
    char str[1000][1000];
    char command;
    int linha,coluna, c;
    int n;
    int a;
    for(int i = 0; i < 1000; ++i){
     for(int j = 0; i < 1000; ++i){
            str[i][j] = '\0';
        }   
    }

    scanf("%d", &l);
    for(int i =0; i<l; ++i){
        scanf(" %[^\n]",str[i]);      
    }
    scanf(" %d", &linha);
    scanf(" %d", &coluna);

    while(scanf(" %c", &command) != EOF){
        c = coluna;
        if(command == 'k'){
            if(linha > 1){
                linha--;
            }            
        }else
        {
            if(linha < l){
                linha++;
            }
        }
        imprime:
            if((str[linha -1][c -1]) != '\0' ){
                printf("%d %d %c\n", linha, c, str[linha -1][c-1]);
            }else{
                if(c > 0){
                    c--;
                }
                goto imprime;
            }
                
    }
    return 0;
}