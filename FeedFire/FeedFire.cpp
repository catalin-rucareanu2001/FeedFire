// FeedFire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdlib.h>  
#include <stdio.h>  
#include <time.h> 
#include<algorithm>

using namespace std;

vector<float> RandWood(int n, int v, int k)
{
	// Print n random value.  
	int i;
	vector <float> vals;
	for (i = 0; i < n; i++)
	{
		vals.push_back(rand() % v + k+rand()%10/10.0);
	}
	cout << endl;
	cout << endl;
	return vals;
}
//generate rand values for caloric capacity

vector <float> RemoveWood(vector<float> wood, int k)
{
	wood.erase(wood.begin()+k);
	return wood;
}
//removes a piece of wood from vector

void ShowWood(vector<float> wood)
{
	cout << "wood: ";
	for (int i = 0; i < wood.size(); i++)
	{
		cout << wood.at(i) << " ";
	}
}
//prints the wood from vector

vector<float> TakeWood( vector<float> wood, float Capacity)
{
	vector<float> taken;
	for (int i = 0; i < wood.size(); i++)
	{
		if (Capacity-wood.at(i)/2.3>0)
		{
			Capacity -= wood.at(i) * 1.5;
			taken.push_back(wood.at(i));
		}
	}
	return taken;
}
//moves wood in hand to take home

vector<float> ProduceWood(float Capacity)
{
	vector<float> wood;
	wood = RandWood(10, 18, 2);  //generate 10 wood from weight 2 to weight 20
	return TakeWood(wood, Capacity);
}
//automates the rand and take wood

vector<float> AddWood(vector<float> t, vector<float> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		t.push_back(a.at(i));
	}
	return t;
}
//is push_back but with vectors

 void NewTemp(float *t, float *ot, vector<float> *wood, float d,float n)
{
	 vector<float> w;
	 w = *wood;
	 sort(w.begin(), w.end(), greater<float>());
	*t = (2 * *ot + *t) / 3;
	*ot = *t - d;
	while (*t<n)
	{
		if (w.size()>0)
		{
			*t += (w).at(0);
			w = RemoveWood(w, 0);
		}
		else
		{
			break;
		}
		
	}
	*wood = w;
	cout <<endl<< w.size() << "\n wood left \n";
	if (w.size()>0)
	{
		ShowWood(w);
	}
	cout << endl;
}
//calculate the new temperature

int main()
{
	int cycles = 0,maxCycles=50,randomVal;
	float maxCap = 20, temp = 20, decrease=3, nededTemp=15, outsideTemp=10,bodyTemp=38.5;
	vector<float> taken;

	cout << "What is the max capacity to carry?\n";
	cin >> maxCap;
	cout << "What is the initial bonefire temp?\n";
	cin >> temp;
	cout << "What is the decrease temp?\n";
	cin >> decrease;
	cout << "What is the needed temp to survive?\n";
	cin >> nededTemp;
	cout << "What is the outside temp?\n";
	cin >> outsideTemp;
	cout << "What is the max cycles number?\n";
	cin >> maxCycles;
	cout << "\nTemperature:" << temp;
	
	
	while (true)
	{
		cycles++;
		
		randomVal = rand() % 100 + 1;
		if (randomVal<=100-100/(maxCycles*2/3)*cycles)
		{
			if (taken.size() <= 10)
			{
				taken = AddWood(taken, ProduceWood(maxCap));
			}
		}
		ShowWood(taken);
		cout << endl;

		NewTemp(&temp, &outsideTemp, &taken,decrease,nededTemp);

		cout << "\nTemperature:" << temp<<endl;

		if (cycles>=maxCycles)
		{
			
			//
			cout << "(" << temp << "*7.5+" << bodyTemp << "*2.5)/10=" << (temp * 7.5 + bodyTemp * 2.5) / 10.0<<endl;
			bodyTemp = (temp * 7.5 + bodyTemp * 2.5) / 10.0;
			cout << "\n\nYou survived!\n body temp: "  <<bodyTemp <<endl;
			if (bodyTemp < 35)
			{
				if (bodyTemp < 32)
				{
					if (bodyTemp < 28)
					{
						if (bodyTemp < 20)
						{
							if (bodyTemp < 14)
							{
								cout << "\nBut you suffered from Deep Hypothermia\n";
								return 0;
							}
							cout << "\nBut you suffered from Profound Hypothermia\n";
							return 0;
						}
						cout << "\nBut you suffered from Severe Hypothermia\n";
						return 0;
					}
					cout << "\nBut you suffered from Moderate Hypothermia\n";
					return 0;
				}
				cout << "\nBut you suffered from Mild Hypothermia\n";
				return 0;
			}
			return 0; 
		}

		if (temp<=0)
		{
			cout << "\n\nYou froze to death!\n";
			return 0;
		}
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
