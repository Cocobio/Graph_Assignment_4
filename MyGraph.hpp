/*
Author:
	Ignacio Osorio W.
	
Definition for a ADT graph.
	- Conex or disconex
	- Simple (no parallel edges)
*/

#ifndef MY_GRAPH
#define MY_GRAPH

#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>

template <typename K=std::string>
class MyGraph {
	public:
		typedef K		VertexId;

		typedef std::list<VertexId>								AdjacencyList;
		typedef std::unordered_map<VertexId, AdjacencyList>		Container;
		typedef typename Container::iterator				VertexIterator;
		typedef typename AdjacencyList::const_iterator			EdgeIterator;

	private:
		Container vertex;

	public:
		MyGraph();
		~MyGraph();

		void bfs(VertexId s, std::unordered_map<VertexId,bool>& color=std::unordered_map<VertexId,bool>());
		void dfs(VertexId s, std::unordered_map<VertexId,bool>& color=std::unordered_map<VertexId,bool>());

		size_t degree(VertexId v);

		// get_radius();
		// get_center();
		// get_diameter();

		// compact;
		// clique;

		void add_edge(VertexId u, VertexId v);
		void remove_edge(VertexId u, VertexId v);
		
		void add_vertex(VertexId v);
		void remove_vertex(VertexId v);

		void print();

		VertexIterator vertex_begin();
		VertexIterator vertex_end();

		EdgeIterator edge_begin(VertexId v);
		EdgeIterator edge_end(VertexId v);
};

// For linking error purposes
#include "MyGraph.cpp"

#endif