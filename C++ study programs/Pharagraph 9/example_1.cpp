#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ifstream in("f.txt");
    ofstream out("g.txt");
    string s;
    while (in.peek() != EOF) // пока не прочитан маркер конца файла
    {
        getline(in, s); // читаем очередную строку из файла f.txt
        for (unsigned int i = 0; i < s.length()/2; i++) // зеркально отображаем строку
        {
            char a = s[i];
            s[i] = s[s.length() - 1 - i];
            s[s.length() - 1 - i] = a;
        }
        // записываем измененную строку в файл g.txt
        out << s << endl;
    }
    in.close();
    out.close();
    return 0;
}
