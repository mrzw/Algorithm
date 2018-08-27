#include <iostream>
using namespace std;
// 并查集，可以判断有多少个连通分量
int pre[1000];  //记录每个节点的前导点是什么


//查找x的根节点
int find(int x)
{
    while(pre[x]!=x)
        x = pre[x];
    return x;
}

//判断x和y是否连通
void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    //如果不连通，就把他们所在的连通分支合并起来
    if(fx != fy)
    {
        pre[fx] = fy;
    }
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
    // n组测试，每组m个连接,判断最后有几个连通图
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
