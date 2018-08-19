class Solution {
public:
	// 以array[i]为尾的子数组的最大和 tmp[i] = max(tmp[i-1]+array[i], array[i])
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        vector<int> tmp(len); // tmp[i]记录以array[i]为尾的子数组的最大和
        tmp[0] = array[0];
        int maxData = array[0];
        for(int i=1; i<len; ++i) {
            if(tmp[i-1]<=0) {
                tmp[i] = array[i];
            } else {
                tmp[i] = tmp[i-1]+array[i];
            }
            if(tmp[i]>maxData)
                maxData = tmp[i];
        }
        return maxData;
    }
};
