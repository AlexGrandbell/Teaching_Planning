//
// Created by 沈嘉瑞 on 2023.11.21.
//

#ifndef TEACHING_PLANNING_ALGRAPH_H
#define TEACHING_PLANNING_ALGRAPH_H

#include "Course.h"

//顶点数组节点
template<class T>
struct ALGraphSqNode{
    T data;//信息
    bool isDelete;//是否删除
    list<int> list;//前节点链表，记录的是下标
    ALGraphSqNode():data(),isDelete(false),list(){}
    ALGraphSqNode(T d):data(d),isDelete(false),list(){};

    bool operator==(const ALGraphSqNode& other) const {
        return data == other.data;
    }
};

//逆邻接表
template<class T>
class ALGraph{
private:
    int vNum = 0;//顶点个数
    int aNum = 0;//数组元素个数
    array<ALGraphSqNode<T>,MaxSize> vList;//邻接表的数组
    queue<int> AOVQueue;//展示的数组
public:
    ALGraph();
    int indexOfVertex(T t);
    void addVertex(T);//添加一个顶点,有重复检查
    void addEdge(T,T);//添加一条边，前与后节点
    void addEdge(int ,int );//添加一条边，前与后节点
    void deleteVertex(T);//删除一个顶点
    void deleteVertex(int );//删除一个顶点
    void deleteEdge(T ,T);//删除一条边
    void deleteEdge(int ,int);//删除一条边
    void changeVertex(T ,T);//修改一个顶点为另一个
    void changeVertex(int ,T);//修改一个顶点为另一个
    bool findVertex(T);//查找顶点
    bool findEdge(T,T);//查找边,这是没有int选项的
    bool findEdge(int ,int);//查找边
    int inOfVertex(T);//入度
    int inOfVertex(int);//入度
    void AOVNetTopologicalSorting1();//AOV网拓扑排序方法1
    void AOVNetTopologicalSorting2();//AOV网拓扑排序方法2
    void ShowAOVLinkCourse();//展示拓扑排序课
    void ShowOne(int );//展示一个课程
    T ShowAndGetOne(int );//展示一个课程并返回
    void ShowAllCourse();//普通显示
    void ShowAllCourseWithIndex();//普通有序号显示
    void ShowAllCourseWithIndexAndFront();//有序号+前驱显示
    void indexTest(int );//序号检测
    int getVNum();//未删除的总数

    bool hasLoop();//环检测
};

template<class T>
ALGraph<T>::ALGraph():vNum(0),aNum(0) {}

template<class T>
int ALGraph<T>::indexOfVertex(T t) {
    if (!findVertex(t)){
        throw NoFoundExpection("没有找到该课程，无需删除");
    }
    auto i = std::find(vList.begin(), vList.end(), t);
    int index = std::distance(vList.begin(),i);
    return index;
}

template<class T>
void ALGraph<T>::addVertex(T t){
    if (vNum >= MaxSize){
        throw SqFullExpection("已满，添加失败.");
    }
    if (findVertex(t)){
        throw AddSameExpection("重复添加，添加失败。");
    } else{
        vList[aNum++] = ALGraphSqNode(t);
        vNum++;
    }
}

template<class T>
void ALGraph<T>::addEdge(T t1, T t2) {
    if (!findVertex(t1) || !findVertex(t2)){
        throw NoFoundExpection("没有找到该课程，添加失败");
    }
    addEdge(indexOfVertex(t1), indexOfVertex(t2));
}

template<class T>
void ALGraph<T>::addEdge(int index1, int index2) {
    if (index2 == index1){
        throw AddSameExpection("课程不可自指。");
    }
    indexTest(index1);
    indexTest(index2);
    if (std::find(vList[index2].list.begin(), vList[index2].list.end(),index1) != vList[index2].list.end()){
        throw AddSameExpection("重复添加，添加失败。");
    }
    vList[index2].list.push_back(index1);
    if (hasLoop()){
        deleteEdge(index1,index2);
        throw AOVHasLoopException("出现了环，添加无效。");
    }
}

