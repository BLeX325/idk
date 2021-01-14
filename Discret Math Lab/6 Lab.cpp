#include <iostream> //библиотека для работы с числами с плавающей точкой
#include <vector> //библиотека для работы с векторами
#include <list> //библиотека для работы со списками
#include <string> //библиотека для работы со строками

using namespace std;

vector < vector <int> > matrix;
vector < pair <int, int> > result;

vector < vector <int> > validateData(vector < vector <int> > data) //добавляем в матрицу столбец и строку с нумерацией для отслеживания удаляемых ребер
{
for (int i = 0; i < data.size(); i++) //цикл инициализации двумерного массива который будет изображать матрицу
{
    for (int j = 0; j < data[i].size(); j++)
    {
        if (data[i][j] == 0)
        {
            data[i][j] = INT32_MAX;
        }
    }
}

vector<vector<int>> temp(data);
for (int i = 0; i < data.size(); i++)
{
    data[i].push_back(i + 1);
}
vector<int> numeration; //вектор для подсчёта нумерации
for (int i = 0; i < data[0].size(); i++)
{
    numeration.push_back(i + 1);
}
data.push_back(numeration);
return data;
}

int getMin(vector<vector<int>> matrix, int sel, char pos) //функция возращения минимального
{
    int min = INT32_MAX;
    for (int i = 0; i < matrix[sel].size() - 1; i++)
        switch (pos)
        {
            case 'R':
                    if (min > matrix[sel][i])
                        min = matrix[sel][i];
                    break;
            case 'C':
                    if (min > matrix[i][sel])
                        min = matrix[i][sel];
                    break;

        }
    return min;
}

