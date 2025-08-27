#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long hours(vector<int> &arr, int hrs) {
        long long totalhrs = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalhrs += (arr[i] + hrs - 1) / hrs;  // ceiling division
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mid, ans = high;

        //Basically the idea is the maximum value in the array will always be the last possible answer to any h
        //So the answer will always be from 1 to max_value 
        // Using binarysearch by adding the total hrs you try to fit in that value
        
        while (low <= high) {
            mid = (low + high) / 2;
            long long val = hours(piles, mid);

            if (val <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
