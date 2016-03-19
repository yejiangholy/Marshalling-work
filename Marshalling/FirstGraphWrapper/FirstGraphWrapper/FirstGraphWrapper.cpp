// FirstGraphWrapper.cpp : main project file.

#include "stdafx.h"
#include "FirstGraphWrapper.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
    return 0;
}


GraphWrapper::FirstGraphWrapper::FirstGraphWrapper()
{
	a = new Node();
	std::string s5("First Work !");
	nodes = new std::list<Node>();
	myEdge = new Edge();
	myEdge->AddNode(*a);
	myEdge->changeWork(s5);
	works = gcnew String(s5.c_str());
}

std::string GraphWrapper::FirstGraphWrapper::GetWork()
{
	return myEdge->GetWork();
}

GraphWrapper::FirstGraphWrapper::FirstGraphWrapper(const std::string &work, std::list<Node> &nodelist)
{
	myEdge = new Edge(work,nodelist);
}


	
