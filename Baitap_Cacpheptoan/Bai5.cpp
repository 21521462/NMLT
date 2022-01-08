#include <iostream>

using namespace std;

int main()
{
    int i = 5, j = 4; //khai báo và khởi tạo 2 biến kiểu số nguyên i, j với i = 5, j = 4

    double f; //khai báo biến f có kiểu số thực
    
    f = (double)i/j; //ép kiểu i và j về số thực, nên đây là phép chia, kết quả là 1.25
    
    f = i/(double)j; //ép kiểu j về số thực, nên đây là phép chia, kết quả là 1.25
    
    f = (double)i/double(j); //ép kiểu i và j về số thực, nên đây là phép chia, kết quả là 1.25
    
    f = (double)(i/j); //thực hiện lấy phần nguyên i/j rồi mới thực hiện ép kiểu, kết quả là 1

    return 0;
}