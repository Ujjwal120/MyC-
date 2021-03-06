#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *ab = NULL;
    ListNode **node = &ab;
    
    while(l1 != NULL || l2 != NULL || carry > 0) {
        
        if(l1 != NULL) {
            carry += l1->val;
            l1 = l1->next;
        }
        
        if(l2 != NULL) {
            carry += l2->val;
            l2 = l2->next;
        }

        *node = new ListNode(carry % 10);
        carry /= 10;
        node = &((*node)->next);
    }        
    return ab;
}

int main() {

    return 0;
}