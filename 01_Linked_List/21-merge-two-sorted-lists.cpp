# include <iostream>
# include "list_utils.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while(curr1 != nullptr && curr2 != nullptr) {
            if(curr1->val <= curr2->val) {
                curr -> next = curr1;
                curr1 = curr1 -> next;
            } else {
                curr -> next = curr2;
                curr2 = curr2 -> next;
            }
            curr = curr -> next;
        }
        if (curr1 != nullptr)
        {
            curr -> next = curr1;
        }
        if (curr2 != nullptr)
        {
            curr -> next = curr2;
        }

        ListNode* mergedHead = dummy -> next;
        delete dummy;
        return mergedHead;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 4};
    vector<int> nums2 = {1, 3, 4};
    
    ListNode* list1 = createList(nums1);
    ListNode* list2 = createList(nums2);
    
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    
    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);
    
    cout << "Merged: ";
    printList(merged);
    
    return 0;
}