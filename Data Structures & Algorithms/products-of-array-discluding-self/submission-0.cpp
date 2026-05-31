class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        bool a=false;
        int z;
        for(int k=0;k<nums.size();k++){
            if(nums[k]==0){
                a=true;
                z=k;
                break;
            }
        }
        if(a==true){
            int prod=1;
            for(int q=0;q<nums.size();q++){
               if(q!=z) prod*=nums[q];
            }
            for(int y=0;y<nums.size();y++){
                if(y!=z) ans.push_back(0);
                else{ans.push_back(prod);}
            }
            return ans;
        }
        else{int tp=1;
        for(int i=0;i<nums.size();i++){
            tp*=nums[i];
        }
        for(int j=0;j<nums.size();j++){
            ans.push_back(tp/nums[j]);
        }
        return ans;
        }
    }
};