template<class T>
void ALGraph<T>::deleteVertex(T t) {
    if (!findVertex(t)){
        throw NoFoundExpection("没有找到该课程，无需删除");
    }
    deleteVertex(indexOfVertex(t));
}

template<class T>
void ALGraph<T>::deleteVertex(int index) {
    indexTest(index);
    //删除相关边
    for (int i = 0; i < vNum; ++i) {
        vList[i].list.remove(index);
    }
    vList[index].isDelete = true;
    vNum--;
}

template<class T>
void ALGraph<T>::deleteEdge(T t1,T t2) {
    if (!findVertex(t1) || !findVertex(t2)){
        throw NoFoundExpection("没有找到该课程，删除失败");
    }
    deleteEdge(indexOfVertex(t1), indexOfVertex(t2));
}

template<class T>
void ALGraph<T>::deleteEdge(int index1,int index2) {
    indexTest(index1);
    indexTest(index2);
    if (std::find(vList[index2].list.begin(), vList[index2].list.end(),index1) == vList[index2].list.end()){
        throw NoFoundExpection("没有找到该边，无需删除");
    }
    vList[index2].list.remove(index1);
}

template<class T>
void ALGraph<T>::changeVertex(T t1, T t2) {
    if (!findVertex(t1)){
        throw NoFoundExpection("没有找到该课程，修改失败");
    }
    changeVertex(indexOfVertex(t1),t2);
}

template<class T>
void ALGraph<T>::changeVertex(int index, T t) {
    indexTest(index);
    if (findVertex(t) && vList[index].data != t){
        throw AddSameExpection("课程编号重复，修改失败。");
    }
    vList[index].data = t;
}

template<class T>
bool ALGraph<T>::findVertex(T t) {
    auto i = std::find(vList.begin(), vList.end(), t);
    if (i == vList.end()){
        return false;
    }
    int index = std::distance(vList.begin(),i);
    if (vList[index].isDelete){
        return false;
    }
    return true;
}

template<class T>
bool ALGraph<T>::findEdge(T t1,T t2) {
    if (!findVertex(t1) || !findVertex(t2)){
        return false;
    }
    return findEdge(indexOfVertex(t1), indexOfVertex(t2));
}

template<class T>
bool ALGraph<T>::findEdge(int index1,int index2) {
    indexTest(index1);
    indexTest(index2);
    return std::find(vList[index2].list.begin(), vList[index2].list.end(),index1) != vList[index2].list.end();
}

template<class T>
int ALGraph<T>::inOfVertex(T t) {
    auto i = std::find(vList.begin(), vList.end(), t);
    if (i == vList.end()){
        throw NoFoundExpection("没有找到该课程。");
    }
    int index = std::distance(vList.begin(),i);
    return inOfVertex(index);
}

template<class T>
int ALGraph<T>::inOfVertex(int index) {
    indexTest(index);
    return vList[index].list.size();
}

template<class T>
void ALGraph<T>::AOVNetTopologicalSorting1() {
    while (!AOVQueue.empty()){
        AOVQueue.pop();
    }
    if (vNum == 0) {
        cout << "没有课程。" << endl;
    } else {
        array<ALGraphSqNode<T>, MaxSize> tmpVList = vList;
        int tmpVNum = vNum;
        int tmpANum = aNum;
        bool haveLoop = false;
        while (tmpVNum > 0) {
            haveLoop = true;
            for (int i = 0; i < tmpANum; ++i) {
                if (!tmpVList[i].isDelete && tmpVList[i].list.size() == 0) {
                    haveLoop = false;
                    AOVQueue.push(i);
                    //删除相关边
                    for (int j = 0; j < tmpANum; ++j) {
                        tmpVList[j].list.remove(i);
                    }
                    tmpVList[i].isDelete = true;
                    tmpVNum--;
                }
            }
            if (haveLoop) {
                throw AOVHasLoopException("存在环，无法构建AOV网。");
            }
        }
    }
}

