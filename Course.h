//
// Created by 沈嘉瑞 on 2023.11.21.
//

#ifndef TEACHING_PLANNING_COURSE_H
#define TEACHING_PLANNING_COURSE_H

#include "Tool.h"

struct Course {
    string number;
    string title;
    double credit;

    Course();
    Course(string, string, double);
    Course(string);

    bool operator==(const Course& other) const;
    bool operator!=(const Course& other) const;
};

ostream& operator<<(ostream& out, const Course& c);

#endif //TEACHING_PLANNING_COURSE_H
