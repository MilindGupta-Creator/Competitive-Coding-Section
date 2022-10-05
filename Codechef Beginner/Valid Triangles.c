#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int q=0;q<t;q++){
	    int a,b,c,ans=0;
	    scanf("%d%d%d",&a,&b,&c);
	    ans=a+b+c;
	    if(ans==180)
	        printf("YES\n");
	    else
	        printf("NO\n");
	}
	return 0;
}

