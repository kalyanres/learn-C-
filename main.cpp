// main.cpp - библиотека
#include <iostream>
#include <fstream>
#include <cstring>      // для strchr()
#include "libr.h"

const int SIZE_B = 120;      // максимальное количество книг
const int SIZE_R = 20;      // максимальное количество читателей

int main(){
    Book *library[SIZE_B];           // массив книг
    Reader *readerer[SIZE_R];        // массив читателей
    int ibook = 0;                  // количество зарегистрированных книг
    int ireader = 0;                  // количество зарегистрированных читателей
    std::cout << "Добрый день!\n Приветствуем Вас в нашей библиотеке.\n";
    std::cout << "  Хотите добавить книгу в нашу библиотеку? (нажмите a)\n"
              << "  Хотите стать нашим новым читателем? (нажмите r)\n"
              << "  Если Вы уже являетесь нашим читателем? (нажмите b)\n"
              << "  Хотите выйти? (нажмите q)\n";
    char ch;
    while(std::cin >> ch){
        if(std::strchr("arbq", ch) == nullptr){
            std::cin.get();
            std::cout << "Пожалуйста, введите корректную букву: ";
            continue;
        }

        // реализация выхода
        if (ch == 'q') break;
        
        // реализация добавления книги
        if (ch == 'a'){
            library[ibook] = new Book;
            library[ibook]->Set();
            ibook++;
        }

        // реализация добавления читателя
        if (ch == 'r'){
            readerer[ireader] = new Reader;
            readerer[ireader]->Set();
            ireader++;
        }

        // реализация вывода списка читателей и выбора своей карточки
        if (ch == 'b'){
            for (int i = 0; i < ireader; i++)
                readerer[i]->Show();
            std::cout << std::endl;
            std::cout << "Найдите себя из предложенного списка (нажмите соответствующий номер): ";
            unsigned int rnumb;
                if (rnumb > ireader){
                    std::cout << "Введите корректное число: ";
                    continue;
                }
                else
                    break;
            std::cout << "Приветствуем Вас, " << readerer[rnumb]->show_name() << " "
                      << readerer[rnumb]->show_surname() << std::endl;
            std::cout << "  Хотите взять книгу?   (нажмите t)\n"
                      << "  Хотите вернуть книгу? (нажмите r)\n"
                      << "  Хотите посмотреть взятые книги? (нажмите s)\n";

            // Реализация взятия книги
            while(std::cin >> ch){
                if (ch == 't'){
                    std::cout << "Список доступных книг: \n";
                    for (int i = 0; i < ibook; i++){    
                        if (!library[i]->sstatus())        // проверка на доступность книги
                            continue;
                        library[i]->Show();
                    }
                    std::cout << std::endl;
                    std::cout << "Введите номер нужной вам книги: ";
                    unsigned int bnumb;
                    while (std::cin >> bnumb){           // проверка на правильность
                        if (bnumb > ireader){
                            std::cout << "Введите корректное число: ";
                            continue;
                        }
                        std::cout << "Вы выбрали книгу ";
                        library[bnumb]->Show();
                        std::cout << "Хотите её взять? (y/n)";
                        char choise;
                        std::cin >> choise;
                        if (choise == 'n'){
                            std::cout << "Введите номер нужной вам книги: ";
                            continue;
                        }
                        else if (choise == 'y'){
                            readerer[rnumb]->takebook(library[bnumb]);
                            break;
                        }
                        else {
                            std::cout << "Введите корректный символ: ";
                            continue;
                        }
                    }
                    break;
                }

                // Реализация возврата книги
                else if (ch == 'r'){
                    std::cout << "У вас находятся следующие книги: " << std::endl;
                    readerer[rnumb]->Show_books();
                    std::cout << "Введите номер книги, которую хотите вернуть: ";
                    unsigned int nnumb;
                    std::cin >> nnumb;
                    while (!readerer[rnumb]->rebook(library[nnumb])){       // проверка на корректность
                        std::cin >>nnumb;
                        continue;
                    }
                    break;
                }

                // Печать списка книг, находящихся у читателя
                else if (ch == 's'){
                    readerer[rnumb]->Show_books();
                    break;
                }

                else {
                    std::cout << "Введите корректный символ: ";
                    continue;
                }
            }
        }


        std::cout << "  Хотите добавить книгу в нашу библиотеку? (нажмите a)\n"
                  << "  Хотите стать нашим новым читателем? (нажмите r)\n"
                  << "  Хотите взять или вернуть книгу? (нажмите b)\n"
                  << "  Хотите выйти? (нажмите q)\n";
    }
    std::cout << "До свидания, заходите к нам ещё :)" << std::endl;
}
