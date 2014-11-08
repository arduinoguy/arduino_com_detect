

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <SerialClass.h>	
#include <string>
#include <Windows.h>
#include <iostream>
#include <cstring>

using namespace std;


void main()
{
	printf("Welcome to the serial test app!\n\n");

	float number = 0;




	for (; number < 10; number++)
	{
		string xps = "COM";
		xps = xps + char(number + '0');
		const char * q = xps.c_str();
		char p[10];
		strcpy_s(p, 10, q);
		Serial* SP = new Serial(p);    

		

		char incomingData[256] = "";			
		int dataLength = 256;
		int readResult = 0;

		while (SP->IsConnected())
		{

		Sleep(1000);
		readResult = SP->ReadData(incomingData, dataLength);
		cout << "Hardware found"<<endl;
		if (readResult != -1)
		{
		
			string test(incomingData);

			test = "";
			if (strcmp(incomingData, "sdk") == 1)
			{
				cout << "Hardware found on " << xps << endl;
				break;
			}

		
			
		}
		
		}
		}
		
	}
	


