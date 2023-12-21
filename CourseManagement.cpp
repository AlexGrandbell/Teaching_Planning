//
// Created by 沈嘉瑞 on 2023.11.21.
//

#include "CourseManagement.h"

void CourseManagement::outPutMenu() {
    cout<<"\n ----------菜单----------"<<endl;
    cout<<" |1.添加课程信息         |"<<endl;
    cout<<" |2.查看课程信息         |"<<endl;
    cout<<" |3.修改课程信息         |"<<endl;
    cout<<" |4.课程信息拓扑排序      |"<<endl;
    cout<<" |0.退出当前程序         |"<<endl;
    cout<<" -----------------------"<<endl;
    //输出提示选择编号
    cout<<"请选择菜单项编号(0-4):";
}

//创建课程图
void CourseManagement::CreateCourseGraph() {
    cout<<"\n----------添加课程信息----------"<<endl;
    try{
        cout<<"请选择操作(1-添加课程,2-添加课程连接,3-样例课程添加):";
        switch (inputInt()) {
            case 1: {
                cout << "(1/3)请输入课程编号(唯一编号):";
                string number = inputString();
                cout << "(2/3)请输入课程名称:";
                string title = inputString();
                cout << "(3/3)请输入课程学分:";
                double score = inputDouble();
                courseGraph.addVertex(Course(number, title, score));
                cout << "课程添加成功!" << endl;
                break;
            }
            case 2: {
                if (courseGraph.getVNum() == 0) {
                    cout << "当前无课程，无需添加课程链接。" << endl;
                } else {
                    cout << "当前课程为:" << endl;
                    courseGraph.ShowAllCourseWithIndex();
                    cout << "(1/2)请输入起始课程序号:";
                    int start = inputInt();
                    cout << "(2/2)请输入终点课程序号:";
                    int end = inputInt();
                    courseGraph.addEdge(start, end);
                    cout << "课程链接添加成功!"<<endl;
                }
                break;
            }
            case 3:{
                cout<<"正在加载软件工程样例课程..."<<endl;
                Course c[80];
                c[1] = Course("4050001210","高等数学A上",4.5);

                c[2] = Course("4030001210","大学英语1",2);
                c[3] = Course("3210001170","体育1",2);

                c[4] = Course("1050001210","军事技能训练",2);
                c[5] = Course("4120347170","计算机科学导论",2);
                c[6] = Course("4120348170","高级语言程序设计",3.5);
                c[7] = Course("4120361170","专业教育与创新创业",1);

                c[8] = Course("4030002210","大学英语2",2);
                c[9] = Course("3210002170","体育2",2);

                c[10] = Course("4050002210","高等数学A下",5.5);
                c[11] = Course("4050229110","线性代数",2.5);
                c[12] = Course("4050463130","大学物理B",5);
                c[13] = Course("1050002210","军事理论",2);
                c[14] = Course("4120349170","离散结构",3.5);
                c[15] = Course("4120014210","程序设计综合实验",1);
                c[16] = Course("4120012210","面向对象程序设计",2.5);
                c[17] = Course("4220003180","毛泽东思想和中国特色社会主义理论体系概论",4.5);


                c[18] = Course("4030003210","大学英语3",2);
                c[19] = Course("3210003170","体育3",2);

                c[20] = Course("4050058110","概率论与数理统计",3);
                c[21] = Course("4120079110","数字逻辑",3);
                c[22] = Course("4120002220","数据结构",4);
                c[23] = Course("4120263140","面向对象与多线程综合实验",1);
                c[24] = Course("4120425170","JAVA语言程序设计",2.5);
                c[25] = Course("4120363170","创新创业指导B",2);
                c[26] = Course("4220005180","马克思主义基本原理",2.5);
                c[27] = Course("4120059210","通信原理",2.5);

                c[28] = Course("4030004210","大学英语4",2);
                c[29] = Course("3210004170","体育4",2);

                c[30] = Course("4120265140","数据结构与算法综合实验",1);
                c[31] = Course("4120430170","计算机数值分析",2.5);
                c[32] = Course("4120015210","计算机组成与体系结构",4);
                c[33] = Course("4120369170","软件工程基础",2.5);
                c[34] = Course("4120275140","软件工程基础实验",1);
                c[35] = Course("4120288140","信息组织与检索",2);
                c[36] = Course("4120435170","算法设计与分析B",2);
                c[37] = Course("4120052210","汇编语言程序设计",2.5);
                c[38] = Course("4120044110","可视化编程",2.5);
                c[39] = Course("4120331150","编译原理",3.5);
                c[40] = Course("0000000000","系统软件应用综合实验",1);
                c[41] = Course("4120273141","数据库系统原理E",3);
                c[42] = Course("4120270140","数据库系统综合实验",1);
                c[43] = Course("4120040110","计算机系统结构B",2);
                c[44] = Course("4120371170","软件工程经济学A",2);
                c[45] = Course("4120237120","计算机科学与经济学A",2);
                c[46] = Course("4120071110","软件需求工程B",2);
                c[47] = Course("4120175120","软件设计与体系结构B",2);
                c[48] = Course("4120065110","软件开发工具",2);
                c[49] = Course("4120055110","人工智能概论B",2);
                c[50] = Course("4120445190","网络、群体与市场",2);
                c[51] = Course("4120016210","操作系统",3.5);
                c[52] = Course("4120354170","UML建模技术",2);
                c[53] = Course("4120298140","单片机原理与应用",2);
                c[54] = Course("4120019210","嵌入式系统应用",2.5);
                c[55] = Course("4120377170","软件工程实践(一)",2);
                c[56] = Course("4120102110","信息安全",2);
                c[57] = Course("4120027210","计算机网络",2.5);
                c[58] = Course("4120006220","计算机网络综合实验",1);
                c[59] = Course("4120311140","多媒体技术C",2);
                c[60] = Course("4120041210","Web应用开发",2);
                c[61] = Course("4120010110","XML技术",2);
                c[62] = Course("4120434170","数据挖掘C",2);
                c[63] = Course("4120055210","软件构件与中间件技术",2);
                c[64] = Course("4120370170","Python高级程序设计",2);
                c[65] = Course("4120247120","大数据技术与应用",2);
                c[66] = Course("4120049110","嵌入式操作系统",2);
                c[67] = Course("4120378170","软件工程实践(二)",3);
                c[68] = Course("4120115110","毕业实习",3);
                c[69] = Course("4120054210","信息安全基础实验",1);
                c[70] = Course("4120324140","数字图像处理E",2);
                c[71] = Course("4120317130","云计算基础B",2);
                c[72] = Course("4120374170","软件安全",2);
                c[73] = Course("4120328140","软件过程与项目管理",2);
                c[74] = Course("4120085210","智能汽车互联技术",2);
                c[75] = Course("4120026110","计算机接口技术",2);
                c[76] = Course("4120388170","创新创业实践",2);
                c[77] = Course("4120316140","软件企业认知实习",3);
                c[78] = Course("4120389170","岗位实习B",6);
                c[79] = Course("4120123210","毕业设计",8);

                for (int i = 1; i < 80; ++i) {
                    cout<<"正在加载第"<<i<<"门课程..."<<endl;
                    courseGraph.addVertex(c[i]);
                }
                //英语
                courseGraph.addEdge(c[2],c[8]);
                courseGraph.addEdge(c[8],c[18]);
                courseGraph.addEdge(c[18],c[28]);

                courseGraph.addEdge(c[3],c[9]);
                courseGraph.addEdge(c[9],c[19]);
                courseGraph.addEdge(c[19],c[29]);

                courseGraph.addEdge(c[1],c[10]);
                courseGraph.addEdge(c[4],c[13]);
                courseGraph.addEdge(c[5],c[14]);
                courseGraph.addEdge(c[6],c[15]);
                courseGraph.addEdge(c[6],c[16]);
                courseGraph.addEdge(c[7],c[25]);
                courseGraph.addEdge(c[10],c[20]);
                courseGraph.addEdge(c[11],c[31]);
                courseGraph.addEdge(c[12],c[21]);
                courseGraph.addEdge(c[14],c[22]);
                courseGraph.addEdge(c[16],c[25]);
                courseGraph.addEdge(c[16],c[38]);
                courseGraph.addEdge(c[17],c[26]);
                courseGraph.addEdge(c[20],c[27]);
                courseGraph.addEdge(c[21],c[32]);
                courseGraph.addEdge(c[22],c[23]);
                courseGraph.addEdge(c[22],c[30]);
                courseGraph.addEdge(c[22],c[35]);
                courseGraph.addEdge(c[23],c[36]);
                courseGraph.addEdge(c[24],c[23]);
                courseGraph.addEdge(c[25],c[55]);
                courseGraph.addEdge(c[27],c[56]);
                courseGraph.addEdge(c[30],c[39]);
                courseGraph.addEdge(c[30],c[41]);
                courseGraph.addEdge(c[31],c[30]);
                courseGraph.addEdge(c[31],c[43]);
                courseGraph.addEdge(c[32],c[51]);
                courseGraph.addEdge(c[32],c[37]);
                courseGraph.addEdge(c[33],c[45]);
                courseGraph.addEdge(c[33],c[34]);
                courseGraph.addEdge(c[36],c[49]);
                courseGraph.addEdge(c[37],c[53]);
                courseGraph.addEdge(c[37],c[54]);
                courseGraph.addEdge(c[33],c[44]);
                courseGraph.addEdge(c[33],c[46]);
                courseGraph.addEdge(c[33],c[47]);
                courseGraph.addEdge(c[33],c[52]);
                courseGraph.addEdge(c[38],c[55]);
                courseGraph.addEdge(c[27],c[55]);
                courseGraph.addEdge(c[39],c[40]);
                courseGraph.addEdge(c[40],c[79]);
                courseGraph.addEdge(c[41],c[59]);
                courseGraph.addEdge(c[41],c[60]);
                courseGraph.addEdge(c[41],c[61]);
                courseGraph.addEdge(c[41],c[42]);
                courseGraph.addEdge(c[44],c[73]);
                courseGraph.addEdge(c[45],c[73]);
                courseGraph.addEdge(c[46],c[40]);
                courseGraph.addEdge(c[47],c[40]);
                courseGraph.addEdge(c[47],c[63]);
                courseGraph.addEdge(c[47],c[78]);
                courseGraph.addEdge(c[48],c[40]);
                courseGraph.addEdge(c[49],c[50]);
                courseGraph.addEdge(c[49],c[65]);
                courseGraph.addEdge(c[49],c[74]);
                courseGraph.addEdge(c[51],c[66]);
                courseGraph.addEdge(c[53],c[66]);
                courseGraph.addEdge(c[54],c[66]);
                courseGraph.addEdge(c[55],c[67]);
                courseGraph.addEdge(c[56],c[57]);
                courseGraph.addEdge(c[57],c[69]);
                courseGraph.addEdge(c[57],c[58]);
                courseGraph.addEdge(c[59],c[70]);
                courseGraph.addEdge(c[60],c[71]);
                courseGraph.addEdge(c[61],c[71]);
                courseGraph.addEdge(c[63],c[73]);
                courseGraph.addEdge(c[63],c[77]);
                courseGraph.addEdge(c[64],c[77]);
                courseGraph.addEdge(c[65],c[79]);
                courseGraph.addEdge(c[66],c[75]);
                courseGraph.addEdge(c[67],c[68]);
                courseGraph.addEdge(c[67],c[77]);
                courseGraph.addEdge(c[69],c[79]);
                courseGraph.addEdge(c[70],c[79]);
                courseGraph.addEdge(c[71],c[79]);
                courseGraph.addEdge(c[72],c[78]);
                courseGraph.addEdge(c[73],c[77]);
                courseGraph.addEdge(c[74],c[79]);
                courseGraph.addEdge(c[75],c[79]);
                courseGraph.addEdge(c[76],c[77]);
                courseGraph.addEdge(c[77],c[79]);

                cout<<"课程加载成功!"<<endl;
                break;
            }
            default: {
                cout<<"您输入的序号错误。";
                break;
            }
        }
    }catch (const exception& e){
        cout << e.what() << endl;
    }
    cout<<"------------------------------"<<endl;
}

