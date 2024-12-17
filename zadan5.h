#ifndef ZADAN5_H
#define ZADAN5_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

// Структура для хранения данных о каждом ученике
template <typename T>
struct Student {
    string lastName;
    string firstName;
    int schoolNumber;
    T score;

    // Конструктор для инициализации всех переменных
    Student(const string& ln = "", const string& fn = "", int sn = 0, T sc = T())
        : lastName(ln), firstName(fn), schoolNumber(sn), score(sc) {}
};

// Класс, реализующий функционал словаря
template <typename T>
class Dictionary {
public:
    Dictionary() {}  // Конструктор

    // Добавление ученика
    void addStudent(const Student<T>& student) {
        students.push_back(student);
    }

    // Чтение данных из файла
    void readDataFromFile(const string& filename) {
        ifstream file(filename);
        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            Student<T> student;
            ss >> student.lastName >> student.firstName >> student.schoolNumber >> student.score;
            addStudent(student);
        }
    }

    // Вывод студентов
    void printStudents() const {
        for (const auto& student : students) {
            std::cout << student.lastName << " " << student.firstName << " "
                << student.schoolNumber << " " << student.score << std::endl;
        }
    }

    void computeExcellentScore() {
        // Проверяем, есть ли студенты в списке
        if (students.empty()) {
            std::cout << "Нет студентов!" << std::endl; // Если список студентов пуст, выводим сообщение
            return; // Завершаем выполнение функции
        }

        // Создаем вектор для хранения баллов студентов
        std::vector<T> scores;
        for (const auto& student : students) {
            scores.push_back(student.score); // Добавляем балл каждого студента в вектор
        }

        // Сортируем баллы студентов по убыванию
        std::sort(scores.begin(), scores.end(), std::greater<T>());

        // Определяем количество студентов, которые могут получить "отлично" (20% от общего числа)
        int excellentCount = scores.size() / 5; // Рассчитываем 20% от общего количества студентов
        if (excellentCount == 0) {
            excellentCount = 1; // Если студентов меньше 5, то хотя бы один студент получит "отлично"
        }

        // Находим минимальный балл среди студентов, получивших "отлично"
        int minExcellentScore = scores[excellentCount - 1]; // Индекс - 1, так как индексация начинается с 0

        // Выводим минимальный балл для отличников
        std::cout << "Минимальный балл для отличников: " << minExcellentScore << std::endl;
    }

    void removeStudent(const std::string& lastName) {
        // Удаляем студентов с заданной фамилией из вектора
        auto it = std::remove_if(students.begin(), students.end(),
            [&lastName](const Student<T>& student) { // Исправлено: убрано лишнее t
                return student.lastName == lastName; // Сравниваем фамилию
            });

        if (it != students.end()) { // Если были найдены студенты для удаления
            students.erase(it, students.end()); // Удаляем их из вектора
            std::cout << "Студент(ы) с фамилией '" << lastName << "' удалены." << std::endl;
        }
        else {
            std::cout << "Студент с фамилией '" << lastName << "' не найден." << std::endl;
        }
    }

private:
    std::vector<Student<T>> students;
};

#endif
