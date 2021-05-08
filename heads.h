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
inline void print_vec(vector<T> &vec) {
    for (auto a : vec)
        cout << a << ", " ;
    cout << endl ;
}

template<typename T>
inline void print_list(T p) {
    while (p)   cout << p->val << ", ", p = p->next ;
    cout << endl ;
}


// 并查集
int *ufsInit(int n) { 
    int *fa = new int[n] ;
    for (int i = 0; i < n; ++ i)    fa[i] = i ; 
    return fa ;
}
void ufsDeinit(int *fa) { delete fa ; }
int ufsFather(int *fa, int e) {
    int x = e, y = e, z ;
    while (x != fa[x])  x = fa[x] ;
    while (y != fa[y])  z = y, y = fa[y], fa[z] = x ;
    return x ;
}
int ufsUnion(int *fa, int a, int b) {
    a = ufsFather(fa, a), b = ufsFather(fa, b) ;
    if (a != b) fa[b] = a ;
    return a ;
}


// 堆
void adjustMaxHeap(vector<int> &vec, int k, int end) {
    int left = 2*k+1, right = 2*k+2, bigidx = k ;
    // 先选出三者间最大值得索引
    if (left < end && vec[left] > vec[bigidx])   bigidx = left ;
    if (right < end && vec[right] > vec[bigidx])   bigidx = right ;
    if (bigidx != k) {
        swap (vec[bigidx], vec[k]) ;
        adjustMaxHeap (vec, bigidx, end) ;
    }
}
void updateMaxHeap(vector<int> &vec) {
    for (int i = vec.size()/2; i >= 0; -- i)    
        adjustMaxHeap(vec, i, vec.size()) ;
}
void insertMaxHeap(vector<int> &vec, int num) {
    vec.push_back (num) ;
    updateMaxHeap (vec) ;
}
int getMax(vector<int> &vec) {
    int num = vec.front() ;
    vec.front() = vec.back() ;
    vec.pop_back() ;
    adjustMaxHeap (vec, 0, vec.size()) ;
    return num ;
}


#endif
