#include <iostream>

/*
141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution141 {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) {
      return false; // If the list is empty, there can't be a cycle
    }
    ListNode *slow_pointer = head;
    ListNode *fast_pointer = head;

    while (slow_pointer != nullptr && slow_pointer->next != nullptr) {

      fast_pointer = fast_pointer->next->next;

      if (fast_pointer != nullptr && fast_pointer == slow_pointer)
        return true;
      slow_pointer = slow_pointer->next;
    }
    return false;
  }
};

int main() {

  // head = [3,2,0,-4], pos = 1

  ListNode three(3);
  ListNode two(2);
  ListNode zero(0);
  ListNode minus_four(-4);

  three.next = &two;
  two.next = &zero;
  zero.next = &minus_four;
  minus_four.next = &two;
  Solution141 s;
  std::cout << std::boolalpha << s.hasCycle(nullptr) << std::endl;
  return 0;
}
