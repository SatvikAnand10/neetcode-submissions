class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int,int> um;

        for(int i=0;i<numbers.size();i++){
            int a=target-numbers[i];

            if(um.count(a)) return {um[a],i+1};

            um[numbers[i]]=i+1;
        }
        return {};
    }
};
