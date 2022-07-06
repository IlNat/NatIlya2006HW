//Задание 1.
//Добавьте в класс двусвязного списка механизм обработки исключений.На ваш выбор генерируйте исключения
//в случае ошибок.Например, нехватка памяти, попытка
//удаления из пустого списка и т.д.

#include <iostream>
#include <string>
#include "Windows.h"
using namespace std;

// Класс "Список покупок".
class ShoppingList
{
private: 
    string* list; // Указатель типа "string".
    int sizeOfList; // Количество позиций.
public:
    // Конструктор класса "Список покупок". Принимает значение количества позиций.
    ShoppingList(int settingSize) 
    { 
        sizeOfList = settingSize; 
        list = new string [sizeOfList];
    }

    // Установка количества позиций.
    void setSize()
    {
        int settingSizeOfList;
        cout << "Введите количество позиций: ";
        cin >> settingSizeOfList;
        sizeOfList = settingSizeOfList;
    }

    // Заполнение списка.
    void fillList()
    {
        for (int i = 0; i < sizeOfList; i++)
        {
            cout << "Введите " << ++i << " позицию: ";
            cin >> list[i];
        }
    }
    
    // Вывод списка.
    void printList()
    {
        try
        {
            if (list == nullptr) // Если лист не был заполенен, то останавливает функцию и выводит сообщение. Иначе выводит весь список.
                throw "Лист не заполнен!\n";
            else
            {
                for (int i = 0; i < sizeOfList; i++)
                {
                    cout << "Позиция " << ++i << ": " << list[i];
                }
            }
        }
        catch (string message)
        {
            cout << message;
        }
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Программа \"Список покупок\". ";
    int sizeOfList;
    cout << "Введите изначальное количество позиций: ";
    cin >> sizeOfList;
    ShoppingList shopList(sizeOfList);
    int choice;
    do 
    {
        cout << "Команды:\n1 - заполнить список;\n2 - вывести список;\n3 - изменить количество позиций;\n4 - выйти из программы.\nВведите команду:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            shopList.fillList();
        }
        case 2:
        {
            shopList.printList();
        }
        case 3:
        {
            shopList.setSize();
        }
        case 4: 
        {
            cout << "Выход из программы.\n";
        }
        default:
        {
            cout << "Такой команды нет. Повторите ввод.\n";
        }
        }
    } while (choice != 4);