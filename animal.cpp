#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "animal.h"

double Animal::similarity(Animal& another){
    int similar_chromosomes = 0;
    int maximum = max(myVec.size() , another.myVec.size());
    int minimum = min(myVec.size() , another.myVec.size());
    for(int i = 0 ; i< minimum ; i++){
        if (myVec[i].DNA1 == another.myVec[i].DNA1 && myVec[i].DNA2 == another.myVec[i].DNA2 ){
            similar_chromosomes++;
        }
    }
    return (similar_chromosomes  *100 /maximum);
}
bool Animal::operator==(Animal& animal){
    if(myVec.size() == animal.myVec.size() && similarity(animal) > 70){
        return true;
    }
    else{
        return false;
    }
}
Animal Animal::asexual_reproduction() {
    Animal child;
    vector<Genome> copy;
    for(int i = 0 ; i < myVec.size() ; i++){
        copy.push_back(myVec[i]);
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(copy.begin() , copy.begin()+copy.size() , g);
    std::uniform_int_distribution<> distr(0,100); 
    for(int i = 0 ; i < myVec.size(); i++){
        if (distr(g) > 80) {
            child.push(copy[i]);
        }else{
            child.push(myVec[i]);
        }
    }
    return child;
}
Animal Animal::operator+(Animal& partner){
    Animal child;
    int n = myVec.size();
    if(n % 2 == 1) {
        cout << "N is odd, should be even" << endl;
        return child;
    }
    Animal c1 = asexual_reproduction();
    Animal c2 = partner.asexual_reproduction();
    random_device rd;
    mt19937 g(rd());
    std::uniform_int_distribution<> distr(0,100);
    for(int i = 0 ; i < n; i++){
        if (distr(g) > 50) {
            child.push(c1.myVec[i]);
        }else{
            child.push(c2.myVec[i]);
        }
    }
    return child;

}

void Animal::cell_death() {
    for(int i = 0; i < myVec.size() ; i++) {
        string str = myVec[i].DNA1 +  myVec[i].DNA2; 
        size_t finder1 = str.find('A');
        size_t finder2 = str.find('T');
        size_t finder3 = str.find('C');
        size_t finder4 = str.find('G');
        int counter1 = 0;
        int counter2 = 0;
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
        if(counter1 > (counter2 * 3)) {
           
            myVec.erase(myVec.begin() + i);
            break;
        }
    }
}