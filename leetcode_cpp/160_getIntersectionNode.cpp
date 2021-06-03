class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 时间复杂度为O(n)，空间复杂度为O(1)
        int n1(0), n2(0);
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != NULL) {
            n1 += 1;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            n2 += 1;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        if (n1 >= n2) {
            while (n1 > n2) {
                n1 -= 1;
                p1 = p1->next;
            }
        } else {
            while (n2 > n1) {
                n2 -= 1;
                p2 = p2->next;
            }
        }
        while (p1 != NULL) {
            if (p1 == p2) {
                return p1;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return NULL;
        
    }
};