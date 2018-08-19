class Solution {
public:
	// 后序遍历最后一个点是关键点，将sequence分成两部分，前半部分比关键点小，后半部分比关键点大。
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len<=0) return false;
        return Verify(sequence,0,len-1);
    }
    bool Verify(vector<int>& sequence, int left, int right) {
        if(left>=right) return true;
        int index = 0;
        int root = sequence[right];
        for(index = left; index<right; ++index) {
            if(sequence[index]>root)
                break;
        }
        for(int i=index; i<right; ++i) {
            if(sequence[i]<root)
                return false;
        }
        return Verify(sequence, left, index-1) && Verify(sequence, index, right-1);
    }
};
