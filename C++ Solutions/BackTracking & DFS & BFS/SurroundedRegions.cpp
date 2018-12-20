//Surrounded Regions
//Tags: BFS, pair

/*
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/

//Solution:
//刚拿到这个题，首先得想法就是BFS。对于每一个O，扫描其相邻节点，然后标示之（B）,
//如果一个联通区域中有任何一个O在边界上，则保留之，否则清除该联通域.因为，外围
//一圈上的O肯定会保留下来。然后，从外围的O能达到的O也要保留。

class Solution {
public:
	//w is width, l is length
    void bfsBoundary(vector<vector<char> >& board, int w, int l){
        int width = board.size();
        int length = board[0].size();
        deque<pair<int, int> > q;
        q.push_back(make_pair(w, l)); //Put the border element into queue
        board[w][l] = 'B'; //强行装B， B表示这靠边（Border）
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop_front();
            //扫邻居
            pair<int, int> adjs[4] = {{cur.first-1, cur.second}, {cur.first+1, cur.second}, 
                                    {cur.first, cur.second-1},{cur.first, cur.second+1}};
            for (int i = 0; i < 4; ++i){
                int adjW = adjs[i].first;
                int adjL = adjs[i].second;
                if ((adjW >= 0) && (adjW < width) && (adjL >= 0) && (adjL < length) && (board[adjW][adjL] == 'O')) {
                    q.push_back(make_pair(adjW, adjL));
                    board[adjW][adjL] = 'B';
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int width = board.size();
        if (width == 0) //Add this to prevent run-time error!
            return;
        int length = board[0].size();
        if  (length == 0) // Add this to prevent run-time error!
            return;
    
        for (int i = 0; i < length; ++i){
            if (board[0][i] == 'O') bfsBoundary(board, 0, i);
            if (board[width-1][i] == 'O') bfsBoundary(board, width-1, i);
        }
        for (int i = 0; i < width; ++i){
            if (board[i][0] == 'O') bfsBoundary(board, i, 0);
            if (board[i][length-1] == 'O') bfsBoundary(board, i, length-1);
        }
        //标记完之后，讲剩下的0转为X，同时将B转为0
        for (int i = 0; i < width; ++i){
            for (int j = 0; j < length; ++j){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if (board[i][j] == 'B'){
                    board[i][j] = 'O';//reverse back
                }
            }
        }
    }
};
