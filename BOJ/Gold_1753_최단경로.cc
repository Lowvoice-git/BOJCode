#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#define SIZE 20001
#define INF 1000000000

using namespace std;

vector< pair<int, int> > vtx[SIZE];
int vtx_num, edge_num, start_node;
int dist[SIZE];

void dijkstra()
{
	for (int i = 1; i <= vtx_num; ++i)
	{
		dist[i] = INF;
	}
	dist[start_node] = 0;

	
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
	
	pq.push({ 0, start_node });

	while (!pq.empty())
	{
		int		iCost = pq.top().first;
		int		iCur_node = pq.top().second;
		pq.pop();

		if (dist[iCur_node] < iCost) continue;
		
		for (int i = 0; i < vtx[iCur_node].size(); ++i)
		{
			int next_node = vtx[iCur_node][i].first;
			int next_cost = iCost + vtx[iCur_node][i].second;

			if (dist[next_node] > next_cost)
			{
				dist[next_node] = next_cost;
				pq.push({next_cost, next_node});
			}
		}
	}

	for (int i = 1; i <= vtx_num; ++i)
	{
		if (start_node == i) cout << "0" << '\n';
		else if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> vtx_num >> edge_num >> start_node;

	for (int i = 0; i < edge_num; ++i)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		vtx[a].push_back({ b, cost });
	}

	dijkstra();

	return 0;
}