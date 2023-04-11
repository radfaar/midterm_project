#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "genome.h"

using namespace std;


Genome::Genome(string _DNA1,string _DNA2, string _RNA){
    DNA1 = _DNA1;
    DNA2 = _DNA2;
    RNA = _RNA;
}
Genome::Genome(){}
//recieving RNA
void Genome::getRNA(){
    cout << RNA << endl;
}
//recieving DNA in 2 lines
void Genome::getDNA(){
    
    cout << DNA1 << endl;
    cout<<  DNA2 << endl;
   
}
void Genome::print() {
    cout << "RNA: "<< endl;
    getRNA();
    cout<< "_____" <<endl;
    cout << "DNA :" << endl;
    getDNA();
    cout<< "_____" <<endl;
}

//RNA or DNA supplement
string Genome::mokamel(string RNA){
    string RNA__ = "";
    for(int i = 0; i < RNA.size(); i++){
        if(RNA[i] == 'A'){
            RNA__ += 'T';
        }
        else if(RNA[i] == 'T'){
            RNA__ += 'A';
        }
        else if(RNA[i] == 'C'){
            RNA__ += 'G';
        }
        else if(RNA[i] == 'G'){
            RNA__ += 'C';
        }
    }
    return RNA__;
}
//used to correct DNA after replacements
void Genome::correctDNA(){\    
    for(int i=0; i<DNA1.size(); i++){
        if(DNA1[i] == 'A'){
            DNA2[i] = 'T';
        }
        else if(DNA1[i] == 'T'){
            DNA2[i] = 'A';
        }
        else if(DNA1[i] == 'C'){
            DNA2[i] = 'G';
        }
        else if(DNA1[i] == 'G'){
            DNA2[i] = 'C';
        }
    }
    for(int i=0; i<DNA2.size(); i++){
        if(DNA2[i] == 'A'){
            DNA1[i] = 'T';
        }
        else if(DNA2[i] == 'T'){
            DNA1[i] = 'A';
        }
        else if(DNA2[i] == 'C'){
            DNA1[i] = 'G';
        }
        else if(DNA2[i] == 'G'){
            DNA1[i] = 'C';
        }
    }
}

//making DNA from RNA
string Genome::makeDNA(string _RNA){
    string DNA__ = "";
    for(int i = 0; i < _RNA.size(); i++){
        if(_RNA[i] == 'A'){
            DNA__ += 'T';
        }
        else if(_RNA[i] == 'T'){
            DNA__ += 'A';
        }
        else if(_RNA[i] == 'C'){
            DNA__ += 'G';
        }
        else if(_RNA[i] == 'G'){
            DNA__ += 'C';
        }
    }
    return DNA__ + "\n" + mokamel(DNA__);
}


//making a change by replacing n characters with another one
void Genome::replaceChar(char charToReplace, char charReplacement, int n){
    
    int counter=0;
    for(int i = 0; i < DNA1.size(); i++){
       
        if(DNA1[i] == charToReplace){
            DNA1[i] = charReplacement;
            counter++;
        }
        if(counter == n){
            break;
        }
        
    }
    correctDNA();
    counter=0;
    for(int i = 0; i < RNA.size(); i++){
        
        if(RNA[i] == charToReplace){
            RNA[i] = charReplacement;
            counter++;
            if(counter == n){
                break;
            }
        }
    }
}
    

void Genome::hugejump(string stringtofind, string stringtoreplace){
    if(RNA.find(stringtofind)!= string::npos){
        RNA.replace(RNA.find(stringtofind), stringtofind.length(), stringtoreplace);
    }
    if(DNA1.find(stringtofind) != string::npos) {
         DNA1.replace(DNA1.find(stringtofind), stringtofind.length(), stringtoreplace);
    }

    if(DNA2.find(stringtofind) != string::npos) {
         DNA2.replace(DNA2.find(stringtofind), stringtofind.length(), stringtoreplace);
    }
    correctDNA();
}


void Genome::diverse_jump(string s1){
    size_t in_rna = RNA.find(s1);
    if(in_rna != string::npos){
        RNA.replace(in_rna,s1.length(), mokamel(s1));
    }
    size_t in_dna = DNA1.find(s1);
    if(in_dna != string::npos){
        DNA1.replace(in_dna,s1.length(), mokamel(s1));
    }
    correctDNA();
}