int getResultSum() //функция возвращения результата суммирования
{
    int sum = 0;
    for (int i = 0; i < result.size(); i++)
        sum += matrix[result[i].first - 1][result[i].second - 1];
    return sum;
}
void matrixProcedure (vector< vector<int> > matrix) //функция создания матрицы
{
if (matrix.size() - 1 > 2)  //инициализируем точку возврата и удаляем необходимое ребро
{
    vector<int> vertexes;
    for (int i = 0; i < result.size(); i++)
    {
        vertexes.push_back(result[i].first);
        vertexes.push_back(result[i].second);
    }
    for (int i = 0; i < vertexes.size(); i++)
    {
        pair<int, int> elem(INT32_MAX, INT32_MAX), elem1(INT32_MAX, INT32_MAX);
        for (int j = 0; j < vertexes.size(); j++)
        {
            if (vertexes[i] != vertexes[j])
            {
                for (int k = 0; k < matrix[matrix.size() - 1].size() - 1; k++)
                {
                    if (vertexes[i] == matrix[k][matrix[k].size() - 1]) elem.first = k;
                    if (vertexes[j] == matrix[k][matrix[k].size() - 1]) elem1.first = k;
                }
                for (int k = 0; k < matrix.size() - 1; k++)
                {
                    if (vertexes[i] == matrix[matrix.size() - 1][k]) elem.second = k;
                    if (vertexes[j] == matrix[matrix.size() - 1][k]) elem1.second = k;
                }
            }
        }
        for (int i = 0; i < matrix.size() - 1; i++)
            for (int j = 0; j < matrix.size() - 1; j++)
                if (i == elem1.first && j == elem1.second)
                    matrix[elem1.first][elem1.second] = INT32_MAX;
        for (int i = 0; i < matrix.size() - 1; i++)
            for (int j = 0; j < matrix.size() - 1; j++)
                if (i == elem.first && j == elem.second)
                    matrix[elem.first][elem.second] = INT32_MAX;
    }
}


for (int i = 0; i < matrix.size() - 1; i++)  //цикл вычитания из каждой строки минимального значения
{
    int min = 0;
    if ((min = getMin(matrix, i, 'R')) == INT32_MAX)
    {
        return;
    }
    if ((min = getMin(matrix, i, 'R')) != 0)
        for (int j = 0; j < matrix[i].size() - 1; j++)
            if (matrix[i][j] != INT32_MAX) matrix[i][j] -= min;
}

for (int i = 0; i < matrix[matrix.size() - 1].size() - 1; i++) //цикл вычитания из каждого столбца минимального значения
{
    int min = 0;
    if ((min = getMin(matrix, i, 'C')) == INT32_MAX)
    {
        return;
    }
    if ((min = getMin(matrix, i, 'C')) != 0)
        for (int j = 0; j < matrix.size() - 1; j++)
            if (matrix[j][i] != INT32_MAX) matrix[j][i] -= min;
}



int Max = 0; //задаём начальное значение переменной для хранения максимально оценимого нуля
for (int i = 0; i < matrix.size() - 1; i++) //цикл нахождения максимально оцененного нуля
    for (int j = 0; j < matrix[i].size() - 1; j++)
        if (matrix[i][j] == 0)
        {
            matrix[i][j] = INT32_MAX;
            int max = (getMin(matrix, i, 'R') == INT32_MAX || getMin(matrix, j, 'C') == INT32_MAX) ? INT32_MAX : getMin(matrix, i, 'R') + getMin(matrix, j, 'C');
            if (max > Max) Max = max;
            matrix[i][j] = 0;
        }



vector<pair<int, int>> Maxs;
for (int i = 0; i < matrix.size() - 1; i++) //цикл нахождения всхе нулей максимальная оценка которых равна Max
    for (int j = 0; j < matrix[i].size() - 1; j++)
        if (matrix[i][j] == 0)
        {
            matrix[i][j] = INT32_MAX;
            int max = (getMin(matrix, i, 'R') == INT32_MAX || getMin(matrix, j, 'C') == INT32_MAX) ? INT32_MAX : getMin(matrix, i, 'R') + getMin(matrix, j, 'C');
            if (max == Max) Maxs.push_back(pair<int, int>(matrix[i][matrix.size() - 1], matrix[matrix.size() - 1][j]));
            matrix[i][j] = 0;
        }


for (int i = 0; i < Maxs.size(); i++) //Завершаем выполнение данной ветви если нету нулей
{
    result.push_back(Maxs[i]);
    if (matrix.size() - 1 == 1)
    {
        for (int i = 0; i < result.size(); i++)
            cout << "(" << result[i].first << ", " << result[i].second << ")\t";
        cout << endl;
        cout << "Result: " << getResultSum() << endl;
        result.pop_back();
        return;
    }

//Создаем копию текущей матрицы и удаляем из нее строку и столбец выбранного нуля

vector<vector<int>> temp(matrix);
pair<int, int> elem(INT32_MAX, INT32_MAX), elem1(INT32_MAX, INT32_MAX);
for (int j = 0; j < temp[temp.size() - 1].size() - 1; j++)
{
    if (Maxs[i].first == temp[j][temp[j].size() - 1]) elem.first = j;
    if (Maxs[i].second == temp[j][temp[j].size() - 1]) elem1.first = j;
}
for (int j = 0; j < temp.size() - 1; j++)
{
    if (Maxs[i].second == temp[temp.size() - 1][j]) elem.second = j;
    if (Maxs[i].first == temp[temp.size() - 1][j]) elem1.second = j;
}

for (int i = 0; i < temp.size() - 1; i++)
    for (int j = 0; j < temp.size() - 1; j++)
        if (i == elem1.first && j == elem1.second)
            temp[elem1.first][elem1.second] = INT32_MAX;

for (int j = 0; j < temp[temp.size() - 1].size(); j++)
    temp[j].erase(temp[j].begin() + elem.second);
temp.erase(temp.begin() + elem.first);

matrixProcedure(temp); //Вызываем рекурсивно эту же функцию для уже новой матрицы

result.pop_back(); //Удаляем последние значение из массива с результатом

}
}

int main() //главная функция

{
    int n; //переменная для хранения числа вершин
    cout << "Введите число вершин";
    cin >> n;
    cout << "Введите матрицу :";
    for (int i = 0; i < n; i++)
    {
        vector <int> R;
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            R.push_back(t);
        }
        matrix.push_back(R);
    }
    matrixProcedure(validateData(matrix)); //запускаем нашу основную функцию для нахождения кратчайшего пути
return 0;
}
