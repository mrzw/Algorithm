#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 冒泡排序
void BubbleSort(vector<int>& da, int len) {
    bool extrange = false;
    for(int i=0; i<len; ++i) {
        extrange = false;
        for(int j=0; j<len-1-i; ++j) {
            if(da[j]>da[j+1]) {
                swap(da[j],da[j+1]);
                extrange = true;
            }
        }
        if(!extrange) return;
    }
    return;
}
// 选择排序
void SelectSort(vector<int>& da, int len) {
    int minIndex = 0;
    for(int i=0; i<len; ++i) {
        minIndex = i;
        for(int j=i+1; j<len; ++j) {
            if(da[minIndex]>da[j]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(da[minIndex],da[i]);
        }
    }
}
// 快速排序
int partion(vector<int>& da, int start, int end) {
    int pivot = da[start];
    while(start<end) {
        while(start<end && da[end]>=pivot) --end;
        da[start] = da[end];
        while(start<end && da[start]<=pivot) ++start;
        da[end] = da[start];
    }
    da[start] = pivot;
    return start;
}
void QuickSort(vector<int>& da, int start, int end) {
    if(start>=end) return;
    int index = partion(da, start, end);
    QuickSort(da, start, index-1);
    QuickSort(da, index+1, end);
}
// 归并排序
void Merge(vector<int>& da, int start, int mid, int end) {
    vector<int> L(mid-start+1);
    vector<int> R(end-mid);
    for(int i=0; i<mid-start+1; ++i) {
        L[i] = da[start+i];
    }
    for(int i=0; i<end-mid; ++i) {
        R[i] = da[mid+1+i];
    }
    int i=0,j=0, k=start;
    while(i<mid-start+1 && j<end-mid) {
        if(L[i] < R[j]) {
             da[k++] = L[i++];
        } else {
            da[k++] = R[j++];
        }
    }
    while(i<mid-start+1) {
        da[k++] = L[i++];
    }
    while(j<end-mid) {
        da[k++] = R[j++];
    }
}
void MergeSort(vector<int>& da, int start, int end) {
    if(start>=end) return;
    int mid = (start+end)/2;
    MergeSort(da, start, mid);
    MergeSort(da, mid+1, end);
    Merge(da, start, mid, end);
}
// 堆排序
void heapify(vector<int>& da, int len, int i) {
    int tmp = da[i];
    for(int k=2*i+1; k<len; k = 2*k+1) {
        if(k+1<len && da[k]<da[k+1]) { // 将k指向左右子结点中较大的
            ++k;
        }
        if(da[k] > tmp) { //左右孩子节点数值大于父节点的数值,将左右孩子节点中数值大的赋值给父节点
            da[i] = da[k];
            i = k; //调整i指向较大的儿子结点
        } else break;
    }
    da[i] = tmp;
}
void HeapSort(vector<int>& da, int len) {
    for(int i=len/2-1; i>=0; --i) {
        heapify(da, len, i);
    }
    for(int i=len-1; i>=0; --i) {
        swap(da[0],da[i]);
        heapify(da, i, 0);
    }
}
// 插入排序
void InsertSort(vector<int>& da, int len) {
    int minIndex = 0;
    int tempData = 0;
    for(int i=1; i<len; ++i) {
        minIndex = i-1;
        tempData = da[i];
        while(minIndex >= 0 && tempData < da[minIndex]) {
            da[minIndex+1] = da[minIndex];
            --minIndex;
        }
        da[minIndex+1] = tempData;
    }
}
// 希尔排序
void ShellSort(vector<int>& da, int len) {
    int minIndex = 0;
    int tmp = 0;
    for(int gap=len/2; gap>0; gap/=2) {
        for(int i=gap; i<len; ++i) {
            minIndex = i-gap;
            tmp = da[i];
            while(minIndex>=0 && da[minIndex]>tmp) {
                da[minIndex+gap] = da[minIndex];
                minIndex -= gap;
            }
            da[minIndex+gap] = tmp;
        }
    }
}
// 基数排序
void countSort(vector<int>& da, int len, int exp) {
    vector<int> count(10, 0);
    vector<int> output(len, 0);
    for(int i=0; i<len; ++i) {
        ++count[(da[i]/exp)%10];
    }
    for(int i=1; i<10; ++i) {
        count[i] += count[i-1];
    }
    for(int i=len-1; i>=0; --i) {
        output[--count[(da[i]/exp)%10]] = da[i];
    }
    da.assign(output.begin(), output.end());
}
void RadixSort(vector<int>& da, int len) {
    int maxData = *(max_element(da.begin(), da.end()));
    for(int i=1; maxData/i>0; i*=10) {
        countSort(da, len, i); // 基于特定位排序
    }
}

int main() {
    vector<int> a = {5,3,1,2,4,6};
//    BubbleSort(a, a.size());
//    SelectSort(a, a.size());
//    InsertSort(a, a.size());
//    QuickSort(a, 0, a.size()-1);
//    MergeSort(a, 0, a.size()-1);
//    HeapSort(a, a.size());
//    ShellSort(a, a.size());
//    RadixSort(a, a.size());
    for(auto i:a) cout << i << " ";
    return 0;
}
