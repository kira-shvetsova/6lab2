#ifndef ZADAN4_H
#define ZADAN4_H
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

template <typename T>
class Unordered {
private:
    unordered_set <T> elements; // Хранит уникальные элементы

public:
    // Добавляет элемент в коллекцию
    void add(const T& element) {
        elements.insert(element); // Добавляем элемент в множество
    }

    // Удаляет элемент из коллекции
    void remove(const T& element) {
        elements.erase(element); // Удаляем элемент из множества
    }

    //Объединяет текущую коллекцию с другой
    Unordered<T> Union(const Unordered<T>& other) const {
        Unordered<T> result = *this; // Копируем текущее множество
        result.elements.insert(other.elements.begin(), other.elements.end()); // Добавляем элементы из другого множества
        return result;
    }

    // Удаляет из текущей коллекции элементы другой коллекции
    Unordered<T> Except(const Unordered<T>& other) const {
        Unordered<T> result = *this; // Копируем текущее множество
        for (const auto& elem : other.elements) {
            result.elements.erase(elem); // Удаляем элементы, присутствующие в другом множестве
        }
        return result;
    }

    // Возвращает пересечение текущей коллекции и другой
    Unordered<T> Intersect(const Unordered<T>& other) const {
        Unordered<T> result;
        for (const auto& elem : elements) {
            if (other.elements.count(elem)) { // Если элемент присутствует в обоих множествах
                result.add(elem);
            }
        }
        return result;
    }

    // Проверяет, содержит ли коллекция заданный элемент
    bool Contains(const T& element) const {
        return elements.count(element) > 0; // Проверяем, есть ли элемент в множестве
    }

    // Выводит все элементы коллекции
    void print() const {
        for (const auto& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }

    size_t size() const {
        return elements.size(); // Возвращаем количество элементов
    }
};

// Функция для поиска символов, встречающихся только в одном слове
template <typename T>
void findUniqueSymbols(const T& text) {
    unordered_map<char, int> charCount; // Счетчик символов, где ключ - символ, значение - количество его появлений

    istringstream iss(text); // Создаем поток для разбивки текста на слова
    string word; // Переменная для хранения текущего слова
    while (iss >> word) { // Пока есть слова в потоке
        unordered_set<char> wordChars(word.begin(), word.end()); // Создаем множество уникальных символов текущего слова
        for (char c : wordChars) { // Проходим по каждому уникальному символу в слове
            charCount[c]++; // Увеличиваем счетчик для этого символа
        }
    }

    cout << "Символы, которые встречаются только в одном слове: "; // Сообщение для вывода результата
    for (const auto& pair : charCount) { // Проходим по каждому символу и его счетчику
        char ch = pair.first; // Получаем символ
        int count = pair.second; // Получаем количество появлений этого символа
        if (count == 1) { // Проверяем, встречается ли символ только в одном слове
            cout << ch << " "; // Выводим символ, если он уникален
        }
    }
    cout << endl; // Переход на новую строку после вывода всех уникальных символов
}

#endif
