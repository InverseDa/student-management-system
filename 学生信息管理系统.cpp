// 学生信息管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。


#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>

#define FILENAME "studentfile.txt"

using namespace std;

const int MAXN = 1000;

/****************************以下为类的定义*****************************/
/**********************************************************************/
//类 学生
class Student {
public:
    string name;
    int sex;    //1为男，2为女
    int age;
    int grade;  //1表示高一，2表示高二，3表示高三
    int score;  //评级，满分为100
    string phoneNumber;
    string teacher;
    string addr;    //地址
};

//类 学生信息档案
class Books {
public:
    Student stuArray[MAXN];
    //学生人数
    int size;
};


/****************************以下为函数的定义*****************************/
/***********************************************************************/

//显示菜单
void showMenu() {
    cout << "*********************************" << endl;
    cout << "*****欢迎使用学生信息管理系统****" << endl;
    cout << "********* 【1】添加学生 *********" << endl;
    cout << "********* 【2】显示学生 *********" << endl;
    cout << "********* 【3】删除学生 *********" << endl;
    cout << "********* 【4】查找学生 *********" << endl;
    cout << "********* 【5】修改学生 *********" << endl;
    cout << "********* 【6】清空学生 *********" << endl;
    cout << "********* 【7】学生排序 *********" << endl;
    cout << "********* 【8】退出系统 *********" << endl;
    cout << "*********************************" << endl;
}

//添加学生
void addStu(Books* abs) {
    //判断档案是否满了
    if (abs->size == MAXN) {
        cout << "档案满了，无法继续添加学生" << endl;
        cout << "若要继续添加，请删除学生或清空学生" << endl;
        return;
    }
    //添加学生
    else {

        //1.姓名
        string name;
        cout << "请输入姓名：";
        cin >> name;
        abs->stuArray[abs->size].name = name;

        //2.性别
        int sex = 0;
        cout << "注意：使用1表示男性，2表示女性，请规范输入！"<<endl;
        cout << "请输入性别：";
        
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->stuArray[abs->size].sex = sex;
                break;
            }
            else {
                cout << "请规范输入！" << endl;
            }
        }

        //3.年龄
        int age;
        cout << "请输入年龄：";
        cin >> age;
        abs->stuArray[abs->size].age = age;

        //4.年级
        int grade;
        cout << "注意：使用1表示高一，2表示高二，3表示高三，请规范输入！" << endl;
        cout << "请输入年级：";
        while (true) {
            cin >> grade;
            if (grade == 1 || grade == 2 || grade == 3) {
                abs->stuArray[abs->size].grade = grade;
                break;
            }
            else {
                cout << "请规范输入！" << endl;
            }
        }

        //5.评级
        int score;
        cout << "请输入该学生的评级（满分为100分）：";
        cin >> score;
        abs->stuArray[abs->size].score = score;

        //6.电话号码
        string phoneNumber;
        cout << "请输入学生的联系电话：";
        cin >> phoneNumber;
        abs->stuArray[abs->size].phoneNumber = phoneNumber;

        //7.班主任
        string teacher;
        cout << "请输入班主任姓名：";
        cin >> teacher;
        abs->stuArray[abs->size].teacher = teacher;

        //8.家庭住址
        string addr;
        cout << "请输入学生的家庭住址：";
        cin >> addr;
        abs->stuArray[abs->size].addr = addr;

        //最后进行人数更新
        abs->size++;
        
        cout << "添加成功！"<< endl;


        //调用stdlib.h函数
        system("pause");    //暂停
        system("cls");  //清屏
    }
}

//显示学生
void showStu(Books* abs) {
    //判断档案人数是否为0
    if (abs->size == 0) {
        cout << "当前人数为空"<<endl;
    }
    else {
        for (int i = 0; i < abs->size; i++) {
            cout << "姓名： " << abs->stuArray[i].name << " ";
            cout << "性别： " << (abs->stuArray[i].sex == 1 ? "男" : "女") << " ";
            cout << "年龄： " << abs->stuArray[i].age << " ";
            cout << "年级： ";
            if (abs->stuArray[i].grade == 1)
                cout << "高一";
            else if (abs->stuArray[i].grade == 2)
                cout << "高二";
            else
                cout << "高三";
            cout << " ";
            cout << "评级： " << abs->stuArray[i].score << " ";
            cout << "电话号码： " << abs->stuArray[i].phoneNumber << " ";
            cout << "班主任姓名： " << abs->stuArray[i].teacher << " ";
            cout << "家庭住址： " << abs->stuArray[i].addr << endl;
        }
    }

    //调用stdlib.h函数
    system("pause");    //暂停
    system("cls");  //清屏
}

//检测学生是否存在，存在返回数组下标，不存在返回-1
int isExist(Books* abs, string name) {
    for (int i = 0; i < abs->size; i++) {
        if (abs->stuArray[i].name == name) {
            return i;   //找到了，返回数组下标
        }
    }
    return -1;  //如果没找到，返回-1
}

//删除学生
void deleteStu(Books* abs) {
    cout << "请输入你要删除的学生：";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1) {
        cout << "学生档案中并不存在此人" << endl;
    }
    else {
        for (int i = ret; i < abs->size; i++) {
            //数据前移
            abs->stuArray[i] = abs->stuArray[i + 1];
        }
        abs->size--;    //更新人数
        cout << "删除成功！" << endl;
    }

    //调用stdlib.h函数
    system("pause");    //暂停
    system("cls");  //清屏
}

