/* Bum Soo Kim */
/* TA: Guohui Ding */

#ifndef CHARTREE_H
#define CHARTREE_H
#include <iostream>
#include <fstream>

struct character{
  std::string name;
  int ranking;
  std::string universe;
  character *parent;
  character *leftChild;
  character *rightChild;

  character(){};
  character(int rank, std::string charName, std::string charUniverse){
    ranking = rank;
    name = charName;
    universe = charUniverse;
    parent = NULL;
    leftChild = NULL;
    rightChild = NULL;
  }
};

class charTree{
 public:
  charTree();
  ~charTree();
  void addCharacter(int ranking, std::string name, std::string universe);
  void addCharacterByRank(int ranking, std::string name, std::string universe);
  std::string findCharacter(int rank);
  int findRank(std::string name);
  std::string findUniverse(std::string name);
  void wantRank(std::string name);
  void wantName(int rank);
  void wantUniverse(std::string universe);
  void wantAll(std::string name);
  void printCharacterInfo();
  void printCharacterInfoRankFirst();
  void displayMenu();
 private:
  void printCharacterInfo(character *node);
  void printCharacterInfoRankFirst(character *node);
  character *root;
};

#endif // CHARTREE_H
