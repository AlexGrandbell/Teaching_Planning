//
// Created by 沈嘉瑞 on 2023.11.21.
//

#ifndef TEACHING_PLANNING_MENU_H
#define TEACHING_PLANNING_MENU_H

#include "CourseManagement.h"

class Menu {
private:
    CourseManagement courseManagement;
public:
    void Welcome();
    void DoMenu();
};

#endif //TEACHING_PLANNING_MENU_H
