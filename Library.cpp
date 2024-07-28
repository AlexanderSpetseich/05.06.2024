#include <iostream>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    std::string publisher;
    std::string genre;
};

void printBooks(const Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Книга " << (i + 1) << ": " << books[i].title << ", " << books[i].author
            << ", " << books[i].publisher << ", " << books[i].genre << std::endl;
    }
}

void editBook(Book& book) {
    std::cout << "Введите новое название книги: ";
    std::getline(std::cin, book.title);
    std::cout << "Введите нового автора: ";
    std::getline(std::cin, book.author);
    std::cout << "Введите новое издательство: ";
    std::getline(std::cin, book.publisher);
    std::cout << "Введите новый жанр: ";
    std::getline(std::cin, book.genre);
}

void searchByAuthor(const Book books[], int size, const std::string& author) {
    for (int i = 0; i < size; ++i) {
        if (books[i].author == author) {
            std::cout << "Найдена книга: " << books[i].title << " от " << author << std::endl;
        }
    }
}

void searchByTitle(const Book books[], int size, const std::string& title) {
    for (int i = 0; i < size; ++i) {
        if (books[i].title == title) {
            std::cout << "Найдена книга: " << books[i].title << " от " << books[i].author << std::endl;
        }
    }
}

bool compareByTitle(const Book& a, const Book& b) {
    return a.title < b.title;
}

bool compareByAuthor(const Book& a, const Book& b) {
    return a.author < b.author;
}

bool compareByPublisher(const Book& a, const Book& b) {
    return a.publisher < b.publisher;
}

int main() {
    setlocale(LC_ALL, "RU");
    Book library[10] = {
        {"Книга 1", "Автор 1", "Издательство 1", "Жанр 1"},
        {"Книга 2", "Автор 2", "Издательство 2", "Жанр 2"},
        {"Книга 3", "Автор 1", "Издательство 1", "Жанр 3"},
        {"Книга 4", "Автор 3", "Издательство 3", "Жанр 1"},
        {"Книга 5", "Автор 2", "Издательство 1", "Жанр 2"},
        {"Книга 6", "Автор 4", "Издательство 2", "Жанр 4"},
        {"Книга 7", "Автор 5", "Издательство 2", "Жанр 2"},
        {"Книга 8", "Автор 6", "Издательство 3", "Жанр 1"},
        {"Книга 9", "Автор 3", "Издательство 3", "Жанр 3"},
        {"Книга 10", "Автор 4", "Издательство 1", "Жанр 4"}
    };

    int choice;
    do {
        std::cout << "\n1. Редактировать книгу\n";
        std::cout << "2. Печать всех книг\n";
        std::cout << "3. Поиск книг по автору\n";
        std::cout << "4. Поиск книги по названию\n";
        std::cout << "5. Сортировка по названию\n";
        std::cout << "6. Сортировка по автору\n";
        std::cout << "7. Сортировка по издательству\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите операцию: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            int index;
            std::cout << "Введите номер книги для редактирования (1-10): ";
            std::cin >> index;
            std::cin.ignore();
            if (index >= 1 && index <= 10) {
                editBook(library[index - 1]);
            }
            else {
                std::cout << "Неверный номер книги." << std::endl;
            }
            break;
        }
        case 2:
            printBooks(library, 10);
            break;
        case 3: {
            std::string author;
            std::cout << "Введите имя автора: ";
            std::getline(std::cin, author);
            searchByAuthor(library, 10, author);
            break;
        }
        case 4: {
            std::string title;
            std::cout << "Введите название книги: ";
            std::getline(std::cin, title);
            searchByTitle(library, 10, title);
            break;
        }
        case 5:
            std::sort(library, library + 10, compareByTitle);
            std::cout << "Книги отсортированы по названию." << std::endl;
            break;
        case 6:
            std::sort(library, library + 10, compareByAuthor);
            std::cout << "Книги отсортированы по автору." << std::endl;
            break;
        case 7:
            std::sort(library, library + 10, compareByPublisher);
            std::cout << "Книги отсортированы по издательству." << std::endl;
            break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);

    return 0;
}