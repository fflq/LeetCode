/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */
#include "heads.h"

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        //return findLongestWord20230928(s, dictionary);
        return findLongestWord20230928_2(s, dictionary);
    }


    /*
        A:
        1. 按照要求排序字典
        2. 双指针比较字典
    */
    string findLongestWord20230928_2(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {
            if (a.size() == b.size())   return a < b ;
            return a.size() > b.size() ;
        }) ;

        for (auto &word : dictionary) {
            int i = 0, j = 0;
            while (i < s.size() && j < word.size()) {
                if (s[i] == word[j])    ++ j ;
                ++ i ;
            }
            if (j == word.size())   return word ;
        }

        return "";
    }


    /*
        A:
        1. 按照要求排序字典
        2. 计算每个字符串的各字符频次表作为比较
        3. 比较
        Q:
        1. 只考虑频次，没有考虑顺序
    */
    string findLongestWord20230928(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {
            if (a.size() == b.size())   return a < b ;
            return a.size() > b.size() ;
        }) ;

        map<char, int> s_freqs;
        for (auto c : s)    ++ s_freqs[c]; 

        for (auto& word : dictionary) {
            map<char, int> word_freqs;
            for (auto c : word) ++ word_freqs[c];

            bool ok = true ;
            for (auto& [c, n] : word_freqs) {
                if (s_freqs[c] < n) {
                    ok = false ;
                    break ;
                }
            }
            if (ok) return word ;
        }

        return ""; 
    }

};
// @lc code=end

int main() {
    Solution sol;
    {
        auto s = "abpcplea";
        auto d = vector<string>{"ale","apple","monkey","plea"};
        assert(sol.findLongestWord(s, d) == "apple");
    }
    {
        auto s = "abpcplea";
        auto d = vector<string>{"a","b","c"};
        assert(sol.findLongestWord(s, d) == "a");
    }
    {
        auto s = "bab";
        auto d = vector<string>{"ba","ab","a","b"};
        assert(sol.findLongestWord(s, d) == "ab");
    }
    return 0;
}
