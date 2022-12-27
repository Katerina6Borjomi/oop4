#include "functions.h"
#include <sstream>
#include <utility>
#include <cstring>
#include "menu.h"

int Student::count = 0;

void Student::printInfo(){
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<< this->cipher << "->" <<this->name<<" "<<this->group<<" "<<this->departament<<" "<<this->getType()<<endl;
}

void Student::setName(string n){
    this->name = std::move(n);
}

void Student::setGroup(int g){
    this->group = g;
}

void Student::setDepartament(int d){
    this->departament = d;
}

int Student::getCipher() const{
    return this->cipher;
}

void Student::setCipher(int ciph){
    this->cipher = ciph;
}

string JuniorStudent::getType(){
    return "Junior student";
}

string OlderStudent::getType(){
    return "Older student";
}

string Graduated::getType(){
    return "Graduated";
}

string JuniorStudent::printEstimates(){
    stringstream ss;
    string str;
    for(int i = 0; i < 5; i++){
        ss << this->estimates[i];
        str = str + ss.str() + " ";
    }
    return str;
}

string OlderStudent::printEstimates(){
    stringstream ss;
    string str;
    for(int i = 0; i < 4; i++){
        ss << this->estimates[i];
        str = str + ss.str() + " ";
    }
    return str;
}

string OlderStudent::printERWestinates(){
    stringstream ss;
    string str;
    for(int i = 0; i < 2; i++){
        ss << this->estimatesErw[i];
        str = str + ss.str() + " ";
    }
    return str;
}

string Graduated::printEstimates(){
    stringstream ss;
    string str;
    for(int i = 0; i < 3; i++){
        ss << this->estimatesErw[i];
        str = str + ss.str() + " ";
    }
    return str;
}

void JuniorStudent::setEstimates(int* est){
    for(int i = 0; i < 5; i++){
        this->estimates[i] = est[i];
    }
}

void OlderStudent::setEstimates(int* est){
    for(int i = 0; i < 4; i++){
        this->estimates[i] = est[i];
    }
}

void OlderStudent::setERWestimates(int* est) {
    for(int i = 0; i < 2; i++){
        this->estimatesErw[i] = est[i];
    }
}

void Graduated::setEstimates(int* est){
    for(int i = 0; i < 3; i++){
        this->estimatesErw[i] = est[i];
    }
}

OlderStudent* JuniorStudent::changeType(OlderStudent* olds){
    olds->setName(this->name);
    olds->setGroup(this->group);
    olds->setDepartament(this->departament);
    olds->setCipher(this->cipher);
    string str2, strT, strP;
    cout << "Введите 4 семестровых оценки студента в одну строку через пробел" << endl;
    cin >> str2;
    int estO[4]{};
    for (int i = 0; i < 4; i++) {
        estO[i] = str2[i] - '0';
    }
    olds->setEstimates(estO);
    cout << "Введите тему УИР" << endl;
    cin >> strT;
    olds->setTopic(strT);
    cout << "Введите место написания УИР" << endl;
    cin >> strP;
    olds->setPlace(strP);
    cout << "Введите 2 оценки за УИР студента в одну строку через пробел" << endl;
    cin >> str2;
    int estOERW[2]{};
    for (int i = 0; i < 2; i++) {
        estOERW[i] = str2[i] - '0';
    }
    olds->setERWestimates(estOERW);
    return olds;
}

Graduated* OlderStudent::changeType(Graduated* grad){
    grad->setName(this->name);
    grad->setGroup(this->group);
    grad->setDepartament(this->departament);
    grad->setCipher(this->cipher);
    string strT, strP, str2;
    cout << "Введите тему ДП" << endl;
    cin >> strT;
    grad->setTopic(strT);
    cout << "Введите место написания ДП" << endl;
    cin >> strP;
    grad->setPlace(strP);
    cout << "Введите 3 оценки за ДП студента в одну строку через пробел" << endl;
    cin >> str2;
    int estG[3]{};
    for (int i = 0; i < 3; i++) {
        estG[i] = str2[i] - '0';
    }
    grad->setEstimates(estG);
    return grad;
}

string OlderStudent::getTopic(){
    string str = this->topic;
    return str;
}

string Graduated::getTopic(){
    string str = this->topic;
    return str;
}

void OlderStudent::setTopic(string tp){
    this->topic =std::move(tp);
}

void Graduated::setTopic(string tp){
    this->topic =std::move(tp);
}

string OlderStudent::getPlace(){
    string str = this->place;
    return str;
}

string Graduated::getPlace(){
    string str = this->place;
    return str;
}

void OlderStudent::setPlace(string pl){
    this->place = std::move(pl);
}

void Graduated::setPlace(string pl){
    this->place = std::move(pl);
}

JuniorStudent::JuniorStudent(){
    this->group = 0;
    this->departament = 0;
    for(int i = 0; i < 5; i++){
        this->estimates[i] = 0;
    }
}

JuniorStudent::JuniorStudent(string str, int g, int d, int *est){
    this->name = str;
    this->departament = d;
    this->group = g;
    for(int i = 0; i < 5; i++){
        this->estimates[i] = est[i];
    }
    count ++;
    this->cipher = count;
}

OlderStudent::OlderStudent(){
    this->group = 0;
    this->departament = 0;
    for(int i = 0; i < 4; i++){
        this->estimates[i] = 0;
    }
    for(int j = 0; j < 2; j++){
        this->estimatesErw[j] = 0;
    }
}

OlderStudent::OlderStudent(string str, int g, int d, const string& str2, const string& str3, int* est, int* erwest){
    this->name = str;
    this->departament = d;
    this->group = g;
    this->topic = str2;
    this->place = str3;
    for(int i = 0; i < 4; i++){
        this->estimates[i] = est[i];
    }
    for(int j = 0; j < 2; j++){
        this->estimatesErw[j] = erwest[j];
    }
    count ++;
    this->cipher = count;
}

Graduated::Graduated(){
    this->group = 0;
    this->departament = 0;
    for(int j = 0; j < 3; j++){
        this->estimatesErw[j] = 0;
    }
}

Graduated::Graduated(const string& str, int g, int d, const string& str2, const string& str3, int* est){
    this->name = str;
    this->departament = d;
    this->group = g;
    this->topic = str2;
    this->place = str3;
    for(int i = 0; i < 3; i++){
        this->estimatesErw[i] = est[i];
    }
    count ++;
    this->cipher = count;
}