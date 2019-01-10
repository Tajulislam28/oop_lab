#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    string birthday;

public:
    Person (){}
    Person(string input_name,string input_birthday)
    {
        name = input_name;
        birthday=input_birthday;


    }


    string getName()
    {
        return name;
    }

     string getBirthday()
    {
        return birthday;
    }

};
class Student : public Person
{
private:
    int id;


public:

    Student (){}
    Student(string name,string birthday ,int input_id) : Person(name,birthday)
    {
        id = input_id;
    }

    int getId()
    {
        return id;
    }
};

class Teacher : public Person
{
private:
    int id;


public:

    Teacher () {}
    Teacher(string name,string birthday,int input_id) : Person(name,birthday)
    {
        id = input_id;
    }

    int getId()
    {
        return id;
    }
};


class Society_Member : public Student
{
private:
    string title;
    int marks = 0;

public:


    Society_Member () {}
    Society_Member(string name,string birthday,int id,string title) : Student(name,birthday,id)
    {
        this->title = title;
    }

    void operator+(int number)
    {
        marks+=number;
    }
    string getTitle()
    {
        return title;
    }
    void showMarks()
    {
        cout<<marks<<endl;
    }
};

int countVote(string name)
{
    cout<<"\nEnter the likeness (range from 1 to 5) for "<<name<<" : ";
    int number;
    cin>>number;
    while(1)
    {
        if(number<=5 and number>0) return number;
        else
        {
            cout<<"Invalid likeness number\n";
            cout<<"\nEnter the (valid)likeness (range from 1 to 5) for "<<name<<" : ";
            cin>>number;
        }

    }

}

int main()
{
    Student student[5]=
    {
        Student("Tajul","01-12-1996",11508028),
        Student("rafiq","01-12-1997",11508038),
        Student("shuvo","01-12-1998",11508027),
        Student("jamil","01-12-1995",11508045),
        Student("rakib","01-12-1995",11508046),
    };
    cout<<"Here are the 5 selected student, they will vote.\n\n";

    for( int i=0; i<5; i++) cout<<student[i].getId() <<". "<<student[i].getName()<<endl;

    Teacher teachers[3] =
    {
        Teacher("Kamal Hossain Chowdhury","01-12-1982",1),
        Teacher("Mahmudul Hasan","01-12-1980",2),
        Teacher("Faisal Bin Abdul Aziz","01-12-1985",3),
    };
    cout<<"Here are the Teachers, they will vote.\n\n";
    for( int i=0; i<3; i++) cout<<teachers[i].getId() <<". "<<teachers[i].getName()<<endl;

    Society_Member members[3]=
        {
            Society_Member("jisu das","01-12-1993",1,"VP"),
            Society_Member("Nahid Iqbal","01-12-1994",2,"GS"),
            Society_Member("Shaheen Nizam","01-12-1995",3,"AGS"),

        };


    cout<<endl<<"Vote of the Students"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<endl<<"Voting of student "<<student[i].getId()<<" "<<student[i].getName()<<"."<<endl;

        for(int i=0;i<3;i++)
        {
            cout<<"Vote for Society member "<< members[i].getId()<<" "<<members[i].getName()<<" ( "<<members[i].getTitle()<<" )"<<endl;
            int a= countVote(members[i].getName());
            members[i] + a;
        }


    }

    cout<<endl<<"Vote of the Teachers"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<endl<<"Voting of teacher "<<teachers[i].getId()<<" "<<teachers[i].getName()<<"."<<endl;

        for(int i=0;i<3;i++)
        {
            cout<<"Vote for Society member "<< members[i].getId()<<" "<<members[i].getName()<<" ( "<<members[i].getTitle()<<" )"<<endl;
            int a= countVote(members[i].getName());
            members[i] + a;
        }


    }
  cout<<endl<<"Final Votes of Society members"<<endl;
    for(int i=0; i<3; i++)
        {
            cout<<members[i].getName() <<" = ";
            members[i].showMarks();
        }



    return 0;

}

