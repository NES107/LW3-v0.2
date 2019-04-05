#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>


using namespace std;

struct results
{
    string surname;
    string name;
    vector <float> hwm;
    float examm;
    float average;
    float fpointsa;
    float fpointsm;
};

void random(struct results *results);
void mean(struct results *results);
void median(struct results *results);
void output(vector <results> students);

int main()
{
vector <results> students;
results results;

int path;
cout<<"1 - manual mark input/random value generation"<<endl<<"2 - file output"<<endl;
cin>>path;
int path1;
if(path==1)
    {
        cout<<"1 - manual mark input"<<endl<<"2 - random value generation"<<endl;
        cin>>path1;

        char choice1='y';
        while(choice1!='n')
            {
                cout<<"Enter surname: ";
                cin>>results.surname;
                cout<<"Enter name: ";
                cin>>results.name;
                if(path1==1)
                {
                    char choice2 ='y';
                        while(choice2!='n')
                        {
                            float hw;
                            cout<<"Enter HW mark "<<results.hwm.size()+1<<": ";
                            cin>>hw;
                            results.hwm.push_back (hw);
                            cout<<"Add mark (y/n)?: ";
                            cin>>choice2;
                        }
                    cout<<"Enter EXAM mark: ";
                    cin>>results.examm;
                    cout<<endl;
                }
                else if(path1==2)random(&results);
                else cout<<"Error in input"<<endl;

                mean(&results);
                median(&results);
                results.hwm.resize(0);
                students.push_back (results);
                cout<<"Add student "<<students.size()+1<<"(y/n)?: ";
                cin>>choice1;
            }
    }
else if(path==2)
    {
        ifstream student_list;
        student_list.open("student_list.txt");
        if(!student_list.is_open())
        {
            cerr<<"Error Opening File"<<endl;
            exit(EXIT_FAILURE);
        }
        student_list.ignore( 1000, '\n' );
        while(!student_list.eof())
        {
            student_list>>results.surname;
            student_list>>results.name;
            for(int i=0; i<5; i++)
            {
                float mark;
                student_list>>mark;
                results.hwm.push_back(mark);
            }
        student_list>>results.examm;
        mean(&results);
        median(&results);
        results.hwm.resize(0);
        students.push_back (results);
        }
    student_list.close();
    }
else cout<<"Error in input"<<endl;

output(students);

return 0;
}

void random(struct results *results)
{
    int randd;
    for(int i=0;i<5;i++)
    {
        randd=rand()%10+1;
        results->hwm.push_back(randd);
    }
    results->examm = rand()%10+1;
}

void mean(struct results *results)
{
    results->average = accumulate(results->hwm.begin(),results->hwm.end(),0.0)/results->hwm.size();
    results->fpointsa = results->examm*0.6+results->average*0.4;
}

void median(struct results *results)
{
    if (results->hwm.size()%2!=0) results->fpointsm = 0.4*results->hwm[results->hwm.size()/2]+0.6*results->examm;
    else results->fpointsm = 0.4*((results->hwm[results->hwm.size()/2-1] + results->hwm[results->hwm.size()/2])/2)+0.6*results->examm;
}

void output(vector <results> students)
{
    cout<<endl<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.) / Final points (Med.)"<<endl;
    for(int i=0; i<82; i++)cout<<"-";
    cout<<endl;
    for(unsigned int i=0; i<students.size(); i++)
    {
        cout<<students[i].surname<<setw(22-students[i].surname.size())<<cout.fill(' ')<<right<<
        students[i].name<<setw(26-students[i].name.size())<<cout.fill(' ')<<right;
        printf("%.2f",students[i].fpointsa);
        cout<<setw(18)<<cout.fill(' ')<<left;
        printf("%.2f\n",students[i].fpointsm);
    }
}
