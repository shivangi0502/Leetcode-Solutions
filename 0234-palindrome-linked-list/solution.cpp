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

    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            ListNode*nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr  = nex;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = reverseList(slow);
        ListNode* firstHead = head;
        bool res = true;
        ListNode* left = firstHead;
        ListNode* right = secondHead;
        while(right!=nullptr){
            if(left->val!=right->val){
                res = false;
                break;
            }
            left = left->next;
            right = right->next;
        }
        return res;
    }
};
