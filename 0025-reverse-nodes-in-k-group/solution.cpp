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

    ListNode* rev(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(k--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* left = head;
        ListNode* res = nullptr;
        ListNode* right = nullptr;
        ListNode* prevleft = nullptr;
        while(left!=nullptr){
            right = left;
            bool has_k_nodes = true;
            for(int i=0;i<k-1;i++){
                if(right == nullptr || right->next == nullptr){
                    has_k_nodes = false;
                    break;
                }
                right = right->next;
            }
            if(has_k_nodes && right!=nullptr){
                ListNode* nextleft = right->next;
                rev(left,k);
                left->next = nextleft;
                if(prevleft){
                    prevleft->next = right;
                }
                else{
                    res = right;

                }
                prevleft = left;
                left = nextleft;
            }
            else{
                if(prevleft){
                    prevleft->next = left;
                }
                if(res==nullptr){
                    res = head;
                }
                break;
            }
        }
        return res;
    }
};
