#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>
int const n=1000;//定义的账户数组的个数
int number=0;//实际账户数
int num_n=0;//登录用户在数组中的位置数
using namespace std;
class ATM;
void main_menu();//主菜单
void secondary_menu();//次级菜单
void new_account(ATM atm[]);//新建账户
int login(ATM atm[]);//登录账号并进行一系列操作
void depoist(ATM atm[]);//存款
void balande_enquiry(ATM atm[]);//余额查询
void calculate_interest(ATM atm[]);//利息计算
float interest1(float mm,int y,int mo);//活期存款的利息计算
float interest2(float mm,int y,int mo);//定期存款的利息计算
float interest3(float mm,int y,int mo);//零存整取，整存零取，存整利息计算
void infile_account(ATM atm[]);
void outfile_account(ATM atm[]);
void make_zero();
class account//账户类  基类
{
public:
    account(){money=0;}
    string account_number;
    string password;
    string name;
    char sex;
    string address;
    string phone_number;
    string ID;
    float money;
};
class saving_account:virtual public account
{
public:
    void withdrawing1();

};
class credit_card:virtual public account
{
public:
    void withdrawing2();
};
class ATM:public saving_account,public credit_card
{
public:
    ATM()
    {
        type=1;
    }
    char type;
};
ATM atm[n];
void new_account(ATM atm[])//新建账户
{
    system("cls");
    string s1,s2;
    int flag=0;
    cout<<"请输入您的自定义账户:";
    cin>>atm[number].account_number;
    cout<<"请输入密码:";
    cin>>s1;
    cout<<"请再次输入密码:";
    do
    {
        cin>>s2;
        if(s1!=s2)
        {
            cout<<"密码输入有误，请重新输入:";
        }
        else
        {
            flag=1;
            atm[number].password=s1;
        }
    }
    while(flag!=1);
    cout<<"请选择账户类型:"<<endl;
    cout<<"1.储蓄账户"<<endl;
    cout<<"2.信用卡账户"<<endl;
    cin>>atm[num_n].type;
    cout<<"请输入您的姓名:";
    cin>>atm[number].name;
    cout<<"请输入您的性别（m/w）:";
    cin>>atm[number].sex;
    cout<<"请输入您的住址:";
    cin>>atm[number].address;
    cout<<"请输入您的联系方式:";
    cin>>atm[number].phone_number;
    cout<<"请输入您的身份证号:";
    cin>>atm[number].ID;
    number++;
    outfile_account(atm);
}
int login(ATM atm[])//登录账号并进行一系列操作
{
    system("cls");
    infile_account(atm);
    string s1,s2;
    int flag1=0,flag2=0,i=0,k=0;
    cout<<"请输入您的账号:";
    do
    {
        cin>>s1;
        for(k=0; k<=number; k++)
        {
            if(atm[k].account_number==s1)
            {
                flag1=1;
                num_n=k;
            }
        }
        if(k>number+1)
        {
            cout<<"此账号不存在！"<<endl;
            return 0;
        }
    }
    while(flag1!=1);
    cout<<"请输入密码:";
    do
    {
        cin>>s2;
        i++;
        if(atm[num_n].password!=s2&&i<=3)
        {
            cout<<"密码错误，请重新输入:";
        }
        else if(atm[num_n].password!=s2&&i>=4)
        {
            cout<<"输入密码错误次数达三次，请重新登录！"<<endl;
            return 0;
        }
        else
        {
            flag2=1;
        }
    }
    while(flag2!=1);
    return 1;
}
void depoist(ATM atm[])//存款
{
    system("cls");
    float dep;
    int flag=0;
    cout<<"请输入存款金额:";
    do
    {
        cin>>dep;
        if(dep<0)
        {
            cout<<"存入金额为负值，请重新输入:";
        }
        else
        {
            flag=1;
        }
    }
    while(flag!=1);
    atm[num_n].money+=dep;
    cout<<"您的账户余额为:"<<atm[num_n].money<<endl;
    cin.get();
}
void balande_enquiry(ATM atm[])//余额查询
{
    system("cls");
    cout<<"您的账户余额为:"<<atm[num_n].money<<endl;
    cin.get();
    cin.get();
}
void calculate_interest(ATM atm[])//利息计算
{
    system("cls");
    int num1,year,month;
    int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
    float mm;
    cout<<"*****************"<<endl;//利率表
    cout<<"现行利率如下:"<<endl;
    cout<<"活期存款：0.35%"<<endl;
    cout<<"整存整取："<<endl;
    cout<<"三个月：1.10%"<<endl;
    cout<<"半年：1.30%"<<endl;
    cout<<"一年：1.50%"<<endl;
    cout<<"两年：2.10%"<<endl;
    cout<<"三年及以上：2.75%"<<endl;
    cout<<"零存整取，整存零取，存整"<<endl;
    cout<<"一年：1.10%"<<endl;
    cout<<"三年：1.30%"<<endl;
    if(atm[num_n].type=='1')//储蓄账户的利率计算
    {
        cout<<"您的账户为储蓄账户，利息计算有以下选择:"<<endl;
        cout<<"*****************"<<endl;
        cout<<"1.活期存款"<<endl;
        cout<<"2.整存整取"<<endl;
        cout<<"3.零存整取，整存零取，存整"<<endl;
        cout<<"*****************"<<endl;
        cout<<"请输入你的选择:"<<endl;
        do
        {
            cin>>num1;
            if(num1!=1&&num1!=2&&num1!=3)
            {
                cout<<"输入错误，请重新输入:";
            }
            else
            {
                flag1=1;
            }
        }
        while(flag1!=1);
        cout<<"输入您要存储的金额:";
        do
        {
            cin>>mm;
            if(mm<0)
            {
                cout<<"输入金额小于0，请重新输入:";
            }
            else
            {
                flag2=1;
            }
        }
        while(flag2!=1);
        cout<<"输入您要存储的时间:";
        do
        {
            cout<<"年数:";
            cin>>year;
            cout<<"月数:";
            cin>>month;
            if(year<0||month<0||month>12)
            {
                cout<<"输入时间错误，请重新输入！"<<endl;
            }
            else
            {
                flag3=1;
            }
        }
        while(flag3!=1);
        switch(num1)
        {
        case 1:
        {
            cout<<mm<<"活期存储"<<year<<"年"<<month<<"月，利息为"<<interest1(mm,year,month)<<"元"<<endl;
            break;
        }
        case 2:
        {
            cout<<mm<<"定期存储"<<year<<"年"<<month<<"月，利息为"<<interest2(mm,year,month)<<"元"<<endl;
            break;
        }
        case 3:
        {
            cout<<mm<<"零存整取，整存零取，存整"<<year<<"年"<<month<<"月，利息为"<<interest3(mm,year,month)<<"元"<<endl;
            break;
        }
        }
    }
    else//信用卡账户的利息计算
    {
        cout<<"您的账户为银行卡账户，只能活期存款."<<endl;
        cout<<"输入您要存储的金额:";
        do
        {
            cin>>mm;
            if(mm<0)
            {
                cout<<"输入金额小于0，请重新输入:";
            }
            else
            {
                flag4=1;
            }
        }
        while(flag4!=1);
        cout<<"输入您要存储的时间:";
        do
        {
            cout<<"年数:";
            cin>>year;
            cout<<"月数:";
            cin>>month;
            if(year<0||month<0||month>12)
            {
                cout<<"输入时间错误，请重新输入！"<<endl;
            }
            else
            {
                flag5=1;
            }
        }
        while(flag5!=1);
        cout<<mm<<"活期存储"<<year<<"年"<<month<<"月，利息为"<<interest1(mm,year,month)<<"元"<<endl;
    }
    cin.get();
    cin.get();
}
float interest1(float mm,int y,int mo)//活期存款的利息计算
{
    float const p=0.0035;
    return mm*p*(y+mo/12.0);
}
float interest2(float mm,int y,int mo)//定期存款的利息计算
{
    float const p1=0.011;
    float const p2=0.013;
    float const p3=0.015;
    float const p4=0.021;
    float const p5=0.0275;
    if(y==0&&mo<6)
        return mm*p1*(mo/12.0);
    else if(y==0&&mo>=6&&mo<12)
        return mm*p2*(mo/12.0);
    else if(y==1&&mo>=0&&mo<12)
        return p3*mm*(y+mo/12.0);
    else if(y==2&&mo>=0&&mo<12)
        return p4*mm*(y+mo/12.0);
    else return p5*mm*(y+mo/12.0);
    }
