/*
todo:
	- program compact
*/

#include "MySocialNetwork.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ManualTest.cpp"

using namespace std;

// Parse the instruction into Find, Clique, Follow and Compact
void parse_instruction(string inst_line, MySocialNetwork& social_net) {
	stringstream s(inst_line);
	string tmp;

	s >> tmp;

	if (tmp=="Add") {
		string user1, user2;
		s >> user1 >> user2;
		social_net.friending(user1,user2);
	}
	else if (tmp=="Find") {
		string user, output;
		s >> user;

		output = social_net.find(user) ? "Yes" : "No";
		cout << output << endl;
	}
	else if (tmp=="Clique") {
		vector<MySocialNetwork::Graph::AdjacencySet> cliques = social_net.listing_comunities();
		for (auto it = cliques.rbegin(); it!=cliques.rend(); it++) {
			if (it->size()>2) {
				for (auto &user : *it)
					cout << user << " ";
				cout << endl;
			}
		}
	}
	else if (tmp=="Follow") {
		int n;
		s >> n;
		vector<pair<int,string>> important_users = social_net.follow(n);
		for (auto it = important_users.rbegin(); it!=important_users.rend(); it++)
			cout << it->second << endl;
	}
	else if (tmp=="Compact") {
		cout << tmp << " not implemented" << endl;
	}
	else {
		cout << "Instruction not recongniced" << endl;
	}
}

int main() {
	MySocialNetwork social_net;

	// // Input from cin or piping from file
	string inst;

	while (getline(cin, inst)) {
		if (inst.size() == 0)
			continue;

		parse_instruction(inst, social_net);
	}
	
	// // Manual testing
	// manual_testing(social_net);

	return 0;
}