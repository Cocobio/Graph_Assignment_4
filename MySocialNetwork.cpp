#include "MySocialNetwork.hpp"

//
void MySocialNetwork::new_profile(std::string p) {
	relations_graph.add_vertex(p);
}

//
void MySocialNetwork::delete_profile(std::string p) {
	relations_graph.remove_vertex(p);
}

//
void MySocialNetwork::friending(std::string p1, std::string p2) {
	relations_graph.add_edge(p1, p2);
}

//
void MySocialNetwork::unfriending(std::string p1, std::string p2) {
	relations_graph.remove_edge(p1, p2);
}

//
bool MySocialNetwork::find(std::string p, int m) {
	unordered_map<std::string, bool> color;

	void (MyGraph<string>::* method)(string, unordered_map<string,bool>&);

	if (m) method = relations_graph.dfs;
	else method = relations_graph.bfs;

	for (auto v = relations_graph.vertex_begin(); v!=relations_graph.vertex_end(); v++) {
		if (!color[v->first]) {
			(relations_graph.*method)(v->first, color);

			if(color.find(p)!=color.end()) return true;
		}
	}

	return false;
}

//
vector<pair<size_t, string>> MySocialNetwork::follow(int n) {
	vector<pair<size_t, string>> vertex_container, output;

	for (auto v = relations_graph.vertex_begin(); v!=relations_graph.vertex_end(); v++)
		vertex_container.emplace_back(v->second.size(), v->first);

	struct MyComp {
		bool operator()( pair<size_t, string> const a, pair<size_t, string> const b )
		{ return a.first>b.first; }
	};

	// Couldn't use greater<> because the comparador was working weird with the pairs (some times gave me the wrong answer)
	priority_queue<pair<size_t, string>, vector<pair<size_t, string>>, MyComp> rank(vertex_container.begin(), vertex_container.end());

	for(int i=0; i<n && !rank.empty(); i++) {
		output.push_back(rank.top());
		rank.pop();
	}

	return output;
}

//
void MySocialNetwork::print() {
	relations_graph.print();	
}

