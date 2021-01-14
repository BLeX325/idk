#include <algorithm> // плдключаем библиотеку для использования алгоритмов и функций, которые отсутствуют в базовой библиотеке
#include <climits> // переменная для работы с лимитами
#include <iostream> //подключаем библиотеку для работы с числами с плавающей точкой
#include <vector> // подключаем библиотеку для работы с векторами
using namespace std; //используем стандартное пространство имён

int main() //главная функция
{
    setlocale(LC_ALL, "Russian"); //добавляем возможность использовать русский язык в консоле
    int** tr; //задаём имя массива в котором будет хранится матрица смежности
    int V; //переменная для хранения числа вершин графа
    int st;
    cout << "Введите число вершин графа = "<< endl;
    cin >> V;
    cout << "Опишити матрицу инцидентности сетевого графа  = " << endl;
    tr = new int* [V]; //создаём двумерный массив, который будет хранить матрицу смежности графа
    for (int i = 0; i < V; i++) {
        tr[i] = new int [V] ;
    }
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            cin >> tr[i][j];
        }
    cout << "Номер первой вершины для подсчёта кратчайшего пути = " << endl;
    int st1; //переменная для хранения номера первой вершины
    cin >> st1; // считываем
    st = st1 - 1;
    int* dist, count, index, i, u; //инициализируем ссылки, которые понадобятся нам для хранения данных при работе с массивом
    bool* vistd; // булевый счётчик была ли пройдена вершина графа
    vector <int> parent(V , -1);//создаём вектор
    dist = new int[V]; //метка дистанции
    vistd = new bool[V]; //метка посещения
    for (i = 0; i < V; i++) { dist[i] = INT_MAX; vistd[i] = false; } // добавляем в наши метки начальные значния, в соответсвии с входными данными
    dist[st] = 0; // начальному эл-ту подсчёта пути задаём дистанцию 0
    for (count = 0; count < V - 1; count++) { //цикл вычисления кратчайшего пути
        int min = INT_MAX;
        for (i = 0; i < V; i++) //для всех вершин графа
            if (!vistd[i] && dist[i] <= min) { min = dist[i]; index = i; } //если не посетили вершину и дистанция до неёё не больше min то min присвоить дистанция до вершины i
        u = index;
        vistd[u] = true; // выбираем корень для шага
        for (i = 0; i < V; i++) //для всех вершин графа
            if (!vistd[i] && tr[u][i] && dist[u] != INT_MAX &&
                dist[u] + tr[u][i] < dist[i]) {
                dist[i] = dist[u] + tr[u][i];
                parent.at(i) = u;
            } // заменяем значения дочерних меток, в массив предков добавляются предки
    }
    cout << "Введите номер последней вершины = ";
    int n;
    cin >> n;
    vector<int> temp;
    for ( int i = n-1 ; i != -1; i = parent.at(i) )
        temp.push_back(i + 1);
    reverse(temp.begin(), temp.end()) ;

    for ( int i = 0; i < temp.size(); ++i ) //цикл подсчёта конечного значения кратчайшей длины
        cout << temp.at(i) << " "; //печатаем ответ
    return 0;
}
