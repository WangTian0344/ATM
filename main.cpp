#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>
int const n=1000;//������˻�����ĸ���
int number=0;//ʵ���˻���
int num_n=0;//��¼�û��������е�λ����
using namespace std;
class ATM;
void main_menu();//���˵�
void secondary_menu();//�μ��˵�
void new_account(ATM atm[]);//�½��˻�
int login(ATM atm[]);//��¼�˺Ų�����һϵ�в���
void depoist(ATM atm[]);//���
void balande_enquiry(ATM atm[]);//����ѯ
void calculate_interest(ATM atm[]);//��Ϣ����
float interest1(float mm,int y,int mo);//���ڴ�����Ϣ����
float interest2(float mm,int y,int mo);//���ڴ�����Ϣ����
float interest3(float mm,int y,int mo);//�����ȡ��������ȡ��������Ϣ����
void infile_account(ATM atm[]);
void outfile_account(ATM atm[]);
void make_zero();
class account//�˻���  ����
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
void new_account(ATM atm[])//�½��˻�
{
    system("cls");
    string s1,s2;
    int flag=0;
    cout<<"�����������Զ����˻�:";
    cin>>atm[number].account_number;
    cout<<"����������:";
    cin>>s1;
    cout<<"���ٴ���������:";
    do
    {
        cin>>s2;
        if(s1!=s2)
        {
            cout<<"����������������������:";
        }
        else
        {
            flag=1;
            atm[number].password=s1;
        }
    }
    while(flag!=1);
    cout<<"��ѡ���˻�����:"<<endl;
    cout<<"1.�����˻�"<<endl;
    cout<<"2.���ÿ��˻�"<<endl;
    cin>>atm[num_n].type;
    cout<<"��������������:";
    cin>>atm[number].name;
    cout<<"�����������Ա�m/w��:";
    cin>>atm[number].sex;
    cout<<"����������סַ:";
    cin>>atm[number].address;
    cout<<"������������ϵ��ʽ:";
    cin>>atm[number].phone_number;
    cout<<"�������������֤��:";
    cin>>atm[number].ID;
    number++;
    outfile_account(atm);
}
int login(ATM atm[])//��¼�˺Ų�����һϵ�в���
{
    system("cls");
    infile_account(atm);
    string s1,s2;
    int flag1=0,flag2=0,i=0,k=0;
    cout<<"�����������˺�:";
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
            cout<<"���˺Ų����ڣ�"<<endl;
            return 0;
        }
    }
    while(flag1!=1);
    cout<<"����������:";
    do
    {
        cin>>s2;
        i++;
        if(atm[num_n].password!=s2&&i<=3)
        {
            cout<<"�����������������:";
        }
        else if(atm[num_n].password!=s2&&i>=4)
        {
            cout<<"�������������������Σ������µ�¼��"<<endl;
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
void depoist(ATM atm[])//���
{
    system("cls");
    float dep;
    int flag=0;
    cout<<"����������:";
    do
    {
        cin>>dep;
        if(dep<0)
        {
            cout<<"������Ϊ��ֵ������������:";
        }
        else
        {
            flag=1;
        }
    }
    while(flag!=1);
    atm[num_n].money+=dep;
    cout<<"�����˻����Ϊ:"<<atm[num_n].money<<endl;
    cin.get();
}
void balande_enquiry(ATM atm[])//����ѯ
{
    system("cls");
    cout<<"�����˻����Ϊ:"<<atm[num_n].money<<endl;
    cin.get();
    cin.get();
}
void calculate_interest(ATM atm[])//��Ϣ����
{
    system("cls");
    int num1,year,month;
    int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
    float mm;
    cout<<"*****************"<<endl;//���ʱ�
    cout<<"������������:"<<endl;
    cout<<"���ڴ�0.35%"<<endl;
    cout<<"������ȡ��"<<endl;
    cout<<"�����£�1.10%"<<endl;
    cout<<"���꣺1.30%"<<endl;
    cout<<"һ�꣺1.50%"<<endl;
    cout<<"���꣺2.10%"<<endl;
    cout<<"���꼰���ϣ�2.75%"<<endl;
    cout<<"�����ȡ��������ȡ������"<<endl;
    cout<<"һ�꣺1.10%"<<endl;
    cout<<"���꣺1.30%"<<endl;
    if(atm[num_n].type=='1')//�����˻������ʼ���
    {
        cout<<"�����˻�Ϊ�����˻�����Ϣ����������ѡ��:"<<endl;
        cout<<"*****************"<<endl;
        cout<<"1.���ڴ��"<<endl;
        cout<<"2.������ȡ"<<endl;
        cout<<"3.�����ȡ��������ȡ������"<<endl;
        cout<<"*****************"<<endl;
        cout<<"���������ѡ��:"<<endl;
        do
        {
            cin>>num1;
            if(num1!=1&&num1!=2&&num1!=3)
            {
                cout<<"�����������������:";
            }
            else
            {
                flag1=1;
            }
        }
        while(flag1!=1);
        cout<<"������Ҫ�洢�Ľ��:";
        do
        {
            cin>>mm;
            if(mm<0)
            {
                cout<<"������С��0������������:";
            }
            else
            {
                flag2=1;
            }
        }
        while(flag2!=1);
        cout<<"������Ҫ�洢��ʱ��:";
        do
        {
            cout<<"����:";
            cin>>year;
            cout<<"����:";
            cin>>month;
            if(year<0||month<0||month>12)
            {
                cout<<"����ʱ��������������룡"<<endl;
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
            cout<<mm<<"���ڴ洢"<<year<<"��"<<month<<"�£���ϢΪ"<<interest1(mm,year,month)<<"Ԫ"<<endl;
            break;
        }
        case 2:
        {
            cout<<mm<<"���ڴ洢"<<year<<"��"<<month<<"�£���ϢΪ"<<interest2(mm,year,month)<<"Ԫ"<<endl;
            break;
        }
        case 3:
        {
            cout<<mm<<"�����ȡ��������ȡ������"<<year<<"��"<<month<<"�£���ϢΪ"<<interest3(mm,year,month)<<"Ԫ"<<endl;
            break;
        }
        }
    }
    else//���ÿ��˻�����Ϣ����
    {
        cout<<"�����˻�Ϊ���п��˻���ֻ�ܻ��ڴ��."<<endl;
        cout<<"������Ҫ�洢�Ľ��:";
        do
        {
            cin>>mm;
            if(mm<0)
            {
                cout<<"������С��0������������:";
            }
            else
            {
                flag4=1;
            }
        }
        while(flag4!=1);
        cout<<"������Ҫ�洢��ʱ��:";
        do
        {
            cout<<"����:";
            cin>>year;
            cout<<"����:";
            cin>>month;
            if(year<0||month<0||month>12)
            {
                cout<<"����ʱ��������������룡"<<endl;
            }
            else
            {
                flag5=1;
            }
        }
        while(flag5!=1);
        cout<<mm<<"���ڴ洢"<<year<<"��"<<month<<"�£���ϢΪ"<<interest1(mm,year,month)<<"Ԫ"<<endl;
    }
    cin.get();
    cin.get();
}
float interest1(float mm,int y,int mo)//���ڴ�����Ϣ����
{
    float const p=0.0035;
    return mm*p*(y+mo/12.0);
}
float interest2(float mm,int y,int mo)//���ڴ�����Ϣ����
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
float interest3(float mm,int y,int mo)//�����ȡ��������ȡ��������Ϣ����
{
    float const p1=0.011;
    float const p2=0.013;
    if(y<3)
        return mm*p1*(y+mo/12.0);
    else
        return mm*p2*(y+mo/12.0);
}
void saving_account::withdrawing1()//�����˻�ȡ��
{
    system("cls");
    float with;
    int flag=0;
    cout<<"������ȡ����:";
    do
    {
        cin>>with;
        if(with>atm[num_n].money)
        {
            cout<<"�����˻����㣬����������:";
        }
        else if(with>50000)
        {
            cout<<"ȡ������ڵ���ȡ����50000������������:";
        }
        else
        {
            flag=1;
        }
    }
    while(flag!=1);
    atm[num_n].money-=with;
    cout<<"�����˻����Ϊ:"<<atm[num_n].money<<endl;
    cin.get();
}
void credit_card::withdrawing2()//���ÿ��˻�ȡ��
{
    system("cls");
    float with;
    float const Money=50000;
    int flag=0;
    cout<<"������ȡ����:";
    do
    {
        cin>>with;
        if(with>Money+atm[num_n].money)
        {
            cout<<"͸֧��������޶�50000������������:"<<endl;
        }
        else
        {
            flag=1;
        }
    }
    while(flag!=1);
    atm[num_n].money-=with;
    cout<<"�����˻����Ϊ:"<<atm[num_n].money<<endl;
    cin.get();
}
void main_menu()//���˵�
{
    while(1)
    {
         system("cls");
        cout<<"******************"<<endl;
        cout<<"   1.�½��˻�"<<endl;
        cout<<"   2.��¼�˻�"<<endl;
        cout<<"   3.�˳�ϵͳ"<<endl;
        cout<<"******************"<<endl;
        int num,flag=0;
        cout<<"���������ѡ�����ֱ�ţ�:";
        do
        {
            cin>>num;
            if(num!=1&&num!=2&&num!=3)
            {
                cout<<"�����������������."<<endl;
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
void secondary_menu()//�μ��˵�
{
    while(1)
    {
        system("cls");
        cout<<"**********************"<<endl;
        cout<<"      1.���"<<endl;
        cout<<"      2.ȡ��"<<endl;
        cout<<"      3.����ѯ"<<endl;
        cout<<"      4.��Ϣ����"<<endl;
        cout<<"      5.�˳��˻�"<<endl;
        cout<<"**********************"<<endl;
        int num,flag=0;
        cout<<"���������ѡ�����ֱ�ţ�:";
        do
        {
            cin>>num;
            if(num!=1&&num!=2&&num!=3&&num!=4&&num!=5)
            {
                cout<<"�����������������:"<<endl;
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
            depoist(atm);//���
            break;
        case 2://ȡ��
        {
            if(atm[num_n].type=='1')
            {
                atm[num_n].withdrawing1();//�����˻�ȡ��
            }
            else
            {
                atm[num_n].withdrawing2();//���ÿ��˻�ȡ��
            }
        }
        case 3:
            balande_enquiry(atm);//����ѯ
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
        cerr<<"���ļ�ʧ��"<<endl;
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
        cerr<<"���ļ�ʧ��"<<endl;
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
