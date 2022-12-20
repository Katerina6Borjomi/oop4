#include "functions.h"
#include <sstream>

void Student::printInfo(){
    cout<<this->name<<" "<<this->group<<" "<<this->departament;
}

void Student::setName(string name){
    this->name = name;
}

void Student::setGroup(int g){
    this->group = g;
}

void Student::setDepartament(int d){
    this->departament = d;
}

string JuniorStudent::getType(){
    return "Junoir studednt";
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
    return olds;
}

Graduated* OlderStudent::changeType(Graduated* grad){
    grad->setName(this->name);
    grad->setGroup(this->group);
    grad->setDepartament(this->departament);
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

void OlderStudent::setTopic(string topic){
    this->topic =topic;
}

void Graduated::setTopic(string topic){
    this->topic =topic;
}

string OlderStudent::getPlace(){
    string str = this->place;
    return str;
}

string Graduated::getPlace(){
    string str = this->place;
    return str;
}

void OlderStudent::setPlace(string place){
    this->place = place;
}

void Graduated::setPlace(string place){
    this->place = place;
}