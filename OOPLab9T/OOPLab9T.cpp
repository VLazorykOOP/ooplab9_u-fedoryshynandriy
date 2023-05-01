#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
STL7Mix13. 
Вихідна послідовність містить інформацію про абітурієнтів.
Кожен елемент послідовності включає такі поля:
<Номер школи> <Рік вступу> <Прізвище>
Для кожного року, присутнього у вихідних даних, знайти школу з найбільшим номером серед шкіл, 
які закінчили вступники цього року, і вивести рік і знайдений номер школи.
Відомості про кожен рік виводити на новому рядку і впорядковувати за зростанням номера року.
*/

class Records
{
    string last_name;
    int year, school_number;

public:
    Records() : last_name(""), year(0), school_number(0) {}
    Records(const string& l_name, int y, int number)
        : last_name(l_name), year(y), school_number(number)
    {
    }

    string Get_Last_Name() const { return last_name; };
    void Set_Last_Name(const string& l_name) { last_name = l_name; }
    int Get_Year() const { return year; };
    void Set_Year(int y) { year = y; }
    int Get_School_Number() const { return school_number; };
    void Set_School_Number(int number) { school_number = number; }
};

void task1()
{
    vector<Records> records;
    records.push_back(Records("Johnson", 2010, 1));
    records.push_back(Records("Jonix", 2013, 1));
    records.push_back(Records("Kahn", 2012, 1));
    records.push_back(Records("Smith", 2011, 2));
    records.push_back(Records("Williams", 2010, 3));
    records.push_back(Records("Brown", 2012, 4));
    records.push_back(Records("Jones", 2011, 1));
    records.push_back(Records("Garcia", 2012, 2));
    records.push_back(Records("Martin", 2014, 2));
    records.push_back(Records("Bodu", 2016, 2));
    records.push_back(Records("Koi", 2015, 5));


    for (int year = 1800; year <= 2023; year++)
    {
        int max_school_number = -1;
        for (size_t i = 0; i < records.size(); i++)
        {
            if (records[i].Get_Year() == year)
            {
                int school_number = records[i].Get_School_Number();
                if (school_number > max_school_number)
                {
                    max_school_number = school_number;
                }
            }
        }
        if (max_school_number > 0) {
            cout << "Year " << year << ": School " << max_school_number << endl;
        }
    }
}

/*
STL3Alg13.
Даний список L. 
Подвоїти значення в останній парі сусідніх елементів, що збігаються. 
Наприклад, список: 1, 2, 2, 3, 3, 1, 2, 2, 2, 4
повинен бути перетворений наступним чином: 1, 2, 2, 3, 3, 1, 2, 4, 4, 4.
Якщо список не містить сусідніх збігаються елементів, то не змінювати його.
Використовувати алгоритм adjacent_find і зворотні ітератори.
*/
void task2() {
    vector<int> L = { 1, 2, 2, 3, 3, 1, 2, 2, 2, 4 };

    cout << "Original vector: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    auto it = adjacent_find(L.rbegin(), L.rend());

    if (it == L.rend()) {
        cout << "No matching pair found.\n";
    }
    else {
        *it *= 2;
        *(it + 1) *= 2;
    }

    cout << "Result: ";
    copy(L.begin(), L.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

}
/*
STL5Assoc13. 
Вирішити дану задачу: Даний вектор V. 
Визначити кількість повторень кожного числа у векторі V 
і вивести всі різні елементи вектора V разом з кількістю їх повторень (у порядку зростання значень елементів); 
кількість повторень виводити відразу після значення відповідного елемента.
Використовувати допоміжне мультимножина та цикл, у якому викликається функція-член upper_bound для мультимножини 
та функція difference для його ітераторів, не використовуючи допоміжне мультимножина та функцію difference. 
Але замість цього використовувати для вихідного вектора алгоритм sort 
та в циклі алгоритм upper_bound та операцію різниці для ітераторів вектора.
*/

void task3() {
    vector<int> V = { 1, 3, 2, 4, 3, 5, 4, 6, 7, 5 };

    cout << "Original vector: ";
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort(V.begin(), V.end()); // сортування вектора

    for (auto it = V.begin(); it != V.end(); )
    {
        auto it2 = upper_bound(it, V.end(), *it); // пошук першого елемента, що більший за *it
        int count = it2 - it; // кількість повторень *it
        cout << *it << ": " << count << endl;
        it = it2;
    }
}

int main() {
    int task = 4;
    cout << "WHAT TASK TO EXECUTE? \n";
    cin >> task;
    switch (task)
    {
         case 1: task1(); break;
         case 2: task2(); break;
         case 3: task3(); break;
    default:
        break;
    }
    
    return 0;
}