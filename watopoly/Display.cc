#include "Display.h"
#include <iostream>
#include <iomanip>
#include <locale>
#include "AcademicBuilding.h"


using namespace std;

Display::Display(){}

Display::~Display(){}

void Display::printGameBoard(Cell *board[40]){
   int improv,nspace;
   // line 1
   cout << "-----------------------------------------------------------------------------------------" << endl;
   // line 2
   for(int i = 20; i < 31; ++i){
      if(board[i]->getName() == "Goose Nesting"){
         cout << "|Goose  ";                       
      }
      else if(board[i]->getName() == "NEEDLES HALL"){
      	cout << "|NEEDLES";
      }
      else if(board[i]->getName() == "V1"){
      	cout << "|V1     ";
      }
      else if(board[i]->getName() == "CIF"){
      	cout << "|CIF    ";
      }
      else if(board[i]->getName() == "GO TO TIMS"){
         cout << "|GO TO  ";
      }
      else {
      	cout << "|";
        AcademicBuilding *ac = dynamic_cast<AcademicBuilding *>(board[i]); 
        improv = ac->getCurrentLevel();
         for(int j = 0; j < improv; ++j){
            cout << "I";
         }
      	nspace = 8 - improv - 1;
         for(int x = 0; x < nspace; ++x){
            cout <<" ";
         }
      }
   }
   cout << "|" << endl;
   // line 3
   for(int i = 20; i < 31; ++i){
      if(board[i]->getName() == "Goose Nesting"){
         cout << "|Nesting";                       
      }
      else if(board[i]->getName() == "NEEDLES HALL"){
         cout << "|HALL   ";
      }
      else if(board[i]->getName() == "V1"){
         cout << "|       ";
      }
      else if(board[i]->getName() == "CIF"){
         cout << "|       ";
      }
      else if(board[i]->getName() == "GO TO TIMS"){
         cout << "|TIMS   ";
      }
      else {
         cout << "|-------";
      }
   }
   cout << "|" << endl;
   // line 4
   for(int i = 20; i < 31; ++i){
      if((board[i]->getName() != "Goose Nesting") && (board[i]->getName() != "NEEDLES HALL") && 
         (board[i]->getName() != "V1") && (board[i]->getName() != "CIF") 
         && (board[i]->getName() != "GO TO TIMS")){
      cout << "|" << left << setfill(' ') << setw(7) << board[i]->getName();
      }
      else{
         cout << "|       ";
      }
   }
   cout << "|" << endl;
   // line 5 : display players
   for(int i = 20; i < 31;++i){
      cout << "|";
      board[i]->printPlayers();        
   }
   cout << "|" << endl;
   // line 6 
   for(int i = 0; i < 11;++i){
      cout << "|_______";
   }
   cout << "|" << endl;
   // line 7
   cout << "|";
   AcademicBuilding *ac1 = dynamic_cast<AcademicBuilding *>(board[19]); 
   improv = ac1->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|                                                                       |";
   AcademicBuilding *ac2 = dynamic_cast<AcademicBuilding *>(board[31]); 
   improv = ac2->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|" << endl;
   // line 8
   cout << "|-------|                                                                       |-------|" << endl;
   // line 9
   cout << "|OPT    |                                                                       |EIT    |" << endl;
   // line 10 : display players board[19], board[31]
   cout << "|";
   board[19]->printPlayers();
   cout << "|                                                                       |";
   board[31]->printPlayers();
   cout << "|" << endl;
   // line 11
   cout << "|_______|                                                                       |_______|" << endl;
   // line 12
   cout << "|";
   AcademicBuilding *ac3 = dynamic_cast<AcademicBuilding *>(board[18]); 
   improv = ac3->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|                                                                       |";
   AcademicBuilding *ac4 = dynamic_cast<AcademicBuilding *>(board[32]); 
   improv = ac4->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|" << endl;
   // line 13
   cout << "|-------|                                                                       |-------|" << endl;
   // line 14
   cout << "|BMH    |                                                                       |ESC    |" << endl;
   // line 15 : display players board[18], board[32]
   cout << "|";
   board[18]->printPlayers();
   cout << "|                                                                       |";
   board[32]->printPlayers();
   cout << "|" << endl;
   // line 16
   cout << "|_______|                                                                       |_______|" << endl;
   // line 17
   cout << "|SLC    |                                                                       |SLC    |" << endl;
   // line 18 
   cout << "|       |                                                                       |       |" << endl;
   // line 19
   cout << "|       |                                                                       |       |" << endl;
   // line 30 : display players board[17], board[33]
   cout << "|";
   board[19]->printPlayers();
   cout << "|                                                                       |";
   board[33]->printPlayers();
   cout << "|" << endl;
   // line 31
   cout << "|_______|                                                                       |_______|" << endl;
   // line 32
   cout << "|";
   AcademicBuilding *ac5 = dynamic_cast<AcademicBuilding *>(board[16]); 
   improv = ac5->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|                                                                       |";
   AcademicBuilding *ac6 = dynamic_cast<AcademicBuilding *>(board[34]); 
   improv = ac6->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|" << endl;
   // line 33
   cout << "|-------|                                                                       |-------|" << endl;
   // line 34
   cout << "|LHI    |                                                                       |C2     |" << endl;
   // line 35 display players board[16], board[34]
   cout << "|";
   board[16]->printPlayers();
   cout << "|             ---------------------------------------------             |";
   board[34]->printPlayers();
   cout << "|" << endl;
   // line 31
   cout << "|_______|            |                                             |            |_______|" << endl;
   // line 32
   cout << "|UWP    |            | #   #  ##  #####  ###  ###   ###  #   #   # |            |REV    |" << endl;
   // line 33
   cout << "|       |            | #   # #  #   #   #   # #  # #   # #   #   # |            |       |" << endl;
   // line 34
   cout << "|       |            | # # # ####   #   #   # ###  #   # #    # #  |            |       |" << endl;
   // line 35 : display players board[15], board[35]
   cout << "|";
   board[15]->printPlayers();
   cout << "|            | # # # #  #   #   #   # #    #   # #     #   |            |";
   board[35]->printPlayers();
   cout << "|" << endl;
   // line 36
   cout << "|_______|            | ##### #  #   #    ###  #     ###  ####  #   |            |_______|" << endl;
   // line 37
   cout << "|";
   AcademicBuilding *ac7 = dynamic_cast<AcademicBuilding *>(board[14]); 
   improv = ac7->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|            |_____________________________________________|            |NEEDLES|" << endl;
   //line 38
   cout << "|-------|                                                                       |HALL   |" << endl;
   // line 39
   cout << "|CPH    |                                                                       |       |" << endl;
   // line 40 : display players board[14], board[36]
   cout << "|";
   board[14]->printPlayers();
   cout << "|                                                                       |";
   board[36]->printPlayers();
   cout << "|" << endl;
   // line 41
   cout << "|_______|                                                                       |_______|" << endl;
   // line 42
   cout << "|";
   AcademicBuilding *ac8 = dynamic_cast<AcademicBuilding *>(board[13]); 
   improv = ac8->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|                                                                       |";
   AcademicBuilding *ac9 = dynamic_cast<AcademicBuilding *>(board[37]); 
   improv = ac9->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|" << endl;
   // line 43 
   cout << "|-------|                                                                       |-------|" << endl;
   // line 44
   cout << "|DWE    |                                                                       |MC     |" << endl;
   // line 45 : display players board[13], board[37]
   cout << "|";
   board[13]->printPlayers();
   cout << "|                                                                       |";
   board[37]->printPlayers();
   cout << "|" << endl;
   // line 46
   cout << "|_______|                                                                       |_______|" << endl;
   // line 47
   cout << "|PAC    |                                                                       |COOP   |" << endl;
   // line 48
   cout << "|       |                                                                       |FEE    |" << endl;
   // line 49
   cout << "|       |                                                                       |       |" << endl;
   // line 50 : display players board[12], board[38]
   cout << "|";
   board[12]->printPlayers();
   cout << "|                                                                       |";
   board[38]->printPlayers();
   cout << "|" << endl;
   // line 51
   cout << "|_______|                                                                       |_______|" << endl;
   // line 52
   cout << "|";
   AcademicBuilding *ac10 = dynamic_cast<AcademicBuilding *>(board[11]); 
   improv = ac10->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|                                                                       |";
   AcademicBuilding *ac11 = dynamic_cast<AcademicBuilding *>(board[39]); 
   improv = ac11->getCurrentLevel();
   for(int j = 0; j < improv; ++j){
      cout << "I";
   }
   nspace = 8 - improv - 1;
   for(int x = 0; x < nspace; ++x){
      cout <<" ";
   }
   cout << "|" << endl;
   // line 53
   cout << "|-------|                                                                       |-------|" << endl;
   // line 54
   cout << "|RCH    |                                                                       |DC     |" << endl;
   // line 55 : display players board[11], board[39]
   cout << "|";
   board[11]->printPlayers();
   cout << "|                                                                       |";
   board[39]->printPlayers();
   cout << "|" << endl;
   // line 56
   cout << "|_______|_______________________________________________________________________|_______|" << endl;
   // line 57
   for(int i = 10; i >= 0; --i){
      if(board[i]->getName() == "DC Tims Line"){
         cout << "|DC Tims";                       
      }
      else if(board[i]->getName() == "NEEDLES HALL"){
         cout << "|NEEDLES";
      }
      else if(board[i]->getName() == "MKV"){
         cout << "|MKV    ";
      }
      else if(board[i]->getName() == "TUITION"){
         cout << "|TUITION";
      }
      else if(board[i]->getName() == "SLC"){
         cout << "|SLC    ";
      }
      else if(board[i]->getName() == "COLLECT OSAP"){
         cout << "|COLLECT";
      }
      else {
         cout << "|";
         AcademicBuilding *ac = dynamic_cast<AcademicBuilding *>(board[i]);
         improv = ac->getCurrentLevel();
         for(int j = 0; j < improv; ++j){
            cout << "I";
         }
         nspace = 8 - improv - 1;
         for(int x = 0; x < nspace; ++x){
            cout <<" ";
         }
      }
   }
   cout << "|" << endl;
   // line 58
   for(int i = 10; i >=0; --i){
      if(board[i]->getName() == "DC Tims Line"){
         cout << "|Line   ";                       
      }
      else if(board[i]->getName() == "NEEDLES HALL"){
         cout << "|HALL   ";
      }
      else if(board[i]->getName() == "MKV" && board[i]->getName() == "TUITION" && board[i]->getName() == "SLC"){
         cout << "|       ";
      }
      else if(board[i]->getName() == "COLLECT OSAP"){
         cout << "|OSAP   ";
      }
      else {
         cout << "|-------";
      }
   }
   cout << "|" << endl;
   // line 59
   for(int i = 10; i >= 0; --i){
      if(board[i]->getName() != "DC Tims Line" && board[i]->getName() != "NEEDLES HALL" && \
         board[i]->getName() != "MKV" && board[i]->getName() != "TUITION" && board[i]->getName() != "SLC" \
         && board[i]->getName() != "COLLECT OSAP"){
      cout << "|" << left << setfill(' ') << setw(7) << board[i]->getName();
      }
      else{
         cout << "|       ";
      }
   }
   cout << "|" << endl;
   //line 60
   for(int i = 10; i >= 0;--i){
      cout << "|";
      board[i]->printPlayers();
      
   }
   cout << "|" << endl;
   // line 61
   for(int i = 0; i < 11;++i){
      cout << "|_______";
   }
   cout << "|" << endl;
}






  
