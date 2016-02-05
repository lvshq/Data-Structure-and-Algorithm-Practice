/*
Description
给定两个无序可重复序列A和B，它们的交集、并集、差集定义如下：
交集（A交B）：在两个序列中同时出现的元素，交集序列中元素的顺序与A序列中的元素顺序一致，注意序列的可重复的。
并集（A并B）：将B序列中不属于A序列的元素接到A序列后面即得到并集序列
差集（A差B）：所有属于序列A但不属于数列B的元素组成的序列，顺序与序列A一致
例如序列A = 【1 2 4 2】，B = 【3 2 5 4】
交集：【2 4 2】
并集：【1 2 4 2 3 5】
差集：【1】

请写一个程序来求解两个序列的交集、并集、差集。

Input
输入有多个测试用例，每个测试用例有3行：
第1行是两个整数M和N，中间用空格隔开，代表序列A和序列B的元素个数
0 ≤M, N ≤100
第2行是M个整数，每两个整数之间用空格隔开，代表序列A的所有元素
第3行是N个整数，每两个整数之间用空格隔开，代表序列B的所有元素
输入结束的标记是EOF。
Output
对于每个测试用例，输出都有3行，分别是A与B的交集、并集和差集（注意差集是A差B而不是B差A），注意每个整数后面都有一个空格。

Sample Input
4 4
1 2 4 2
3 2 5 4

Sample Output
2 4 2
1 2 4 2 3 5
1
*/

//  因为序列可重复，所以不能用set模拟。改为用STL中的vector模拟即可
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N, n;
    while (cin >> M >> N) {
        vector<int> a, b, Inters, Union, Diff;
        for (int i = 0; i < M; i++) {
            cin >> n;
            a.push_back(n);
        }
        for (int i = 0; i < N; i++) {
            cin >> n;
            b.push_back(n);
        }
        vector<int>::iterator it = a.begin();
        
        // Intersection
        for (; it != a.end(); it++) {
            vector<int>::iterator itb = b.begin();
            for (; itb != b.end(); itb++) {  //  Implement "find" method 
                if (*it == *itb)
                   break;
            }
            if (itb != b.end()) // The element exists in b
                cout << *it << ' ';
        }
        cout << endl;
        
        // Union
        for (it = a.begin(); it != a.end(); it++) {
            cout << *it << ' ';
        }
        for (it = b.begin(); it != b.end(); it++) {
            vector<int>::iterator ita = a.begin();
            for (; ita != a.end(); ita++) {  //  Implement "find" method 
                if (*it == *ita)
                   break;
            }
            if (ita == a.end()) // The element doesn't exist in a
                cout << *it << ' ';
        }
        cout << endl;
        
        // Difference
        for (it = a.begin(); it != a.end(); it++) {
            vector<int>::iterator itb = b.begin();
            for (; itb != b.end(); itb++) {  //  Implement "find" method 
                if (*it == *itb)
                   break;
            }
            if (itb == b.end())  // The element doesn't exist in b
                cout << *it << ' ';
        }
        cout << endl;
    }
    
    return 0;
}