float interest3(float mm,int y,int mo)//零存整取，整存零取，存整利息计算
{
    float const p1=0.011;
    float const p2=0.013;
    if(y<3)
        return mm*p1*(y+mo/12.0);
    else
        return mm*p2*(y+mo/12.0);
}
void saving_account::withdrawing1()//储蓄账户取款
{
    system("cls");
    float with;
    int flag=0;
    cout<<"请输入取款金额:";
    do
    {
        cin>>with;
        if(with>atm[num_n].money)
        {
            cout<<"您的账户余额不足，请重新输入:";
        }
        else if(with>50000)
        {
            cout<<"取款金额大于单日取款金额50000，请重新输入:";
        }
        else
        {
            flag=1;
        }
    }
    while(flag!=1);
    atm[num_n].money-=with;
    cout<<"您的账户余额为:"<<atm[num_n].money<<endl;
    cin.get();
}
void credit_card::withdrawing2()//信用卡账户取款
{
    system("cls");
    float with;
    float const Money=50000;
    int flag=0;
    cout<<"请输入取款金额:";
    do
    {
        cin>>with;
        if(with>Money+atm[num_n].money)
        {
            cout<<"透支超出最大限额50000，请重新输入:"<<endl;
        }
        else
        {
            flag=1;
        }
    }
    while(flag!=1);
    atm[num_n].money-=with;
    cout<<"您的账户余额为:"<<atm[num_n].money<<endl;
    cin.get();
}
void main_menu()//主菜单
{
    while(1)
    {
         system("cls");
        cout<<"******************"<<endl;
        cout<<"   1.新建账户"<<endl;
        cout<<"   2.登录账户"<<endl;
        cout<<"   3.退出系统"<<endl;
        cout<<"******************"<<endl;
        int num,flag=0;
        cout<<"请输入你的选择（数字编号）:";
        do
        {
            cin>>num;
            if(num!=1&&num!=2&&num!=3)
            {
                cout<<"输入错误！请重新输入."<<endl;
            }
            else
            {
                flag=1;
            }
        }
        while(flag!=1);
        switch(num)
        {
        case 1:
            new_account(atm);
            break;
        case 2:
        {
            if(!login(atm))
            {
                continue;
            }
            else
            {
                secondary_menu();
            }
            break;
        }
        }
        if(num==3)
        {
            outfile_account(atm);
            make_zero();
            return ;
        }
    }
}
void secondary_menu()//次级菜单
{
    while(1)
    {
        system("cls");
        cout<<"**********************"<<endl;
        cout<<"      1.存款"<<endl;
        cout<<"      2.取款"<<endl;
        cout<<"      3.余额查询"<<endl;
        cout<<"      4.利息计算"<<endl;
        cout<<"      5.退出账户"<<endl;
        cout<<"**********************"<<endl;
        int num,flag=0;
        cout<<"请输入你的选择（数字编号）:";
        do
        {
            cin>>num;
            if(num!=1&&num!=2&&num!=3&&num!=4&&num!=5)
            {
                cout<<"输入错误！请重新输入:"<<endl;
            }
            else
            {
                flag=1;
            }
        }
        while(flag!=1);
        switch(num)
        {
        case 1:
            depoist(atm);//存款
            break;
        case 2://取款
        {
            if(atm[num_n].type=='1')
            {
                atm[num_n].withdrawing1();//储蓄账户取款
            }
            else
            {
                atm[num_n].withdrawing2();//信用卡账户取款
            }
        }
        case 3:
            balande_enquiry(atm);//余额查询
            break;
        case 4:
            calculate_interest(atm);
            break;
        case 5:
            return ;
        }
    }
}
void outfile_account(ATM atm[])
{
    int i;
    ofstream outfile("ATM.dat",ios::out|ios::binary);
    if(!outfile)
    {
        cerr<<"打开文件失败"<<endl;
    }
    for(i=0; i<n; i++)
    {
        outfile.write((char*)&atm[i],sizeof(atm[i]));
    }
    outfile.close();
}
void infile_account(ATM atm[])
{
    int i;
    ifstream infile("ATM.dat",ios::binary);
    if(!infile)
    {
        cerr<<"打开文件失败"<<endl;
    }
    for(i=0; i<n; i++)
    {
        infile.read((char*)&atm[i],sizeof(atm[i]));
    }
    infile.close();
}
void make_zero()
{
    num_n=0;
}
int main()
{
     main_menu();
    return 0;
}
