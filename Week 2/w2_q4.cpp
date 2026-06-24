class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> win;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            while(!win.empty() and win.front()<=i-k) win.pop_front();
            while(!win.empty() and nums[win.back()]<=nums[i]) win.pop_back();
            win.push_back(i);
            if(i>=k-1) v.push_back(nums[win.front()]);
        }
        return v;
    }
};