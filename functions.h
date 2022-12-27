#ifndef OOP4_FUNCTIONS_H
#define OOP4_FUNCTIONS_H
using namespace std;
#include <cstring>
#include <iostream>
#include <vector>

class Student{
protected:
    string name;
    int group;
    int departament;
    int cipher;

public:
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
    Graduated* changeType(Graduated*);
};

class JuniorStudent: public Student{ //1
private:
    int estimates[5]{};

public:
    JuniorStudent();
    explicit JuniorStudent(string str, int g, int d, int* est);
    string getType() override;
    string printEstimates() override;
    void setEstimates(int*) override;
    OlderStudent* changeType(OlderStudent*);
};

void printTable();



#endif //OOP4_FUNCTIONS_H
