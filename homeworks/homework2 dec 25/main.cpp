#include <iostream>
#include "vector"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// I put my code in leetcode.com and it passes all tests and everything works fine
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        while(n%2==0) n/=2;
        return n==1;
    }


    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 31; i >= 0; i--){
            ans |= (n & 1) <<i;
            n>>=1;
        }
        return ans;
    }


    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0)
        {
            if (n & 1)sum++;
            n = n >> 1;
        }
        return sum;
    }


    int maxProfit(vector<int>& prices) {
        int max = INT_MAX;
        int op = 0;
        int curentDif = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < max){
                max = prices[i];
            }
            curentDif = prices[i] - max;
            if(op < curentDif){
                op = curentDif;
            }
        }
        return op;
    }


    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 0; i < nums.size(); i++) {
            for(int k = i + 1; k < nums.size(); k++) {
                if(nums.at(k) + nums.at(i) == target) {
                    return {i, k};
                }
            }
        }
        return {};
    }

    int findPeakElement(vector<int>& nums) {
        int start=0, end=nums.size();
        while (start < end) {
            int mid=start+(end-start)/2;
            if (mid < nums.size()-1 && nums[mid] < nums[mid+1]) {
                start=mid+1;
            }
            else {
                end=mid;
            }
        }

        return start;
    }
};