#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2 ;

            if(target == nums[mid]) return mid;

            //You are sure that either of the part will be sorted you just need to find that part

            //Left part is sorted
            if(nums[low]<=nums[mid])
            {
                //Here we are looking that if my answer exists between that sorted part or not
                if(target<nums[mid] && target>=nums[low])
                {
                    high = mid-1;
                }
                //If it dosen't check in rotated part
                else{
                    low = mid+1;
                }
            }

            //Right part is sorted
            else{
                if(target>nums[mid] && target<=nums[high])
                {
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }

        return -1;
    
    }