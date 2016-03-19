#pragma once
#include <string>
#include <list>

	 struct Node
	{ 
		double X;
		double y;
		int num;
	};
	 class Edge
	{
		public :
		std::string Work;
		std::list<Node> NodeList;
		Edge();

	public:
		Edge(const std::string &work, std::list<Node> &nodelist)
		{
			this->Work = work;
			this->NodeList = nodelist;
		}

		std::string GetWork() { return Work; }
		std::list<Node>GetNodeList() { return NodeList; }

		 int NodeNum();
		 void AddNode(Node &node);
		 void changeWork(std::string &work);
		 std::string showWork();
		
		
	};
