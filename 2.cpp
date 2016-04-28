/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Graph{
	map<string, vector<string> > adjList;

	void DFTUtil(string start, set<string>& visited)
	{
		cout << start << " ";
		visited.insert(start);

		for(string s : adjList[start])
			if(visited.find(s) == visited.end())
				DFTUtil(s, visited);

		return;
	}
	
	void BFTUtil(string start, set<string>& visited)
	{
		queue<string> memory;
		
		memory.push(start);
		visited.insert(start);
		
		string curr;
		
		while(!memory.empty())
		{
			curr = memory.front();
			cout << curr << " ";
			memory.pop();
			
			for(string s : adjList[curr])
			{
				if(visited.find(s) == visited.end())
				{
					visited.insert(s);
					memory.push(s);
				}
			}
		}
		
		return;
	}
public:
	Graph() {}

	void addVertex(string name)
	{
		vector<string> temp;
		adjList.insert(make_pair(name, temp));
	}

	void addEdge(string src, string dest)
	{
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}

	void DFT(void)
	{
		set<string> visited;
		map<string, vector<string> >::iterator it;
		
		for(it = adjList.begin(); it != adjList.end(); it++)
			if(visited.find(it->first) == visited.end())
				DFTUtil(it->first, visited);
	}
	
	void BFT(void)
	{
		set<string> visited;
		map<string, vector<string> >::iterator it;
		
		for(it = adjList.begin(); it != adjList.end(); it++)
			if(visited.find(it->first) == visited.end())
				BFTUtil(it->first, visited);
	}
};

int main(void)
{
	Graph g;
	
	int V, E;
	string vertex, vertex1, vertex2;
	
	cout << "Enter number of vertices : ";
	cin >> V;
	
	cout << "Enter number of Edges : ";
	cin >> E;
	
	for(int i = 0; i < V; i++)
	{
		cout << "Enter the name of #" << i+1 << " Vertex :";
		cin >> vertex;
		g.addVertex(vertex);
	}
	
	for(int i = 0; i < E; i++)
	{
		cout << "Enter the source vertex name of #" << i+1 << " Edge :";
		cin >> vertex1;
		cout << "Enter the destination vertex name of #" << i+1 << " Edge :";
		cin >> vertex2;
		g.addEdge(vertex1, vertex2);
	}
	
	cout << "Depth First Traversal : ";
	g.DFT();
	cout << endl;
	
	cout << "Breadth First Traversal : ";
	g.BFT();
	cout << endl;

	return 0;
}
