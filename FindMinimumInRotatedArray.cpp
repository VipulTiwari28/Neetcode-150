#include<bits/stdc++.h>
using namespace std;

 int findMin(vector<int>& arr) {
        // complete the function here
        int low = 0;
        int high = arr.size()-1;
        
        int ans = INT_MAX;
        
        int mid;
        
        while(low <= high)
        {
            mid = (low + high) / 2 ;
            
            //This tells us that left part is sorted 
            // so we take the minimum element in that part
            //And eliminate the left part
            if(arr[low] <= arr[mid])
            {
                ans = min(ans,arr[low]);
                low = mid + 1;
            }
            
            //if the right part is sorted that means 
            //mid element is minimum element
            // and we eliminate the right part
            else{
                ans = min(ans,arr[mid]);
                high = mid - 1;
            }
            
        }
        
        return ans;
 }
