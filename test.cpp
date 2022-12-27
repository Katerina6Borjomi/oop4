#include <iostream>
#include "gtest/gtest.h"
#include "functions.h"

using namespace std;

TEST(JuniorStudent_get_type, get_type){
    int est[5] = {1, 2, 3, 4, 5};
    JuniorStudent Jst = JuniorStudent("Ivan", 1, 2, est);
    string str = "Junior student";
    ASSERT_EQ(Jst.getType(), str);
}

TEST(OlderStudent_get_type, get_type){
    int est[5] = {1, 2, 3, 4};
    int estE[2] = {1, 2};
    string t = "Topic";
    string p = "Place";
    OlderStudent Ost = OlderStudent("Ivan", 1, 2, t, p, est, estE);
    string str = "Older student";
    ASSERT_EQ(Ost.getType(), str);
}

TEST(Graduated_get_type, get_type){
    int est[3] = {1, 2, 3};
    string t = "Topic1";
    string p = "Place1";
    Graduated Grad = Graduated("Ivan", 1, 2, t, p, est);
    string str = "Graduated";
    ASSERT_EQ(Grad.getType(), str);
}

TEST(JuniorStudent_get_est, get_est1){
    int est[5] = {1, 2, 3, 4, 5};
    JuniorStudent Jst = JuniorStudent("Ivan", 1, 2, est);
    string str = "1 2 3 4 5 ";
    ASSERT_EQ(Jst.printEstimates(), str);
}

TEST(JuniorStudent_get_est, get_est2){
    int est[5] = {0, 0, 1, 1, 2};
    JuniorStudent Jst = JuniorStudent("Igor", 2, 3, est);
    string str = "0 0 1 1 2 ";
    ASSERT_EQ(Jst.printEstimates(), str);
}

TEST(OlderStudent_get_est, get_est1){
    int est[5] = {1, 2, 3, 4};
    int estE[2] = {1, 2};
    string t = "Topic";
    string p = "Place";
    OlderStudent Ost = OlderStudent("Ivan", 1, 2, t, p, est, estE);
    string str = "1 2 3 4 ";
    ASSERT_EQ(Ost.printEstimates(), str);
}

TEST(OlderStudent_get_est, get_est2){
    int est[5] = {2, 2, 2, 2};
    int estE[2] = {1, 2};
    string t = "Topic1";
    string p = "Place1";
    OlderStudent Ost = OlderStudent("Egor", 3, 4, t, p, est, estE);
    string str = "2 2 2 2 ";
    ASSERT_EQ(Ost.printEstimates(), str);
}

TEST(OlderStudent_get_estERW, get_estERW1){
    int est[5] = {1, 2, 3, 4};
    int estE[2] = {1, 2};
    string t = "Topic";
    string p = "Place";
    OlderStudent Ost = OlderStudent("Ivan", 1, 2, t, p, est, estE);
    string str = "1 2 ";
    ASSERT_EQ(Ost.printERWestinates(), str);
}

TEST(OlderStudent_get_estERW, get_estERW2){
    int est[5] = {1, 2, 3, 4};
    int estE[2] = {0, 0};
    string t = "Topic1";
    string p = "Place1";
    OlderStudent Ost = OlderStudent("Egor", 11, 22, t, p, est, estE);
    string str = "0 0 ";
    ASSERT_EQ(Ost.printERWestinates(), str);
}

TEST(OlderStudent_get_topic, get_topic1){
    int est[5] = {1, 2, 3, 4};
    int estE[2] = {1, 2};
    string t = "Topic";
    string p = "Place";
    OlderStudent Ost = OlderStudent("Ivan", 1, 2, t, p, est, estE);
    string str = "Topic";
    ASSERT_EQ(Ost.getTopic(), str);
}

TEST(OlderStudent_get_topic, get_topic2){
    int est[5] = {1, 2, 3, 4};
    int estE[2] = {1, 2};
    string t = "Theme";
    string p = "Place1";
    OlderStudent Ost = OlderStudent("Ivan", 1, 2, t, p, est, estE);
    string str = "Theme";
    ASSERT_EQ(Ost.getTopic(), str);
}

TEST(OlderStudent_get_place, get_place1){
    int est[5] = {1, 2, 3, 4};
    int estE[2] = {1, 2};
    string t = "Topic";
    string p = "Place";
    OlderStudent Ost = OlderStudent("Ivan", 1, 2, t, p, est, estE);
    string str = "Place";
    ASSERT_EQ(Ost.getPlace(), str);
}

TEST(OlderStudent_get_place, get_place2){
    int est[5] = {1, 2, 3, 4};
    int estE[2] = {1, 2};
    string t = "Theme";
    string p = "Laboratory";
    OlderStudent Ost = OlderStudent("Ivan", 1, 2, t, p, est, estE);
    string str = "Laboratory";
    ASSERT_EQ(Ost.getPlace(), str);
}

TEST(Graduated_get_topic, get_topic1){
    int est[3] = {1, 2, 3};
    string t = "Topic1";
    string p = "Place1";
    Graduated Grad = Graduated("Ivan", 1, 2, t, p, est);
    string str = "Topic1";
    ASSERT_EQ(Grad.getTopic(), str);
}

TEST(Graduated_get_topic, get_topic2){
    int est[3] = {1, 2, 3};
    string t = "Pinterest";
    string p = "Place1";
    Graduated Grad = Graduated("Ivan", 1, 2, t, p, est);
    string str = "Pinterest";
    ASSERT_EQ(Grad.getTopic(), str);
}

TEST(Graduated_get_place, get_place1){
    int est[3] = {1, 2, 3};
    string t = "Topic1";
    string p = "Place1";
    Graduated Grad = Graduated("Ivan", 1, 2, t, p, est);
    string str = "Place1";
    ASSERT_EQ(Grad.getPlace(), str);
}

TEST(Graduated_get_place, get_place2){
    int est[3] = {1, 2, 3};
    string t = "Topic1";
    string p = "Paris";
    Graduated Grad = Graduated("Ivan", 1, 2, t, p, est);
    string str = "Paris";
    ASSERT_EQ(Grad.getPlace(), str);
}