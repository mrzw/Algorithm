class Solution {
public:
	// 采用2分查找的思想
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()<=0) return 0;
        int low = 0;
        int high = rotateArray.size()-1;
        int index = 0;
        while(rotateArray[low]>=rotateArray[high]) {
            if(high-low==1) {
                index = high;
                break;
            }
            index = (high-low)/2+low;
            // 如果头，中间，尾的数字一样，只能顺序查找
            if(rotateArray[low]==rotateArray[index] && rotateArray[index]==rotateArray[high]) {
                index = lineSearch(rotateArray);
                break;
            }
            if(rotateArray[index]>=rotateArray[low]) {
                low = index;
            } else if(rotateArray[index]<=rotateArray[high]) {
                high = index;
            }
        }
        return rotateArray[index];
    }
    int lineSearch(const vector<int> &rotateArray) {
        int len = rotateArray.size();
        int index = 0;
        for(int i=1; i<len; ++i) {
            if(rotateArray[i]<rotateArray[index])
                index = i;
        }
        return index;
    }
};
