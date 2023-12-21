//
// Created by 沈嘉瑞 on 2023.11.21.
//
#include "Course.h"

Course::Course() : number(""), title("none"), credit(0) {}

Course::Course(string n, string t, double c) : number(n), title(t), credit(c) {}

Course::Course(string n) : number(n), title(""), credit(0) {}

bool Course::operator==(const Course& other) const {
    return number == other.number;
}

bool Course::operator!=(const Course& other) const {
    return number != other.number;
}

ostream& operator<<(ostream& out, const Course& c) {
    return out << "课程编号:" << setw(15) << left << c.number << "学分:" << setw(10) << left << c.credit << "课程名称:" << c.title;
}