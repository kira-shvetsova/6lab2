#ifndef ZADAN2_H
#define ZADAN2_H
using namespace std;
#include <iostream>

// Структура узла двунаправленного списка
template <typename T>
struct Node2 {
    T data;           // Данные, хранящиеся в узле
    Node2* prev;      // Указатель на предыдущий узел
    Node2* next;      // Указатель на следующий узел

    // Конструктор для инициализации узла с заданным значением
    Node2(T value) : data(value), prev(nullptr), next(nullptr) {}
};

// Шаблонный класс, представляющий двунаправленный список
template <typename T>
class DoublyLinkedList {
private:
    Node2<T>* head; // Указатель на первый узел списка
    Node2<T>* tail; // Указатель на последний узел списка

    // Метод для поиска узла с минимальным значением
    Node2<T>* findMin() const {
        Node2<T>* current = head; // Начинаем с головы как минимального узла
        Node2<T>* minNode = head; // Переменная для итерации по списку

        while (current) {
            if (current->data < minNode->data) { // Сравниваем данные узлов
                minNode = current; // Обновляем минимальный узел, если найден меньший
            }
            current = current->next; // Переходим к следующему узлу
        }
        return minNode; // Возвращаем найденный минимальный узел
    }

    // Метод для поиска узла с максимальным значением
    Node2<T>* findMax() const {
        Node2<T>* current = head; // Начинаем с головы как максимального узла
        Node2<T>* maxNode = head;// Переменная для итерации по списку

        while (current) {
            if (current->data > maxNode->data) { // Сравниваем данные узлов
                maxNode = current; // Обновляем максимальный узел, если найден больший
            }
            current = current->next; // Переходим к следующему узлу
        }
        return maxNode; // Возвращаем найденный максимальный узел
    }

public:
    // Конструктор
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Деструктор
    ~DoublyLinkedList() {
        Node2<T>* current = head; //Начинаем с головы списка
        while (current) {
            Node2<T>* toDelete = current; // Запоминаем узел для удаления
            current = current->next;//Переходим к следующему узлу
            delete toDelete; //Удаляем текущий
        }
    }

    // Метод для добавления элемента в конец списка
    void addElement(T value) {
        Node2<T>* newNode = new Node2<T>(value); // Создаем новый узел с заданным значением
        if (!tail) {
            head = tail = newNode; // Если список пуст, новый узел становится головой и хвостом
        }
        else {
            tail->next = newNode; // Связываем новый узел с текущим хвостом
            newNode->prev = tail; // Устанавливаем указатель на предыдущий узел
            tail = newNode; // Обновляем хвост на новый узел
        }
    }

    // Метод для вывода элементов списка
    void printList() const {
        Node2<T>* current = head; // Начинаем с головы списка
        while (current) {
            cout << current->data << " "; // Выводим данные текущего узла
            current = current->next;// Переходим к следующему узлу
        }
        cout << "nullptr" << endl;
    }

    // Удаление элемента из списка
    void removeElement(T value) {
        Node2<T>* current = head; // Начинаем с головы списка
        while (current) {
            if (current->data == value) { // Если нашли элемент с заданным значением
                if (current->prev != nullptr) {
                    current->prev->next = current->next; // Переподключаем указатели предыдущего узла
                }
                else {
                    head = current->next; // Если удаляем голову, обновляем голову списка
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev; // Переподключаем указатели следующего узла
                }
                else {
                    tail = current->prev; // Если удаляем хвост, обновляем хвост списка
                }
                delete current; // Удаляем текущий узел
                return;
            }
            current = current->next; // Переходим к следующему узлу
        }
    }

    // Метод для замены 
    void swapSegments() {
        if (!head || !head->next) return; // Список пуст или из одного элемента

        Node2<T>* minNode = findMin();//Находим минимальный элемент
        Node2<T>* maxNode = findMax();//Находим максимальный элемент

        if (minNode == maxNode) return;// Минимальный и максимальный элемент совпадают

        // Определяем порядок минимального и максимального элементов
        if (minNode->data > maxNode->data) {
            swap(minNode, maxNode);// Меняем местами указатели на минимальный и максимальный элементы, если нужно
        }

        // Инвертируем порядок элементов между minNode и maxNode
        Node2<T>* start = minNode->next; // Начинаем с узла после минимального элемента
        Node2<T>* end = maxNode->prev;// Начинаем с узла перед максимальным элементом
        while (start && end && start != end && start->prev != end) {
            // Меняем местами данные узлов
            swap(start->data, end->data);
            // Двигаем указатели к следующему и предыдущему узлам соответственно
            start = start->next;
            end = end->prev;
        }
    }
};

#endif
