#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int board_size=board.size();

    vector<int> top(board_size,0);
    vector<int> stc;
    for(int i=0;i<board_size;i++){
        int top_index=0;
        while(top_index<board_size && board[top_index][i]==0){
            top_index++;
        }
        top[i]=top_index;

    }

    for(auto& n : moves){
        if(top[n-1]<board_size){

            if(!stc.empty() &&stc.back()==board[top[n-1]][n-1]){
                stc.pop_back();
                answer+=2;
            }
            else{
                stc.push_back(board[top[n-1]][n-1]);
            }


            board[top[n-1]][n-1]=0;
            top[n-1]++;

        }

    }



    return answer;
}


