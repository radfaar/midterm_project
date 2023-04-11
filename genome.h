#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Genome{
public:
    string DNA1;
    string DNA2;
    string RNA;

    Genome(string _DNA1,string _DNA2, string _RNA);

    Genome();

    //recieving RNA
    void getRNA();
    //recieving DNA in 2 lines
    void getDNA();
    void print() ;
    //RNA or DNA supplement
    string mokamel(string RNA);
    //used to correct DNA after replacements
    void correctDNA();
    //making DNA from RNA
    string makeDNA(string _RNA);
    //making a change by replacing n characters with another one
    void replaceChar(char charToReplace, char charReplacement, int n);
    void hugejump(string stringtofind, string stringtoreplace);
    void diverse_jump(string s1);
};