#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string usr_name;
    int num_tries,num_right;
    ofstream outfile("seq_data.txt",ios_base::app);//在输出模式中以追加模式打开文件“seq_data.txt”
    if(!outfile) cerr<<"Oops! Unable to save session data!";//（！outfile）表示如果outfile结果为false，cerr函数表示输出结果并无缓存
    else{
    outfile<<usr_name<<' '
    <<num_tries<<' '//中间有一个空格
    <<num_right<<endl;
    }
    ifstream infile("seq_data.txt");//以读取模式打开文件
    num_tries = 0;
    int num_cor = 0;
    if(!infile){}
    else{
        string name;
        int nt;
        int nc;
        while(infile>>name)//返回值为从infile读到的类对象
        {
            infile>>nt>>nc;
            if (name ==usr_name)
            {
                cout<<"Welcome back,"<<usr_name
                <<"\nYoour currentscore is "<<nc
                <<" out of"<< nt <<"\nGood Luck!\n";
            }
            
        }
    }
}