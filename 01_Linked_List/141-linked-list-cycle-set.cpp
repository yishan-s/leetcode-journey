# include <iostream>
# include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited = {};
        ListNode* curr = head;
        while(curr != nullptr) {
            if(visited.find(curr) == visited.end()) {
                visited.insert(curr);
                curr = curr -> next;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    // ==========================================
    // case 1：Linked List with cycle
    // ==========================================
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    cout << "Test Case 1 (Expected: true): " << boolalpha << sol.hasCycle(node1) << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;


    // ==========================================
    // case 2：Linked List without cycle
    // ==========================================
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    n1->next = n2;

    cout << "Test Case 2 (Expected: false): " << boolalpha << sol.hasCycle(n1) << endl;

    delete n1;
    delete n2;

    return 0;
}