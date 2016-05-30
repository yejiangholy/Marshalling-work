// Controler.h
#include <Windows.h> 
#include <string.h>
#include <vector>
#include <numeric>
#pragma once

using namespace System;

namespace Controler {

	extern "C" __declspec(dllexport) void createGraph(const char str[])
	{
		const char position3 = str[3*2];
		
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

	extern "C" __declspec(dllexport) void getOutPut( char *output, int length)
	{
	     char str[] = "sample output";
		 memcpy(output, str, strlen(str) + 1);
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
