#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Triangle // создаём класс Triangle
{
    int a, b, c; // поля int a, b, c
public:
    Triangle()
    {
        // просим ввести и считываем с клавиатуры длины 3 сторон треугольника
        cout << "a = "; cin >> a; cout << endl;
        cout << "b = "; cin >> b; cout << endl;
        cout << "c = "; cin >> c; cout << endl;
    }
    Triangle(int a1, int b1, int c1)
    {
        a = a1;
        b = b1;
        c = c1;
    }
    bool exist(); // функция проверки треугольника на существование
    int perimetr(); // функция вычисления периметра
    double square(); // функция вычисления площади
    void print(); // функция для вывода информации о треугольнике
    Triangle operator++(); // перегрузка операции ++
    Triangle operator--(); // перегрузка операции --
    Triangle operator*(); // перегрузка операции *
};

bool Triangle::exist() // функция проверки треугольника на существование
{
    if ((a < b + c) && (b < a + c) && (c < b + a)) // если любая сторона меньше чем сумма двух других то
    {
        return true; // возвращаем true
    }
    else return false; // иначе false
}

int Triangle::perimetr() // функция вычисления периметра
{
    return a + b + c;
}

double Triangle::square() // функция вычисления площади
{
    double p = perimetr()/2;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

void Triangle::print() // не возвращающая значаний функция которая сразу печатает результаты работы всех функций лля удобства
{
    // так же можно отдельно вызывыть каждую из функций в int main
    if( exist() == true ) // если результат функции проверки на существования true, то печатаем все данные о треугольнике
    {
    cout << "Треугольник с данными длинами сторон существует: " << endl << endl;
    cout << "Длина стороны a = " << a << endl;
    cout << "Длина стороны b = " << b << endl;
    cout << "Длина стороны c = " << c << endl;
    cout << "Периметр треугольника = " << perimetr() << endl;
    cout << "Площадь треугольника = " << square() << endl;
    if (((a == b)&&(a != c))||((a == c)&&(a != b))||(b == c)&&(b != a))
    {
        cout << "Данный треугольник равнобедренный" << endl;
    }
    else if ((a == b)&&(b == c))
    {
        cout << "Данный треугольник равносторонный" << endl;
    }
    else cout << "Данный треугольник разносторонний" << endl;
    }
    // иначе печатаем что такого треугольника нет
    else cout << "Треугольник с данными длинами сторон не существует " << endl;
}

Triangle Triangle::operator++() // перегрузка операции ++
{
    return Triangle(a++, b++, c++);
}

Triangle Triangle::operator--() // перегрузка операции --
{
    return Triangle(a--, b--, c--);
}

 Triangle Triangle::operator*() // перегрузка операции *
 {
     // умножает поля a, b и c на заданный скаляр
     int n;
     cout << "Введите число на которое нужно умножить стороны треугольника: " << endl;
     cin >> n;
     cout << endl;
     return Triangle(a=a*n,b=b*n,c=c*n);
 }

int main()
{
    setlocale(LC_ALL, "Russian"); // подключаем русский язык в консоли
    Triangle Treg; // создаём треугольник Treg
    *Treg; // пример операции умножения
    ++Treg; // пример операции ++
    ++Treg;
    --Treg; // пример операции --
    Treg.print(); // печатаем всю информацию о данном треугольнике
    return 0;
}
