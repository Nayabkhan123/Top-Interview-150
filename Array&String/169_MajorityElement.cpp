/*
    Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times. 
    You may assume that the majority element always exists in the array.
*/

// Moore Voting Algorithm
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int cnt=0,ans=nums[0],n=nums.size();
            for(int i=0;i<n;i++){
                if(cnt==0){
                    cnt=1;
                    ans=nums[i];
                }
                else if (nums[i]!=ans) cnt--;
                else cnt++;
            }
            return ans;
        }
};

// timeComplexity: O(N) spaceComplexity: O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto it : nums){
            mp[it]++;
            if(mp[it]>(n/2)) return it;
        }
        return 0;
    }
};

// timeComplexity: O(N^2) spaceComplexity: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]) cnt++;
            }
            if(cnt>(n/2)) return nums[i];
        }
    return 0;
    }
};