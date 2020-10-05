#include <iostream>
#include <vector>
using namespace std;

double find_middle(vector<double> a,vector<double> b){
    int n = a.size();
    if(n % 2 == 1){
        double a1 = a[(n - 1) / 2];
        double b1 = b[(n - 1) / 2];
        if(a1 == b1)    return a1;
        if(a1 != b1 && n == 1)  return (a1 + b1) / 2;
        else if(a1 > b1){
            a.erase(a.begin() + (n + 1) / 2, a.end());
            b.erase(b.begin(), b.begin() + (n - 1) / 2);
            return find_middle(a, b);
        }
        else if(a1 < b1){
            b.erase(b.begin() + (n + 1) / 2, b.end());
            a.erase(a.begin(), a.begin() + (n - 1) / 2);
            return find_middle(a, b);
        }
    }
    else{
        double a1 = a[n / 2];
        double b1 = b[n / 2 - 1];
        if(a1 == b1)    return a1;
        if(n == 2){
            a.pop_back();
            b.erase(b.begin());
            return find_middle(a, b);
        }
        if(a1 > b1){
            a.erase(a.begin() + n / 2 + 1, a.end());
            b.erase(b.begin(), b.begin() + n / 2 - 1);
            return find_middle(a, b);
        }
        else if(a1 < b1){
            b.erase(b.begin() + n / 2 + 1, b.end());
            a.erase(a.begin(), a.begin() + n / 2 - 1);
            return find_middle(a, b);
        }
    }
}
int main() {
    int n = 0;
    cout << "请输入数组规模：";
    cin >> n;
    vector <double> a(n);
    vector <double> b(n);
    cout << "请依次输入a数组的数字：";
    for(int i = 0; i < n ; i++)
        cin >> a[i];
    cout << "请依次输入b数组的数字：";
    for(int i = 0; i < n ; i++)
        cin >> b[i];
    cout << find_middle(a, b) << endl;
    return 0;
}
