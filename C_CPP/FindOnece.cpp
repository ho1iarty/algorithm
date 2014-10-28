/***************************************************************
题目：一个整数列，除了某一个数字出现1次之外，所有其他数字都重复
    出现3次。找到那个只出现1次的。
提示：出现3次的数字的二进制位的每一位之和必定能被3整除。则出现1
    次的数其二进制为1的位，将导致这一位上的和不能被3整除。
****************************************************************/

#include <stdio.h>
#include <string.h>
int FindOnce(int a[], int a_len)
{
    // 计算int型的二进制位数
    int int_length = sizeof(int) * 8;

    int bits[int_length];
    int i, j;
    // 累加二进制位
    memset(bits, 0, int_length * sizeof(int));
    for (i = 0; i < a_len; i++){
        for (j = 0; j < int_length; j++){
            bits[j] += ((a[i] >> j) & 1);
        }
    }
    // 遍历统计结果，检测是否能被整除
    int rst = 0;
    for (j = 0; j < int_length; j++){
        if (bits[j] % 3 != 0){
            rst += (1 << j);
        }
    }
    return rst;
}

int main()
{
    const int NUM = 10;
    int a[NUM] = {1,2,3,3,4,3,2,2,1,1};
    printf("%d\n", FindOnce(a, NUM));

    return 0;
}
