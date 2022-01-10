#include <iostream>

using namespace std;

//Bai 9
/*void func() {
    int n1 = 100, n2 = 3;
    float ketqua = n1 / n2;
    printf("%d / %d = %f", n1, n2, ketqua);
    //Ket qua la 33.00000 (phan nguyen cua 100 chia cho 3 kieu so thuc)
}*/

//Bai 10
/*int main() {
    void *p;
    p = (float *)malloc(sizeof(float));
    *p = 1.23;
    //Khong the gan gia tri cho con tro void bang toan tu *
}*/

//Bai11
/*void hamf(int *a) {
    a = new int[5];

    for (int i = 0; i < 5; i++)
        a[i] = i + 1;
}

int main() {
    int n = 5;
    int *a = &n;

    cout << "Gia tri *a = " << *a;
    hamf(a);
    cout << "Gia tri *a = " << *a;
    //Ket qua la "Gia tri *a = 5Gia tri *a = 5"
    //Vi tham so cua hamf khong phai la tham so tham chieu
}*/

//Bai12
void hamf(int *&a) {
    a = new int[5];

    for (int i = 0; i < 5; i++)
        a[i] = i + 1;
}

int main() {
    int n = 5;
    int *a = &n;
    
    cout << "Gia tri *a = " << *a;
    hamf(a);
    cout << "Gia tri *a = " << *a;
    //Ket qua la "Gia tri *a = 5Gia tri *a = 1"
    //Vi tham so cua hamf la tham so tham chieu
}