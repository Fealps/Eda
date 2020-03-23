        #include <stdio.h>
        #include <stdlib.h>

        int main(){
            int n;
            int a;
            double soma = 0;
            scanf("%d", &n);
            for(int i = 0; i<n; ++i){
                scanf("%d", &a);
                soma+=a;
            }
            printf("%.0f\n", soma);
        }