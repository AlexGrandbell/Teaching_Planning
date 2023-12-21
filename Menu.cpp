//
// Created by 沈嘉瑞 on 2023.11.21.
//

#include "Menu.h"

void Menu::Welcome() {
    cout << "\n欢迎进入课程管理系统系统" << endl;
    cout<<"你可以随时输入'q'来退出当前操作。"<<endl;
    cout<<"----------任意输入以开始----------"<<endl;
    string tmp = inputString();
    cout<<endl;
}

void Menu::DoMenu() {
    int nSelection = -1;//判断用户输入的数字选择对应的菜单
    //不断循环，执行操作
    do {
        //界面与输入
        courseManagement.outPutMenu();//界面
        fflush(stdin);//清除输入流缓存
        nSelection = -1;
        try {
            nSelection = inputInt();

            //根据输入选择行为
            switch (nSelection) {
                case 0: {
                    courseManagement.ExitApp();
                    return;
                }//再见
                case 1: {
                    courseManagement.CreateCourseGraph();
                    break;
                }//输入
                case 2: {
                    courseManagement.ShowCourseGraph();
                    break;
                }//输出
                case 3:{
                    courseManagement.ChangeCourse();
                    break;
                }//信息修改
                case 4:{
                    courseManagement.CourseInfo();
                    break;
                }//信息查询
                default: {
                    cout<<"您输入的序号错误。";
                    break;
                }//错误
            }//完成
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
        if (nSelection != 0) {
            cout<<"继续操作请按1，关闭程序请按0:";
            fflush(stdin);//清除输入流缓存
            nSelection = -1;
            try {
                nSelection = inputInt();
                if (nSelection == 0) {
                    courseManagement.ExitApp();
                }
            }catch  (const exception& e){
                cout<<e.what()<<endl;
            }
        }
    } while (nSelection != 0);
}