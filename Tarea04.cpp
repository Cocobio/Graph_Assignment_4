/*
todo:
	- Test find with disconex graphs
	- program clique finder
	- program compact
*/

#include "MySocialNetwork.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void exec_opt(int opt, MySocialNetwork &sn) {
	string node_u, node_v, node;
	vector<pair<size_t,string>> important_users;
	int n;

	switch (opt) {
		case 1:
		cout << "Insert vertex: ";
		cin >> node;
		sn.new_profile(node);
		break;
		
		case 2:
		cout << "Insert edge: ";
		cin >> node_u >> node_v;
		sn.friending(node_u, node_v);
		break;
		
		case 3:
		cout << "Vertex to be deleted: ";
		cin >> node;
		sn.delete_profile(node);
		break;

		case 4:
		cout << "Edge to be deleted: ";
		cin >> node_u >> node_v;
		sn.unfriending(node_u, node_v);
		break;

		case 5:
		cout << "printing graph:" << endl;
		sn.print();
		break;

		case 6:
		cout << "Profile to be found: ";
		cin >> node;
		cout << node << "found: " << sn.find(node) << endl;
		break;

		case 7:
		cout << "Insert number of top Profiles: ";
		cin >> n;
		important_users = sn.follow(n);
		for (auto it = important_users.rbegin(); it!=important_users.rend(); it++)
			cout << it->second << " with " << it->first << " connections" << endl;
		break;

		default:
		cout << "Exiting." << endl;
	}
}

int main() {
	vector<string> options;
	options.push_back(string(".-Insert Profile: "));
	options.push_back(string(".-Insert Friendship: "));
	options.push_back(string(".-Delete Profile: "));
	options.push_back(string(".-Delete Friendship: "));
	options.push_back(string(".-Print graph: "));
	options.push_back(string(".-Find Profile: "));
	options.push_back(string(".-Top n Profiles: "));
	options.push_back(string(".-Exit"));
	int opt=0;
	
	MySocialNetwork social_net;
	for(int i=0; i<options.size(); i++)
		cout << i+1 << options[i] << endl;

	while (opt!=options.size()) {
		cin >> opt;
		exec_opt(opt, social_net);
	}
	
	return 0;
}