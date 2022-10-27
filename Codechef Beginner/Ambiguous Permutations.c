#include <stdio.h>

int main(void) {
    int n,a[100000],i;
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=1;i<=n;i++)
             scanf("%d",&a[i]);
        for(i=1;i<=n;i++){
            if(a[a[i]]!=i){
                printf("not ambiguous \n");
                break;
            }
            if(i==n)
                printf("ambiguous \n");
        }
    }
    return 0;
}