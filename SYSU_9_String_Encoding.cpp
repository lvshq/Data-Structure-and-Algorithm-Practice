/*
Description
Jourk最近在研究一种加密算法，里面涉及编码传输的相关应用。运用这种加密传输编码，可以提高传输效率和安全性。刚好Even近来总抱怨手机总被非法程序入侵，导致信号的不稳定和信息的泄露，于是Jourk打算运用这种编码技术，帮她开发一个手机端安全编码传输程序。
Jourk运用的编码技术涉及两个概念，前端字典表以及后端映射表。前端字典表为n串长度为1的字母字符串。后端映射表是一串由数字'0'-'9'以及编码分隔符'-'组成的字符串，其中分隔符之间的数字i表示对应前端字典表的第i个（从1开始计数）字符串。如果数字为0，则进行字符串传送以及前端字母表扩增，即对现阶段本手机上的字符串进行传送，并将该字符串放入前端字母表中。例如前端字母表为“AB”，后端映射表为“1-2-0-3-1-0-1-2-3-0”，则1对应“A”，2对应“B”，当遇到0，则传送“AB”，并将“AB”存入前端字母表为3的位置，之后的传送以此类推，注意两个传送字符串之间需要用一个空格隔开，加密算法需要将后端映射表的所有字符按照上述规定处理并在最后做输出处理。
现在要求你来编写程序实现Jourk需要这个传送模块的功能。

Input
输入共三行。第一行为一个整数n，表示前端字符表有几个长度为1的字母字符串。
第二行有n个长度为1的字母字符串，注意之间没有空格隔开。
第三行为一个字符串s，表示后端映射表。
对于100%的数据，1<=n<=26，对于字符串s的长度len，保证1<=len<=255。
Output
输出共一行，表示完整传送的字符串。

Sample Input
2
AB
1-2-0-3-1-0-1-2-3-0

Sample Output
AB ABA ABAB
*/

// 模拟题意。难点在于理解题意，若未仔细读题，可能卡题。此外，特殊情况如0-0-0也需要考虑，要删去多余空格。 

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    string finalStr = "";
    cin >> n;
    vector<string> backend;
    char *charTable = new char[n];  //  charTable stores the characters, no more than 26.
    string tem = "";
    for (int i = 0; i < n; i++) {
        cin >> charTable[i];
        tem = "";
        tem += charTable[i];
        backend.push_back(tem);
    }
    int num;
    char c;
    string toPrint = "";  //  toPrint appends the characters and stores the string to be print
    scanf("%d", &num);  //  Get the first number
    toPrint += charTable[num-1];
    c = getchar();
    while (c != '\0' && c != '\n' && c != EOF) {
        scanf("%d", &num);
        if (num == 0) {  // Print and increase capacity
            int i, len = backend.size();
            backend.push_back(toPrint);  //  Increase capacity. 
            finalStr += toPrint + " ";  //  Print
            toPrint.clear();
        } else {
            toPrint += backend[num-1];
        }
        c = getchar(); // jump over the '-'
    }
    
    int strlen = finalStr.size();
    while (finalStr[strlen-1] == ' ') {
        strlen--;
    }
    for (int i = 0; i < strlen; i++) {
        cout << finalStr[i];
    }
    cout << endl;
    
    return 0;
}
