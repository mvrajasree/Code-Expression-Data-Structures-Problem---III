#include <iostream>
#include <vector> //dynamic array 
#include <deque> //double ended queue , stores in chunks

using namespace std;

void maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // deque with name 'dq' stores indices/positions
    vector<int> result; //dynamic array to store values pushed by deque

    for (int i = 0; i < nums.size(); i++) {
        //  Remove indices that are out of the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current one from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        //  Add current element's index
        dq.push_back(i);

        //  The front of the deque is the largest element for the window
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
