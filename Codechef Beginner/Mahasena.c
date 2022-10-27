#include <stdio.h>

int main(void) {
	int n,even=0,odd=0;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	    if(a[i]%2==0)
	        even++;
	    else
	        odd++;
	}
	    
	if(even>odd)
	    printf("READY FOR BATTLE");
	else
	    printf("NOT READY");
	return 0;
}