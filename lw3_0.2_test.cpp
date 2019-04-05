#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

struct results
{
    string surname, name;
    vector <int> hwm;
    int examm;
};

int main()
{
    vector <results> students;
    results results;
    ifstream student_list;
    student_list.open("student_list - Copy.txt");

    if(!student_list.is_open())
    {
        cerr<<"Error Opening File"<<endl;
        exit(EXIT_FAILURE);
    }

    while(!student_list.eof())
    {
        student_list>>results.surname;
        student_list>>results.name;

        for(int i=0; i<5; i++)
        {
            int mark;
            student_list>>mark;
            results.hwm.push_back(mark);
        }
        student_list>>results.examm;
        cout<<results.surname<<" "<<results.name<<" "<<results.examm<<endl;
        students.push_back(results);
    }
    student_list.close();

for(unsigned int i=0; i<students.size(); i++)
    {
        cout<<endl;
        cout<<students[i].surname<<setw(15)<<cout.fill(' ')<<right<<students[i].name<<setw(15)<<cout.fill(' ')<<right;
        cout<<endl;
    }

return 0;
}
