#include <iostream>
#include <ctime> 
#include <random> 
using namespace std;

int main() {
  cout << "Let's play NIM with me" << endl;
  cout << endl;
  cout << "Game will start now" << endl;
  cout << "We got 12 sticks" << endl;
  cout << "Each player takes turns picking up 1-4 sticks " << endl;
  cout << "The player who picks up the last stick wins " << endl;
  cout << endl;
  cout << "Good luck and have fun! " << endl;
  cout << endl;
  cout << "The computer will start first" << endl; 
  

  int comp; 
  int user; 
  int sticks = 12; 


  random_device rd; 
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1,4); 

  while ( sticks > 0) { 
     if ( sticks < 4) { 
       uniform_int_distribution<> dis2(1,sticks); 
       comp = dis2(gen);
     }
     else { 
     comp = dis(gen);
     }
     cout << "Computer turn. " << comp << " sticks were picked. " << endl;
     sticks = sticks - comp; 
     cout << "There are " << sticks << " sticks left " << endl;
     if (sticks <= 0) { 
       cout << "The computer wins! " << endl; 
     }
     else {
       cout << "Now. Your turn " << endl;
       cout << "Choose number of sticks you want to pịck (1-4) " << endl;
       cin >> user; 
       cout << "********************************" << endl;
          while ( user > 4 || user < 1) {
              cout << "Invalid input " << endl;
              cout << "Please enter a number between 1-4 " << endl;
              cout << "*************************************" << endl;
              cin >> user; 
            }
          while (user > sticks) { 
          cout << "Only " << sticks << " sticks left " << endl;
          cout << "Enter a valid number " << endl;
          cin >> user;
             }
          sticks = sticks - user; 
          if (sticks == 0) {
                cout << "You win! " << endl;
              }
           }
         }
       }