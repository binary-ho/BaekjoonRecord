function solution(board, k) {
    let answer = 0;
   
    for(let i=0; i< board.length; i++){
        const item = board[i];
        for(let j=0; j < item.length; j++){
           if( i + j <= k)  {
               answer += board[i][j];
           }
        }
    }
    
    return answer;
}