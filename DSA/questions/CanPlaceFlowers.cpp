// 605. Can Place Flowers


// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

// Example 1:

// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true

// Example 2:

// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: false

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        int count=0;
        if(size==1 and flowerbed[0]==0 and n<=1){
            return true;
        }
        for(int j=0;j<size;j++){
            if(flowerbed[j]==0 and (j==0||flowerbed[j-1]==0) and(j==size-1 || flowerbed[j+1]==0)){
                flowerbed[j]=1;
                count++;
            }
        }

        if(count>=n) return true;
        else return false;
    }
};