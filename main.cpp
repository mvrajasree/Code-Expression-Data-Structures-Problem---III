#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // 1. Remove indices that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // 2. Remove elements smaller than the current one from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // 3. Add current element's index
        dq.push_back(i);

        // 4. The front of the deque is the largest element for the window
        if (i >= k - 1) {
            cout << nums[dq.front()] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter array size and window size (k): ";
    cin >> n >> k;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Maximums: ";
    maxSlidingWindow(arr, k);

    return 0;
}
