#include <iostream>
#include <cmath>
using namespace std;

int B(int n) // возвращающая функция типа int
{
    if(n == 1) // 1 и 2 эл-ты уже известны поэтому если введён их номер то просто выводим их
    {
        return -10;
    }
    if ( n == 2)
    {
        return 2;
    }
    return abs(B(n-2))-6*(B(n-1)); // нахождение n-го элемента рекурсивно заданной последовательности
}

int main()
{
    setlocale(LC_ALL, "Russian"); // подключаем русский язык
    int n;
    cout << "Введите номер искомого элемента последовательности" << endl;
    cin >> n;
    cout << B(n);
    return 0;
}
