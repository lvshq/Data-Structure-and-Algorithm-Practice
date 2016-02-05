#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    public:
         LinkedList() {
            head = NULL;
            size = 0;
         }
         
        /*
        插入一个元素content到链表的第position个位置，注意position从0开始
        如原始链表是 1 2 3，insert(0, 5)之后变成 5 1 2 3
        如果插入的位置在链表末尾或者之后，则直接将元素插入到链表末尾
        如原始链表是 1 2 3，insert(50, 6)之后变成 1 2 3 6
        第50个位置在当前链表大小之后，所以直接插入到链表末尾，也就是第3个位置
        */
         void insert(int position, int content) {
            Node *p = head;
            Node *newNode = new Node();
            newNode->data = content;
            if (position >= size) {  // 链表为空或者超出范围 
                if (p == NULL) {  // 链表为空 
                    p = new Node();
                    newNode->next = NULL;
                    head = newNode;
                } else {  // 超出范围 
                  while (p->next != NULL)
                        p = p->next;  // 找到队尾指针 
                  p->next = newNode; // 进行插入 
                  newNode->next = NULL;
                }
            } else {  //  正常插入
              if (position == 0) { // 单独处理插入到头指针（下标为0）的情况 
                  newNode->next = head;
                  head = newNode;
              } else { // 正常情况 
                  while (position > 1) { //因为已经处理过0的情况，所以这里下界为1 
                      position--;
                      p = p->next;
                  }
                  newNode->next = p->next;
                  p->next = newNode;
              }
            }
            size++;
         }
         
        /*
        删除链表的第position个元素
        如果链表没有第position个元素，则不删除任何元素
        */
         void deleteByPosition(int position) {
            Node *p = head;
            if (position >= size) // 超出范围，不作处理 
               return;
            else if (position == 0) { // 单独处理0的情况 
                if (head == NULL) cout << "here" << endl;
                Node *p = head;
                head = head->next;
                delete p;
                size--;
            } else { // 其他正常情况 
              while (position > 1) {  // 用while(--position)，则position为0时仍会进入循环。因为已经处理过0的情况，所以这里下界为1 
                p = p->next; // 找到要删除的操作 
                position--;
              }
              Node *q = p->next;
              p->next = q->next;
              delete q;
              size--;
            }
         }

        /*
        将链表内容打印到屏幕，每个元素后面都跟着一个制表符，
        并且最后一个元素的制表符后面需要换行
        */
         void print() {
            Node *p = head;
            while (p != NULL) {
                cout << p->data << "\t";
                p = p->next;
            }
            cout << endl;
         }
         
    private:
         Node *head;  // 链表头指针
         int size;  // 链表内元素个数
};
