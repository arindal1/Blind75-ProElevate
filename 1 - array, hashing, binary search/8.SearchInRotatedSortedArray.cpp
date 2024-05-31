class Solution {
public:
bool sorted(vector<int>& nums, int s, int e) {
    if(nums[s] > nums[e]) return false;
    return true;
}
    int search(vector<int>& nums, int target){
        int s = 0, e = nums.size()-1;

        while(s<=e){
            int mid = (s+e)/2;
            cout << mid << " ";
            if(nums[mid] == target) return mid;
            if(nums[s] == target) return s;
            if(nums[e] == target) return e;
            if(sorted(nums, s, mid) == true){
                if(nums[s] < target and target < nums[mid]) e = mid-1;
                else s = mid+1;
            }
            else{
                if(nums[mid] < target and target < nums[e]) s = mid+1;
                else e = mid-1;
            }   
        }
        return -1;
    }
};