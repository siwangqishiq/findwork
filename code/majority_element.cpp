/**
 * @file majority_element.cpp
 * 
 *

169. 多数元素

给定一个大小为 n 的数组 nums ，
返回其中的多数元素。
多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums){
    if(nums.empty()){
        return 0;
    }

    unordered_map<int , int> elementCountMap;
    int halfCount = nums.size() / 2;
    for(int &value : nums){
        if(elementCountMap.find(value) == elementCountMap.end()){ //not found
            elementCountMap[value] = 1;
        }else{
            elementCountMap[value] = elementCountMap[value] + 1;
        }
    }//end for each

    std::pair<int , int> maxCountPair(0 , 0);
    for(auto &pair : elementCountMap){
        // cout << pair.first << " : " << pair.second << endl;
        if(maxCountPair.second < pair.second){
            maxCountPair = pair;
        }
    }
    return maxCountPair.first;
}

int main(){
    vector<int> nums = {1 , 3,4, 5, 5,5 ,5,5,5,3 , 2 ,3};
    cout << majorityElement(nums) << endl;
    return 0;
}
