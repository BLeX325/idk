#include <iostream>
#include <cmath>
using namespace std;

struct point // структура для хранения координат точки
{
    int x, y, z;
};
double dlina(point a, point b) // функция которая вычисляет длину от центра до заданной точки
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}
int main()
{
    point center, a[10]; // создаём структуру point center которая хранит координаты центра
    // и массив из 10 элементов для хранения координат точек
    int n;
    cout << "Vvedite koordinati centra " << endl;
    cin >> center.x >> center.y >> center.z;
    cout << "Vvedite kol-vo tochek " << endl;
    cin >> n;
    for(int i = 0; i < n; i++) // цикл ввода координат каждой из точек
    {
        cout << "Vvedite koordinati " << i+1 << "-i tochki " << endl; // печатаем i+1 чтобы не начинать с нуля
        cin >> a[i].x >> a[i].y >> a[i].z; // поочерёдно считываем координаты
    }
    int k = 0; // переменная для хранения номера точки, которая наиболее отдалена от центра
    int max = dlina(center, a[0]); // переменная max для нахождения наиболее отдалённой точки
    // инициализируем её как длину от центра до "нулевой" точки, при i = 0
    for (int i = 0; i < n; i++) // цикл нахождения max
    {
        if (dlina(center, a[i]) > max)
        {
            max = dlina(center, a[i]);
            k = i;
        }
    }
     cout << "Naibolee otdalennaya tochka pod nomerom " << k+1 << endl;
     cout << "S koordinatami " << "(" << a[k].x << "," << a[k].y << "," << a[k].z << ")";
     return 0;
}
