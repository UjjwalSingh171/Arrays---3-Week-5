// Count the number of triplets whose sum is equal to the given value x.
#include <iostream>
#include <algorithm>
using namespace std;

int countTriplets(int arr[], int n, int x) {
    sort(arr, arr + n);
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum == x) {
                count++;
                left++;
                right--;
            } else if (currentSum < x) {
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 22;

    cout << "Number of triplets: " << countTriplets(arr, n, x) << endl;

    return 0;
}
 