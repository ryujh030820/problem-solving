#include <iostream>
#include <deque>

using namespace std;

int board[100][100];
int snake[100][100];
int change[10000]; //1=왼쪽, 2=오른쪽
int n, direction=0, sec=0;

int dx[] = {1,0,-1,0}; //오른쪽, 아래, 왼쪽, 위 순
int dy[] = {0,1,0,-1};

deque<pair<int,int>> q;

void DFS(int x,int y) {
    int nx, ny;

    snake[y][x]=1;
    q.push_front(make_pair(x,y));

    if(change[sec] == 1) {
        if(direction == 0) {
            direction=3;
        }
        else {
            direction--;
        }
    }
    else if(change[sec]==2) {
        if(direction == 3) {
            direction=0;
        }
        else {
            direction++;
        }
    }

    sec++;

    nx=x+dx[direction];
    ny=y+dy[direction];

    if(snake[ny][nx]==1 || nx<0 || nx>=n || ny<0 || ny>=n) {
        cout << sec;
    }
    else {
        if(board[ny][nx] != 1) {
            int X=q.back().first;
            int Y=q.back().second;
            q.pop_back();
            snake[Y][X]=0;
        }
        else {
            board[ny][nx]=0;
        }

        DFS(nx,ny);
    }
}

int main(void) {
    int k, l;

    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            board[i][j]=0;
            snake[i][j]=0;
        }
    }

    for(int i=0;i<10000;i++) {
        change[i]=0;
    }

    cin >> n;

    cin >> k;

    for(int i=0;i<k;i++) {
        int row,col;

        cin >> row >> col;

        board[row-1][col-1]=1;
    }

    cin >> l;

    for(int i=0;i<l;i++) {
        int a;
        char c;

        cin >> a >> c;

        if(c=='L') {
            change[a]=1;
        }
        else if(c=='D') {
            change[a]=2;
        }
    }

    DFS(0,0);

    return 0;
}