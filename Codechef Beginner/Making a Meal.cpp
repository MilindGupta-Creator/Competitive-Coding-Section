/*Codecehf April Cook-off*/
/* problem is about creat a meal names "codechef" using ingredients*/
//Approch
/* count the alphabates present in the the string "codechef"
   after that concate all the ingredients strig , then count each alphabate using unordered map,
   then find the minimum count of 'c' and 'e' as their count is 2 so count minimum seperately
   after that count the minimum other aplhabates which are present once ,
   al last find the minimum of this two diffrent minimum count and that will be the answer.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;  //Number of test cases
    while(t--)
    {
        int n,i;
        string s,s_t="";
        cin>>n;  // Number of ingredients
        for(i=0;i<n;i++)
        {
            cin>>s;   //Name of ingredients
            s_t+=s;   //Concate all the ingredients in am empty string
        }
        unordered_map<char,int>m;
        for(i=0;i<s_t.size();i++)
        {
            m[s_t[i]]++;   //count the alphabates presnet in the concatinated string
        }
        int m_e,m_o,mini;
        m_e=min(m['c']/2,m['e']/2);     //Find the minimum of 'c' and 'e' as they are present even times to divide by 2 , to get the main count .
        m_o=min({m['o'],m['d'],m['e'],m['f'],m['h']});
        mini=min(m_e,m_o);   
        cout<<mini<<endl;  //output
    }
	return 0;
}

