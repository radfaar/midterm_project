#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "genome.h"

using namespace std;

class Cell{
    public:
    vector <Genome> myVec;
    int counter=0;
    void push(Genome chr);
    void number_of_chromosomes();
    void cell_death();
    void hugeJump(string s1 , int n, string s2, int m);
    void replaceChar(char charToReplace, char charReplacement, int n,int m);   
    void diverse_jump(string s, int n);
    bool isPalindrome(string str);
    void substringPalindrome(string a);
    void find_palindrome(Genome chromosome);
    void print();
 };