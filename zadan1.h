#ifndef LAB6_H
#define LAB6_H
#include <iostream>

// Класс, представляющий узел однонаправленного списка
template <typename T>
class Node {
public:
    T data;        // Данные, хранящиеся в узле
    Node* next;    // Указатель на следующий узел

    // Конструктор для инициализации узла
    Node(T value) : data(value), next(nullptr) {}
};

// Класс, представляющий однонаправленный список
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Указатель на голову списка

public:
    // Конструктор, инициализирующий голову списка нулевым указателем
    LinkedList() : head(nullptr) {}

    // Деструктор, освобождающий память, занятую узлами списка
    ~LinkedList() {
        Node<T>* current = head; // Начинаем с головы списка
        while (current != nullptr) {
            Node<T>* nextNode = current->next; // Сохраняем указатель на следующий
            delete current; // Освобождаем память текущего узла
            current = nextNode; // Переходим к следующему узлу
        }
    }

    // Метод для добавления нового элемента в конец списка
    void add(T data) {
        Node<T>* newNode = new Node<T>(data);// Создаём новый узел
        if (!head) {
            head = newNode;// Если список пуст, новый узел становится головой
            return;
        }
        Node<T>* lastNode = head;// Иначе ищем последний узел
        while (lastNode->next) {
            lastNode = lastNode->next; // Переходим к следующему узлу
        }
        lastNode->next = newNode;// Добавляем новый узел в конец списка
    }

    // Метод для удаления элемента из списка
    void remove(T data) {
        Node<T>* current = head; // Начинаем с головы списка
        Node<T>* previous = nullptr; // Предыдущий узел (изначально пустой)

        // Ищем элемент для удаления
        while (current != nullptr && current->data != data) {
            previous = current;// Обновляем предыдущий узел
            current = current->next;// Переходим к следующему узлу
        }

        if (current == nullptr) return;// Элемент не найден

        if (previous == nullptr) {
            head = current->next; // Удаляем голову списка
        }
        else {
            previous->next = current->next;// Удаляем текущий узел
        }

        delete current; // Освобождаем память удаляемого узла
    }

    // Метод для повторения указанного элемента
    void repeatElements(T element) {
        Node<T>* current = head;// Начинаем с головы списка
        while (current != nullptr) {
            if (current->data == element) { // Если нашли совпадение
                Node<T>* newNode = new Node<T>(element); // Создаём новый узел с тем же элементом
                newNode->next = current->next; // Новый узел указывает на следующий после текущего
                current->next = newNode; // Текущий узел указывает на новый узел
                current = newNode->next; // Пропускаем новый узел и переходим к следующему
            }
            else {
                current = current->next; // Переходим к следующему узлу
            }
        }
    }

    // Метод для вывода списка
    void printList() const {
        Node<T>* current = head; // Начинаем с головы списка
        while (current != nullptr) {
            std::cout << current->data << " -> "; // Выводим данные текущего узла
            current = current->next; // Переходим к следующему узлу
        }
        std::cout << "nullptr" << std::endl; // Завершаем вывод указателем на ноль

    }
};

#endif
