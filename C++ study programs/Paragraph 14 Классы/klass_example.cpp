#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Point
{
private:
    // координаты точки
    int x;
    int y;
    static int count;
public:
    // конструктор с нулевыми координатами
    Point() : x(0), y(0) { count++; }
    // конструктор с заданными координатами
    Point(int x, int y) : x(x), y(y) { count++; }
    // функция позволяет определить кол-во объектов типа Point
    int GetCount() { return count; }
    // функция позволяет установить новые координаты точки
    void SetXY(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    // функция позволяет вывести на экран информацию о точке
    void Show(string info)
    {
        cout << "Point " << info << " : ( " << x << ", " << y << " )" << endl;
    }
    // функция повзоляет вычислить расстояние от начала координат до точки
    double GetDistance()
    {
        return sqrt((double)(x*x+y*y));
    }
    // перегрузка операции ++
    Point operator++()
    {
        return Point(++x, ++y);
    }
    Point operator--()
    {
        return Point(--x, --y);
    }
    // вариант 1 перегрузки операции +
    Point operator+(Point temp)
    {
        return Point(x+temp.x, y+temp.y);
    }
    // вариант 2 перегрузки операции +
    Point operator+(int a)
    {
        return Point(x+a, y+a); }
};
int Point::count = 0; // инициализация статического поля

int main()
{
    Point pointA; // создаём точку А с нулевыми координатами
    pointA.Show("A");
    cout << "Distance: " << pointA.GetDistance() << endl << endl;
    pointA.SetXY(-3, 4); // устанавливаем новые координаты для точки А
    pointA.Show("A");
    cout << "Distance: " << pointA.GetDistance() << endl << endl;
    Point pointB(3, 4); // создаём точку B с заданными координатами
    pointB.Show("B");
    cout << "Distance: " << pointB.GetDistance() << endl << endl;
    --pointB; // демонстрация перегрузки --
    pointB.Show("B");
    cout << "Distance: " << pointB.GetDistance() << endl << endl;
    // демонстрация варианта 1 перегрущки операции +
    Point pointC = pointA + pointB;
    pointC.Show("C");
    cout << "Distance: " << pointC.GetDistance() << endl << endl;
    // демонстрация варианта 2 перегрузки операции +
    Point pointD = pointC + 3;
    pointD.Show("D");
    cout << "Distance: " << pointD.GetDistance() << endl << endl;
    // выводим общее количество точек
    cout << "Count of point: " << pointD.GetCount();
    return 0;
}
