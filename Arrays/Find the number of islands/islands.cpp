#include <iostream>

using namespace std;

bool is_attached(int N, int M, int indx, int indy, bool** visited,int** mat) {

    if(indx < N && indx >=0 && indy < M && indy >= 0 && !visited[indx][indy] && mat[indx][indy]) return true;
    return false;
}

void dfs(int sx, int sy, int** mat, bool** visited, int maxX, int maxY) {
    visited[sx][sy] = true;

    if(is_attached(maxX,maxY,sx+1,sy+1,visited,mat)) dfs(sx+1,sy+1,mat,visited,maxX,maxY);     //dig..bottom...right
    if(is_attached(maxX,maxY,sx+1,sy,visited,mat)) dfs(sx+1,sy,mat,visited,maxX,maxY);     //right...
    if(is_attached(maxX,maxY,sx,sy+1,visited,mat)) dfs(sx,sy+1,mat,visited,maxX,maxY);     //bottom...
    if(is_attached(maxX,maxY,sx,sy-1,visited,mat)) dfs(sx,sy-1,mat,visited,maxX,maxY);     //top
    if(is_attached(maxX,maxY,sx-1,sy,visited,mat)) dfs(sx-1,sy,mat,visited,maxX,maxY);     //left...
    if(is_attached(maxX,maxY,sx-1,sy+1,visited,mat)) dfs(sx-1,sy+1,mat,visited,maxX,maxY);     //dig..bottom...left
    if(is_attached(maxX,maxY,sx-1,sy+1,visited,mat)) dfs(sx-1,sy+1,mat,visited,maxX,maxY);     //dig..top...left
    if(is_attached(maxX,maxY,sx+1,sy-1,visited,mat)) dfs(sx+1,sy-1,mat,visited,maxX,maxY);     //dig..top...right

}

int dfs_util(int N, int M, int** mat) {

    bool** visited = new bool*[N];
    for(int i=0;i<N;i++)
        visited[i] = new bool[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            visited[i][j] = false;
        }
    }

    int islands=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(!visited[i][j] && mat[i][j]) {
                cout << "hey " << i << " " << j << endl;
                dfs(i,j,mat,visited,N,M);
                islands++;
            }
        }
    }

    return islands;
}

int sameIsland(int x, int y, int N, int M, int** mat) {

    bool** visited = new bool*[N];
    for(int i=0;i<N;i++)
        visited[i] = new bool[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            visited[i][j] = false;
        }
    }

    dfs(x,y,mat,visited,N,M);
    int count = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j])
                count++;
        }
    }

    return count;

}

int main() {

    int N,M;
    cout << "N*M Matrix...Enter N & M:" << endl;
    cin >> N >> M;
    int** mat = new int*[N];
    for(int i=0;i<N;i++)
        mat[i] = new int[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> mat[i][j];
        }
    }

    cout << "The number of islands in this graph is:" << endl;
    cout << dfs_util(N,M,mat) << endl;

    int x,y;
    cout << "Given a location find how many lie on the same island:" << endl;
    cin >> x >> y;
    cout << "Island population is: " << sameIsland(x,y,N,M,mat) << endl;

}
