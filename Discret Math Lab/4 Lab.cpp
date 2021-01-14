#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //подключаем русский язык в консоли
	int m; // переменная для хранения числа рёбер
	int n; // переменная для хранения числа вершин
	cout << "Введите число вершин = " << endl;
	cin >> n; //считываем число вершин
	cout << "Введите число рёбер = " << endl;
	cin >> m; // считывем число ребер
	vector < pair < int, pair<int, int> > > g(m); // инициализация структуры рёбер
	cout << "Введите список рёбер (вес ребра _ 1-я вершина _ 2-я вершина):";
	for (int i = 0; i < m; i++) { //цикл считывания веса рёбер
		int a, b, c;
		cin >> a >> b >> c;
		g.at(i) = { a, { b-1, c-1 } };
	}
	int cost = 0;
	// Здесь будет храниться вес искомого поддерева
	vector < pair<int, int> > res; // вектор для хранения результата в виде списка пар вершин, соединияющих рёбра
	sort(g.begin(), g.end()); // сортируем по весу
	cout << "Список ребер поддерева по возрастанию веса :" << endl;
	for (int i = 0; i < m; i++) { //печатаем отсортированный список ребер
		cout << g[i].first << " " << g[i].second.first +1<< " "<< g[i].second.second+1 << endl;
	}
	vector<int> tree_id(n);
	for (int i = 0; i < n; ++i) // задаём структуру дерева
		tree_id[i] = i;
	for (int i = 0; i < m; ++i) //цикл подсчёта наименьшей коммуникационной сети
	{
		int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
		if (tree_id[a] != tree_id[b]) // если вершины в разных деревьях - соединяем их
		{
			cost += l;
			res.push_back(make_pair(a, b));
			int old_id = tree_id[b];
			int new_id = tree_id[a];
			for (int j = 0; j < n; ++j){
				if (tree_id[j] == old_id)
					tree_id.at(j) = new_id;
			}
		}
	}
	int size_res = res.size();
	cout << "Ребра искомого поддерева :" << endl;
	for (int i = 0; i < size_res; i++) { //цикл вывода результатов в консоль
		cout << res[i].first+1 << " " << res[i].second+1 << endl;
	}
	cout << endl << "Вес коммуникационной сети минимальной длины = " << cost << endl; // выводим вес полученной сети
	return 0;
}
