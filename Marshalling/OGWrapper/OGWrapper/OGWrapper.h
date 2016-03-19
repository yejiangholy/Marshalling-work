#pragma once
#include "ogdf/planarity/PlanarizationLayout.h"


namespace OGWrapp {

	public ref class OGWrapper
	{
		ogdf::PlanarizationLayout* pl;

	public:
		//public method 
		OGWrapper()
		{
			pl = new ogdf::PlanarizationLayout();
			G = new ogdf::Graph();
			*N1 = G->newNode(1);
			*N2 = G->newNode(2);
			*E = G->newEdge(*N1, *N2);
			GA = new ogdf::GraphAttributes(*G, 3L);
		}
		~OGWrapper() { this->!OGWrapper(); }
		!OGWrapper() { delete pl; }
		void call(ogdf::GraphAttributes ga) { pl->call(ga); }
		double X(ogdf::node v) { return GA->x(v); }
		double Y(ogdf::node v) { return GA->y(v); }
		double Z(ogdf::node v) { return GA->z(v); }

		//public variable 
		ogdf::Graph* G;
		ogdf::GraphAttributes* GA;
		ogdf::node* N1;
		ogdf::node* N2;
		ogdf::edge* E;
	};
}
 
