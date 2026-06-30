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

    ListNode* rev(ListNode* head, int times){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(times--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nex;
        }
        return prev;
    }

    ListNode* swapPairs(ListNode* head) {
        int size = 2;
        if(head == nullptr) return head;
        
        ListNode* left = head;
        ListNode* res = nullptr;
        ListNode* prevleft = nullptr;
        ListNode* right = nullptr;
        
        while(left != nullptr){
            right = left;
            
            // 1. Structural Scan Block: Identify if a complete pair exists
            bool has_full_pair = true;
            for(int i = 0; i < size - 1; i++){
                if(right == nullptr || right->next == nullptr) {
                    has_full_pair = false;
                    break;
                }
                right = right->next;
            }
            
            // 2. Condition Loop: If a pair exists, process it
            if(has_full_pair && right != nullptr){
                ListNode* nextleft = right->next; // Cache the start of the next pair group
                
                // FIXED: Called 'rev' instead of 'reverse'
                rev(left, 2); 
                
                // FIXED: Explicitly attach the tail of this flipped pair to the next group
                left->next = nextleft; 
                
                // FIXED: Handled the assignment logic properly across both states
                if(prevleft){
                    prevleft->next = right; // Link previous flipped pair tail to current pair head
                }
                else{
                    res = right; // If this was the very first pair, 'right' becomes the global head
                }
                
                prevleft = left;  // The old 'left' node is now the tail of the flipped pair
                left = nextleft;  // Advance our scan window forward to the next pair
            }
            else {
                // Remaining elements are less than a full pair (0 or 1 node left)
                if(prevleft) {
                    prevleft->next = left; // Connect the last odd node or null safely
                }
                if(res == nullptr) {
                    res = head; // Fallback safeguard if the list size was less than 2
                }
                break;
            }
        }
        return res;
    }
};
