#include<stdio.h>
#include<memory.h>
//题目：从2.5亿个正整数中找到不重复的整数。

//用char数组存储2-Bitmap 00代表没出现，01代表出现一次，10代表出现多次
unsigned char flags[1000]; //数组大小自定义

unsigned get_val(int idx)
{
    int i = idx/4;
    int j = idx%4;
    // 获取当前数的两位字节
    unsigned ret = (flags[i]&(0x3<<(2*j)))>>(2*j);
    return ret;
}

unsigned set_val(int idx, unsigned int val)
{
    int i = idx/4;
    int j = idx%4;
    // (flags[i]&(~(0x3<<(2*j)))) 将当前数的两位字节设为00
    // ((val%4)<<(2*j))将新设的val移动到指定位置
    // (flags[i]&(~(0x3<<(2*j)))) | ((val%4)<<(2*j)) 将新设的val赋值到指定位置
    unsigned tmp = (flags[i]&(~(0x3<<(2*j)))) | ((val%4)<<(2*j));
    flags[i] = tmp;
    return 0;
}
unsigned add_one(int idx)
{
    if (get_val(idx)>=2) {
        return 1;
    }
    else  {
        set_val(idx, get_val(idx)+1);
        return 0;
    }
}

//只测试非负数的情况;
//假如考虑负数的话,需增加一个2-Bitmap数组.
int a[]={1, 3, 5, 7, 9, 1, 3, 5, 7, 1, 3, 5,1, 3, 1,10,2,4,6,8,0};

int main()
{
    int i;
    memset(flags, 0, sizeof(flags));

    printf("原数组为:");
    for(i=0;i < sizeof(a)/sizeof(int); ++i)  {
        printf("%d  ", a[i]);
        add_one(a[i]);
    }
    printf("\r\n");

    printf("只出现过一次的数:");
    for(i=0;i < 100; ++i)  {
        if(get_val(i) == 1)
            printf("%d  ", i);
    }
    printf("\r\n");

    return 0;
}
