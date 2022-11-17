// Simplified PageRank Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <map>

#include "AdjacencyList .h"

int main()
{
    //Declare variables
    int no_of_lines, power_iterations;
    std::string from, to;

    //Read in user's input
    std::cin >> no_of_lines; //Number of actions being done
    std::cin >> power_iterations; //Power Iteration

    //Create a graph object
    AdjacencyList Created_Graph;


    for (int i = 0; i < no_of_lines; i++)
    {
        //Store from and to urls
        std::cin >> from;
        std::cin >> to;

        //If the "to" url is not a key in the map, add it to map 
        if (Created_Graph.GetWebpages().find(to) == Created_Graph.GetWebpages().end()) {
            Created_Graph.SetWebpages(to);
        }

        //If the "from" url is not a key in the map, add it to map 
        if (Created_Graph.GetWebpages().find(from) == Created_Graph.GetWebpages().end()) {
            Created_Graph.SetWebpages(from);
        }

        //Add 1 to the outdegree for the "from" url into the out_degree_map
        Created_Graph.SetOutDegreeMap(from);

        //Stores an edge into the main graph
        Created_Graph.insertEdge(Created_Graph.GetWebpages()[from], Created_Graph.GetWebpages()[to]);
    }
    //Created_Graph.PrintSmthn();
    //Sets every edge in the adjacency list to include a "weight" of 1 over the outdegree of the "from" url
    //Created_Graph.InitializePageRank();

    Created_Graph.PageRank(power_iterations);

    /*std::map<int, double>::iterator itr;
    for (itr = Created_Graph.GetPowerIterationMap().begin(); itr != Created_Graph.GetPowerIterationMap().end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }*/
    


    /*std::map<std::string, int>::iterator itr;
    for (itr = Created_Graph.GetOutDegreeMap().begin(); itr != Created_Graph.GetOutDegreeMap().end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }

    


    */
    
    //Created_Graph.PrintWebpages();
    return 0;
}


