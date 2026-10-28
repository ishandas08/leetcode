class Solution {
public:
     vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int posidx=0;
        int negidx=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negidx]=nums[i];
                negidx+=2;
            }else{
                ans[posidx]=nums[i];
                posidx+=2;
            }
        }
        return ans;
    }
};