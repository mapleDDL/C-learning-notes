/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode * next;
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto res = head;
        auto p = head;

        for (int i = 0; i < k-1; i++) {
            p = p->next;
        }

        while (p->next) {
            res = res->next;
            p = p->next;
        }

        return res;
    }
};
