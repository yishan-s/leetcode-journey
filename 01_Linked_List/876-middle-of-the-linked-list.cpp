# include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head->next;
        delete head;
        head = temp;
    }
}

int main() {
    Solution sol;

    // ==========================================
    // case 1：奇數長度
    // ==========================================
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Case 1 - Original List: ";
    printList(head1);
    
    ListNode* mid1 = sol.middleNode(head1);
    cout << "Case 1 - Middle List: ";
    printList(mid1); 

    // ==========================================
    // case 2：偶數長度
    // ==========================================
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    cout << "Case 2 - Original List: ";
    printList(head2);
    
    ListNode* mid2 = sol.middleNode(head2);
    cout << "Case 2 - Middle List: ";
    printList(mid2); 

    freeList(head1);
    freeList(head2);

    return 0;
}