template<class T>
void ALGraph<T>::AOVNetTopologicalSorting2() {
    while (!AOVQueue.empty()){
        AOVQueue.pop();
    }
    if (vNum == 0) {
        cout << "没有课程。" << endl;
    } else {
        array<ALGraphSqNode<T>, MaxSize> tmpVList = vList;
        int tmpVNum = vNum;
        int tmpANum = aNum;
        bool haveLoop = false;
        while (tmpVNum > 0) {
            haveLoop = true;
            for (int i = 0; i < tmpANum; ++i) {
                if (!tmpVList[i].isDelete && tmpVList[i].list.size() == 0) {
                    haveLoop = false;
                    AOVQueue.push(i);
                    //删除相关边
                    for (int j = 0; j < tmpANum; ++j) {
                        tmpVList[j].list.remove(i);
                    }
                    tmpVList[i].isDelete = true;
                    tmpVNum--;
                    break;
                }
            }
            if (haveLoop) {
                throw AOVHasLoopException("存在环，无法构建AOV网。");
            }
        }
    }
}

template<class T>
bool ALGraph<T>::hasLoop() {
    if (vNum == 0) {
        return false;
    } else {
        array<ALGraphSqNode<T>, MaxSize> tmpVList = vList;
        int tmpVNum = vNum;
        int tmpANum = aNum;
        bool haveLoop = false;
        while (tmpVNum > 0) {
            haveLoop = true;
            for (int i = 0; i < tmpANum; ++i) {
                if (!tmpVList[i].isDelete && tmpVList[i].list.size() == 0) {
                    haveLoop = false;
                    //删除相关边
                    for (int j = 0; j < tmpANum; ++j) {
                        tmpVList[j].list.remove(i);
                    }
                    tmpVList[i].isDelete = true;
                    tmpVNum--;
                    break;
                }
            }
            if (haveLoop) {
                return true;
            }
        }
    }
    return false;
}

template<class T>
void ALGraph<T>::ShowAOVLinkCourse() {
    int num = 0;
    while (!AOVQueue.empty()){
        cout<<"第"<< setw(3) << left << ++num <<"门: "<<vList[AOVQueue.front()].data<< endl;
        AOVQueue.pop();
    }
}

template<class T>
void ALGraph<T>::ShowAllCourse() {
    if (vNum==0){
        throw NoFoundExpection("没有课程。");
    } else {
        for (int i = 0; i < vNum; ++i) {
            if (!vList[i].isDelete) {
                cout << vList[i].data << endl;
            }
        }
    }
}

template<class T>
void ALGraph<T>::ShowAllCourseWithIndex() {
    if (vNum==0){
        throw NoFoundExpection("没有课程。");
    } else {
        for (int i = 0; i < vNum; ++i) {
            if (!vList[i].isDelete) {
                cout << "序号:" << setw(4) << left << i << vList[i].data << endl;
            }
        }
    }
}

template<class T>
void ALGraph<T>::ShowAllCourseWithIndexAndFront() {
    if (vNum==0){
        throw NoFoundExpection("没有课程。");
    } else {
        for (int i = 0; i < vNum; ++i) {
            if (!vList[i].isDelete) {
                cout << "序号:" << setw(4) << left << i << vList[i].data<< endl;
                cout<<"相邻需先修课程序号为:";
                if (vList[i].list.empty()){
                    cout<<"无";
                } else {
                    for (int index: vList[i].list) {
                        cout << index << " ";
                    }
                }
                cout<<"\n"<<endl;
            }
        }
    }
}

template<class T>
void ALGraph<T>::ShowOne(int index) {
    try {
        indexTest(index);
        cout<<vList[index].data<< endl;
    }catch (const SqIExpection& e){
        throw SqIExpection("该课程不存在。");
    }
}

template<class T>
T ALGraph<T>::ShowAndGetOne(int index) {
    try {
        indexTest(index);
        cout<<vList[index].data<< endl;
        return vList[index].data;
    }catch (const SqIExpection& e){
        throw SqIExpection("该课程不存在。");
    }
}

template<class T>
void ALGraph<T>::indexTest(int index) {
    if (index<0 || index>=vNum || vList[index].isDelete){
        throw SqIExpection("序号下标错误。");
    }
}

template<class T>
int ALGraph<T>::getVNum() {
    return vNum;
}

#endif //TEACHING_PLANNING_ALGRAPH_H
