#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    string name[10];
    string lastName[10];
    double salary[10];
    string dateSalary[10];
    string path = "C:\\develop\\Tasks_19_5\\salary.txt";
    ifstream chart;
    chart.open(path);
    double sum = 0;
    double maxSalary = 0;
    int idxMax;
    for (int i = 0; i < 10; i++)
    {
        chart >> name[i] >> lastName[i] >> salary[i] >> dateSalary[i];
        sum += salary[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (salary[i] > maxSalary)
        {
            maxSalary = salary[i];
            idxMax = i;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << name[i] << "\t" << lastName[i] << "           \t" << salary[i] << "\t" << dateSalary[i] << endl;
    }
    cout << endl;
    cout << "Сумма выплат по ведомости - " << sum << endl;
    cout << "Максимальную выплату в сумме " << salary[idxMax] << " получил: " << name[idxMax] << " " << lastName[idxMax] << endl;
}