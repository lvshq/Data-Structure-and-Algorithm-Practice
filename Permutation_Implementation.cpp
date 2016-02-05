/*
Description
输入一个数字n，输出从1~n组成的数字的全排列，每个排列占一行，输出按照数值升序排列
比如输入2，则输出是：
12
21
又如输入3，则输出是：
123
132
213
231
312
321

Input
第一行是一个整数m，代表有m个测试用例
接下来的m行，每行是一个整数n，0 < n < 10
Output
对于每个用例，输出它的全排列，每个排列占一行，输出按照数值升序排列

Sample Input
2
2
3

Sample Output
12
21
123
132
213
231
312
321
*/

// 递归题目。经典算法。 

#include <iostream>
#include <algorithm>
using namespace std;


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
递归全排列 1 2 3 4 5
1，for循环将每个位置的数据交换到第一位
    swap(1,1~5)
2，按相同的方式全排列剩余的位
*/ 
void Perm(int* arr, int begin, int end) {
    if (begin == end - 1) {
        for (int i = 0; i < end; i++)
            cout << arr[i];
        cout << endl;
    } else {
        for (int i = begin; i < end; i++) {  //  begin为每次交换最左端的位置，表示每次将i位置的元素交换到第一位。如1234-1243，则begin为2（从0开始）；1234-2134，则begin为0.
            //  排序保证"交换到第一位"这个操作是在一个"静态"的初始数组上进行的，而不是因为某些全排列操作而被改动。 
            sort(arr+begin, arr+end);  //  排序确保每一步开始时，后面的待全排列的数都是按升序排列的。如当1XXX全部排完、切换到2XXX时，后面的数是按字典序排的(如2134)。否则则是沿用上一步的结果。 
            swap(arr[begin], arr[i]);  //  分别将每个元素交换到最前面，之后全排列剩下的位。即1XXX，然后是2XXX，再是3XXX... 
            Perm(arr, begin + 1, end);
            //swap(arr[begin], arr[i]);  //  复位，循环到下一个元素。但有了sort后，保证剩余元素开始全排列时都能够"从头开始"，所以这一步可以不要了。 
        }
    }
}

int main() {
    int num;
    cin >> num;
    while (num--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = i+1;
        Perm(arr, 0, n);
    }
    return 0;
}
