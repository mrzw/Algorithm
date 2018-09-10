#include <iostream>
using namespace std;
// https://www.jianshu.com/p/fc17847b0a31
// 并查集，可以判断有多少个连通分量
int pre[1000];  //记录每个节点的前导点是什么


//查找x的根节点
int find(int x)
{
    return x==pre[x]?x:(pre[x]=find(pre[x])); // 路径压缩
//    return x==pre[x]?x:(find(pre[x])); // 非压缩
}

//判断x和y是否连通
void join(int x, int y)
{
    pre[find(x)] = pre[find(y)];
}

//初始化（每个元素都是一个集合）

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        pre[i] = i;
    }
}

/*
 * 只用到了初始化（每个元素都是一个集合）、查找（某个元素所在的集合，集合以根节点标志）、合并（两集合不属于同一集合则合并）
 * 思想：找出连通分量的个数。而利用并查集时可以发现连通分量的个数等于父节点为自身的节点数目。
 */
int main()
{
    // n个结点，m个连接,判断最后有几个连通图
    int n,m,a,b;
    while(cin>>n)
    {
        init(n);
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            join(a,b);
        }
        //统计连通分支个数
        int count = 0;
        for(int i=1;i<=n;i++)
        {
            if(pre[i] == i)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
