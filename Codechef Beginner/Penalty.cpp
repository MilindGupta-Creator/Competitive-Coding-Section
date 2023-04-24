// Problem Code: PENALTY(Difficulty rating = 925)
#include <iostream>
using namespace std;
int T,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10;
int main() {
	// your code goes here
	std::cin >> T;
	while(T--){
	    int var=0,car=0;
	   std::cin >> A1 >> A2 >> A3 >> A4 >> A5 >> A6 >> A7 >> A8 >> A9 >> A10;
	   var = A1 + A7 + A3 + A9 + A5;
	   car = A10 + A2 + A8 + A4 + A6;
	   if(car==var){
	       std::cout << 0 << std::endl;
	   }
	   else if(car>var){
	       std::cout << 2 << std::endl;
	   }
	   else {
	       std::cout << 1 << std::endl;
	   }
	}
	return 0;
}
