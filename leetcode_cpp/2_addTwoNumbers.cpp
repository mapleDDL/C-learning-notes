class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* res = new ListNode();
        ListNode* resp = res;
        int c(0);
        int a1(0), a2(0);
        int temp = 0;
        while (p1 != nullptr || p2 != nullptr || c != 0) {
            if (p1 != nullptr) {
                a1 = p1->val;
                p1 = p1->next;
            } else {
                a1 = 0;
            }

            if (p2 != nullptr) {
                a2 = p2->val;
                p2 = p2->next;
            } else {
                a2 = 0;
            }
            
            temp = a1 + a2 + c; 
            resp->next = new ListNode(temp%10);
            resp = resp->next;
            c = temp >= 10 ? 1 : 0;
        }
        return res->next;
    }
};