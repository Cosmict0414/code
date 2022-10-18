#include <stdio.h>

//通过class关键字类定义类,相较于C中的结构体，类中的元素可以是函数
class Student{
public:
    //类包含的变量
    char *name;
    int age;
    float score;
    //类包含的函数
    void say(){
        printf("%s的年龄是 %d,成绩是 %f\n", name, age, score);
    }
};
/*类中对函数的定义也可以用
    void Student::say(){
        cout<<name<<"的年龄是"<<age<<"，成绩是"<<score<<endl;
    }
    的形式进行定义，其中“::”被称为域解析符，用来连接类名和函数名，指明函数所属的类

    一般建议为在类中声明函数，在类外定义函数
*/

int main(){
    //通过类来定义变量，即创建对象,C中的对象=CPP中的对象
    class Student stu1;  //也可以省略关键字class
    //为类的成员变量赋值
    stu1.name = "小明";
    stu1.age = 15;
    stu1.score = 92.5f;
    //调用类的成员函数
    stu1.say();
    Student *pStu = new Student;//new的作用和C语言中的malloc相同，但new在堆上创建的对象是匿名的，必须使用指针指向它才能进行访问和修改
    pStu->name = "小明";
    pStu->age = 15;
    pStu->score = 92.5f;
    pStu->say();
    delete pStu;
    return 0;
}