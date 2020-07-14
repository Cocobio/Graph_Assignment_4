/*
Author:
	Ignacio Osorio W.



*/


#ifndef MY_SOCIAL_NETWORK
#define MY_SOCIAL_NETWORK

#include <string>
#include "MyGraph.hpp"
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

// Interface class that can be extended into a real social network, with information on a DB, etc...
class MySocialNetwork {
	public:
		typedef MyGraph<string>			Graph;

	private:
		Graph relations_graph;

	public:
		void new_profile(std::string p);
		void delete_profile(std::string p);

		void friending(std::string p1, std::string p2);
		void unfriending(std::string p1, std::string p2);

		bool find(std::string p, int m=0);

		void print();

		//
		vector<pair<size_t,string>> follow(int n);
};


// For linking error purposes
#include "MySocialNetwork.cpp"

#endif