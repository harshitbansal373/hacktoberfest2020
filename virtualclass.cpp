#include<iostream>
using namespace std;

class student
{
    protected:
        int roll;
    public:
        void get_roll(int a)
        {
            roll = a;
        }
        void put_roll()
        {
            cout<<"Roll Number : "<<roll<<"\n";
        }
};

class test : virtual public student
{
    protected:
        float m1,m2;
    public:
        void get_marks(float x,float y)
        {
            m1 = x; m2 = y;
        }
        void put_marks()
        {
            cout<<"Marks Obtained : "<<"\n"
                <<"Part1 = "<<m1<<"\n"
                <<"Part2 = "<<m2<<"\n";
        }
};

class sports : virtual public student
{
    protected:
        float score;
    public:
        void get_score(float s)
        {
            score = s;
        }
        void put_score()
        {
            cout<<"Sports  = "<<score<<"\n";
        }
};

class result : public test, public sports
{
        float total;
    public:
        void display()
        {
            total = m1 + m2 + score;
            put_roll();
            put_marks();
            put_score();

            cout<<"Total Score : "<<total<<"\n";
        }
};

int main()
{
    result stud;
    stud.get_roll(22);
    stud.get_marks(49.6f,32.5f);
    stud.get_score(3.3f);
    stud.display();
    return 0;
}

