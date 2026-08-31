class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int zeroes=0;

        for(auto a:nums){
            if(a!=0) prod*=a;
            else{zeroes++;}
        }
        vector<int> ans(nums.size(),0);
        if(zeroes>1) return ans;
        if(zeroes==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0) ans[i]=prod;
            }
            return ans;
        }

        for(int i=0;i<nums.size();i++){
            ans[i]=prod/nums[i];
        }
        return ans;
    }
};
