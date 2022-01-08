//Cho biết ý nghĩa của các khai báo và câu lệnh
//Tìm lỗi sai trong đoạn code sau
#include <iostream>
using namespace std;

int main() {
    int *x, y = 2; //unreference local variable: x
    *x = y; //gán giá trị vùng nhớ x trỏ đến = y
    *x += y++; //tăng giá trị vùng nhớ x trỏ đến lên (y + 1) đơn vị
    cout << *x << y;
}