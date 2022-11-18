#pragma once
#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <algorithm>


class AdjacencyList
{
	private:

		//Assigns new integer to be set as the unique ID for a url
		int count = 1;

		//Graph
		std::map<int, std::vector<std::pair<int, double>>> graph;

		//Map that stores a unique ID for evry url
		std::map<std::string, int> webpages;

		//Map that stores outdegree value of each url
		std::map<std::string, int> out_degree_map;

		//Map that stores power iteration values
		std::map<int, double> power_iteration_map;

	public:

		//Inserts edge into graph
		void insertEdge(int from, int to);

		//Returns webpages map
		std::map<std::string, int>& GetWebpages();

		//Adds url and assigns unique ID to webpages map
		void SetWebpages(std::string w);

		//Print webpages
		void PrintWebpages();

		//Returns out_degree_map
		std::map<std::string, int>& GetOutDegreeMap();

		//Adds 1 to a url's outdegree
		void SetOutDegreeMap(std::string o);

		//Initializes Gaph Values
		void InitializeGraphValues();

		//Sets and prints the ranks of every url
		void PageRank(int power_iterations);

		//Returns power iteration map
		std::map<int, double>& GetPowerIterationMap();

		//Prints rank for url
		void PrintPageRank();

};