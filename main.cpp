#include <iostream>
#include <ctime> 
#include <random> 
#include <limits>

using namespace std;

int minValue(int sticksLeft, int maxPick, int alpha, int beta);
int maxValue(int sticksLeft, int maxPick, int alpha, int beta);

int main() {
  cout << "Let's play NIM with me" << endl << endl;
  cout << "Game will start now" << endl;
  
  int sticks;
  cout << "Enter the initial number of sticks in the pile: "; 
  cin >> sticks;
  cout << endl;
  
  int maxStick;
  cout << "Enter the maximum number of sticks you can pick up: ";
  cin >> maxStick;
  cout << endl;
  
  while (sticks <= 0 || maxStick <= 0) {
      cout << "Invalid number of sticks or max pick. Please enter valid values." << endl;
      cout << "Initial sticks in the pile: ";
      cin >> sticks;
      cout << "Maximum number of sticks you can pick up: ";
      cin >> maxStick;
  }
  
  cout << "Each player takes turns picking up 1 to " << maxStick << " sticks" << endl;
  cout << "The player who picks up the last stick wins " << endl;
  cout << endl;
  cout << "Good luck and have fun! " << endl;
  cout << endl;
  cout << "The computer will start first" << endl; 

  int user;
  
  while ( sticks > 0) { 
    int comp = maxValue(sticks, maxStick, numeric_limits<int>::min(), numeric_limits<int>::max());
    sticks -= comp;
    cout << "Computer turn. " << comp << " sticks were picked. " << endl; 
    cout << "There are " << sticks << " sticks left " << endl;
    if (sticks <= 0) { 
      cout << "The computer wins! " << endl; 
      break;
    }
    cout << "********************************" << endl << endl;
    
      
    cout << "Now. Your turn " << endl;
    cout << "Choose number of sticks you want to pịck (1-" << maxStick << "): ";
    cin >> user; 
    
    while (user > maxStick || user < 1 || user > sticks){
      cout << "Invalid input " << "Please enter a number between 1 and " << min(maxStick, sticks) << ": ";
      cin >> user; 
    }
    cout << "You choosed " << user << " sticks. " << endl;
    sticks -= user;
    cout << "There are " << sticks << " sticks left " << endl;
    cout << "********************************" << endl << endl;
    if (sticks <= 0) {
      cout << "You win! " << endl;
      break;
    }
  }

  return 0;
}

int minValue(int sticksLeft, int maxPick, int alpha, int beta) {
    if (sticksLeft <= 0) return -1;
    for (int i = 1; i <= min(maxPick, sticksLeft); ++i) {
        int score = maxValue(sticksLeft - i, maxPick, alpha, beta);
        if (score < beta) beta = score;
        if (alpha >= beta) break;
    }
    return beta;
}

int maxValue(int sticksLeft, int maxPick, int alpha, int beta) {
    if (sticksLeft <= 0) return 1;
    for (int i = 1; i <= min(maxPick, sticksLeft); ++i) {
        int score = minValue(sticksLeft - i, maxPick, alpha, beta);
        if (score > alpha) alpha = score;
        if (alpha >= beta) break;
    }
    
    int bestMove = 1;
    for (int i = maxPick; i >= 1; --i) {
        if (sticksLeft - i >= 0) {
            int score = minValue(sticksLeft - i, maxPick, alpha, beta);
            if (score == 1) {
                bestMove = i;
                break;
            }
        }
    }
    return bestMove;
}