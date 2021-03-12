/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#ifdef FLQ
#include "heads.h"
#endif

// @lc code=start
class Solution {
public:
    // 双指针，实际是O(nn)，好家伙，即使改成这样，有时提交还是现实超时，要多试几次
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size() ;
        vector<vector<int>> res ;
        sort (nums.begin(), nums.end()) ;
        for (int i = 0; i < len; ++ i) {
            // 避免相同a，手动set去重a
            if (i > 0 && nums[i] == nums[i-1])  continue ;

            // 因为b<c，而b:j..len, c:len-b，故b+c==len，故以下双for是O(n)
            int tgt = -nums[i] ;
            for (int j = i+1, k=len-1; j < len; ++ j) {
                // 同理去重b
                if (j > i+1 && nums[j] == nums[j-1])  continue ;

                while (j < k && nums[j] + nums[k] > tgt) {
                    --k;
                }
                // c从尾开始，因为a+b不断增大，c会不断减小，据说这样jk双指针，会O(n)
                //for (k = len-1; k > j; -- k)
                    //if (nums[j] + nums[k] <= tgt)   break ;
                if (k == j) break ; // 超时关键，因为bc重合无的话，后面增大就更无了
                if (k > j && nums[j] + nums[k] == tgt)
                    res.push_back({nums[i], nums[j], nums[k]}) ;
            }
        }
        return res ;
    }

    // 暴力超时，O(nnn)
    vector<vector<int>> threeSum1(vector<int>& nums) {
        //vector<vector<int>> res ;
        set<vector<int>> st ;
        sort (nums.begin(), nums.end()) ;
        for (int i = 0; i < nums.size(); ++ i)
            for (int j = i+1; j < nums.size(); ++ j)
                for (int k = j+1; k < nums.size(); ++ k)
                    if (nums[i] + nums[j] + nums[k] == 0)
                        st.insert({nums[i], nums[j], nums[k]}) ;
        return vector<vector<int>>(st.begin(), st.end()) ;
    }
};
// @lc code=end

int main() {
    auto a = {1} ;
    auto s = new Solution(); 
    auto r = s->threeSum3(a) ;
    cout << r.size() << endl ;
    for (auto e : r)
        cout << e.size() << " " ;
    return 0 ;
}
