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

		//Initializes Page Rank 
		void InitializePageRank();

		void PageRank(int power_iterations);

		std::map<int, double>& GetPowerIterationMap();

		void PrintPageRank();



		//void PrintGraph();
		void PrintSmthn() {
			int source = 1;
			//std::vector<double> d;

			std::set<int> visited;
			std::queue<int> q;

			visited.insert(source);
			q.push(source);

			while (!q.empty())
			{
			
				int u = q.front();

				std::vector<std::pair<int, double>> neighbors = graph[u];
				for (int i = 0; i < neighbors.size(); i++) {
					std::cout << u << " " << neighbors[i].first << " " << neighbors[i].second << " ";
				}

				std::cout << std::endl;

				q.pop();

				std::sort(neighbors.begin(), neighbors.begin() + neighbors.size());
				for (std::pair<int, double> v : neighbors)
				{
					if (visited.count(v.first) == 0)
					{
						visited.insert(v.first);
						q.push(v.first);
					}
				}
			}
		}
};