//展示课程顺序图
void CourseManagement::ShowCourseGraph() {
    cout<<"\n----------查看课程信息----------"<<endl;
    try{
        cout<<"请选择操作(1-仅查看课程,2-查看课程与必须先修课程):";
        switch (inputInt()) {
            case 1:{
                cout<<"课程为:"<<endl;
                courseGraph.ShowAllCourse();
                break;
            }
            case 2:{
                cout<<"课程与其必须先修课程为:"<<endl;
                courseGraph.ShowAllCourseWithIndexAndFront();
                break;
            }
            default: {
                cout<<"您输入的序号错误。";
                break;
            }
        }
    }catch (const exception& e){
        cout << e.what() << endl;
    }
    cout<<"------------------------------"<<endl;
}

//信息修改，包括课程信息修改，边信息修改，边的增删，课程的增删
void CourseManagement::ChangeCourse() {
    cout<<"\n----------修改课程信息----------"<<endl;
    try{
        cout<<"请选择操作(1-删除课程,2-修改课程,3-删除课程链接):";
        switch (inputInt()) {
            case 1:{
                cout << "当前课程为:" << endl;
                courseGraph.ShowAllCourseWithIndex();
                cout << "删除该课程后，其所关联的所有课程链接均会被删除，要继续吗?(q-取消,任意-继续):";
                inputString();
                cout << "(1/1)请输入所要删除的课程序号:";
                int index = inputInt();
                courseGraph.deleteVertex(index);
                cout<<"删除成功!"<<endl;
                break;
            }
            case 2:{
                cout << "当前课程为:" << endl;
                courseGraph.ShowAllCourseWithIndex();
                cout << "(1/4)请输入所要修改的课程序号:";
                int index = inputInt();
                cout<<"所选课程为:"<<endl;
                Course c = courseGraph.ShowAndGetOne(index);
                cout << "(2/4)请输入修改后的课程编号(唯一编号，输入skip跳过修改):";
                string number = inputString();
                if (number != "skip"){
                    c.number = number;
                }
                cout << "(3/4)请输入修改后的课程名称(输入skip跳过修改):";
                string title = inputString();
                if (title != "skip"){
                    c.title = title;
                }
                cout << "(4/4)请输入修改后的课程学分(输入skip跳过修改):";
                string score = inputString();
                if (score != "skip"){
                    c.credit = doubleNumberTest(score);
                }
                courseGraph.changeVertex(index,c);
                cout<<"课程信息修改成功!"<<endl;
                break;
            }
            case 3:{
                cout << "当前课程与课程链接为:" << endl;
                courseGraph.ShowAllCourseWithIndexAndFront();
                cout << "(1/2)请输入所要删除的课程链接起始序号:";
                int start = inputInt();
                cout << "(2/2)请输入所要删除的课程链接终点序号:";
                int end = inputInt();
                courseGraph.deleteEdge(start,end);
                cout<<"课程链接删除成功!"<<endl;
                break;
            }
            default: {
                cout<<"您输入的序号错误。";
                break;
            }
        }
    }catch (const exception& e){
        cout << e.what() << endl;
    }
    cout<<"------------------------------"<<endl;
}

//拓扑排序
void CourseManagement::CourseInfo() {
    cout<<"\n----------课程信息拓扑排序----------"<<endl;
    try{
        cout<<"请选择操作(1-拓扑排序1,2-拓扑排序2):";
        switch (inputInt()) {
            case 1:{
                courseGraph.AOVNetTopologicalSorting1();
                cout<<"拓扑排序1结果为:"<<endl;
                courseGraph.ShowAOVLinkCourse();
                break;
            }
            case 2:{
                courseGraph.AOVNetTopologicalSorting1();
                cout<<"拓扑排序2结果为:"<<endl;
                courseGraph.ShowAOVLinkCourse();
                break;
            }
            default: {
                cout<<"您输入的序号错误。";
                break;
            }
        }
    }catch (const exception& e){
        cout << e.what() << endl;
    }
    cout<<"------------------------------"<<endl;
}

//退出
void CourseManagement::ExitApp() {
    cout<<"\n欢迎再次使用，再见。"<<endl;
}
