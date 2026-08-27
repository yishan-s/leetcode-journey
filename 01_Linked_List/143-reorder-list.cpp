# include <iostream>
# include "list_utils.h"

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        // 先 Fast-slow ptr 找 mid
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* mid = slow -> next;
        slow -> next = nullptr;

        // reverse list
        ListNode* curr = mid;
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        while(curr != nullptr) {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        // connect alternately
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while(p2 != nullptr) {
            ListNode* tmp1 = p1 -> next;
            ListNode* tmp2 = p2 -> next;

            p1 -> next = p2;
            p2 -> next = tmp1;

            p1 = tmp1;
            p2 = tmp2;
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr);
    
    cout << "Original:  ";
    printList(head);
    
    sol.reorderList(head);
    
    cout << "Reordered: ";
    printList(head);
    
    freeList(head);
    
    return 0;
}