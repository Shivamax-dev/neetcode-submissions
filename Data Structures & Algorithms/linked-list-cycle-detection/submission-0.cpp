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
#define Node ListNode
class Solution {
public:
    bool hasCycle(ListNode* head) {
        
        if(head == NULL|| head->next == NULL){  //Note that "NULL" is same as "nullptr"
            return false;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){   //while(fast != NULL && fast->next != NULL)
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
            
        }
        return false;
    }
    
};
