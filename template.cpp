#ifdef FLQ
#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;
#endif


#ifndef FLQ 
#define cout 0&&cout
#endif


class Solution{
    public:
    int func(string s) {}    
} ;

#ifdef FLQ
int main() {
   Solution solution = Solution() ;
   string s ;
   while (cin >> s) {           
       int res = solution.func(s) ;
       cout << res << endl ;
   }
   return 0 ;
}
#endif
