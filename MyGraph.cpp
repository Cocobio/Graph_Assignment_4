#include "MyGraph.hpp"

// Constructor
template <typename K> MyGraph<K>::MyGraph() {
	
}

// Destructor
template <typename K> MyGraph<K>::~MyGraph() {
	
}

template <typename K> void MyGraph<K>::add_edge(VertexId u, VertexId v) {
	auto u_vertex = vertex.find(u);
	auto v_vertex = vertex.find(v);

	if (u_vertex == vertex.end()) {
		add_vertex(u);
		u_vertex = vertex.find(u);
	}
	if (v_vertex == vertex.end()) {
		add_vertex(v);
		v_vertex = vertex.find(v);
	}


	// Create edge if not presented
	auto tmp = find(v_vertex->second.begin(), v_vertex->second.end(), u);
	if (tmp == v_vertex->second.end()) {
		v_vertex->second.push_back(u);
		u_vertex->second.push_back(v);
	}
}

template <typename K> void MyGraph<K>::remove_edge(VertexId u, VertexId v) {
	auto u_vertex = vertex.find(u);
	auto v_vertex = vertex.find(v);

	// If one of the vertex is not on the container, then just return
	if (u_vertex == vertex.end() || v_vertex == vertex.end()) {
		return;
	}


	// Create edge if not presented
	auto u_in_v = find(v_vertex->second.begin(), v_vertex->second.end(), u);
	auto v_in_u = find(u_vertex->second.begin(), u_vertex->second.end(), v);

	v_vertex->second.erase(u_in_v);
	u_vertex->second.erase(v_in_u);
}

template <typename K> void MyGraph<K>::add_vertex(VertexId v) {
	if (vertex.find(v) == vertex.end())
		vertex.emplace(v, AdjacencyList());
}

template <typename K> void MyGraph<K>::remove_vertex(VertexId v) {
	auto v_vertex = vertex.find(v);

	if (v_vertex != vertex.end()) {
		// Remove edges that are contained
		for (auto &N_i : v_vertex->second) {
			AdjacencyList *list_ref = &vertex.find(N_i)->second;
			auto it = find(list_ref->begin(), list_ref->end(), v);
			list_ref->erase(it);
		}

		// Remove from reference table and vertex list
		vertex.erase(v);
	}
}

//////////////////////////// TMP ////////////////////////////

#include <iostream>
#include <string>

using namespace std;

template <typename K> void MyGraph<K>::print() {
	for (auto &it : vertex) {
		cout << it.first << ":\t";
		for (auto &it2 : it.second)
			cout << it2 << " ";
		cout << endl;
	}
}

static void DummyFunc() {
	MyGraph<string> string_graph;
	string_graph.add_vertex(string("A"));
	string_graph.add_vertex(string("B"));
	string_graph.add_edge(string("A"), string("B"));
	string_graph.remove_edge("A", "B");
	string_graph.remove_vertex("A");
	string_graph.remove_vertex("B");
	string_graph.print();
}