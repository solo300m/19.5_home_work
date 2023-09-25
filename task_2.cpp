#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    string path = "C:\\develop\\Tasks_19_5\\Harry_Potter.txt";
    ifstream book;
    char str[700];
    book.open(path, std::ios::binary);
    int count = 0;
    char next;
    cout << "Для выхода из режима чтения нажмите Q";
    while (next != 'Q')
    {
        book.read(str, sizeof(str));
        str[699] = 0;
        cout << str << endl;
        int tmp = book.tellg();
        book.seekg(tmp - 1);
        cin >> next;
    }
    book.close();
}