//查找学生
void findStu(Books* abs) {
    cout << "请输入你要查找的学生：";
    string name;
    cin >> name;
    int i = isExist(abs, name);
    if (i == -1) {
        cout << "学生档案中并不存在此人" << endl;
    }
    else {
        cout << "姓名： " << abs->stuArray[i].name << " ";
        cout << "性别： " << (abs->stuArray[i].sex == 1 ? "男" : "女") << " ";
        cout << "年龄： " << abs->stuArray[i].age << " ";
        cout << "年级： ";
        if (abs->stuArray[i].grade == 1)
            cout << "高一";
        else if (abs->stuArray[i].grade == 2)
            cout << "高二";
        else
            cout << "高三";
        cout << " ";
        cout << "评级： " << abs->stuArray[i].score << " ";
        cout << "电话号码： " << abs->stuArray[i].phoneNumber << " ";
        cout << "班主任姓名： " << abs->stuArray[i].teacher << " ";
        cout << "家庭住址： " << abs->stuArray[i].addr << endl;
    }

    //调用stdlib.h函数
    system("pause");    //暂停
    system("cls");  //清屏
}

//修改学生信息
void modifyStu(Books* abs) {
    cout << "请输入你要修改的学生：";
    string name;
    cin >> name;
    int i = isExist(abs, name);
    if (i == -1) {
        cout << "学生档案中并不存在此人" << endl;
    }
    else {

        //1.姓名
        cout << "请输入姓名：";
        cin >> name;
        abs->stuArray[i].name = name;

        //2.性别
        int sex = 0;
        cout << "注意：使用1表示男性，2表示女性，请规范输入！" << endl;
        cout << "请输入性别：";

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->stuArray[i].sex = sex;
                break;
            }
            else {
                cout << "请规范输入！" << endl;
            }
        }

        //3.年龄
        int age;
        cout << "请输入年龄：";
        cin >> age;
        abs->stuArray[i].age = age;

        //4.年级
        int grade;
        cout << "注意：使用1表示高一，2表示高二，3表示高三，请规范输入！" << endl;
        cout << "请输入年级：";
        while (true) {
            cin >> grade;
            if (grade == 1 || grade == 2 || grade == 3) {
                abs->stuArray[i].grade = grade;
                break;
            }
            else {
                cout << "请规范输入！" << endl;
            }
        }

        //5.评级
        int score;
        cout << "请输入该学生的评级（满分为100分）：";
        cin >> score;
        abs->stuArray[i].score = score;

        //6.电话号码
        string phoneNumber;
        cout << "请输入学生的联系电话：";
        cin >> phoneNumber;
        abs->stuArray[i].phoneNumber = phoneNumber;

        //7.班主任
        string teacher;
        cout << "请输入班主任姓名：";
        cin >> teacher;
        abs->stuArray[i].teacher = teacher;

        //8.家庭住址
        string addr;
        cout << "请输入学生的家庭住址：";
        cin >> addr;
        abs->stuArray[i].addr = addr;

        cout << "修改成功！" << endl;
    }

    //调用stdlib.h函数
    system("pause");    //暂停
    system("cls");  //清屏
}

//清空学生
void cleanStu(Books* abs) {
    abs->size = 0;
    cout << "清空成功！" << endl;

    //调用stdlib.h函数
    system("pause");    //暂停
    system("cls");  //清屏
}

//评级排序
/*void sortStu(Books* abs) {
    if (abs->size == 0) {
        cout << "当前人数为空！" << endl;
    }
    else {
        sort(abs->stuArray->score, abs->stuArray->score + abs->size);
        cout << "排序成功！";
    }
    
    //调用stdlib.h函数
    system("pause");    //暂停
    system("cls");  //清屏
}*/

//I/O流写入文件（保存学生信息—>学生信息.txt）
void save(Books *abs){
    ofstream ofs;
    ofs.open(FILENAME, ios::out);   //用输出方式打开文件

    //将每个学生的数据写入到文件中
    for (int i = 0; i < abs->size; i++) {
        ofs << abs->stuArray[i].name << " "
            << abs->stuArray[i].sex << " "
            << abs->stuArray[i].age << " "
            << abs->stuArray[i].grade << " "
            << abs->stuArray[i].score << " "
            << abs->stuArray[i].phoneNumber << " "
            << abs->stuArray[i].teacher << " "
            << abs->stuArray[i].addr << " " << endl;
    }


    //关闭文件
    ofs.close();
}


/********************************主函数**********************************/
/***********************************************************************/

int main()
{
    //创建信息档案结构
    Books abs;
    //人数初始化为0
    abs.size = 0;
    
    //选择变量
    int select = 0;

    //用户输入
    while (true) {
        //菜单显示
        showMenu();
        cin >> select;
        switch (select) {
            case 1: {
                addStu(&abs);
                save(&abs);
                break;
            } 
            case 2: 
                showStu(&abs);
                break;
            case 3: 
                deleteStu(&abs);
                break;
            case 4: 
                findStu(&abs);
                break;
            case 5: 
                modifyStu(&abs);
                break;
            case 6: 
                cleanStu(&abs);
                break;
            case 7: {
                cout << "该功能在维护中！" << endl;

                //调用stdlib.h函数
                system("pause");    //暂停
                system("cls");  //清屏

                break;
            } 
            case 8: 
                cout << "欢迎下次使用本系统" << endl;
                return 0;
        }
    }
    return 0;
}


