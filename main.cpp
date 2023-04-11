
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "animal.h"

using namespace std;

int main(){

    vector<Genome> genomes;
    vector<Cell> cells;
    vector<Animal> animals;

    // add dummy data for ease of testing
    Genome g1("AAATTT","TTTAAA","AAATTT");
    Genome g2("CGCGCA","GCGCGT","CGCGCA");
    Genome g3("CGCGCC","GCGCGC","CGCGCG");
    genomes.push_back(g1);
    genomes.push_back(g2);
    
    Cell c1;
    c1.push(g1);
    c1.push(g2);
    Cell c2;
    c2.push(g1);
    c2.push(g3);
    cells.push_back(c1);
    cells.push_back(c2);

    Animal a1;
    a1.push(g1);
    a1.push(g1);
    a1.push(g1);
    a1.push(g1);
    a1.push(g3);
    Animal a2;
    a2.push(g1);
    a2.push(g1);
    a2.push(g1);
    a2.push(g1);
    a2.push(g2); // Animal1 and animal2 have 80 percent similarity.
    Animal a3;
    a3.push(g1);
    a3.push(g3);
    a3.push(g2);
    a3.push(g3);
    a3.push(g2);
    a3.push(g1);
    a3.push(g1);
    a3.push(g2);
    a3.push(g3);
    a3.push(g3);
    Animal a4;
    a4.push(g2);
    a4.push(g2);
    a4.push(g2);
    a4.push(g3);
    a4.push(g1);
    a4.push(g1);
    a4.push(g1);
    a4.push(g3);
    a4.push(g2);
    a4.push(g1);
    animals.push_back(a1);
    animals.push_back(a2);
    animals.push_back(a3); 
    animals.push_back(a4);

    while(true){
        int type;
        cout << endl << "________________" << endl << "Which entity do you want to work with?" << endl;
        cout << "1) Genome" << endl << "2) Cell" << endl << "3) animal" << endl;
        cin >> type;
        
        if (type == 1){
            int action;
            cout << "What do you want me to do?" << endl;
            cout << "1) Create a new genome" << endl;
            cout << "2) Make a DNA by RNA" << endl;
            cout << "3) Make a small jump (A, C, n)" << endl;
            cout << "4) Make a huge jump (S1, S2)" << endl;
            cout << "5) Make a diverse jump (S1)" << endl;
            cin >> action;

            if(action == 1){
                string dna1,dna2,rna;
                cout << "Enter the RNA: (can be empty if you want to enter DNA only)" << endl;
                cin >> rna;
                cout << "Enter the DNA:" << endl;
                cin >> dna1;
                cout << "Enter the DNA's complement:" << endl;
                cin >> dna2;
                Genome genome(dna1,dna2,rna);
                genomes.push_back(genome);
                cout << ">> Your new genome's index is: " << genomes.size() -1 << endl << endl;;
            }

            if(action == 2){
                string rna;
                cout << "Enter the RNA:" << endl;
                cin >> rna;
                Genome genome;
                cout << genome.makeDNA(rna) << endl;
            }

            if(genomes.size() == 0){
                cout << "No genome has been created!" << endl;
                continue;
            }

            int genomeIndex;
            cout << "Which genome? from 0 to " << genomes.size()-1 << endl;
            cin >> genomeIndex;

            if(action == 3){
                char A, C;
                int N;
                cout << "Enter the A: " << endl;
                cin >> A;
                cout << "Enter the C: " << endl;
                cin >> C;
                cout << "Enter the N: " << endl;
                cin >> N;

                genomes[genomeIndex].replaceChar(A, C, N);
                genomes[genomeIndex].print();

            }

            if(action == 4){
                string s1,s2;
                cout << "Enter s1: "<< endl;
                cin >> s1;
                cout << "Enter s2: "<< endl;
                cin >> s2;
                genomes[genomeIndex].hugejump(s1, s2);
                genomes[genomeIndex].print();
            }

            if (action == 5) {
                string s1;
                cout << "Enter s1: "<< endl;
                cin >> s1;
                genomes[genomeIndex].diverse_jump(s1);
                genomes[genomeIndex].print();
            }

        }

        if (type == 2) {
            int _action;
            cout << "what do you want to do?"<< endl;
            cout << "1) create a cell" << endl;
            cout << "2) save the number of chromosomes and the DNAs " << endl;
            cout << "3) delete the cell using cell_death " << endl;
            cout << "4) make a huge modify in chromosome (S1,n,S2,m) "<< endl;
            cout << "5) replace N nuclide of the Mth chromosome with another nuclide (A,C,n,m)" <<endl;
            cout << "6) make a diverse jump in the Nth chromosome (S1,n)" << endl;
            cout << "7) find complement palindromes in chromosome" << endl;
            cin >> _action;


            if(_action == 1){
                    int genomeindex;
                    Cell cell;
                    while(true){
                    
                    cout<< "Please enter your genome index" << endl;
                    cin>> genomeindex;
                    if(genomeindex == -1){
                        break;
                    }
                    cell.push(genomes[genomeindex]);
                    cout<< "Genome #" << genomeindex << " added to cell. add another ID or press -1 to finish the process"<< endl;

                    }
                    cells.push_back(cell);
                    
                    cout<< "ID of new cell is: " << cells.size()-1 << endl;

                
            }

            if(_action == 2){
                
                int cellindex;
                cout << "which cell? enter frome 0 to " << cells.size()-1 << endl;
                cin>> cellindex;
                cells[cellindex].number_of_chromosomes();

                if(cells.size() == 0){
                    cout<< "No cell has been created"<< endl;
                    continue;
                }

            }

            if(_action == 3){

                int cellindex;
                cout << "which cell? enter frome 0 to " << cells.size()-1 << endl;
                cin>> cellindex;
                cells[cellindex].cell_death();

                if(cells.size() == 0){
                    cout<< "No cell has been created"<< endl;
                    continue;
                }                


            }

            if(_action == 4){
                string S1;
                string S2;
                int n,m,cellindex;
                cout<<"which cell? enter frome 0 to " << cells.size()-1 << endl;
                cin>> cellindex;
                cout << "so you are going to make a huge change" << endl;
                cout << "enter S1 (sth to replace): "<< endl;
                cin >> S1;
                cout << "enter S2 (sth that is gonna be replace with): "<< endl;
                cin >> S2;
                cout << "enter n (number of first chromosome): "<< endl;
                cin >> n;
                cells[cellindex].myVec[n].print();
                cout << "enter m (number of second chromosome): "<< endl;
                cin >> m;
                cells[cellindex].myVec[m].print();
                cells[cellindex].hugeJump(S1,n,S2,m);



            }

            if(_action == 5){
                char chartoreplace, charreplacement;
                int n,m,cellindex;              
                cout << "OK! you are making small change in your cell."<< endl;
                cout<<"which cell? enter frome 0 to " << cells.size()-1 << endl;
                cin>> cellindex;       
                cout << "enter the nuclide to replace: "<< endl;
                cin >> chartoreplace;
                cout << "enter the nuclide to be replaced with: " << endl;
                cin >> charreplacement;
                cout<< "enter the number of nuclides to replace: " << endl;
                cin >> n;
                cout<< "enter the index of chromosome: " << endl;
                cin >> m;
                



                cells[cellindex].replaceChar(chartoreplace,charreplacement,n,m);
                cells[cellindex].print();


            }

            if(_action == 6){
                int cellindex,n;
                string s;
                cout <<"which cell? enter frome 0 to " << cells.size()-1 << endl;
                cin >> cellindex;

                cout <<"enter sth that you wanna inverse it: " << endl;
                cin >> s;
                cout <<"enter the number of chromosome: " << endl;
                cin >> n;


                cells[cellindex].diverse_jump(s,n);
                cells[cellindex].print();

            }

            if(_action == 7){
                int cellindex,genomeindex;
                cout <<"which cell? enter from 0 to " << cells.size()-1 << endl;
                cin >> cellindex;
                cout <<  "which chromosome? enter a number from 0 to " << genomes.size()-1 <<  endl;
                cin >> genomeindex;
                cout << "Palindromes are : " << endl;
                cells[cellindex].find_palindrome(cells[cellindex].myVec[genomeindex]);
            }

        }

        if (type == 3) {
            int _action;
            cout << "what do you want to do?"<< endl;
            
            cout << "1) genetics similarity" << endl;
            cout << "2) check whether two animals are the same ( with == )" << endl;
            cout << "3) for an asexual reproduction of an animal" << endl;
            cout << "4) for sexual reproduction of two animals" << endl;
            cin >> _action;

            if (_action == 1) {
                int c1Index, c2Index;
                cout << "Enter the first animal's index:" << endl;
                cin >> c1Index;
                cout << "Enter the second animal's index:" << endl;
                cin >> c2Index;
                cout << "The similarity is " << animals[c1Index].similarity(animals[c2Index]) << endl;
            }

            if (_action == 2) {
                int c1Index, c2Index;
                cout << "Enter the first animal's index:" << endl;
                cin >> c1Index;
                cout << "Enter the second animal's index:" << endl;
                cin >> c2Index;
                if (animals[c2Index] == animals[c1Index]) {
                    cout << "They are the same!" << endl;
                }else{
                    cout << "They're not the same!" << endl;
                }
            }

            if (_action == 3) {
                int c1Index;
                cout << "Enter the animal's index:" << endl;
                cin >> c1Index;
                Animal baby = animals[c1Index].asexual_reproduction();
                cout << "The baby:" << endl;
                baby.print();
                animals.push_back(baby);
                cout << "The baby's index is: " << animals.size() -1 << endl;
            
            }
            if (_action == 4) {
                int c1Index, c2Index;
                cout << "Enter the first animal's index:" << endl;
                cin >> c1Index;
                cout << "Enter the second animal's index:" << endl;
                cin >> c2Index;
                Animal baby = animals[c1Index] + animals[c2Index];
                cout << "The baby:" << endl;
                baby.print();
                animals.push_back(baby);
                cout << "The baby's index is: " << animals.size() -1 << endl;
            }
        }


    }


    return 0;
}