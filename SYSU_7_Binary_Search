//the function search in an ordered vector table between bot and top (inclusive) for x.
// It returns the index of its 【last oocurrence】 if search is successful, it returns -1 if search is unsuccessful.
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int binarySearch(const vector<T> table, int start, int end, const T &x) {
    int left = 0, right = end, mid;
    while (left < right-1) {  //  要减一是因为【除法是向下取整】。比如(5+6)/2 = 5.此时mid就保持不变。若不加-1，则会无限循环。 
        mid = (right + left) / 2;
        if (x >= table[mid])  //  这里把等于的条件加了进去，因此即使找到了相等的元素，也不会直接返回，而是继续向右半部分找，直到left < right-1。最后在循环外的判断条件处返回。 
            left = mid;
        else
            right = mid;
    }

    if (table[right] == x) return right;
    else if(table[left] == x) return left;
    else return -1;
    
    
    //  以下为找【第一次出现】的代码。 
    /*int left, right;
    int mid;
    left = start;
    right = end;*/
    
    //注释中为递归算法，执行效率低，不推荐
    /*
    if(key<Array[mid])
    {
        return(binSearch(Array,left,mid,key));
    }
    else if(key>Array[mid])
    {
        return(binSearch(Array,mid+1,right,key));
    }
    else
    return mid;
    */
    
    /*
    while(left <= right)
    {
        mid = (left + right) / 2;
        if (x == table[mid])  return mid;  //  与找最后一次出现不同，第一次判断到相等就直接返回。 
        else if (x < table[mid]) right = mid-1;
        else if (x > table[mid]) left = mid+1;
    }
    return -1;*/
}

int main() {
	int a[ ] = {0,1,1,3,3,3,6};
    vector<int> v(a,a+7);
    cout << binarySearch(v, 0, v.size()-1, 3) << endl;  // 输出5
    cout << binarySearch(v, 0, v.size()-1, 7) << endl;  //输出-1
    return 0;
}


