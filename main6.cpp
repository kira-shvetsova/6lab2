#include <iostream>
#include <fstream>
#include <sstream>
#define NOMINMAX
#include "lab6.h"
#include "zadan2.h"
#include "zadan3.h"
#include "zadan4.h"
#include "zadan5.h"
#include <Windows.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <stdexcept>
#include <numeric>
using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int count;
    cout << "Лабораторная работа № 6." << endl;
    while (true) { // Бесконечный цикл, пока пользователь не введет 0
        cout << "Введите номер задания от 1 до 5. Введите 0, чтобы закончить." << endl;
        cin >> count;
        if (count == 0) {
            break; // Завершение программы, если введено 0
        }
        switch (count) {
        case 1: {
            cout << "1.Однонаправленный список." << endl;
            cout << "Повторить дважды каждое вхождение элемента Е в список L." << endl;
            LinkedList<int> linkedList; // Однонаправленный список
            int n, value, elementToRepeat;
            // Проверка на корректный ввод количества элементов списка
            while (true) {
                std::cout << "Введите количество элементов списка (положительное число): ";
                std::cin >> n;
                if (std::cin.fail() || n <= 0) {
                    std::cin.clear(); // Сбрасываем состояние потока
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем входной буфер
                    std::cout << "Ошибка: введите положительное число." << std::endl;
                }
                else {
                    break; // Ввод корректен, выходим из цикла
                }
            }
            // Проверка на корректный ввод элементов списка
            std::cout << "Введите элементы списка:" << std::endl;
            for (int i = 0; i < n; ++i) {
                while (true) {
                    std::cout << "Элемент " << (i + 1) << ": ";
                    std::cin >> value; // Считываем значение элемента
                    if (std::cin.fail()) {
                        std::cin.clear(); // Сбрасываем состояние потока
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем входной буфер
                        std::cout << "Ошибка: введите корректное значение." << std::endl;
                    }
                    else {
                        linkedList.add(value); // Добавляем элемент в список
                        break; // Ввод корректен, выходим из цикла
                    }
                }
            }


            std::cout << "Исходный список:" << std::endl;
            linkedList.printList(); // Выводим исходный список

            // Проверка на корректный ввод элемента для повторения
            while (true) {
                std::cout << "Введите элемент для повторения: ";
                std::cin >> elementToRepeat; // Запрашиваем элемент для повторения

                if (std::cin.fail()) {
                    std::cin.clear(); // Сбрасываем состояние потока
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем входной буфер
                    std::cout << "Ошибка: введите корректное значение." << std::endl;
                }
                else {
                    break; // Ввод корректен, выходим из цикла
                }
            }

            linkedList.repeatElements(elementToRepeat); // Повторяем указанный элемент

            std::cout << "Список после повторения элемента " << elementToRepeat << ":" << std::endl;
            linkedList.printList(); // Выводим изменённый список


            break;
        }
        case 2: {
            cout << "2.Двунаправленный список" << endl; // Исправлено на "2."
            cout << "Поменять местами фрагменты списка между минимальным и максимальным элементами." << endl;
            DoublyLinkedList<int> list;
            int n, value;

            // Проверка на корректный ввод количества элементов списка
            while (true) {
                std::cout << "Введите количество элементов списка (положительное число): ";
                std::cin >> n;
                if (std::cin.fail() || n <= 0) {
                    std::cin.clear(); // Сбрасываем состояние потока
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем входной буфер
                    std::cout << "Ошибка: введите положительное число." << std::endl;
                }
                else {
                    break; // Ввод корректен, выходим из цикла
                }
            }

            // Проверка на корректный ввод элементов списка
            std::cout << "Введите элементы списка:" << std::endl;
            for (int i = 0; i < n; ++i) {
                while (true) {
                    std::cout << "Элемент " << (i + 1) << ": ";
                    std::cin >> value; // Считываем значение элемента
                    if (std::cin.fail()) {
                        std::cin.clear(); // Сбрасываем состояние потока
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем входной буфер
                        std::cout << "Ошибка: введите корректное значение." << std::endl;
                    }
                    else {
                        list.addElement(value); // Добавляем элемент в список
                        break; // Ввод корректен, выходим из цикла
                    }
                }
            }


            cout << "Исходный список: "<<endl;;
            list.printList();

            list.swapSegments();

            cout << "Список после замены фрагментов: "<<endl;
            list.printList();

            break; // Завершаем программу успешно
        }
        case 3: {
            cout << "3.Партии" << endl; // Исправлено на "2."
            cout << "Определить: • за какие партии проголосовали граждане из каждой группы;• за какие партии проголосовали граждане только из одной группы; • за какие партии не проголосовали ?" << endl;
            // Создаем множества для групп граждан
            vector<UnorderedSet<string>> groups;

            int n; // Количество групп
            cout << "Введите количество групп граждан: ";
            while (!(cin >> n) || n <= 0) {
                cout << "Ошибка ввода. Введите положительное число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            // Ввод данных для каждой группы
            for (int i = 0; i < n; ++i) {
                UnorderedSet<string> group;
                int m;
                cout << "Введите количество партий, за которые голосовали граждане группы " << i + 1 << ": ";
                while (!(cin >> m) || m < 0) {
                    cout << "Ошибка ввода. Введите неотрицательное число: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore();

                cout << "Введите названия партий: "<<endl;
                for (int j = 0; j < m; ++j) {
                    string party;
                    cout << "Партия " << j + 1 << ":";
                    getline(cin, party);
                    group.add(party);
                }
                groups.push_back(group);
            }

            // 1. За какие партии проголосовали граждане из каждой группы
            cout << "\n1. Голосовавшие партии по группам:\n";
            for (int i = 0; i < n; ++i) {
                cout << "Группа " << i + 1 << ": ";
                groups[i].print();
            }

            // 2. За какие партии проголосовали граждане только из одной группы
            UnorderedSet<string> uniqueParties; // Для партий, присутствующих только в одной группе
            for (int i = 0; i < n; ++i) {
                UnorderedSet<string> temp = groups[i];
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        temp = temp.Except(groups[j]); // Удаляем партии, встречающиеся в других группах
                    }
                }
                uniqueParties = uniqueParties.Union(temp);
            }

            cout << "\n2. Партии, за которые проголосовали граждане только из одной группы:\n";
            uniqueParties.print();

            // 3. За какие партии не проголосовали
            UnorderedSet<string> allParties;  // Все партии
            for (const auto& group : groups) {
                allParties = allParties.Union(group);
            }

            cout << "\nВведите общее количество партий в стране: ";
            int p;
            while (!(cin >> p) || p <= 0) {
                cout << "Ошибка ввода. Введите положительное число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            UnorderedSet<string> allCountryParties; // Все партии в стране
            cout << "Введите названия всех партий в стране: "<<endl;
            for (int i = 0; i < p; ++i) {
                string party;
                cout << "Партия " << i + 1 << ":";
                getline(cin, party);
                allCountryParties.add(party);
            }

            UnorderedSet<string> notVotedParties = allCountryParties.Except(allParties); // Партии, за которые не голосовали
            cout << "\n3. Партии, за которые не голосовали:\n";
            notVotedParties.print();

            break;
        }
        case 4: {
            cout<<"Слова" << endl;
            cout<<"Файл содержит текст на русском языке. Какие символы встречаются в одном и только в одном слове ? " << endl;
            // Открываем файл
            ifstream inputFile("text.txt");
            if (!inputFile) {
                cerr << "Ошибка: не удалось открыть файл text.txt" << endl;
                return 1;
            }

            // Считываем текст из файла
            stringstream buffer;
            buffer << inputFile.rdbuf();
            string text = buffer.str();

            // Находим символы, которые встречаются только в одном слове
            findUniqueSymbols(text);
            break;
        }
        case 5: {
            cout << "5. Экзамены" << endl; // Исправлено на "2."
            cout << "Напишите программу, которая должна вывести на экран наименьший балл, который набрали участники, получившие «отлично». " << endl;
            Dictionary<int> dict;

            // Чтение данных из файла
            std::string filename = "students_data.txt";
            dict.readDataFromFile(filename);

            // Вывод студентов
            dict.printStudents();

            // Вычисление минимального балла для отличников
            dict.computeExcellentScore();

            break;
        }
        default:
            cout << "Неверный номер задания. Пожалуйста, попробуйте снова." << endl;
            break;
        }
    }
    return 0;
}
