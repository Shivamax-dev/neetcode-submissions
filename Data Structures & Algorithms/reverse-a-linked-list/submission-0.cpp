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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;  ///Pahle current pointer ko head se initialize karenge
        ListNode *prev = NULL; //aur previous ko NULL se
        while(curr != NULL){    //jb tk. current pointer NULL n ho jaye
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;    //reuturn krdo previous ko jisme address hai reversed linked list ke first node ka.
    }
};
