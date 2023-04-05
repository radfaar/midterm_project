
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

    Genome(string _DNA1,string _DNA2, string _RNA){
        DNA1 = _DNA1;
        DNA2 = _DNA2;
        RNA = _RNA;
    }

    Genome(){}

    //recieving RNA
    void getRNA(){
        cout << RNA << endl;
    }
    //recieving DNA in 2 lines
    void getDNA(){
        
        cout << DNA1 << endl;
        cout<<  DNA2 << endl;
       
    }

    void print() {
        cout << "RNA: "<< endl;
        getRNA();
        cout<< "_____" <<endl;
        cout << "DNA :" << endl;
        getDNA();
        cout<< "_____" <<endl;
    }

    //RNA or DNA supplement
    string mokamel(string RNA){
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
    void correctDNA(){
        
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
    string makeDNA(string _RNA){
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
     void replaceChar(char charToReplace, char charReplacement, int n){
        
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

        cout << "Debug" << DNA1 << endl;
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
    

     void hugejump(string stringtofind, string stringtoreplace){

        

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


    void diverse_jump(string s1){
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
    


    friend class cell;

    };



class Cell{
    public:
    
    vector <Genome> myVec;
    int counter=0;


    void push(Genome chr) {
        myVec.push_back(chr);
    }

    void number_of_chromosomes(){
        for(int i = 0 ; i< myVec.size() ; i++){
            if(myVec[i].DNA1!= " " && myVec[i].DNA2!= ""){
                counter++;
                
            }
        }
        cout<< counter;
    }


    void cell_death(){
      
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

    void hugeJump(string s1 , int n, string s2, int m){
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


    void replaceChar(char charToReplace, char charReplacement, int n,int m){

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
            
            }}
            myVec[m].correctDNA();

    }

    
    void diverse_jump(string s, int n){

        if(myVec[n].DNA1.find(s) != string :: npos){

            myVec[n].mokamel(s);
        }
        
        if(myVec[n].DNA2.find(s) != string :: npos){

            myVec[n].mokamel(s);
        }

        myVec[n].correctDNA();

    }


    bool isPalindrome(string str){ 
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

    void substringPalindrome(string a) { 
        for(int i = 0 ; i < a.length(); i++){ 
            for(int j = i; j < a.length(); j++){ 
                string sub = a.substr(i,j-i+1); 
                if(isPalindrome(sub)){ 
                    cout << sub << endl; 
                } 
            } 
        } 
    }


    void find_palindrome(Genome chromosome){
        substringPalindrome(chromosome.DNA1);
        substringPalindrome(chromosome.DNA2);
    }

 };

class Animal : public Cell{
    
    double similarity(Animal& another){
        int similar_chromosomes = 0;
        int maximum = max(myVec.size() , another.myVec.size());
        int minimum = min(myVec.size() , another.myVec.size());
        for(int i = 0 ; i< minimum ; i++){

            if (myVec[i].DNA1 == another.myVec[i].DNA1 && myVec[i].DNA2 == another.myVec[i].DNA2 ){
                similar_chromosomes++;
            }
        }
        return (similar_chromosomes/maximum) *100;
    }

    bool operator==(Animal& animal){
        if(myVec.size() == animal.myVec.size() && similarity(animal) > 70){
            return true;
        }
        else{
            return false;
        }

    }

    Animal asexual_reproduction() {
        
        Animal child;
        int n = myVec.size();
        int new_size = n * 2;
        random_device rd;
        mt19937 g(rd());
        shuffle(myVec.begin() , myVec.begin()+new_size , g);

        int num =0;
        for( int i = 0; i< new_size && num < n; i += 2){
            
             child.myVec.push_back(myVec[i]);
             child.myVec.push_back(myVec[i + 1]);
             num++;
    }

        if(similarity(child) <= 70){
            child.myVec.clear();
        }

        return child;

    }

    Animal operator+(Animal& partner){
        Animal child;

        
        Animal parent1 = asexual_reproduction();
        Animal parent2 = partner.asexual_reproduction();

        int n = myVec.size();
        int new_size = n * 2;

        
        random_device rd;
        mt19937 g(rd());
        shuffle(parent1.myVec.begin(), parent1.myVec.end(), g);
        shuffle(parent2.myVec.begin(), parent2.myVec.end(), g);

        int num = 0;
        for(int i = 0; i < new_size && num < n; i += 2){
            child.myVec.push_back(parent1.myVec[i]);
            child.myVec.push_back(parent2.myVec[i + 1]);
            num++;
        }


        if(similarity(child) <= 70){
            child.myVec.clear();
        }

        return child;

    }

    void cell_death() {
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
};








int main(){

    vector<Genome> genomes;
    // add dummy data for ease of testing
    Genome g1("AAATTT","TTTAAA","AAATTT");
    Genome g2("CGCGCA","GCGCGT","CGCGCA");
    genomes.push_back(g1);
    genomes.push_back(g2);
    
    vector<Cell> cells;

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


            }

            if(_action == 6){
                int cellindex,n;
                string s;
                cout <<"which cell? enter frome 0 to " << cells.size()-1 << endl;
                cin >> cellindex;

                cout <<"enter sth that you wanna inverse it: " << endl;
                getline(cin,s);
                cout <<"enter the number of chromosome: " << endl;
                cin >> n;


                cells[cellindex].diverse_jump(s,n);

            }

            if(_action == 7){
                int cellindex,genomeindex;
                cout <<"which cell? enter from 0 to " << cells.size()-1 << endl;
                cin >> cellindex;
                cout <<  "which chromosome? enter a number from 0 to " << genomes.size()-1 <<  endl;
                cin >> genomeindex;
                cells[cellindex].find_palindrome(cells[cellindex].myVec[genomeindex]);

            }

        }


    }


    return 0;
}