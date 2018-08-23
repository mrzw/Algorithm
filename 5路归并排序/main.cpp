// 基于最小堆的5路排序,其中K1-K5已经内部排序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define K 5

struct node {
    int val;
    int index; // 第几路
    int p; // 第几路val下标
    node(int v, int i, int p1):val(v),index(i),p(p1) {}
    bool operator<(const node& n) {
        return this->val > n.val;
    }
};

vector<int> k1 = {2,3,4,5};
vector<int> k2 = {1,3,4,5};
vector<int> k3 = {3,4,6};
vector<int> k4 = {2,3,5,6};
vector<int> k5 = {4,6,7,8};

node heapExtractMin(vector<node>& da) {
    node minNode = da[0];
    pop_heap(da.begin(), da.end());
    da.pop_back();
    return minNode;
}
void insertHeap(vector<node>& da, node node1) {
    da.push_back(node1);
    push_heap(da.begin(), da.end());
}

int main() {
    vector<node> da;
    vector<vector<int> > inputData;
    inputData.push_back(k1);
    inputData.push_back(k2);
    inputData.push_back(k3);
    inputData.push_back(k4);
    inputData.push_back(k5);
    for(int i=0; i<inputData.size(); ++i) {
        if(inputData[i].size()>0) {
            da.push_back(node(inputData[i][0],i,0));
        }
    }

    make_heap(da.begin(), da.end());
    vector<int> res;
    while(!da.empty()) 
    {
        node minData = heapExtractMin(da);
        res.push_back(minData.val);
        if(++minData.p < inputData[minData.index].size()) 
        {
            insertHeap(da, node(inputData[minData.index][minData.p], minData.index, minData.p));
        }
    }

    for(auto i:res) {
        cout << i << " ";
    }
}
