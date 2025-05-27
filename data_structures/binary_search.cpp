#include <iostream>

using namespace std;

int binary_search(std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int target_idx = -1;

    while (left <= right) { // if the target isnt there in the first place, auto break
        int mid = left + (right - left) / 2; 

        if (target > arr[mid]) { // target is on right side 
            left = mid + 1;
        }
        else if (target < arr[mid]) { // target is on the left side
            right = mid - 1;
        }
        else { // target = arr[mid]
            return mid;
        }
    }

    return target_idx;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int target_idx = binary_search(arr, 3);

    cout << target_idx << endl;

    return 0;
}
