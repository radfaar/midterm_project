#include "cell.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void Cell::push(Genome chr) {
    myVec.push_back(chr);
}

void Cell::number_of_chromosomes(){
    for(int i = 0 ; i< myVec.size() ; i++){
        if(myVec[i].DNA1!= " " && myVec[i].DNA2!= ""){
            counter++;
            
        }
    }
    cout<< counter;
}

void Cell::cell_death(){
      
    for(int i = 0; i < myVec.size() ; i++){

    string str= myVec[i].DNA1 +  myVec[i].DNA2; 

    size_t finder1= str.find('A');
    size_t finder2= str.find('T');
    size_t finder3= str.find('C');
    size_t finder4= str.find('G');

    int counter1=0;
    int counter2=0;

    while(finder1 != string::npos && finder2 != string::npos) {
                
        finder1 = str.find('A', finder1+1);
        finder2 = str.find('T', finder2+1);

        counter1++;
    }

    while(finder3 != string::npos && finder4 != string::npos) {
                
        finder3 = str.find('C', finder3+1);
        finder4 = str.find('G', finder4+1);

        counter2++;
    }

    if(counter1 > (counter2 *3)){
        delete this;
    }

    break;
    }
}

void Cell::hugeJump(string s1 , int n, string s2, int m){
    size_t  indexN = myVec[n].DNA1.find(s1);
    size_t  indexM = myVec[m].DNA1.find(s2);

    if(indexM == std::string::npos || indexN == std::string::npos)
        return;
        
    myVec[n].DNA1.replace(indexN,s1.length(),s2);
    myVec[m].DNA1.replace(indexM,s2.length(),s1);

    string ms1 = myVec[n].mokamel(s1);
    string ms2 = myVec[m].mokamel(s2);

    myVec[n].DNA2.replace(indexN,s1.length(),ms2);
    myVec[m].DNA2.replace(indexM,s2.length(),ms1);

    myVec[n].getDNA();
    myVec[m].getDNA();
}


void Cell::replaceChar(char charToReplace, char charReplacement, int n,int m){

    int counter=0;
    for(int i = 0; i< myVec.size(); i++){
        for(int j=0 ;j < myVec[m].DNA1[i] ; j++ ){
        if(myVec[m].DNA1[i] == charToReplace){
            myVec[m].DNA1[i] = charReplacement;
            counter++;
            }

            if(counter == n){
                break;
            }
            
        }
    }
    myVec[m].correctDNA();

}

void Cell::diverse_jump(string s, int n){
    size_t pos = myVec[n].DNA1.find(s);
    if(pos != string :: npos){
        string mok = myVec[n].mokamel(s);
        myVec[n].DNA1.replace(pos,s.length(),mok);
        myVec[n].DNA2.replace(pos,s.length(),s);
    }
}


bool Cell::isPalindrome(string str){ 
    if(str.length() <= 2 || (str.length() % 2) != 0) { 
        return false; 
    } 
    for(int i = 0 ; i < str.length()/2; i++) { 
        char curr = str[i]; 
        char mokamel = 'T'; 

        if(curr == 'A') 
            mokamel = 'T'; 
        if(curr == 'T') 
            mokamel = 'A'; 

        if(curr == 'G') 
            mokamel = 'C'; 
        if(curr == 'C') 
            mokamel = 'G'; 
        
        if(str[str.length()-1-i] != mokamel){ 
            return false; 
        } 
    } 
    return true; 
}

void Cell::substringPalindrome(string a) { 
    for(int i = 0 ; i < a.length(); i++){ 
        for(int j = i; j < a.length(); j++){ 
            string sub = a.substr(i,j-i+1); 
            if(isPalindrome(sub)){ 
                cout << sub << endl; 
            } 
        } 
    } 
}

void Cell::find_palindrome(Genome chromosome){
    substringPalindrome(chromosome.DNA1);
}
void Cell::print() {
    cout << "cell's content:" << endl;
    for(int i = 0 ; i < myVec.size();i++)
        cout << myVec[i].DNA1 << " | " << myVec[i].DNA2 << endl;
}