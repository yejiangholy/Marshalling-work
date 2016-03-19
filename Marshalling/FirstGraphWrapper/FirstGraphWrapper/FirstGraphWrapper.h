#pragma once
#include "FirstGraphLib.h"
#include "FirstGraphLib.cpp"
namespace GraphWrapper {
	public ref class FirstGraphWrapper
	{
		Edge* myEdge;

	public:
		FirstGraphWrapper();
		FirstGraphWrapper(const std::string &work, std::list<Node> &nodelist);
		~FirstGraphWrapper()
		{
			this->!FirstGraphWrapper();
		}
		!FirstGraphWrapper() { delete myEdge; }
		int NodeNum() {
			return myEdge->NodeNum();
		}
		void AddNode(Node &node)
		{
			myEdge->AddNode(node);
		}
		void changeWork(std::string &work)
		{
			myEdge->changeWork(work);
		}

		
		std::string ShowWork()
		{
			return myEdge->showWork();
		}

		 std::string GetWork();
	

		

		//public variable here !! 
		Node* a; 
		std::list<Node>* nodes;
		System::String ^works;

	};
}

