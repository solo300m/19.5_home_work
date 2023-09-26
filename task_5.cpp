#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

const int SIZE_BUFFER = 5000;

int checkSector(vector<int> &ptrHist, int sector)
{
    for (int i = 0; i < ptrHist.size(); i++)
    {
        if (ptrHist.at(i) == sector && sector + 1 < 13)
        {
            sector++;
        }
        else if (ptrHist.at(i) == sector && sector + 1 == 13)
        {
            sector = 13;
        }
        else if (ptrHist.at(i) == sector && sector + 1 > 13)
        {
            sector = 1;
        }
    }
    ptrHist.push_back(sector);
    return sector;
}
bool findNum(string str, char charArr[])
{
    for (int i = 0; i < SIZE_BUFFER; i++)
    {
        if (charArr[i] == str[0])
        {
            if (charArr[i + 1] == str[1])
            {
                return true;
            }
        }
    }
    return false;
}
bool findAnswer(char right, char charArr[])
{
    for (int i = 0; i < SIZE_BUFFER; i++)
    {
        if (charArr[i] == right)
        {
            if (charArr[i + 1] == '.')
            {
                return true;
            }
        }
    }
    return false;
}
bool checkRight(char right, int count)
{
    if (count == 2)
    {
        if (right == 'a' || right == 'b')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (count == 3)
    {
        if ((right == 'a' || right == 'b') || right == 'c')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (count == 4)
    {
        if ((right == 'a' || right == 'b') || (right == 'c' || right == 'd'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void startGame(int currentSector, int &winGamer, int &winPeople)
{
    string number = to_string(currentSector);
    string pathQuestion = "C:\\develop\\Tasks_19_5\\5_task_txt\\questions\\" + number + ".txt";
    string pathAnswer = "C:\\develop\\Tasks_19_5\\5_task_txt\\answers\\" + number + ".txt";
    ifstream question;
    ifstream answer;
    char buffQuest[SIZE_BUFFER];
    char buffAnswer[SIZE_BUFFER];
    question.open(pathQuestion, std::ios::binary);
    answer.open(pathAnswer, std::ios::binary);
    question.read(buffQuest, sizeof(buffQuest));
    answer.read(buffAnswer, sizeof(buffAnswer));

    buffQuest[4999] = 0;
    buffAnswer[4999] = 0;
    cout << buffQuest << endl;
    bool a = findNum("a.", buffQuest);
    bool b = findNum("b.", buffQuest);
    bool c = findNum("c.", buffQuest);
    bool d = findNum("d.", buffQuest);
    char right;
    if ((a && b) && (!c && !d))
    {
        cout << "\nВведите номер правильного ответа латинскими буквами a или b: ";
        cin >> right;
        while (!checkRight(right, 2))
        {
            cout << "Вы ввели символ, отличающийся от латинских a или b. Повторите еще раз! ";
            cin >> right;
        }
    }
    else if ((a && b) && (c && !d))
    {
        cout << "\nВведите номер правильного ответа латинскими буквами a , b или c: ";
        cin >> right;
        while (!checkRight(right, 3))
        {
            cout << "Вы ввели символ, отличающийся от латинских a или b или c. Повторите еще раз! ";
            cin >> right;
        }
    }
    else if ((a && b) && (c && d))
    {
        cout << "\nВведите номер правильного ответа латинскими буквами a , b , c или d: ";
        cin >> right;
        while (!checkRight(right, 4))
        {
            cout << "Вы ввели символ, отличающийся от латинских a , b , c или d. Повторите еще раз! ";
            cin >> right;
        }
    }
    bool checkAnswer = findAnswer(right, buffAnswer);
    if (checkAnswer)
    {
        winGamer++;
        cout << "\nЭто правильный ответ!" << endl;
        cout << "Правильный ответ был - " << buffAnswer << endl;
        cout << "\nОчко присуждается команде \"Что, Где, Когда\"!" << endl;
        cout << "Общий счет: Команда \"Что, Где, Когда\": " << winGamer << " Команда телезрителей: " << winPeople << endl;
    }
    else
    {
        winPeople++;
        cout << "\nЭто не правильный ответ!" << endl;
        cout << "Правильный ответ был - " << buffAnswer << endl;
        cout << "\nОчко присуждается команде телезрителей!" << endl;
        cout << "Общий счет: Команда \"Что, Где, Когда\": " << winGamer << " Команда телезрителей: " << winPeople << endl;
    }

    question.close();
    answer.close();

    for (int i = 0; i < SIZE_BUFFER; i++)
    {
        buffQuest[i] = 0;
        buffAnswer[i] = 0;
    }
}

int main()
{
    int currentSector = 1;
    int offset = 0;
    const int WIN_OPTION = 6;
    int winGamer = 0;
    int &ptrGamer = winGamer;
    int winPeople = 0;
    int &ptrPeople = winPeople;
    vector<int> history;
    vector<int> &ptr = history;

    while (true)
    {
        cout << "Введите положительное число секторов, на которое повернется игровой барабан начиная с текущего: " << currentSector << endl;
        cout << "Сектор -> ";
        cin >> offset;

        int finish = currentSector + offset;
        int control = (currentSector + offset) % 13;

        if (control != 0)
            currentSector = control;
        else
            currentSector = 13;
        currentSector = checkSector(ptr, currentSector);
        startGame(currentSector, ptrGamer, ptrPeople);
        // winGamer++;
        // winPeople++;
        if (winGamer == 6)
        {
            cout << "Победил игрок клуба \"Что, Где, Когда\"!";
            break;
        }
        else if (winPeople == 6)
        {
            cout << "Победила команда зрителей!";
            break;
        }
    }
}