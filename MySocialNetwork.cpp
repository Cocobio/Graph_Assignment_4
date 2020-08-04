#include "MySocialNetwork.hpp"

// Creates a new user
void MySocialNetwork::new_profile(std::string p) {
	relations_graph.add_vertex(p);
}

// Delete a user, it will remove alse all the friendships
void MySocialNetwork::delete_profile(std::string p) {
	relations_graph.remove_vertex(p);
}

// Create a new friendship, and maybe a user (if user was not created before)
void MySocialNetwork::friending(std::string p1, std::string p2) {
	relations_graph.add_edge(p1, p2);
}

// Remove a friendship from the users p1 and p2.
void MySocialNetwork::unfriending(std::string p1, std::string p2) {
	relations_graph.remove_edge(p1, p2);
}

// Using DFS or BFS it searches for a user in the graphs. Starting the search on the first vertex on the container.
bool MySocialNetwork::find(std::string p, int m) {
	Graph::VertexFlagContainer color;

	void (Graph::* method)(string, Graph::VertexFlagContainer&);

	// Method that will use for the search
	if (m) method = relations_graph.dfs;
	else method = relations_graph.bfs;

	// The BFS and DFS are implemented for connected components
	// This will ensure that all the different connected components will get processed
	for (auto v = relations_graph.vertex_begin(); v!=relations_graph.vertex_end(); v++) {
		if (!color[v->first]) {
			(relations_graph.*method)(v->first, color);

			if(color.find(p)!=color.end()) return true;
		}
	}

	return false;
}

// By using a heap, it returns the n users with the most friendships
vector<pair<int, string>> MySocialNetwork::follow(int n) {
	vector<pair<int, string>> vertex_container, output;

	// Build the temporal container that will fasten the heap construction
	for (auto v = relations_graph.vertex_begin(); v!=relations_graph.vertex_end(); v++)
		vertex_container.emplace_back(v->second.size(), v->first);

	// Linear complexity
	priority_queue<pair<int, string>> rank(vertex_container.begin(), vertex_container.end());

	// output the n users with the most friendships (or followers)
	for(int i=0; i<n && !rank.empty(); i++) {
		output.push_back(rank.top());
		rank.pop();
	}

	return output;
}

// Gets a list of maximal cliques from the graph. Sorted in descending order.
vector<typename MySocialNetwork::Graph::AdjacencySet> MySocialNetwork::listing_comunities() {
	return relations_graph.listing_cliques();
}

// Printing function, it will show the vertexs and the connections for each one. On a list.
void MySocialNetwork::print() {
	for (auto it=relations_graph.vertex_begin(); it!=relations_graph.vertex_end(); it++) {
		std::cout << it->first << ":\t";

		for (auto &it2 : it->second)
			std::cout << it2 << " ";

		std::cout << std::endl;
	}
}

// Creates a compact version of the relations_graph and prints the edges using a BFS
void MySocialNetwork:: print_compact_bfs() {
	// naming function for the collapsed vertex
	auto naming_function = [](size_t i) { return std::string("Componente "+std::to_string(i+1)); };

	// Create the compacted version of the relations graph
	Graph compacted = relations_graph.compact(naming_function);
	
	// BFS
	std::queue<typename Graph::VertexId> q;
	typename Graph::VertexFlagContainer color;

	// This for is to support disconnected graphs. So it checks all the vertex
	for (auto it = compacted.vertex_begin(); it != compacted.vertex_end(); it++) {
		if (!color[it->first]) {
			q.push(it->first);

			// BFS algorithm
			while (!q.empty()) {
				auto v = q.front();
				q.pop();
				color[v] = true;

				// Check the neighborhood of v
				for (auto u_it = compacted.Nv_begin(v); u_it != compacted.Nv_end(v); u_it++)
					// If there is a vertex that hasn't been visited yet, print out the edge and push the vertex on the queue
					if (!color[*u_it]) {
						std::cout << "(" << v << ", " << *u_it << ")" << endl;
						q.push(*u_it);
					}
			}
		}
	}
}