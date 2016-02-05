/*
Description
排序是一种必不可少的工具，生活工作中随处可见排序的应用。
例如，平日我们整理文档的时候难免要按序号排序，现在用选择排序方法来解决问题。
选择排序的方法是，将大小为N的数组分成S(Sorted)和U(Unsorted)两个部分，代表已经排序和未排序的部分。
每次操作均从U中挑选一个最小元素，跟U中的第一个元素交换，随后将U中的第一个元素归入S中。
即，每次操作结束后S将增加一个元素，U将减少一个元素。做完(N-1)次操作即可完成整个选择排序。

Input
可能有多个测试输入，第一行给出总共的测试输入的个数。
对于每个测试输入，第一行包含一个正整数N，第二行包含一个大小为N的无序数组(0<N<1000)。

Output
输出每次数组做选择排序得到的结果，共计(N-1)行数据。数据之间用一个空格隔开，行末不能有多余的空格。

Sample Input
1
5
2 5 4 1 3

Sample Output
1 5 4 2 3
1 2 4 5 3
1 2 3 5 4
1 2 3 4 5
Problem Source: 2012年期末机考（Pan）
*/

// 考察选择排序原理 

#include <iostream>
using namespace std;

int main() {
	int T, num, i, j, k, tem, minIndex, min, pos, a[1005];
	bool flag;
	cin >> T;
	while (T--) {
		cin >> num;
		for (i = 0; i < num; i++)
            cin >> a[i];
		for (pos = 0; pos < num-1; pos++) {  //  Right side of pos is unsorted list.
        //  Upper bound is num-1 because the sort ended when unsorted list length is 1. If change to "pos < num", then the last two step will be the same.
			min = a[pos];
            minIndex = pos;
			for (j = pos; j < num; j++) {  //  Starting from pos, find the minimal element in rhs.
				if (min > a[j]) {
					min = a[j];
					minIndex = j;
				}
			}
			//  Exchange minimum element in unsorted list with current position.
			tem = a[minIndex];
			a[minIndex] = a[pos];
			a[pos] = tem;
			//  Print result each pass
            for (j = 0; j < num-1; j++)
                cout << a[j] << ' ';
			cout << a[j] << endl;
		}
	}
	return 0;
}
