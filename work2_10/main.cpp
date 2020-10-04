#include <iostream>
using namespace std;

int b[100000];

int Element_mid(int left, int right){
    int count1,count2 = 0;
    if(left == right) return b[left];
    int middle = (left + right) / 2;
    int Ele_left = Element_mid(left, middle);              //二分寻找主元素
    int Ele_right = Element_mid(middle + 1, right);    //二分寻找主元素
    for(int i = left; i <= right; i++){
        if(b[i] == Ele_left)    count1++;                 //计数
        if(b[i] == Ele_right)   count2++;                 //计数
    }
    if(count1 > (right - left) / 2) return Ele_left;      //判断是否为主元素
    if(count2 > (right - left) / 2) return Ele_right;     //判断是否为主元素
    return 0xffffff;
}

int main(){
    cout << "请输入数组大小n：";
    int n = 0;
    cin >> n;
    cout << "请依次输入n个数字：";
    for(int i = 0; i < n; i++) cin >> b[i];
    int main_Ele = Element_mid(0, n - 1);
    if(main_Ele == 0xffffff)
        cout << "不存在";
    else
        cout << "存在，主元素是" << main_Ele;
    return 0;
}
