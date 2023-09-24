#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    const char *path = "C:\\develop\\Tasks_19_5\\words.txt";
    ifstream file;
    vector<string> str;
    file.open(path);
    while (!file.eof())
    {
        string tmp;
        file >> tmp;
        str.push_back(tmp);
    }
    file.close();
    /*for (string s : str)
    {
        cout << s << " ";
    }*/
    cout << endl;
    string findWord;
    int countWord = 0;
    cout << "Введите искомое слово: ";
    cin >> findWord;
    for (string s : str)
    {
        if (s == findWord)
            countWord++;
    }
    cout << "Количество вхождений равно: " << countWord << endl;
}