/* Problem Implement Atoi
   from GFG Practice
   Time Complexity: O(|S|), |S|= length of string S.
   Space Complexity: O(1)
*/

int atoi(string str)
{
int num=0, index=0, flag=1;
if(str[0]=='-')
{
index = 1;
flag = -1;
}
for(;str[index];index++)
{
if(isdigit(str[index]))
{
num = (num * 10) + (str[index]-'0');
}
else{
return -1;
}
}
return num*flag;
}