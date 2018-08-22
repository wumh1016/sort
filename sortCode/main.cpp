#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void fun1(int* a, int n){ //冒泡排序
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

void fun2(int *a, int n)
{ //选择排序
    for(int j=n-1; j>0; j--)
    {
        int k = 0;
        for(int i=1; i<=j; i++)
        {
            if(a[k] < a[i])
                k = i;
        }
        swap(a[k], a[j]);
    }

}

void fun3(int* a, int n)
{//插入排序
    int i=0, j=0, tmp=0;
    for(i=1; i<n; i++)
    {
        tmp = a[i];
        for(j=i; tmp<a[j-1]&&j>0; j--)
        {
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}

void fun4(int* a, int low, int high)
{//快速排序
    if(low >= high)
        return;
    int first = low;
    int last = high;
    int key = a[first];
    while(first < last){
        while(first<last && a[last]>=key)
            last--;
        a[first] = a[last];//将第一个比key小的移动到低端
        while(first<last && a[first]<=key)
            first++;
        a[last] = a[first];
    }
    a[first] = key;
    fun4(a, low, first-1);
    fun4(a, first+1, high);
}

int main() {
    int a[7] = {4, 6, 2, 9, 3, 1, 8};
    fun4(a, 0, 6);
    for(auto &m : a){
        cout << m << " ";
    }
    cout << endl;
    return 0;
}