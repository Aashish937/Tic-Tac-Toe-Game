#include <bits/stdc++.h>
using namespace std;

void print(vector<char>&game){
    int idx=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(game[idx]=='X' || game[idx]=='O'){
                cout << " " << game[idx];
            }
            else{
                cout << "  ";
            }
            if(j!=2){
                cout<< " |";
            }
            idx++;
        }
        cout << endl;
        if(i!=2){
            cout << "-----------";
        }
        cout << endl;
    }
}

bool check(vector<char>&game){
    if(game[0]!='0' && game[0]==game[1] && game[1]==game[2]){
        return true;
    }
    if(game[3]!='0' && game[3]==game[4] && game[4]==game[5]){
        return true;
    }
    if(game[6]!='0' && game[6]==game[7] && game[7]==game[8]){
        return true;
    }
    if(game[0]!='0' && game[0]==game[3] && game[3]==game[6]){
        return true;
    }
    if(game[1]!='0' && game[1]==game[4] && game[4]==game[7]){
        return true;
    }
    if(game[2]!='0' && game[2]==game[5] && game[5]==game[8]){
        return true;
    }
    if(game[0]!='0' && game[0]==game[4] && game[4]==game[8]){
        return true;
    }
    if(game[2]!='0' && game[2]==game[4] && game[4]==game[6]){
        return true;
    }
    return false;
}

string tictactoeGame(string first,string second){
    vector<char>game(9,'0');
    print(game);
    int ind;
    for(int i=0;i<9;i++){
        cout << "Enter the position between 1 to 9" << endl;
        cin >> ind;

        if(i%2==0){
            game[ind-1]='X';
        }
        else{
            game[ind-1]='O';
        }

        cout << endl;
        print(game);

        // Checking for winner
        if(i>=4 && check(game)){
            return i%2==0 ? first : second;
        }
    }
    return "draw";
}

int main(){
    string first;
    string second;

    cout << "Start the game" <<endl; 
    
    cout << "Enter the name of the first player" << endl;
    cin >> first;

    cout << "Enter the name of the second player" << endl;
    cin >> second;

    cout << first << " will play first" << endl;
    string ans = tictactoeGame(first,second);

    if(ans=="draw"){
        cout << "The Game is drawn";
    }
    else{
        cout << ans << " is winner";
    }
}