#include<stdio.h>
 
int main()
{
        int i,num,arr[1000001]={0},n;
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
               scanf("%d",&n);
               arr[n]++;
        }
        for(i=0;i<1000001;i++)
               if(arr[i])
                       while(arr[i]--)
                               printf("%d\n",i);
        return 0;
}