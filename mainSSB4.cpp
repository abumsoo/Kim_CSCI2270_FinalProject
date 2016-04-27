/*
  Bum Soo Kim
  TA: Guohui Ding
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "charTree.h"

using namespace std;

int main(int argc, char *argv[]){
  charTree charactersABC;
  charTree charactersRank;
  ifstream inFile;
  inFile.open(argv[1]);
  string data;

  if(inFile.good()){
    while(getline(inFile,data)){
      stringstream ss(data);
      string rank;
      getline(ss,rank,',');
      string title;
      getline(ss,title,',');
      string universe;
      getline(ss,universe,',');
      // Fill BST in alphabetical order
      charactersABC.addCharacter(stoi(rank),title,universe);
      // Fill BST in order of rank
      charactersRank.addCharacterByRank(stoi(rank),title,universe);
    }
  }

  int userChoice = 0;
  string userStr;
  int userInt;

  while(userChoice!=7){
    charactersABC.displayMenu();
    cin >> userChoice;
    cin.ignore();

    if(userChoice==1){
      cout << "Enter character's name: ";
      getline(cin,userStr);
      charactersABC.wantRank(userStr);
    }else if(userChoice==2){
      cout << "Enter a rank: ";
      cin >> userInt;
      charactersRank.wantName(userInt);
    }else if(userChoice==3){
      cout << "Enter a character's name: ";
      getline(cin,userStr);
      charactersABC.wantUniverse(userStr);
    }else if(userChoice==4){
      cout << "Enter a character's name: ";
      getline(cin,userStr);
      charactersABC.wantAll(userStr);
    }else if(userChoice==5){
      charactersABC.printCharacterInfo();
    }else if(userChoice==6){
      charactersRank.printCharacterInfoRankFirst();
    }else if(userChoice==7){
      cout << "See ya!" << endl;
    }
  }

  return 0;
}
