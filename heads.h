#ifndef _HEADS_H_
#define _HEADS_H_

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdint>

#include <iostream>
#include <sstream>

#include <list>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

#include <algorithm>
#include <numeric>
#include <bitset>


using namespace std ;

#ifndef FLQ
#define cout 0&&cout 
#endif

template<typename T>
inline void print_vec(vector<T> vec) {
    for (auto a : vec)
        cout << a << ", " ;
    cout << endl ;
}

template<typename T>
inline void print_list(T p) {
    while (p)   cout << p->val << ", ", p = p->next ;
    cout << endl ;
}

#ifdef FLQ_DEP
class Solution;
void flqmain();
int smain() {
    cout << "*** flqmain ***" << endl ;
    flqmain();
    return 0 ;
}
#endif

#endif