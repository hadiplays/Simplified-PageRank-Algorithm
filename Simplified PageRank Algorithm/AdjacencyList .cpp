#include "AdjacencyList .h"

//Insert Edges between two Vectors inside of Adjacency List Graph
void AdjacencyList::insertEdge(int from, int to)
{
    //std::cout << to << " " << from << std::endl;

    graph[to].push_back(std::make_pair(from, (0)));
    if (graph.find(from) == graph.end())
        graph[from] = {};

    //std::cout << graph[to][0].first << std::endl;
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
void AdjacencyList::InitializePageRank() {

    ////BFS starts at unique ID = 1
    //int source = 1;

    ////Containers used to track BFS progress
    //std::set<int> visited;
    //std::queue<int> q;

    ////Inserts source into both containers
    //visited.insert(source);
    //q.push(source);

    //
    //
    ////Iterates through the graph
    //while (!q.empty())
    //{
    //    int u = q.front();
    //    

    //    //Iterates through certain key's vector
    //    for (int i = 0; i < graph[u].size(); i++) {
    //        
    //        //Saves "from" url's unique ID
    //        int fromUrlID = graph[u][i].first;
    //        //Saves "from" url's string
    //        std::string fromUrlString;

    //        //Map Iterator
    //        std::map<std::string, int>::iterator itr;
    //        
    //        //Iterates through the webpage map
    //        for (itr = GetWebpages().begin(); itr != GetWebpages().end(); ++itr) {
    //            
    //            //Find name of url using its unique ID
    //            if (fromUrlID == itr->second) {
    //                
    //                fromUrlString = itr->first;
    //            }
    //        }
    //        
    //        //Set key "u" with its outdegree
    //        graph[u][i].second = 1.00/ out_degree_map[fromUrlString];
    //    }
    //    
    //    //Pops out current saved url ID
    //    q.pop();

    //    //Finds next neighbors of previous ID and stores them in containers for next iteration
    //    std::sort(graph[u].begin(), graph[u].begin() + graph[u].size());
    //    for (std::pair<int, double> v : graph[u])
    //    {
    //        if (visited.count(v.first) == 0)
    //        {
    //            visited.insert(v.first);
    //            q.push(v.first);
    //        }
    //    }
    //}

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

            //Set key "u" with its outdegree
            graph[iter->first][i].second = 1.00 / out_degree_map[fromUrlString];
        }
    }
}

void AdjacencyList::PageRank(int power_iterations) {

    InitializePageRank();

    int init = webpages.size();
    for (int i = 0; i < init; i++) {
        power_iteration_map[i + 1] = (1.00 / init);
        
    }

    /*std::map<std::string, int>::iterator itr;
    for (itr = out_degree_map.begin(); itr != out_degree_map.end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }*/

    for (int k = 0; k < (power_iterations - 1); k++) {
        std::map<int, double> temp;
        std::map<int, std::vector<std::pair<int, double>>>::iterator iter;
        for (iter = graph.begin(); iter != graph.end(); iter++) {
            //Iterates through certain key's vector
            

            double p = 0;

            for (int j = 0; j < graph[iter->first].size(); j++) {
                int fromID = graph[iter->first][j].first;
                //std::cout << " HI ";
                //std::cout << iter->first << " " << (graph[iter->first][j].second) << " " << power_iteration_map[fromID] << " " << fromID << std::endl;
                p += ((graph[iter->first][j].second) * (power_iteration_map[fromID]));
                //std::cout << "p: " << p << std::endl;
            }
            //std::cout << std::endl;

            temp[iter->first] = p;
            /*std::map<int, double>::iterator itr;
            for (itr = power_iteration_map.begin(); itr != power_iteration_map.end(); ++itr) {
                std::cout << itr->first << " " << itr->second << std::endl;
            }*/
            

            
        }
        for (int a = 0; a < temp.size(); a++)
            power_iteration_map[a] = temp[a];
    }

    PrintPageRank();

    ////Containers used to track BFS progress
    //std::set<int> visited;
    //std::queue<int> q;
    //
    //for (int i = 0; i < (power_iterations - 1); i++) {
    //    
    //    std::map<int, double> temp;
    //    
    //    //BFS starts at unique ID = 1
    //    int source = 1;

    //    //visited.clear();

    //    //Inserts source into both containers
    //    visited.insert(source);
    //    q.push(source);

    //    while (!q.empty())
    //    {
    //        int u = q.front();
    //        double p = 0;
    //        //Iterates through certain key's vector
    //        for (int j = 0; j < graph[u].size(); j++) {
    //            int fromID = graph[u][j].first;
    //            //std::cout << " HI ";
    //            std::cout << u << " " << (graph[u][j].second) << " " << power_iteration_map[fromID] << " " << fromID << std::endl;
    //            p += ((graph[u][j].second) * (power_iteration_map[fromID]));
    //            //std::cout << "p: " << p << std::endl;
    //        }
    //        //std::cout << std::endl;
    //        
    //        temp[u] = p;
    //        std::map<int, double>::iterator itr;
    //        for (itr = power_iteration_map.begin(); itr != power_iteration_map.end(); ++itr) {
    //            std::cout << itr->first << " " << itr->second << std::endl;
    //        }

    //        std::cout << std::endl;
    //        //Pops out current saved url ID
    //        q.pop();

    //        //Finds next neighbors of previous ID and stores them in containers for next iteration
    //        std::sort(graph[u].begin(), graph[u].begin() + graph[u].size());
    //        for (std::pair<int, double> v : graph[u])
    //        {
    //            if (visited.count(v.first) == 0)
    //            {
    //                visited.insert(v.first);
    //                q.push(v.first);
    //            }
    //        }
    //    }

    //    for (int i = 0; i < temp.size(); i++) 
    //        power_iteration_map[i] = temp[i];
    //    
        //PrintSmthn();

    //for (int i = 0; i < (power_iterations - 1); i++) {
    //    std::map<int, double> temp;
    //    double p = 0;
    //    std::map<int, std::vector<std::pair<int, double>>>::iterator itr1;
    //    for (itr1 = graph.begin(); itr1 != graph.end(); ++itr1) {
    //        for (int j = 0; j < graph[itr1->first].size(); j++) {
    //            int fromID = graph[itr1->first][j].first;
    //            //std::cout << " HI ";
    //            std::cout << itr1->first << " " << (graph[itr1->first][j].second) << " " << power_iteration_map[fromID] << " " << fromID << std::endl;
    //            p += ((graph[itr1->first][j].second) * (power_iteration_map[fromID]));
    //            //std::cout << "p: " << p << std::endl;
    //        }

    //        temp[itr1->first] = p;
    //        std::map<int, double>::iterator itr2;
    //        for (itr2 = power_iteration_map.begin(); itr2 != power_iteration_map.end(); ++itr2) {
    //            std::cout << itr2->first << " " << itr2->second << std::endl;
    //        }

    //        for (int k = 0; k < temp.size(); k++) {
    //            power_iteration_map[k] = temp[k];
    //        }

    //    }
    //}
        

        
        
        
    //}
    
}

std::map<int, double>& AdjacencyList::GetPowerIterationMap() {
    return power_iteration_map;
}

void AdjacencyList::PrintPageRank() {
    std::map<std::string, int>::iterator itr;
    for (itr = webpages.begin(); itr != webpages.end(); itr++) {
        std::cout << itr->first << " " << std::fixed << std::setprecision(2) <<  power_iteration_map[itr->second] << std::endl;
    }
}