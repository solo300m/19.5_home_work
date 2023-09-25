#include <fstream>
#include <iostream>
using namespace std;
void expertPNG(string path)
{
    char atr[4];
    int intAtr[4];
    string extends = path.substr(path.length() - 4, path.length() - 1);
    // cout<<extends<<endl;
    ifstream file;
    file.open(path, std::ios::binary);
    for (int i = 0; i < 4; i++)
    {
        file >> atr[i];
        intAtr[i] = atr[i];
    }
    cout << "Мета-данные заголовка: ";
    for (int i = 0; i < 4; i++)
    {
        // int tmp = atr[i];
        cout << intAtr[i] << " ";
    }
    cout << endl;
    if ((intAtr[0] == -119 && intAtr[1] == 80) && (intAtr[2] == 78 && intAtr[3] == 71))
    {
        cout << "Файл имеет расширение: " << extends << endl;
        cout << "Файл имеет формат .PNG" << endl;
    }
    else
    {
        cout << "Файл имеет расширение: " << extends << endl;
        cout << "Файл не .PNG формата." << endl;
    }
    file.close();
}
int main()
{
    string path = "C:\\develop\\Tasks_19_5\\brick.png";
    expertPNG(path);
    string path2 = "C:\\develop\\Tasks_19_5\\1block.jpg";
    expertPNG(path2);
}