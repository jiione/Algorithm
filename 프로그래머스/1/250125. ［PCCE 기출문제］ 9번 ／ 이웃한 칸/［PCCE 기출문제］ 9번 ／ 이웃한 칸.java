class Solution {
    static int dx[] = {0,1,0,-1};
    static int dy[] ={1,0,-1,0};
    public int solution(String[][] board, int h, int w) {
        
        int size = board.length;
        String color = board[h][w];
        int answer = 0;
        for(int i=0; i<4; ++i){
            int y = h+dy[i];
            int x = w+dx[i];
            
            if(y>=0 && x>=0 && y<size && x<size && color.equals(board[y][x])){
                answer++;
            }
        }
        
        return answer;
    }
}