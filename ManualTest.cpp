/*
Menu type for testing the implementation of the different needed functions for 
the social network assignment.

*/

#ifndef MANUAL_TEST
#define MANUAL_TEST

#include <vector>
#include <utility>
#include "MySocialNetwork.hpp"
#include "MyGraph.hpp"
#include <string>

using namespace std;

// Parse the input into the testing functions
void exec_opt(int opt, MySocialNetwork &social_net) {
	string node_u, node_v, node;
	vector<pair<int,string>> important_users;
	vector<MyGraph<string>::AdjacencySet> cliques;

	int n;

	switch (opt) {
		case 1:
		cout << "Insert vertex: ";
		cin >> node;
		social_net.new_profile(node);
		break;
		
		case 2:
		cout << "Insert edge: ";
		cin >> node_u >> node_v;
		social_net.friending(node_u, node_v);
		break;
		
		case 3:
		cout << "Vertex to be deleted: ";
		cin >> node;
		social_net.delete_profile(node);
		break;

		case 4:
		cout << "Edge to be deleted: ";
		cin >> node_u >> node_v;
		social_net.unfriending(node_u, node_v);
		break;

		case 5:
		cout << "printing graph:" << endl;
		social_net.print();
		break;

		case 6:
		cout << "Profile to be found: ";
		cin >> node;
		cout << node << "found: " << social_net.find(node) << endl;
		break;

		case 7:
		cout << "Insert number of top Profiles: ";
		cin >> n;
		important_users = social_net.follow(n);
		for (auto it = important_users.rbegin(); it!=important_users.rend(); it++)
			cout << it->second << " with " << it->first << " connections" << endl;
		break;

		case 8:
		cliques = social_net.listing_comunities();
		cout << "Cliques found: " << cliques.size() << endl;
		for (auto &clique : cliques) {
			cout << "( ";
			for (auto &user : clique)
				cout << user << " ";
			cout << ")" << endl;
		}
		break;

		case 9:
		cout << "Compact graph printed as edges on a BFS" << endl;
		social_net.print_compact_bfs();
		break;

		default:
		cout << "Exiting." << endl;
	}
}

// Menu type
void manual_testing(MySocialNetwork& social_net) {
	vector<string> options;
	options.push_back(string(".-Insert Profile: "));
	options.push_back(string(".-Insert Friendship: "));
	options.push_back(string(".-Delete Profile: "));
	options.push_back(string(".-Delete Friendship: "));
	options.push_back(string(".-Print graph: "));
	options.push_back(string(".-Find Profile: "));
	options.push_back(string(".-Top n Profiles: "));
	options.push_back(string(".-Clique Listing: "));
	options.push_back(string(".-Compact and print as BFS: "));
	options.push_back(string(".-Exit"));
	int opt=0;
	
	for(int i=0; i<options.size(); i++)
		cout << i+1 << options[i] << endl;

	while (opt!=options.size()) {
		cin >> opt;
		exec_opt(opt, social_net);
	}
}


#endif
