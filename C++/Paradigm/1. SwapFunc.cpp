//
// 泛型编程
// Created by xiaohui on 2018/10/18.
//
#include <cstring>

#define min(x, y)  ((x)>(y) ? (y) : (x))

/// 交换两个值
/// 给定了交换值的类型，如果需要交换别的类型的值，则需要另一个函数
/// \param x 传入参数指针
/// \param y 传入参数指针
void SwapInt(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/// 交换两个值
/// 使用 void * 代替普通类型
/// 由于使用void * ，编译器不能通过类型得到类型的尺寸，添加 size 参数表示类型的长度
/// \param x 传入参数指针
/// \param y 传入参数指针
/// \param size 传入指针大小
void SwapVoid(void *x, void *y, size_t size) {
    char tmp[size];
    memcpy(tmp, y, size);
    memcpy(y, x, size);
    memcpy(x, tmp, size);
}

/**
 * 交换两个值，宏定义模式
 * 宏定义的方式有个弊端，在使用宏定义时，由于宏替换的缘故，会导致传入的参数发生改变
 * 例如：
 *
 * #define min(x, y)  ((x)>(y) ? (y) : (x))
 *
 * 在使用此宏时  int k = min(i++, j++);
 * 由于宏替换的缘故，相当于执行了
 *
 * (i++) > (j++) ? (j++) : (i++)
 *
 * x 或 y 的值会被累加两次
 * */
#define swap(x, y, size) {\
    char temp[size]; \
    memcpy(temp, &y, size); \
    memcpy(&y,   &x, size); \
    memcpy(&x, temp, size); \
}

int main() {
    int i = 0, j = 1;

    SwapInt(&i, &j);
    return 0;
}