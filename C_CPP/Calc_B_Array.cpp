/*****************************************************************
给定一个数组a[N],构造数组b[N],其中b[j]=a[0]*a[1]...a[N-1] / a[j].
在构造过程中,不允许使用除法
要求O(1)空间复杂度和O(n)的时间复杂度.
除遍历计数器与a[N],b[N]外，不可使用新的变量（包括栈临时变量、堆空间和全局静态变量等）

解析：
设b[0]=1
由b[i]=b[i-1]*a[i-1]可得
b[1] = a[0]
b[2] = a[0]a[1]
...
b[i] = a[0]a[1]a[2]…a[i-1]
...
b[n-1] = a[0]a[1]…a[n-2]
那么再通过b[0]这个变量来迭代出1, a[n-1], a[n-2]a[n-1], a[n-3]a[n-2]a[n-1], … , a[1]a[2]a[3]…a[n-1]
迭代过程中分别乘以b[n-1], b[n-2], … , b[0]
*****************************************************************/

#include <iostream>
using namespace std;

void Translate(int a[], int b[], int n)
{
    b[0] = 1;
    for (int i = 1; i <= n-1; i++)
    {
        b[i] = b[i-1]*a[i-1];
    }

    for (int i = n-1; i >= 1; i--)
    {
        b[i] *= b[0];
        b[0] *= a[i];
    }
}

int main(void){
    const int ARRAY_SIZE = 4;
    int a[ARRAY_SIZE] = {1,2,3,4};
    int b[ARRAY_SIZE];

    Translate(a,b,ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        cout<<b[i]<<endl;
    }
    return 0;
}
