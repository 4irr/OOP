#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

class Employee {
private:
    string name;
    string surname;
    int age;
    int number;
public:
    
    static int objectCount;

    //Реализация конструктора без параметров
    Employee() {
        objectCount++;
        cout << "Сработал конструктор без параметров" << endl;
        number = objectCount;
        name = "-";
        surname = "-";
        age = 0;
    }
    //Реализация конструктора с параметрами
    Employee(string n, string s, int a) {
        objectCount++;
        cout << "Сработал конструктор c параметрами " << endl;
        number = objectCount;
        SetInfo(n, s, a);
    }
    //Реализация конструктора копирования
    Employee(const Employee& obj) {
        cout << "Сработал конструктор копирования" << endl;
        name = obj.name;
        surname = obj.surname;
        age = obj.age;
    }
    void SetInfo(string n, string s, int a) {
        name = n;
        surname = s;
        age = a;
    }
    //Методы
    void PrintNumber() {
        cout << "Мой порядковый номер - " << number << endl;
    }
    string GetName() {
        return name;
    }
    string GetSurname() {
        return surname;
    }
    int GetAge() {
        return age;
    }
    //Метод записи информации в файл
    void PrintInFile() {
        fstream fs;
        string path = "file.txt";
        fs.open(path, fstream::in | fstream::out | fstream::app);
        if (fs.is_open()) {
            fs << name << " " << surname << " " << " " << age << endl;
            fs.close();
            cout << "Информация успешно записана в файл" << endl;
        }
        else {
            cout << "Не удалось записать информацию в файл" << endl;
        }
    }
};
//инициализация статической переменной нулём
int Employee::objectCount = 0;

//функция вывода инфы об объекте
void PrintInfo(Employee object) {
    cout << "Имя: " << object.GetName() << "\tФамилия: " << object.GetSurname() << "\tВозраст: " << object.GetAge() << endl << endl;
}

int main()
{
    //русский язык
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //1-ый объект с параметрами
    Employee person1("Иван", "Иванов", 25);
    person1.PrintNumber();
    PrintInfo(person1);

    //2-ой объект с параметрами
    Employee person2("Пётр", "Петров", 30);
    person2.PrintNumber();
    PrintInfo(person2);

    //3-й объект без параметров
    Employee person3;
    person3.PrintNumber();
    PrintInfo(person3);
}
