#include <bits/stdc++.h> 
using namespace std;
#define V 26
int graph[V][V];
bool dot[V];

void setGraph(int x){
    for(int i = 0;i <V;i++)
        for(int j=0;j <V;j++)
            graph[i][j] = x;
}

int travllingSalesmanProblem(int graph[][V], int s) {
	vector<int> vertex;
    for(int i = 0;i < V;i++)
        if(dot[i] && i != s)
            vertex.push_back(i);
    vector<int> ans;
    int min_path = INT_MAX; 
	do {  
		int current_pathweight = 0;
        bool valid = true;  
		int k = s; 
		for (int i = 0; i < vertex.size() && valid; i++){ 
			if(graph[k][vertex[i]] != -1){
                current_pathweight += graph[k][vertex[i]]; 
			    k = vertex[i];
            }else{
                valid = false;
            } 
		}
        if(graph[k][s] != -1 && valid){
            current_pathweight += graph[k][s];
            if(min_path > current_pathweight){
                min_path = current_pathweight;
                ans = vertex;
            }  
        }  
	} while (next_permutation(vertex.begin(), vertex.end()));
    cout<<char(s+'A')<<" -> ";
    for(auto x : ans)
        cout<<char(x+'A')<<" -> ";
    cout<<char(s+'A')<<endl; 
	return min_path; 
} 

int main(){
    int v = 'S'-'A';  
    setGraph(-1);
    memset(dot,0,sizeof(dot));
    for(int i = 0;i < 13;i++){
        char x,y;
        int z;
        cin>>x>>y>>z;
        graph[x-'A'][y-'A'] = graph[y-'A'][x-'A'] = z;
        dot[x-'A'] = dot[y-'A'] = true; 
    }  
	cout << travllingSalesmanProblem(graph, v) << endl; 
	return 0; 
} 
