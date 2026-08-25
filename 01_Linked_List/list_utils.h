// list_utils.h
#pragma once
#include <iostream>
#include <vector>

using namespace std;

// LeetCode 提供的資料結構
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// 測試用小幫手：印出 Linked List
// 注意前面加了 inline，這是 C++ 的小規則，避免重複定義錯誤
inline void printList(ListNode* head) {
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

// 測試用小幫手：釋放記憶體
inline void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head->next;
        delete head;
        head = temp;
    }
}