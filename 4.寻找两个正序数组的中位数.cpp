/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#ifdef FLQ
#include <iostream>
#include <cstring>
#include <vector>
using namespace std ;
typedef vector<int> Input ;
typedef double Result ;
#endif


// @lc code=start
class Solution {
#ifndef FLQ 
#define cout 0&&cout
#endif

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {            
        double *a = (double *)malloc(8*(nums1.size()+nums2.size())) ;
        int n = 0 ;
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin() ;
    #define v(it, vec)   ((it!=(vec).end())?(*it):1e7)
        while (it1!=nums1.end() || it2!=nums2.end()) {
            a[n++] = v(it1, nums1) < v(it2, nums2) ? *(it1++) : *(it2++) ;
            cout << a[n-1] << " " ;
        }
        int mid = n/2 ;
        double s = (double)( (n%2==0) ? (a[mid-1]+a[mid])/2 : a[mid] ) ;
        cout << s << endl ;
        return s ;
    }
};
// @lc code=end


#ifdef FLQ
int main() {
   Solution solution = Solution() ;
   Input vec1 = {1, 2} ;
   Input vec2 = {3, 4} ;
   solution.findMedianSortedArrays(vec1, vec2) ;
   return 0 ;
}
#endif

