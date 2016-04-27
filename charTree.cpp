// Bum Soo Kim
// TA: Guohui Ding

#include <iostream>
#include <fstream>
#include <sstream>
#include "charTree.h"

using namespace std;

charTree::charTree(){
  root=NULL;
}

charTree::~charTree(){
  //dtor
}

void charTree::printCharacterInfo(){
  printCharacterInfo(root);
}

void charTree::printCharacterInfo(character *node){
  if(node->leftChild!=NULL){
    printCharacterInfo(node->leftChild);
  }
  cout << node->name << endl;
  cout << "Universe: " << node->universe << endl;
  cout << "Rank: " << node->ranking << endl;
  cout << endl;
  if(node->rightChild!=NULL){
    printCharacterInfo(node->rightChild);
  }
}

void charTree::printCharacterInfoRankFirst(){
  printCharacterInfoRankFirst(root);
}

void charTree::printCharacterInfoRankFirst(character *node){
  if(node->leftChild!=NULL){
    printCharacterInfoRankFirst(node->leftChild);
  }
  cout << "Rank: " << node->ranking << " " << node->name << endl;
  cout << "Universe: " << node->universe << endl;
  if(node->rightChild!=NULL){
    printCharacterInfoRankFirst(node->rightChild);
  }
}

void charTree::displayMenu(){
  cout << "=======Main Menu=======" << endl;
  cout << "1. Find a character's rank" << endl;
  cout << "2. Find a character by rank" << endl;
  cout << "3. Find a character's universe" << endl;
  cout << "4. Find rank and universe of a character" << endl;
  cout << "5. Print the characters in alphabetical order" << endl;
  cout << "6. Print the characters in order of rank" << endl;
  cout << "7. Quit" << endl;
}

void charTree::addCharacter(int ranking, string title, string universe){
  character *current = new character;
  character *parent = NULL;
  character *charToAdd = new character(ranking, title, universe);
  current = root;
  bool left = true;
  while(current!=NULL){
    parent = current;
    if(current->name.compare(charToAdd->name) > 0){
      current=current->leftChild;
      left = true;
    }else{
      current=current->rightChild;
      left = false;
    }
  }
  if(parent == NULL){
    root=charToAdd;
  }else if(left){
    parent->leftChild=charToAdd;
    charToAdd->parent=parent;
  }else{
    parent->rightChild=charToAdd;
    charToAdd->parent=parent;
  }
}

void charTree::addCharacterByRank(int ranking, string title, string universe){
  character *current = new character;
  character *parent = NULL;
  character *charToAdd = new character(ranking, title, universe);
  current = root;
  bool left = true;
  while(current!=NULL){
    parent = current;
    if(current->ranking > charToAdd->ranking){
      current=current->leftChild;
      left = true;
    }else{
      current=current->rightChild;
      left = false;
    }
  }
  if(parent == NULL){
    root=charToAdd;
  }else if(left){
    parent->leftChild=charToAdd;
    charToAdd->parent=parent;
  }else{
    parent->rightChild=charToAdd;
    charToAdd->parent=parent;
  }
}

string charTree::findCharacter(int rank){
  character *current = new character;
  current = root;
  while(current!=NULL){
    if(current->ranking!=rank){
      if(current->ranking > rank){
        current=current->leftChild;
      }else{
        current=current->rightChild;
      }
    }else{
      return current->name;
    }
  }
  if(current==NULL){
    cout << "Could not find character." << endl;
    return "nope";
  }
}

int charTree::findRank(string name){
  character *current = new character;
  current = root;
  while(current!=NULL){
    if(current->name != name){
      if(current->name.compare(name) > 0){
        current=current->leftChild;
      }else{
        current=current->rightChild;
      }
    }else{
      return current->ranking;
    }
  }
  if(current==NULL){
    cout << "Could not find such rank." << endl;
    return -1;
  }
}

string charTree::findUniverse(string name){
  character *current = new character;
  current=root;
  while(current!=NULL){
    if(current->name != name){
      if(current->name.compare(name) > 0){
        current=current->leftChild;
      }else{
        current=current->rightChild;
      }
    }else{
      return current->universe;
    }
  }
  if(current==NULL){
    cout << "Could not find character." << endl;
    return "nope";
  }
}

void charTree::wantRank(string name){
  int rank = charTree::findRank(name);
  if(rank>0){
    cout << name << "'s rank is " << rank << endl;
  }
}

void charTree::wantName(int rank){
  string name = charTree::findCharacter(rank);
  if(name!="nope"){
    cout << "Ranked " << rank << " is " << name << endl;
  }
}

void charTree::wantUniverse(string name){
  string universe = charTree::findUniverse(name);
  if(name!="nope"){
    cout << name << " comes from " << universe << endl;
  }
}

void charTree::wantAll(string name){
  int rank = charTree::findRank(name);
  if(rank>0){
    cout << "Rank: " << rank << endl;
  }
  string universe = charTree::findUniverse(name);
  if(universe!="nope"){
    cout << "Universe: " << universe << endl;
  }
}
