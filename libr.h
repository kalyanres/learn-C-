// libr.h -- классы библиотеки
#ifndef LIBR_H_
#define LIBR_H_

const int MB = 5;           // максимальное количество книг на одного читателя

// Книга
class Book{
    std::string author;     // автор
    std::string title;      // название
    bool status;            // статус: 0 - свободна; 1 - занята
    static int number;  // каталожный номер
public:
    Book(const std::string a = "no author", 
            const std::string t = "no title");
    void Set();                 // внесение данных
    void Set_status(bool st);  // изменение статуса
    bool sstatus();         // возврат статуса
    std::string Show_autor();   // возврат имени автора
    std::string Show_title();   // возврат имени названия
    void Show();        // отображение данных книги
    int snumber();      // возврат католожного номера
};

// читатель
class Reader{
    std::string name;       // имя читателя
    std::string surname;    // фамилия читателя
    static int lib_card;    // номер читательского билета
    Book *books[MB];         // не более 5 книг на человека
    int count_book;         // количество взятых книг
public:
    Reader(const std::string n = "no name", 
           const std::string s = "no surname");       // конструктор
    void Set();                         // внесение данных
    std::string show_name();              // возврат имени
    std::string show_surname();           // возврат фамилии
    int show_card();                      // возврат номера чит.бил.
    void takebook(Book *b);      // функция "взять книгу"
    bool rebook(Book *b);      // функция "отдать книгу"
    void Show();                        // вывод на печать данных читателя 
    void Show_books();        // отображение взятых книг
};

#endif
