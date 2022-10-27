#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	for(int p=0;p<t;p++){
	    int a;
	    scanf("%d",&a);
	    int b=sqrt(a);
	    printf("%d\n",b);
	}
	return 0;
}