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

using namespace std;

// Interface class that can be extended into a real social network, with information on a DB, etc...
template<class GraphContainer=MyGraph<string>>
class MySocialNetwork {
	public:
		typedef GraphContainer			Graph;

	private:
		Graph relations_graph;

	public:
		void new_profile(std::string p);
		void delete_profile(std::string p);

		void friending(std::string p1, std::string p2);
		void unfriending(std::string p1, std::stringp2);

		bool find(std::string p, int m=0);


		//
		vector<pair<string,size_t>>& follow(int n);
};


// For linking error purposes
#include "MySocialNetwork.cpp"

#endif