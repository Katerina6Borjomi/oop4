#ifndef OOP4_FUNCTIONS_H
#define OOP4_FUNCTIONS_H
using namespace std;
#include <cstring>
#include <iostream>
#include <vector>

/**
 * \brief Информация об элементах класса Student (Этот класс используется для дальнейшего наследования)
 * @param name ФИО
 * @param group Номер группы
 * @param departament Номер кафедры
 * @param cipher Уникальный шифр
 */

class Student{
protected:
    string name;
    int group;
    int departament;
    int cipher;

public:///В методах класса Student содержатся только get/set методы
    static int count;
    int getCipher() const;
    void setCipher(int);
    void printInfo();
    void setName(string);
    void setGroup(int);
    void setDepartament(int);
    virtual string getType() = 0;
    virtual string printEstimates() = 0;
    virtual void setEstimates(int*) = 0;
};

/**
 * \brief Класс Graduated наследуется от Student
 * @param topic Тема дипломной работы
 * @param place Место написания дипломной работы
 * @param estimatesErw Оценки за дипломную работу
 */

class Graduated: public Student{ //3
private:
    string topic;
    string place;
    int estimatesErw[3]{};

public:
    Graduated();
    explicit Graduated(const string& str, int g, int d, const string& str2, const string& str3, int* est);
    string getTopic();
    void setTopic(string);
    string getPlace();
    void setPlace(string);
    string getType() override;
    string printEstimates() override;
    void setEstimates(int*) override;
};

/**
 * \brief Класс OlderStudent наследуется от Student
 * @param topic Тема УИР
 * @param place Место написания УИР
 * @param estimatesErw Оценки за УИР
 * @param estimates Оценки за семестр
 */

class OlderStudent: public Student{ //2
private:
    int estimates[4]{};
    string topic;
    string place;
    int estimatesErw[2]{};

public:
    OlderStudent();
    explicit OlderStudent(string str, int g, int d, const string& str2, const string& str3, int* est, int* erwest);
    string getTopic();
    void setTopic(string);
    string getPlace();
    void setPlace(string);
    string getType() override;
    string printEstimates() override;
    string printERWestinates();
    void setEstimates(int*) override;
    void setERWestimates(int*);
    Graduated* changeType(Graduated*);///<Перевод студента из Старшекурсников в Выпускников
};

/**
 * \brief Класс JuniorStudent наследуется от Student
 * @param estimates Оценки за семестр
 */

class JuniorStudent: public Student{ //1
private:
    int estimates[5]{};

public:
    JuniorStudent();
    explicit JuniorStudent(string str, int g, int d, int* est);
    string getType() override;
    string printEstimates() override;
    void setEstimates(int*) override;
    OlderStudent* changeType(OlderStudent*);///<Перевод студента из Младшекурсников в Старшекурсников
};

void printTable();



#endif //OOP4_FUNCTIONS_H
