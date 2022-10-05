#include<stdio.h>
 
 
int main(){
    int t;
    char a;
 
    scanf("%d",&t);
 
    while(t--)
        {
             scanf(" %c",&a);
 
               if(a=='b' || a=='B')
            printf("BattleShip\n");
 
        else if(a=='c' || a=='C')
            printf("Cruiser\n");
 
        else if(a=='d' || a=='D')
            printf("Destroyer\n");
 
        else if(a=='f' || a=='F')
            printf("Frigate\n");
    }
    return 0;
}