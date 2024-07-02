#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class library
{

public:
    class book 
    {
    private:
        string content;
    public:
        book(const string& nf)
        {            
            ifstream fin;            
            fin.open(nf);
            if (!fin.is_open())
            {
                cout << "Ошибка: файл по имени " << nf << " не удалось открыть\n";
            }
            char temp;
            while (fin.get(temp))
            {
                content += temp;
            }
            fin.close();
        }

        void get_content() const
        {
            cout << '\n' << "===============================================================================================================================================" << '\n';
            cout << content;
            cout << '\n' << "===============================================================================================================================================" << '\n';
        }
    };

    void welcome() const 
    {
        cout << "Добро пожаловать в библиотеку!\n";
        cout << "Введите цифру, соответствующую вашему пожеланию:\n";
        cout << "1 - посмотреть список книг\n";
        cout << "0 - выйти из программы\n";
    }

    library(const string& name)
    {
        ifstream fin;
        fin.open(name);
        if (!(fin.is_open()))
        {
            cout << "Не удалось открыть файл" << '\n';
        }
        string line;
        while (!(fin.eof())) {
            getline(fin, line);
            assortment.push_back(line);
        }

        fin.close();
    }

    void get_assort()
    {
        for (int i = 0; i != assortment.size(); ++i)
        {            
            cout << i << '\t' << assortment[i] << '\n';
        }
    }

    string& operator[](int index)
    {
        return assortment[index];
    }

private:
    vector<string> assortment;
};



int main()
{
    //Test program

    setlocale(LC_ALL, "ru");

    int choice = 0;
    char ch;
    library lib("names.txt");
    
    while (true)
    {
        lib.welcome();
        cin >> ch;
        if (ch == '0')
        {
            return 0;
        }
        else if (ch == '1')
        {
            cout << "Сейчас будут слева будут представлены индексы с соответствующими названиями справа. Выберите индекс, чтобы получить текст нужной вам книги: \n\n";
            lib.get_assort();
            while (cin >> choice)
            {
                library::book b(lib[choice] + ".txt");
                b.get_content();
                cout << "Введите 0 выхода из программы либо введите 1 для возвращения на оглавление: \n";
                while (cin >> choice) {
                    if (choice == 1)
                    {
                        system("cls");
                        break;
                    }
                    else if (choice == 0)
                    {
                        return 0;
                    }
                    else
                    {
                        cout << "Вы не ввели нужный символ" << '\n';
                    }
                }
                break;
            }
        }
    }

    return 0;
}