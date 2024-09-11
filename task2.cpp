// Task2

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// To find the minimum element in a rotated sorted array
int findMin(const vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum element is in the right half
            left = mid + 1;
        } else {
            // Minimum element is in the left half including mid
            right = mid;
        }
    }

    // After the loop, left == right and points to the smallest element
    return nums[left];
}


void parseInput(const string& input, vector<int>& nums) {
    istringstream iss(input);
    string temp;


    getline(iss, temp, '[');
    getline(iss, temp, ']'); // Extract elements between brackets

    istringstream arrayStream(temp);
    int number;
    char comma;

    while (arrayStream >> number) {
        nums.push_back(number);
        arrayStream >> comma; // Ignore the comma
    }
}

int main() {
    string input;
    vector<int> nums;

 
    cout << "Input'[element1,element2,...]': ";
    getline(cin, input);

    // Parse the input to extract the array elements
    parseInput(input, nums);

    // Ensure the array is not empty before proceeding
    if (nums.empty()) {
        cout << "The array is empty or invalid." << endl;
        return 1;
    }

    // Find and output the minimum element
    int minElement = findMin(nums);
    cout << "Output: " << minElement << endl;

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)
