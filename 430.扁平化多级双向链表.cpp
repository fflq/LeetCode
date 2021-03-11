/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // 树的先序遍历
    Node *list = nullptr ;
    Node* flatten(Node* head) {
        if (!head)  return head ;

        Node *listHead = new Node ; list = listHead ;
        preOrder (head) ;

        listHead->next->prev = nullptr ; // 不然会报错不是双向链表
        return listHead->next ;
    }

    void preOrder(Node *root) {
        if (!root)  return ;

        Node *child=root->child, *next=root->next ;

        // 插入到end最后
        root->next = list->next ;   // nullptr
        root->prev = list ;
        root->child = nullptr ;
        list->next = root ;
        list = root ;

        if (child)    preOrder(child) ;
        if (next) preOrder(next) ;
    }
};
// @lc code=end

