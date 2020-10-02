#include <iostream>
#include <algorithm>
#define N 10000
int a[N];
using namespace std;

int partition(int p, int r ,int x){       //以x为基准划分元素，小于x在左，大于在右
    int m = 0;
    for(int i = p, j = r; i < j; i++){
        if(a[i] > x){
            while(i < j && a[j] > x)
                j--;
            if(i != j){
                int db = a[i];
                a[i] = a[j];
                a[j] = db;
                j--;
            }
        }
        m = i;
    }
    return m - 1;
}

void Sort(int m, int n){
    for (int i = m; i <= n; i++) {
        int x = i;
        for (int j = i + 1; j <= n; j++)
            if (a[x] > a[j])
                x = j;
        if (x != i) {
            int num = a[x];
            a[x] = a[i];
            a[i] = num;
        }
    }
}

int select(int left, int right, int k){
    if(right - left < 5){
        Sort(left, right);
        return a[left + k - 1];
    }
    for (int i = 0; i <= (right - left - 4) / 5; i++){
        Sort(left + 5 * i, left + 5 * i + 4);
        int jk = a[left + 5 * i + 2];
        a[left + 5 * i + 2] = a[left + i];
        a[left + i] = jk;
    }
    int x = select(left, left + (right - left - 4) / 5, (right - left - 4) / 10);
    int local = partition(left, right, x), j = local - left + 1;
    if (k <= j) return select(left, local, k);
    else return select(local + 1, right, k - j);
}

int main() {
    cout << "请输入数组长度n：";
    int n = 0;
    cin >> n;
    cout << "请输入依次输入n个数：";
    for(int i = 0; i < n; i++)  cin >> a[i];
    int finding = select(0, n - 1, n / 2);
    int count = 0;
    for(int i = 0; i < n; i++){
        //cout << a[i] << " ";
        if(a[i] == finding)
            count++;
    }
    if(count > n / 2)
        cout << "存在";
    else
        cout << "不存在";
    return 0;
}
