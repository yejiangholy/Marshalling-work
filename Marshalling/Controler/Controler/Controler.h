// Controler.h
#include <Windows.h> 
#include <string.h>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <istream>
#include <streambuf>
#include <numeric>

#pragma once

using namespace System;

struct membuf : std::streambuf
{
	membuf(){}
};

namespace Controler {

	extern "C" __declspec(dllexport) void createGraph(char str[] , int size)
	{
		std::istringstream inputStream;
		std::string inputString = std::string(str);      
		for (int i = 1; i < 2*size; i++)
		{
			std::string next = std::string(str + i);
			inputString.append(next);
		}

		inputStream.str(inputString);  //put input data to inputStream 

	 // then give it to OGDF 

		char* buffer = new char[size]; //test weather we really put things inside this stream 
		inputStream.read(buffer, size); 

	}

	extern "C" __declspec(dllexport) void sendArrayOfString(char** strings, int count)
	{
		 char *first = strings[0];
		 char *second = strings[1];
		 char *third = strings[2];
	}
	
	extern "C" __declspec(dllexport) void sendArrayDouble(Double *doubles)
	{
		Double first = doubles[1];
		Double second = doubles[2];
		Double third = doubles[3];
		Double sum = first + second + third;
	}

	extern "C" __declspec(dllexport) void getOutPut( char *pointer, int length)
	{

		char output[] = "sample output";
		int size = sizeof(output);
		std::ostringstream outPutStream;
		outPutStream.str(output);         //create a mork output with some content 


		
		std::string getOutPut = outPutStream.str();  // get a string from output of OGDF 
		strcpy(pointer, getOutPut.c_str());  // copy it to pointer, which let C# side get it 

	}

	extern "C" __declspec(dllexport) void getArrayOfString(int *size, char *ArrayOfString)
	{
	    char *dayName[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
		memcpy(ArrayOfString, *dayName, sizeof(dayName));
		*size = sizeof(dayName)/4;
		
	}

	extern "C" __declspec(dllexport) void getDoulbes(int *count, double *values)
	{
		double doubles[] = { 1.1,2.2,3.3,4.4,5.5 };
		memcpy(values, doubles, sizeof(doubles));
		*count = sizeof(doubles) / 8;
	}


	public ref class Class1
	{
		 BOOL WINAPI DllMain(
			 HINSTANCE hinstDLL, 
			 DWORD fdwReason,     
			 LPVOID lpReserved)
		 {
			 switch (fdwReason)
			 {
			 case DLL_PROCESS_ATTACH:   
				 break;

			 case DLL_THREAD_ATTACH:
				 break;

			 case DLL_THREAD_DETACH:    
				 break;

			 case DLL_PROCESS_DETACH:
				 break;
			 }
			 return TRUE;
		 }


	};
}
