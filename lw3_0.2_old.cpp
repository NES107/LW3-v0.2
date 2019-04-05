#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main(){
    	string surname[100], name[100],first;
    	int m[5][100],ex[100],x=0;
		double avg[100], med[100];
		 ifstream fin ("studentai.txt");
		 getline(fin,first);
		while (!fin.eof())
        {
        fin>>surname[x]>>name[x];
        fin>>m[0][x]>>m[1][x]>>m[2][x]>>m[3][x]>>m[4][x]>>ex[x];
        avg[x] = 0.4 * (m[0][x]+m[1][x]+m[2][x]+m[3][x]+m[4][x])/5 + 0.6 * ex[x];
        
        for(int d = 1; d < 5; ++d)
	{
		for(int r = 0; r < 5-d; r++)
		{
			if(m[r][x] >= m[r+1][x])
			{
				int temp = m[r][x];
				m[r][x] = m[r+1][x];
				m[r+1][x] = temp;
			}
		}
	}
		med [x]= m[2][x];
		x++;
}
    cout<<"Surname"<<setw(5)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<right<<"Final points (Avg.)   /  Final points (Med.)"<<endl;
    for(int i=0; i<90; i++)
		cout<<"-";
	cout<<endl;
	
    for(int i=0; i<x-1; i++){
        cout<<surname[i]<<setw(15)<<cout.fill(' ')<<name[i]<<setw(15)<<cout.fill(' ')<<setprecision(3)<<setw(4)<<avg[i]<<setw(20)<<cout.fill(' ')<<setprecision(3)<<setw(4)<<med[i]<<endl;

    }
	fin.close();
    return 0;
}

