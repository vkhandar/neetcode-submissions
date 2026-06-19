class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid = (high + low)/2;

        while((low<=high) ){
            if(nums[mid] == target){
                return mid;
            }
            //if(mid==low) return -1;
            if(nums[low] <= nums[mid]){
                //left side is sorted
                if((nums[low] <= target) && (target <=nums[mid] )){
                    high = mid -1;
                    
                } else {
                    low = mid +1 ;
                }

            }
            else{
                //right side is sorted
                if((nums[high] >= target) && (target >=nums[mid] )){
                    low = mid +1;

                } else {
                    high = mid-1;
                }
            }

            mid = (high + low)/2;
        }

        return -1;
        
        
    }
};
