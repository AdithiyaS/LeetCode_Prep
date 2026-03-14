class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> elements;
        for(int i=0; i< (int)nums.size(); i++){
            elements[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> queue;
        for (auto t = elements.begin(); t != elements.end(); t++){
            int topvalue = t-> first;
            int topcount = t-> second;
            queue.push({topcount, topvalue});
            if((int) queue.size() >k) queue.pop();

        }
        
        vector<int> output;
        output.reserve(k);

        while(!queue.empty()){
            output.push_back(queue.top().second);
            queue.pop();
        }

        // for(int i=0; i<k; i++){
        //     int k=0, c=0;
        //     auto t = elements.begin();
        //     for(; t!= elements.end(); t++){
        //         if(t->second > c){
        //             c = t->second;
        //             k = t->first;
        //         }
        //     }
        //     output.push_back(k);
        //     elements.erase(k);
        // }
        return output;
    }
};

/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/