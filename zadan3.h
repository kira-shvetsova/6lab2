#ifndef ZADAN3_H
#define ZADAN3_H

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Шаблонный класс реализует функционал неупорядоченного множества с уникальными элементами
template <typename T>
class UnorderedSet {
private:
    set<T> elements; // Хранение уникальных элементов

public:
    // Добавление элемента в коллекцию
    void add(const T& value) {
        elements.insert(value); // Добавляет элемент, если его нет
    }

    // Удаление элемента из коллекции
    void remove(const T& value) {
        elements.erase(value); // Удаляет элемент, если он существует
    }

    // Объединение двух коллекций
    UnorderedSet<T> Union(const UnorderedSet<T>& other) const {
        UnorderedSet<T> result;
        result.elements = elements; // Копируем текущие элементы
        for (const auto& elem : other.elements) {
            result.add(elem); // Добавляем элементы из второй коллекции
        }
        return result;
    }

    // Разность двух коллекций
    UnorderedSet<T> Except(const UnorderedSet<T>& other) const {
        UnorderedSet<T> result;
        for (const auto& elem: elements) {
            if (!other.Contains(elem)) {
                result.add(elem); // Добавляем элементы, которых нет во второй коллекции
            }
        }
        return result;
    }

    // Пересечение двух коллекций
    UnorderedSet<T> Intersect(const UnorderedSet<T>& other) const {
        UnorderedSet<T> result;
        for (const auto& elem : elements) {
            if (other.Contains(elem)) {
                result.add(elem); // Добавляем только общие элементы
            }
        }
        return result;
    }

    // Проверка наличия элемента
    bool Contains(const T& value) const {
        return elements.find(value) != elements.end();
    }

    // Получение всех элементов в виде вектора
    vector<T> getElements() const {
        return vector<T>(elements.begin(), elements.end());
    }

    // Вывод множества
    void print() const {
        for (const auto& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

#endif // ZADAN3_H
