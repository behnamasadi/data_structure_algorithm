#include <algorithm>
#include <iostream>
#include <vector>

/*
https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150
215. Kth Largest Element in an Array


Certainly! Let's break down how the min-heap approach works to find the K'th
largest element in more detail.

### Key Concept:
The core idea is to maintain a **min-heap** of size K. This heap will always
contain the K largest elements seen so far as we iterate through the array.

### Step-by-Step Explanation:

1. **Initialization**:
   - Start by inserting the first K elements of the array into a min-heap.
   - Since it's a min-heap, the smallest element among these K elements will be
at the root of the heap.

   Example:
   ```plaintext
   Array: [3, 2, 1, 5, 6, 4], K = 2
   Heap after inserting first K elements (3, 2):
   Min-Heap: [2, 3]
   ```
   Here, the root is `2`, the smallest among the first two elements.

2. **Processing the Rest of the Array**:
   - Now, for each remaining element in the array, compare it with the root of
the heap (which is the smallest of the K largest elements you've seen so far).
   - If the current element is larger than the root, it means this element could
be one of the K largest, so:
     - Replace the root with this element.
     - Heapify to restore the min-heap property.

   Example:
   - Next element is `1`: Compare with the root `2`. Since `1` is not larger
than `2`, we skip it.
   - Next element is `5`: Compare with the root `2`. Since `5` is larger than
`2`, replace `2` with `5` and heapify.

   ```plaintext
   Heap: [3, 5]  (after replacing and heapifying)
   ```
   - Next element is `6`: Compare with the root `3`. Replace `3` with `6` and
heapify.

   ```plaintext
   Heap: [5, 6]  (after replacing and heapifying)
   ```
   - Next element is `4`: Compare with the root `5`. Since `4` is not larger,
skip it.

3. **Result**:
   - After processing all elements, the min-heap will contain the K largest
elements from the array.
   - The root of the min-heap is the smallest among these K largest elements,
which is exactly the K'th largest element in the array.

   Example:
   ```plaintext
   Final Heap: [5, 6]
   K'th largest element (K=2) is 5.
   ```

### Why It Works:
- **Min-Heap Property**: The root is the smallest element in the heap. As we
only replace the root if we find a larger element, the heap always contains the
largest K elements seen so far.
- **Efficiency**: The heap never grows beyond size K, making operations
efficient. The root of this min-heap is the smallest of these K largest
elements, giving us the K'th largest element directly.

### Misunderstanding Clarification:
- **Why Not the Smallest of the Array?**: You're correct that the root is the
smallest in the heap, but remember, this heap only contains the K largest
elements from the array. So the root isn't the smallest of the whole array but
the smallest of these top K largest elements, which is why it represents the
K'th largest element of the entire array.

By keeping the min-heap size fixed at K, we ensure that we are always working
with the largest K elements in the array. The smallest among them (the root of
the heap) is thus the K'th largest in the entire array.


*/

class Solution215 {
public:
  int findKthLargest(std::vector<int> &nums, int k) {

    // std::make_heap(nums.begin(), nums.begin() + k, std::greater());

    // for (std::size_t i = k; i < nums.size(); i++) {

    //   if (nums[i] > nums[0]) {
    //     std::swap(nums[i], nums[0]);
    //     std::make_heap(nums.begin(), nums.begin() + k);
    //   }
    // }

    // Step 1: Create a min-heap with the first K elements
    std::make_heap(nums.begin(), nums.begin() + k, std::greater<>());

    for (std::size_t i = k; i < nums.size(); i++) {
      if (nums[i] > nums[0]) { // If current element is greater than the
                               // smallest in the heap
        std::pop_heap(nums.begin(), nums.begin() + k,
                      std::greater<>()); // Remove the smallest
        nums[k - 1] = nums[i];           // Replace it with the current element
        std::push_heap(nums.begin(), nums.begin() + k,
                       std::greater<>()); // Restore heap property
      }
    }

    return nums[0];
  }
};

int main() {
  //   std::vector<int> nums = {3, 2, 1, 5, 6, 4};
  //   int k = 2;

  // nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  // k = 4;

  //   Solution215 s;
  //   std::cout << s.findKthLargest(nums, k) << std::endl;

  return 0;
}
