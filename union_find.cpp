//I'll be solving https://leetcode.com/submissions/detail/549347434/ to illustrate union find but also tracking the answer

int parent[500]={};
int maxDepth[500]={};

function<int(int)> findParent=[](int u){
	if(parent[u]==0){
		return u;
	}
	return parent[u]=findParent(parent[u]);
};

auto unionn=[](int u, int v, int& num){
	u=findParent(u);
	v=findParent(v);
    cout<<u<<" "<<v<<endl;
	if(u==v){
		return ;
	}
    num--;
	// cout << u<<" : "<<size[u]<<"   "<<v<<" : "<<size[v] << endl ;
	if(maxDepth[v]>maxDepth[u]){
		parent[u]=v;
	}
	else if(maxDepth[v]<maxDepth[u]){
		parent[v]=u;
	}
	else{
		parent[u]=v;
		maxDepth[v]++;
	}
	// cout << u<<" : "<<size[u]<<"   "<<v<<" : "<<size[v] << endl<<endl ;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(parent,0,500);
        memset(maxDepth,0,500);
        int num=isConnected.size();
        int ans=num;
        for(int i=0;i<num;i++){
            for(int j=i+1;j<num;j++){
                if(isConnected[i][j])
                    unionn(i,j,ans);
            }
        }
        return ans;
    }
};
