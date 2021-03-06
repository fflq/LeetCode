#ifndef _HEADS_H_
#define _HEADS_H_

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

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

#endif