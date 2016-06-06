// Touch.h
#include <sstream>
#include <iostream>

#include "ogdf/planarity/PlanarizationLayout.h"
#include "ogdf/planarity/SubgraphPlanarizer.h"
#include "ogdf/planarity/VariableEmbeddingInserter.h"
#include "ogdf/planarity/FastPlanarSubgraph.h"
#include "ogdf/planarlayout/PlanarStraightLayout.h"
#include "ogdf/orthogonal/OrthoLayout.h"
#include "ogdf/fileformats/GraphIO.h"
#include "ogdf/planarity/EmbedderMinDepth.h"
#include "ogdf/planarity/EmbedderMaxFace.h"
#pragma once

using namespace System;

namespace Touch {

	std::ostringstream outPutStream;
	extern "C" __declspec(dllexport) void createGraph(double arg1, double arg2, int arg3, char str[], int size)
	{
		std::istringstream inputStream;
		std::string inputString = std::string(str);
		for (int i = 1; i < 2 * size; i++)
		{
			std::string next = std::string(str + i);
			inputString.append(next);
		}

		inputStream.str(inputString);  //put input data to inputStream 

		// then give it to OGDF 

		ogdf::Graph G;
		ogdf::GraphAttributes GA(G,
			ogdf::GraphAttributes::nodeGraphics |
			ogdf::GraphAttributes::edgeGraphics |
			ogdf::GraphAttributes::nodeLabel |
			ogdf::GraphAttributes::edgeStyle |
			ogdf::GraphAttributes::nodeStyle |
			ogdf::GraphAttributes::nodeTemplate);

		ogdf::GraphIO::readGML(GA, G, inputStream);

		ogdf::node v;
		forall_nodes(v, G){ // iterate through all the node in the graph
			GA.shape(v) = ogdf::Shape::shEllipse;
		}
		ogdf::PlanarizationLayout pl;
		ogdf::SubgraphPlanarizer *crossMin = new ogdf::SubgraphPlanarizer;
		ogdf::FastPlanarSubgraph *ps = new ogdf::FastPlanarSubgraph;
		ps->runs(100);
		ogdf::VariableEmbeddingInserter *ves = new ogdf::VariableEmbeddingInserter;
		ves->removeReinsert(ogdf::rrAll);
		crossMin->setSubgraph(ps);
		crossMin->setInserter(ves);
		ogdf::EmbedderMaxFace *emb = new ogdf::EmbedderMaxFace;
		pl.setEmbedder(emb);
		ogdf::OrthoLayout *ol = new ogdf::OrthoLayout;

		ol->cOverhang(arg1);
		ol->bendBound(arg3);
		ol->separation(arg2);
		pl.setPlanarLayouter(ol);

		pl.call(GA);

		ogdf::GraphIO::writeGML(GA, outPutStream);
	}

	extern "C" __declspec(dllexport) void getOutPut(char *pointer, int length)
	{

		std::string getOutPut = outPutStream.str();  // get a string from output of OGDF 
		strcpy(pointer, getOutPut.c_str());  // copy it to pointer, which let C# side get it 
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
