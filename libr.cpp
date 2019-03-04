// libr.cpp -- реализация
#include <iostream>
#include "libr.h"

//bool Book::status = false;
int Book::number = 0;

Book::Book(const std::string a, const std::string t) : 
    author(a), title(t){
        status = false;
        number++;
    }

void Book::Set(){       // внесение данных
    std::cin.get();
    std::cout << "Введите автора книги: ";
    std::getline(std::cin, author);
    std::cout << "Введите название книги: ";
    std::getline(std::cin, title);
    std::cout << std::endl;
}

void Book::Set_status(bool st){    // изменение статуса книги
    status = st;
}

bool Book::sstatus(){               // возврат статуса
    return status;
}

std::string Book::Show_autor(){           // возврат имени автора
    return author;
}

std::string Book::Show_title(){   // возврат имени названия
    return title;
}

void Book::Show(){          // отображение данных
    std::cout << number << ". " << author << ". " 
        << "\"" << title << "\"" << std::endl;
}

int Book::snumber(){              // возврат католожного номера
    return number;
}

//--------------------------------------------------------------------
int Reader::lib_card = 0;
//int Reader::books[MB] = {0};
int count_book = 0;

Reader::Reader(const std::string n, const std::string s) : name(n), surname(s) {
    lib_card++;
}

void Reader::Set(){                         // внесение данных
    std::cout << "Введите имя читателя: ";
    std::cin >> name;
    std::cout << "Введите фамилию читателя: ";
    std::cin >> surname;
}

std::string Reader::show_name(){        // возврат имени
    return name;
}

std::string Reader::show_surname(){     // возврат фамилии
    return surname;
}

int Reader::show_card(){
    return lib_card;
}

void Reader::takebook(Book *b){
    if (count_book == MB)
        std::cout << "У вас уже максимальное количество книг" << std::endl;
    else{
        for (int i = 0; i < MB; i++){
            if (books[i] != nullptr)          // ищем свободную ячейку массива
                continue;
            if (!b->sstatus()){             // если книга свободна
                books[i] = b;               // то можно ее взять
                b->Set_status(true);
                count_book++;
                break;
            }
        }
    }
}

bool Reader::rebook(Book *b){         // функция возврата книги в библиотеку
    for (int i = 0; i < MB; i++){
        if (books[i]->snumber() == b->snumber()){
            b->Set_status(false);           // книга становится доступной для других
            books[i] = nullptr;             // указатель освобождается
            count_book--;                   // количество книг у читателя уменьшается
            return true;
        }
        else {
            std::cout << "Книга с таким номером не найдена" << std::endl;
            return false;
        }
    }
    return false;
}

void Reader::Show(){                        // отображение данных читателя
    std::cout << lib_card << ". " << name 
        << " " << surname << std::endl;
}
    
void Reader::Show_books(){                  // отображение списка книг, находящихся у читателя
    for (int i = 0; i < MB; i++){
        if (books[i] == nullptr)
            continue;
        books[i]->Show();
    }
}
