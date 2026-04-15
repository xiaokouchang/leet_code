
//https://leetcode.cn/problems/add-two-numbers/?envType=problem-list-v2&envId=linked-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* head = l1;
        while (cur1 && cur2)
        {
            int tmp = 0;
            int num = cur1->val + cur2 + val + tmp;
            if (num >= 10)
            {
                tmp += num / 10;
                num /= 10;
            }
            head->val = num;
            head = head->next;
        }
        if (cur1)
        {
            head->next = cur1;
        }
    }
};