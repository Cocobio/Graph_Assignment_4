/*
Author:
	Ignacio Osorio W.
	
Definition for a ADT graph.
	- It allows 
*/

#ifndef MY_GRAPH
#define MY_GRAPH

#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>

template <typename K>
class MyGraph {
	public:
		typedef K		VertexId;

		typedef std::list<VertexId>								AdjacencyList;
		typedef std::unordered_map<VertexId, AdjacencyList>		Container;

	private:
		Container vertex;

	public:
		MyGraph();
		~MyGraph();

		// bfs;
		// dfs;

		// get_radius();
		// get_center();
		// get_diameter();

		// compact;
		// follow;
		// clique;
		// find;

		void add_edge(VertexId u, VertexId v);
		void remove_edge(VertexId u, VertexId v);
		
		void add_vertex(VertexId v);
		void remove_vertex(VertexId v);

		void print();
};

#endif