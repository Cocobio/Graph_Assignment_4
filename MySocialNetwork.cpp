#include "MySocialNetwork.hpp"

//
template<typename K> void MySocialNetwork<K>::new_profile(std::string p) {
	relations_graph.add_vertex(p);
}

//
template<typename K> void MySocialNetwork<K>::delete_profile(std::string p) {
	relations_graph.remove_vertex(p);
}

//
template<typename K> void MySocialNetwork<K>::friending(std::string p1, std::string p2) {
	relations_graph.add_edge(p1, p2);
}

//
template<typename K> void MySocialNetwork<K>::unfriending(std::string p1, std::stringp2) {
	relations_graph.remove_edge(p1, p2);
}

//
template<typename K> bool MySocialNetwork<K>::find(std::string p, int m=0) {
	unordered_map<std::string, bool> color;

	auto method = m ? relations_graph.dfs : relations_graph.bfs;

	for (auto v = relations_graph.vertex_begin(); v!=relations_graph.vertex_end(); v++) {
		if (!color[v]) {
			method(v, color);

			if(color.find(p)!=color.end()) return true;
		}
	}

	return false;
}


//
template<typename K> vector<pair<string,size_t>>& MySocialNetwork<K>::follow(int n) {
	vector<pair<string,size_t>> vertex_container;

	for (auto v = relations_graph.vertex_begin(); v!=relations_graph.vertex_end(); v++) {
		vertex_container.push_back(make_pair(v->first, v->second.size()));
	}

	sort(vertex_container.begin(), vertex_container.end(), greater<>);

	if (n<vertex_container.size()) vertex_container.resize(n);

	return vertex_container;
}
