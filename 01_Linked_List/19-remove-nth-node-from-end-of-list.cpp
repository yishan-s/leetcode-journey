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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(n != 0) {
            fast = fast -> next;
            n--;
        }

        if(fast == nullptr) {
            return head -> next;
        }

        while(fast != nullptr && fast -> next != nullptr){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* dummy = slow -> next;
        slow -> next = slow -> next -> next;
        delete dummy;
        return head;
    }
};

void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "Empty List (nullptr)" << endl;
        return;
    }
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
    // Case 1: 一般情況 [1, 2, 3, 4, 5], 移除倒數第 2 個
    // 預期結果: 1 -> 2 -> 3 -> 5
    // ==========================================
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Case 1 - Original List: ";
    printList(head1);
    
    // 注意：因為 head1 的長相可能會改變，所以要重新接住回傳值
    head1 = sol.removeNthFromEnd(head1, 2);
    cout << "Case 1 - After Removal: ";
    printList(head1); 
    freeList(head1);
    cout << "------------------------\n";


    // ==========================================
    // Case 2: 極端邊界條件 [1], 移除倒數第 1 個
    // 預期結果: Empty List (nullptr)
    // ==========================================
    ListNode* head2 = new ListNode(1);
    ListNode* toDelete2 = head2; // 偷偷記住舊的 head，等一下幫忙清記憶體

    cout << "Case 2 - Original List: ";
    printList(head2);
    
    head2 = sol.removeNthFromEnd(head2, 1);
    cout << "Case 2 - After Removal: ";
    printList(head2); 
    freeList(head2);
    delete toDelete2; // 手動把被拔掉的第一個節點清掉
    cout << "------------------------\n";


    // ==========================================
    // Case 3: 移除頭部 [1, 2], 移除倒數第 2 個
    // 預期結果: 2
    // ==========================================
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    ListNode* toDelete3 = head3;

    cout << "Case 3 - Original List: ";
    printList(head3);
    
    head3 = sol.removeNthFromEnd(head3, 2);
    cout << "Case 3 - After Removal: ";
    printList(head3); 
    freeList(head3);
    delete toDelete3;
    cout << "------------------------\n";

    return 0;
}