#include "MyGraph.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void exec_opt(int opt, MyGraph<string> &graph) {
	string node_u, node_v, node;
	switch (opt) {
		case 1:
		cout << "Insert vertex: ";
		cin >> node;
		graph.add_vertex(node);
		break;
		
		case 2:
		cout << "Insert edge: ";
		cin >> node_u >> node_v;
		graph.add_edge(node_u, node_v);
		break;
		
		case 3:
		cout << "Vertex to be deleted: ";
		cin >> node;
		graph.remove_vertex(node);
		break;

		case 4:
		cout << "Edge to be deleted: ";
		cin >> node_u >> node_v;
		graph.remove_edge(node_u, node_v);
		break;

		case 5:
		cout << "printing graph:" << endl;
		graph.print();
		break;

		default:
		cout << "not valid" << endl;
	}
}

int main() {
	vector<string> options;
	options.push_back(string(".-Insert Node: "));
	options.push_back(string(".-Insert Edge: "));
	options.push_back(string(".-Delete Node: "));
	options.push_back(string(".-Delete Edge: "));
	options.push_back(string(".-Print graph: "));
	options.push_back(string(".-Exit"));
	int opt=0;
	
	MyGraph<string> social_net;
	for(int i=0; i<options.size(); i++)
		cout << i+1 << options[i] << endl;

	while (opt!=options.size()) {
		cin >> opt;
		exec_opt(opt, social_net);
	}
	
	return 0;
}