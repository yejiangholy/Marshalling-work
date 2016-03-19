#include "FirstGraphLib.h"

#include <stdexcept> 

  int Edge::NodeNum()
{
	return (NodeList.size()+7);
}
  Edge::Edge() {
	  Work = " ";
	  NodeList = std::list<Node>();
  }
  void Edge::AddNode(Node &node)
  {
	  NodeList.push_back(node);
  }

  void Edge::changeWork(std::string &work)
  {
	  Work = work;
  }

  std::string Edge::showWork()
  {
	  return Work; 
  }
