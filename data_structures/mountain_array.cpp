#include <iostream>

using namespace std;

// objective: find the maximum

int linear_search(std::vector<int> arr) {
    int maximum_idx = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > arr[maximum_idx]) {
            maximum_idx = i;
        }
    }

    return maximum_idx;
}

int logn_max_search(std::vector<int> arr) {
    // O(logn) binary search
    int maximum_idx = 0;

    int left = 1;
    int right = arr.size() - 2;

    // Since it's guaranteed to be a mountain array,
    // we can ignore the assumption that 
    // the peak index is 0 or size() - 1
    
    // This is because it HAS to decrease
    // after the peak, at least once.

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]) {
            return mid; 
        }
        else if (arr[mid] < arr[mid - 1]) {
            right = mid - 1;
        }
        else if (arr[mid] > arr[mid - 1]) {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> mtn_arr = {3,5,3,2,0};

    int target_idx = logn_max_search(mtn_arr);

    cout << "The maximum value of " << mtn_arr[target_idx] << " is at index " << target_idx << endl;

    return 0;
}
