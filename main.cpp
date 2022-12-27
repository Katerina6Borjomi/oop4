#include <iostream>
#include <vector>
#include "functions.h"
#include "menu.h"
#include <cstring>

int main() {
    vector<Student*> vec;
    int m1, m2, w, cat, k;
    k = 0;
    int cipher;
    w = 1;
    int est[5]{};
    int estO[4]{};
    int estOERW[2]{};
    int estG[3]{};

    while(w){
        print1Menu();
        m1 = input_int();
        switch (m1){
            case 0: {
                w = 0;
                vec.clear();
                break;
            }
            case 1: {
                if (vec.empty()) {
                    cout << "Ни одного студента нет в базе" << endl;
                    break;
                }
                cout << "Таблица" << endl;
                for(int i = 0; i<vec.size(); i++){
                    vec[i]->printInfo();
                }
                break;
            }
            case 2: {
                cout << "Добавление нового студента" << endl;
                cout << "Введите категорию нового студента:" << endl;
                cout << "1 -- Первокурсник" << endl;
                cout << "2 -- Старшекурсник" << endl;
                cout << "3 -- Выпускник" << endl;
                cat = input_int();
                int g, d;
                cout << "Введите ФИО студента" << endl;
                string str1, str2;
                string strT, strP;
                cin >> str1;
                cout << "Введите номер группы студента" << endl;
                g = input_int();
                cout << "Введите номер кафедры студента" << endl;
                d = input_int();

                switch (cat) {
                    case 1: {
                        cout << "Введите 5 семестровых оценок студента в одну строку без пробела" << endl;
                        cin >> str2;
                        for (int i = 0; i < 5; i++) {
                            est[i] = str2[i] - '0';
                        }
                        auto* newJst = new JuniorStudent(str1, g, d, est);
                        vec.push_back(newJst);
                        break;
                    }
                    case 2: {
                        cout << "Введите 4 семестровых оценки студента в одну строку без пробела" << endl;
                        cin >> str2;
                        for (int i = 0; i < 4; i++) {
                            estO[i] = str2[i] - '0';
                        }
                        cout << "Введите тему УИР" << endl;
                        cin >> strT;
                        cout << "Введите место написания УИР" << endl;
                        cin >> strP;
                        cout << "Введите 2 оценки за УИР студента в одну строку без пробела" << endl;
                        cin >> str2;
                        for (int i = 0; i < 2; i++) {
                            estOERW[i] = str2[i] - '0';
                        }
                        auto* newOst = new OlderStudent(str1, g, d, strT, strP, estO, estOERW);
                        vec.push_back(newOst);
                        break;
                    }
                    case 3: {
                        cout << "Введите тему ДП" << endl;
                        cin >> strT;
                        cout << "Введите место написания ДП" << endl;
                        cin >> strP;
                        cout << "Введите 3 оценки за ДП студента в одну строку без пробела" << endl;
                        cin >> str2;
                        for (int i = 0; i < 3; i++) {
                            estG[i] = str2[i] - '0';
                        }
                        auto* newGst = new Graduated(str1, g, d, strT, strP, estG);
                        vec.push_back(newGst);
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
            case 3: {
                if (vec.empty()) {
                    cout << "Ни одного студента нет в базе" << endl;
                    break;
                }
                cout << "Нахождение студента по индивидуальному шифру" << endl;
                cout << "Введите индивидуальный шифр студента" << endl;
                cipher = input_int();
                k = 0;
                int g, d;
                if ((cipher < vec[0]->getCipher()) || (cipher > vec[vec.size() - 1]->getCipher())) {
                    cout << "Студента с таким шифром не существует" << endl;
                    break;
                }
                string str2, strT, strP;
                for (int j = 0; j < vec.size(); j++) {
                    k++;
                    if (cipher == vec[j]->getCipher()) {
                        string t = vec[j]->getType();
                        cout<<t<<endl;
                        if(t == "Junior student"){
                            auto* ptrJ = dynamic_cast<JuniorStudent*>(vec[j]);
                            print2Menu();
                            m2 = input_int();
                            switch (m2) {
                                case 1: {
                                    cout << "Информация о студенте" << endl;
                                    ptrJ->printInfo();
                                    break;
                                }
                                case 2: {
                                    cout << "Категория студента ___" << vec[j]->getType() << endl;
                                    break;
                                }
                                    case 3: {
                                        cout << "Оценки" << endl;
                                        ptrJ->printEstimates();
                                        break;
                                    }
                                    case 4: {
                                        cout << "Ввод оценок" << endl;
                                        cout << "Введите 5 семестровых оценок студента в одну строку без пробела" << endl;
                                        cin >> str2;
                                        for (int i = 0; i < 5; i++) {
                                            est[i] = str2[i] - '0';
                                        }
                                        ptrJ->setEstimates(est);
                                        break;
                                    }
                                case 5: {
                                    cout << "Изменение индекса группы" << endl;
                                    cout << "Введите номер группы студента" << endl;
                                    g = input_int();
                                    ptrJ->setGroup(g);
                                    break;
                                }
                                case 6: {
                                        cout << "Перевод студента в другую категорию" << endl;
                                        auto* newold = new OlderStudent;
                                        newold = ptrJ->changeType(newold);
                                        vec.erase(vec.begin() + j);
                                        vec.insert(vec.begin() + j, newold);
                                        break;
                                    }
                                default: {
                                    break;
                                }
                            }
                        }else if(t == "Older student") {
                            auto* ptrO = dynamic_cast<OlderStudent *>(vec[j]);
                            print2Menu();
                            printExtraMenu();
                            m2 = input_int();
                            switch (m2) {
                                case 1: {
                                    cout << "Информация о студенте" << endl;
                                    ptrO->printInfo();
                                    break;
                                }
                                case 2: {
                                    cout << "Категория студента ___" << vec[j]->getType() << endl;
                                    break;
                                }
                                case 3: {
                                    cout << "Оценки" << endl;
                                    ptrO->printEstimates();
                                    cout << "Оценки за УИР" <<endl;
                                    ptrO->printERWestinates();
                                    break;
                                }
                                case 4: {
                                    cout << "Ввод оценок" << endl;
                                    cout << "Введите 4 семестровых оценок студента в одну строку без пробела" << endl;
                                    cin >> str2;
                                    for (int i = 0; i < 4; i++) {
                                        est[i] = str2[i] - '0';
                                    }
                                    ptrO->setEstimates(est);
                                    cout << "Введите 2 оценки за УИР студента в одну строку без пробела" << endl;
                                    cin >> str2;
                                    for (int i = 0; i < 2; i++) {
                                        estOERW[i] = str2[i] - '0';
                                    }
                                    ptrO->setERWestimates(estOERW);
                                    break;
                                }
                                case 5: {
                                    cout << "Изменение индекса группы" << endl;
                                    cout << "Введите номер группы студента" << endl;
                                    g = input_int();
                                    ptrO->setGroup(g);
                                    break;
                                }
                                case 6: {
                                    cout << "Перевод студента в другую категорию" << endl;
                                    auto *newGrad = new Graduated;
                                    newGrad = ptrO->changeType(newGrad);
                                    vec.erase(vec.begin() + j);
                                    vec.insert(vec.begin() + j, newGrad);
                                    break;
                                }
                                case 7: {
                                    cout << "Тема УИР" << endl;
                                    cout<<ptrO->getTopic()<<endl;
                                    break;
                                }
                                case 8: {
                                    cout << "Изменение темы УИР" << endl;
                                    cout << "Введите тему УИР" << endl;
                                    cin >> strT;
                                    ptrO->setTopic(strT);
                                    break;
                                }
                                case 9: {
                                    cout << "Место выполнения УИР" << endl;
                                    cout << ptrO->getPlace() << endl;
                                    break;
                                }
                                case 10: {
                                    cout << "Изменение места выполнения УИР" << endl;
                                    cout << "Введите место написания УИР" << endl;
                                    cin >> strP;
                                    ptrO->setPlace(strP);
                                    break;
                                }
                                default: {
                                    break;
                                }
                            }
                        }else{
                            auto* ptrG = dynamic_cast<Graduated*>(vec[j]);
                            print2Menu();
                            printExtraMenu();
                            m2 = input_int();
                            switch (m2) {
                                case 1: {
                                    cout << "Информация о студенте" << endl;
                                    ptrG->printInfo();
                                    break;
                                }
                                case 2: {
                                    cout << "Категория студента ___" << vec[j]->getType() << endl;
                                    break;
                                }
                                case 3: {
                                    cout << "Оценки за ДП" << endl;
                                    ptrG->printEstimates();
                                    break;
                                }
                                case 4: {
                                    cout << "Ввод оценок" << endl;
                                    cout << "Введите 3 оценки за ДП студента в одну строку без пробела" << endl;
                                    cin >> str2;
                                    for (int i = 0; i < 4; i++) {
                                        est[i] = str2[i] - '0';
                                    }
                                    ptrG->setEstimates(est);
                                    break;
                                }
                                case 5: {
                                    cout << "Изменение индекса группы" << endl;
                                    cout << "Введите номер группы студента" << endl;
                                    g = input_int();
                                    ptrG->setGroup(g);
                                    break;
                                }
                                case 6: {
                                    cout << "Перевод студента в другую категорию не возможен" << endl;
                                    break;
                                }
                                case 7: {
                                    cout << "Тема ДП" << endl;
                                    cout<<ptrG->getTopic()<<endl;
                                    break;
                                }
                                case 8: {
                                    cout << "Изменение темы ДП" << endl;
                                    cout << "Введите тему ДП" << endl;
                                    cin >> strT;
                                    ptrG->setTopic(strT);
                                    break;
                                }
                                case 9: {
                                    cout << "Место выполнения ДП" << endl;
                                    cout << ptrG->getPlace() << endl;
                                    break;
                                }
                                case 10: {
                                    cout << "Изменение места выполнения ДП" << endl;
                                    cout << "Введите место написания ДП" << endl;
                                    cin >> strP;
                                    ptrG->setPlace(strP);
                                    break;
                                }
                                default: {
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
                if (k == vec.size()) {
                    cout << "Студента с таким шифром не существует" << endl;
                }
                break;
            }
            case 4: {
                if (vec.empty()) {
                    cout << "Ни одного студента нет в базе" << endl;
                    break;
                }
                cout << "Отчисление студента" << endl;
                cout << "Введите индивидуальный шифр студента" << endl;
                cipher = input_int();
                k = 0;
                for(int i = 0; i < vec.size(); i++){
                    if(vec[i]->getCipher() == cipher){
                        vec.erase(vec.begin() + i);
                        cout << "Студент успешно отчислен )))))))" << endl;
                        k = 1;
                        break;
                    }
                }
                if(k == 0){
                    cout<<"Студента с таким шифром нет в базе"<<endl;
                }
                break;
            }
            default: {
                break;
            }
        }
    }


    return 0;
}
