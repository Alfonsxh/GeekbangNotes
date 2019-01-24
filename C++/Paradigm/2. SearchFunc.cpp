//
// Created by xiaohui on 2018/10/18.
//
#include <iostream>
#include <cstring>

/// 在int 指针对象中搜索目标出现的位置，在此版本中传入对象的类型一定，目标一定
/// \param a 传入对象
/// \param size 对象长度
/// \param target 目标
/// \return 目标所在位置
int SearchNormal(int *a, size_t size, int target) {
    for (int i = 0; i < size; i++) {
        if (a[i] == target) {
            return i;
        }
    }
}

/// 查找泛型函数
/// - 输入对象任意
/// - 偏移依靠元素 size * i 实现
/// - 对比函数由外界提供
/// \param a 传入对象
/// \param size 传入对象长度
/// \param target 目标
/// \param elem_size 传入对象元素大小
/// \param cmpFn 对比函数
/// \return 目标所在位置
int SearchParadigm(void *a, size_t size, void *target, size_t elem_size, int(*cmpFn)(void *, void *)) {
    for (int i = 0; i < size; i++) {
        if (cmpFn((unsigned char *) a + elem_size * i, target) == 0) {
            return i;
        }
    }
}

/// int 类型比较操作
/// \param x 待比较的参数1
/// \param y 待比较的参数2
/// \return 比较结果， 0为相等
int int_cmp(int *x, int *y) {
    return *x - *y;
}

/// char 类型比较操作
/// \param x 待比较的参数1
/// \param y 待比较的参数2
/// \return 比较结果， 0为相等
std::string string_cmp(char *x, char *y) {
    if (strcmp(x, y) == 0)
        return "True";
    else
        return "False";
}


int main() {
    char *i = "stl", *j = "stl";

    std::cout << string_cmp(i, j) << std::endl;
    return 0;
}