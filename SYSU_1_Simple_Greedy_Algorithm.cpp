/*Description
子犇是一只超级懒惰的大牛...每次他在给别人钱的时候都必须用最少数量的钱...因为他懒得多抽一张钱出来...
纸币的面值共有6种，分别是：100  50  20  10  5  1，明天他要给升哥383元，请预测他会拿出多少张纸币...
（假设子犇大牛拥有6种纸币的数量均为无穷大，没错，子犇是真·土豪）

Input
第一行输入一个数字n代表测试用例个数。
接下来的n行，每行是一个数字，代表子犇大牛要给升哥的钱数。

Output
 对于每一行钱数，输出一个数字，代表纸币张数，每个数字占一行。

Sample Input
 Copy sample input to clipboard 
2
15
3

Sample Output
2
3
*/

#include <iostream>
using namespace std;
int M[6] = {100, 50, 20, 10, 5, 1};

int main() {
    int n, i, j, money;
    cin >> n;
    while (n--) {
        cin >> money;
        int count = 0;
        for (int i = 0; i < 6; i++) {
            while (money >= M[i]) {
                  money -= M[i];
                  count++;
            }
        }
        cout << count << endl;
        
    }
    return 0;
}
