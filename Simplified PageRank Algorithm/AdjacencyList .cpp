#include "AdjacencyList .h"

//Insert Edges between two Vectors inside of Adjacency List Graph
void AdjacencyList::insertEdge(int from, int to)
{
    graph[to].push_back(std::make_pair(from, (0)));
    if (graph.find(from) == graph.end())
        graph[from] = {};
}

//Returns webpages
std::map<std::string, int>& AdjacencyList::GetWebpages() {
    return webpages;
}

//Adds a unique ID value to a new url
void AdjacencyList::SetWebpages(std::string w) {
    webpages[w] = count;
    count++;
}

//Print Map of Webpages
void AdjacencyList::PrintWebpages() {
    std::map<std::string, int>::iterator itr;
    for (itr = webpages.begin(); itr != webpages.end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

//Returns out_degree_map
std::map<std::string, int>& AdjacencyList::GetOutDegreeMap() {
    return out_degree_map;
}

//Adds 1 to a url's outdegree
void AdjacencyList::SetOutDegreeMap(std::string o) {
    out_degree_map[o]++;
}

//Sets every edge in the adjacency list to include a "weight" of 1 over the outdegree of the "from" url
void AdjacencyList::InitializeGraphValues() {

    std::map<int, std::vector<std::pair<int, double>>>::iterator iter;
    for (iter = graph.begin(); iter != graph.end(); iter++) {
        //Iterates through certain key's vector
        for (int i = 0; i < graph[iter->first].size(); i++) {

            //Saves "from" url's unique ID
            int fromUrlID = graph[iter->first][i].first;
            
            //Saves "from" url's string
            std::string fromUrlString;

            //Map Iterator
            std::map<std::string, int>::iterator itr;

            //Iterates through the webpage map
            for (itr = GetWebpages().begin(); itr != GetWebpages().end(); ++itr) {

                //Find name of url using its unique ID
                if (fromUrlID == itr->second) {

                    fromUrlString = itr->first;
                }
            }

            //Set key "iter->first" with its outdegree
            graph[iter->first][i].second = 1.00 / out_degree_map[fromUrlString];
        }
    }
}

//This is where the calculations happen in order to find the rank of a homepage
//and iterates depending on the value of power_iterations
void AdjacencyList::PageRank(int power_iterations) {

    //Initializes Page Ranks
    InitializeGraphValues();

    //Initialize power_iteration_map keys with values = 1 / (number of total vectors)
    int init = webpages.size();
    for (int i = 0; i < init; i++) {
        power_iteration_map[i + 1] = (1.00 / init);
        
    }

    //Computes r(t+1) = M.r(t), where M is the graph and r(t) is the power_iteration_map
    for (int k = 0; k < (power_iterations - 1); k++) {
        std::map<int, double> temp;
        std::map<int, std::vector<std::pair<int, double>>>::iterator iter;

        //Iterate through graph
        for (iter = graph.begin(); iter != graph.end(); iter++) {
            
            double p = 0;

            //This is where r(t+1) is actually computed and saved into variable "p"
            for (int j = 0; j < graph[iter->first].size(); j++) {
                int fromID = graph[iter->first][j].first;
                p += ((graph[iter->first][j].second) * (power_iteration_map[fromID]));
                
            }
            
            //Save new values into a temporary map to import into the power_iteration_map
            //after exiting the for loop
            temp[iter->first] = p;
            
        }
        //Adds new ranks to the power_iteration_map
        for (int a = 0; a < temp.size(); a++)
            power_iteration_map[a] = temp[a];
    }

    //Prints page ranks
    PrintPageRank();
    
}

//Returns power_iteration_map
std::map<int, double>& AdjacencyList::GetPowerIterationMap() {
    return power_iteration_map;
}

//Prints the ranks of each url
void AdjacencyList::PrintPageRank() {
    std::map<std::string, int>::iterator itr;
    for (itr = webpages.begin(); itr != webpages.end(); itr++) {
        std::cout << itr->first << " " << std::fixed << std::setprecision(2) <<  power_iteration_map[itr->second] << std::endl;
    }
}