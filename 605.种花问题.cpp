/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    //opt
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // valid in [1,size-2]
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);

        int sz = flowerbed.size();
        for (int i = 1; i < flowerbed.size()-1; ++ i) {
            //left
            if (flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0) {
                if (--n <= 0)   return true;
                flowerbed[i] = 1 ;
            }
        }

        return n <= 0;
    }

    bool canPlaceFlowers1(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        //sp
        if (sz == 1)    return (1-flowerbed[0] >= n);
        //boundary
        if (!flowerbed[0] && !flowerbed[1]) {
            -- n;
            flowerbed[0] = 1;
        }
        if (!flowerbed[sz-2] && !flowerbed[sz-1]) {
            -- n;
            flowerbed[sz-1] = 1;
        }

        int n1 = n, n2 = n; 
        auto fb1 = flowerbed, fb2 = flowerbed;

        //left to right
        for (int i = 1; i < fb1.size(); ++ i) {
            //left
            if (fb1[i-1] == 0 && fb1[i] == 0) {
                //right
                if ((i == fb1.size()-1)
                    || (i < fb1.size()-1 && fb1[i+1] == 0)) {
                        -- n1 ;
                        fb1[i] = 1 ;
                    }
            }
        }
        //right to left
        for (int i = fb2.size()-2; i >= 0; -- i) {
            //right
            if (fb2[i+1] == 0 && fb2[i] == 0) {
                //left
                if ((i == 0)
                    || (i > 0 && fb2[i-1] == 0)) {
                        -- n2 ;
                        fb2[i] = 1 ;
                    }
            }
        }
        //cout << n1 << n2;
        return (n1 <= 0 || n2 <= 0);
    }
};
// @lc code=end

int main() {
    Solution sol;
    {
        vector<int> s{1};
        assert(true == sol.canPlaceFlowers(s, 0));
    }
    {
        vector<int> s{1,0,0,0,0,1};
        assert(false == sol.canPlaceFlowers(s, 2));
    }
    {
        vector<int> s{0,0,1,0,0};
        assert(true == sol.canPlaceFlowers(s, 2));
    }
    return 0;
}