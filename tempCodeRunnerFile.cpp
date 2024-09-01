#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countTriplets(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> freq;  // To store the frequency of each number
    int count = 0;
    
    // Populate the frequency map
    for(int num : nums) {
        freq[num]++;
    }
    
    // Iterate over all pairs (b, c)
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int b = nums[i];
            int c = nums[j];
            int a = (b + c) / 2;

            // Check if (b + c) is even and if `a` exists in the array
            if ((b + c) % 2 == 0 && freq.find(a) != freq.end()) {
                count += freq[a];  // Add the frequency of `a` to the count
            }
        }
    }
    
    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = countTriplets(nums);
    cout << "The number of valid triplets is: " << result << endl;

    return 0;
}
