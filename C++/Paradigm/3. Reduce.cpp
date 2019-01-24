//
// Created by xiaohui on 19-1-24.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/// 模板函数只遍历可迭代对象
/// \tparam Iter 迭代器类型
/// \tparam T 原始类型
/// \tparam Op 操作函数返回类型
/// \param start 迭代开始处
/// \param end 迭代结束处
/// \param init 结果初始化值
/// \param op 操作函数
/// \return
template<class Iter, class T, class Op>
T reduce(Iter start, Iter end, T init, Op op) {
    T result = init;
    for (; start != end; start++) {
        result = op(result, *start);
    }
    return result;
}

// 雇员结构体
struct Employee {
    string name;
    string id;
    int vacation;
    double salary;
};

//template<class T, class Cond>
//struct counter {
//    size_t operator()(size_t c, T t) {
//        return c + (Cond(t) ? 1 : 0);
//    }
//};
//
//
//template<class Iter, class Cond>
//size_t count_if(Iter begin, Iter end, Cond c) {
//    return reduce(begin, end, size_t(0), counter<Iter::value_type, Cond>(c));
//
//}

int main() {
    vector<Employee> v_employee;
    Employee employee_001 = {"Tom", "001", 10, 10000.0};
    v_employee.push_back(employee_001);
    Employee employee_002 = {"John", "002", 7, 220.0};
    v_employee.push_back(employee_002);
    Employee employee_003 = {"Alfons", "003", 6, 9000.0};
    v_employee.push_back(employee_003);
    Employee employee_004 = {"Mich", "004", 1, 101000.0};
    v_employee.push_back(employee_004);

    // 计算总薪金
    double sum_salaries = reduce(v_employee.begin(), v_employee.end(), 0.0,
                                 [](double s, Employee e) -> double { return s + e.salary; });

    cout << "sum salaries is -> " << sum_salaries << endl;

    // 计算最高薪金
    double max_salary = reduce(v_employee.begin(), v_employee.end(), 0.0,
                               [](double s, Employee e) -> double {
                                   return s > e.salary ? s : e.salary;
                               });
    cout << "max salary is -> " << max_salary << endl;

    // 计算最高薪金对象
    Employee max_salary_person = reduce(v_employee.begin(), v_employee.end(), *v_employee.begin(),
                                        [](Employee s, Employee e) -> Employee { return s.salary > e.salary ? s : e; });

    cout << "max salary person is -> " << max_salary_person.name << endl;

    // 计算最低薪金对象
    Employee min_salary_person = reduce(v_employee.begin(), v_employee.end(), *v_employee.begin(),
                                        [](Employee s, Employee e) -> Employee { return s.salary < e.salary ? s : e; });

    cout << "min salary person is -> " << min_salary_person.name << endl;

//    size_t cnt = count_if(v_employee.begin(), v_employee.end(), [](Employee e) -> bool { return e.salary < 10000; });

    return 0;
}