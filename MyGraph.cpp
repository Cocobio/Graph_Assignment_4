#include "MyGraph.hpp"

// Constructor
template <typename K> MyGraph<K>::MyGraph() {
	
}

// Destructor
template <typename K> MyGraph<K>::~MyGraph() {
	
}

// Breast First Search algorithm
template <typename K> std::unordered_map<typename MyGraph<K>::VertexId,bool>& MyGraph<K>::bfs(VertexId s, std::unordered_map<VertexId,bool> color) {
	std::queue<VertexId> q;

	q.push(s);

	while (!q.empty()) {
		VertexId current = q.front();
		q.pop();

		if (!color[current]) {
			color[current] = true;

			for (auto &v : vertex.find(current)->second)
				q.push(v);
		}
	}

	return color;
}

// Depth First Search algorithm
template <typename K> std::unordered_map<typename MyGraph<K>::VertexId,bool>& MyGraph<K>::dfs(VertexId s, std::unordered_map<VertexId,bool> color) {
	std::stack<VertexId> q;

	q.push(s);

	while (!q.empty()) {
		VertexId current = q.top();
		q.pop();

		if(!color[current]) {
			color[current] = true;

			for (auto &v : vertex.find(current)->second)
				q.push(v);
		}
	}

	return color;
}

// Get the degree of a vertex v
template <typename K> size_t MyGraph<K>::degree(VertexId v) {
	auto v_data = vertex.find(v);

	if (v_data == vertex.end()) return 0;
	return v_data->second.size();
}


// Adding an edge, if one of the vertex doesn't exist it will create the vertex
// The edge will be created only if the edge doesn't exist
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

	// Create edge if not presented and its not a self loop
	auto tmp = find(v_vertex->second.begin(), v_vertex->second.end(), u);
	if (tmp == v_vertex->second.end() && u!=v) {
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

template <typename K> typename MyGraph<K>::VertexIterator MyGraph<K>::vertex_begin() {
	return vertex.cbegin();
}

template <typename K> typename MyGraph<K>::VertexIterator MyGraph<K>::vertex_end() {
	return vertex.cend();
}

template<typename K> typename MyGraph<K>::EdgeIterator MyGraph<K>::edge_begin(VertexId v) {
	return vertex.find(v)->second.cbegin();
}

template<typename K> typename MyGraph<K>::EdgeIterator MyGraph<K>::edge_end(VertexId v) {
	return vertex.find(v)->second.cend();	
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

// void DummyFunc() {
// 	MyGraph<string> string_graph;
// 	string_graph.add_vertex(string("A"));
// 	string_graph.add_vertex(string("B"));
// 	string_graph.add_edge(string("A"), string("B"));
// 	string_graph.remove_edge("A", "B");
// 	string_graph.remove_vertex("A");
// 	string_graph.remove_vertex("B");
// 	string_graph.print();
// }