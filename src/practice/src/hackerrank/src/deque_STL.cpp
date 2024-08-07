#include <deque>
#include <iostream>
using namespace std;
#include <algorithm>
void printKMax(int arr[], int n, int k) {
  // Write your code here.

  //     std::deque<int>::iterator max;
  //     std::deque<int> numbersDeque(arr, arr + n);
  //     int head=0;
  //     while(numbersDeque.size()>=k)
  //     {
  //         max=std::max_element(numbersDeque.begin(),numbersDeque.begin() +
  //         k);
  //
  //         printf("%d%s",*max," ");
  //         numbersDeque.pop_front();
  //     }
  //
  //     printf("\n");
  int j, max;
  for (int i = 0; i <= n - k; i++) {
    max = arr[i];

    for (j = 1; j < k; j++) {
      if (arr[i + j] > max)
        max = arr[i + j];
    }
    printf("%d ", max);
  }
  printf("\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  // cin >> t;
  scanf("%d", &t);
  while (t > 0) {
    int n, k;
    // cin >> n >> k;
    scanf("%d", &n);
    scanf("%d", &k);
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
      // cin >> arr[i];
      scanf("%d", &arr[i]);
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}
