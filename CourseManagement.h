//
// Created by 沈嘉瑞 on 2023.11.21.
//

#ifndef TEACHING_PLANNING_COURSEMANAGEMENT_H
#define TEACHING_PLANNING_COURSEMANAGEMENT_H

#include "ALGraph.h"

class CourseManagement {
private:
    ALGraph<Course> courseGraph;
public:
    void outPutMenu();

    void CreateCourseGraph();//创建课程图
    void ShowCourseGraph();//展示课程顺序图
    void ChangeCourse();//信息修改，包括课程信息修改，边信息修改，边的增删，课程的增删
    void CourseInfo();//课程信息查询
    void ExitApp();//退出
};


#endif //TEACHING_PLANNING_COURSEMANAGEMENT_H
