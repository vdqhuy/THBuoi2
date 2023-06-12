#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool kiemTraSoKhongGiam(double n) {
    string str = to_string(n);
    bool sokogiam = true;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            str.erase(i);
            break;
        }
    }

    for (int i = 1; i < str.length(); i++) {
        if (str[i - 1] > str[i])
        {
            sokogiam = false;
            break;
        }
    }
    return sokogiam;
}

void soNgayCuaThang(int thang, int nam) {
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "Thang " << thang << " co 31 ngay" << endl;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "Thang " << thang << " co 30 ngay" << endl;
        break;
    default:
        if (nam % 400 == 0 || nam % 4 == 0 && nam % 100 != 0) {
            cout << "Thang " << thang << " co 29 ngay" << endl;
        }
        else {
            cout << "Thang " << thang << " co 28 ngay" << endl;
        }
    }
}

void nhapMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> arr[i];
    }
}

void xuatMang(int arr[], int n) {
    cout << "Cac phan tu trong mang: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << setw(2);
    }
    cout << endl;
}

void sapXepMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void chenMang(int a1[], int& n, int a2[], int m, int p) {
    for (int i = n - 1; i >= 0; i--) {
        a1[i + m - 1] = a1[i];
        if (i == p) {
            break;
        }
    }
    n += m;
    int j = 0;
    for (int i = p; i < m; i++) {
        a1[i] = a2[j];
        j++;
    }
}

bool ktSoDep(string n) {
    bool sodep = true;
    int sum = 0;
    if (n[0] != '8' || n[n.length() - 1] != '8') {
        sodep = false;
    }
    else {
        for (int i = 0; i < n.length(); i++) {
            sum += int(n[i]) - 48;
        }
        if (sum % 10 != 0) {
            sodep = false;
        }
    }
    return sodep;
}

int main()
{
    int choice, t;
    cout << "Nhap bai tap (1-4): ";
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Nhap so lan chay: ";
        cin >> t;
        while (t--) {
            double n;
            cout << "Nhap so nguyen duong ko qua 18 chu so: ";
            cin >> n;
            if (kiemTraSoKhongGiam(n)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        break;
    case 2:
        cout << "Nhap so lan chay: ";
        cin >> t;
        while (t--) {
            int arr[20][20], n, m;
            cout << "Nhap so hang: ";
            cin >> n;
            cout << "Nhap so cot: ";
            cin >> m;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << "Nhap phan tu tai hang " << i << " cot " << j << ": ";
                    cin >> arr[i][j];
                }
            }

            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    cout << arr[i][j] << setw(3) << "";
                }
                cout << endl;
            }
        }
        break;
    case 3:
        cout << "Nhap so lan chay: ";
        cin >> t;
        while (t--) {
            string n;
            cin >> n;
            if (ktSoDep(n)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        break;
    case 4:
    {
        cout << "Nhap so lan chay: ";
        cin >> t;
        int count = 1;
        while (t--) {
            cout << "Test " << count << ": " << endl;
            count++;
            int a1[100], a2[100], n, m, p;
            cout << "Nhap so luong phan tu thu 1: ";
            cin >> n;
            cout << "Nhap so luong phan tu thu 2: ";
            cin >> m;
            cout << "Nhap vi tri chen: ";
            cin >> p;
            cout << "Nhap cac phan tu thu 1: ";
            nhapMang(a1, n);
            cout << "Nhap cac phan tu thu 2: ";
            nhapMang(a2, m);
            chenMang(a1, n, a2, m, p);
            xuatMang(a1, n);
        }
        break;
    }
    default:
        cout << "Khong co bai tap " << choice << endl;
    }
}

