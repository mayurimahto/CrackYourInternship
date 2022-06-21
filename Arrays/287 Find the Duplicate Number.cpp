//Bruteforce
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Brutefore- Sort and traverse the array.
        int ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                ans = nums[i];
            }
        }
        return ans;
    }
};

//Using Hashmap
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Hashmap
        int ans=0;
        map<int, int>memo;
        for(int i=0; i<nums.size(); i++){
            memo[nums[i]]++;
        }
        
        for(auto j:memo){
            if(j.second>1)
            {
                ans = j.first;
                break;
            }
        }
        return ans;
    }
};

//Optimal
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //LinkedList Cycle Method or Floyld Algorithm(Tortoise and Hare)
        // slw pt and fast ptr
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        fast = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};