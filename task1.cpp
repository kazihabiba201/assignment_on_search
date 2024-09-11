// Task1

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Function to perform binary search
int binarySearch(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found at index mid
        } else if (nums[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

// Function to parse the input array
void parseArrayInput(const string& input, vector<int>& nums) {
    istringstream iss(input);
    string temp;
    

    getline(iss, temp, '[');
    getline(iss, temp, ']'); // Extract the array content

    istringstream arrayStream(temp);
    int number;
    char comma;

    while (arrayStream >> number) {
        nums.push_back(number);
        arrayStream >> comma; // Ignore comma
    }
}

int main() {
    string input;
    vector<int> nums;
    int target;

    // Input the array values
    cout << "Input '[element1,element2,...]': ";
    getline(cin, input);

    // Parse the array input
    parseArrayInput(input, nums);

    // Input the target value
    cout << "target: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(nums, target);

    // Output the result
    cout << "Output: " << result << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
