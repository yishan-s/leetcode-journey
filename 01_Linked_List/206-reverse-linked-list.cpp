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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;

        while(curr != nullptr) {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

int main() {
    ListNode* head = new ListNode(10);
    head -> next = new ListNode(20);
    head -> next -> next = new ListNode(30);

    cout << "Original List: ";
    ListNode* tmp = head;
    while(tmp != nullptr) {
        cout << tmp->val << " -> ";
        tmp = tmp -> next;
    }
    cout << "NULL" << endl;

    cout << "Reversed List: ";
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    ListNode* reversedTmp = reversedHead;
    while(reversedTmp != nullptr) {
        cout << reversedTmp -> val << " -> ";
        reversedTmp = reversedTmp -> next;
    }
    cout << "NULL" << endl;
}