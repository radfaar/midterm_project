
#include <iostream>
#include <vector>
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

    //recieving RNA
    void getRNA(){
        cout << RNA << endl;
    }
    //recieving DNA in 2 lines
    void getDNA(){
        
        cout << DNA1 << endl;
        cout<<  DNA2 << endl;
       
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
        for(int i = 0; i < DNA1.size() && i<DNA2.size(); i++){
           
            if(DNA1[i] == charToReplace){
                DNA1[i] = charReplacement;
                counter++;
                }
            if(DNA2[i] == charToReplace)    
               { DNA2[i] = charReplacement;
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

         if(RNA.find(s1)!= string::npos){
            mokamel(s1);
            cout<< RNA;

         }


         if(DNA1.find(s1) != string::npos){
            mokamel(s1);

         }

         if(DNA2.find(s1) != string::npos){
            mokamel(s1);
         }

         correctDNA();

    }
    


    friend class cell;

    };



class cell{
    public:
    
    vector <Genome> myVec;
    int counter=0;


    void push(Genome chr) {
        myVec.push_back(chr);
    }

    void number_of_chromosomes(){
        for(int i = 0 ; i< myVec.size() ; i++){
            if(myVec[i].DNA1== " " && myVec[i].DNA2== ""){
                counter++;
                myVec[i].getDNA();
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

       while( finder1 and finder2 != string :: npos){
        counter1++;
       }

       while( finder3 and finder4 != string :: npos){
        counter2++;
       }

       if(counter1 > (counter2 *3)){
        delete this;
       }


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
    }


    void replaceChar(char charToReplace, char charReplacement, int n,int m){

        int counter=0;
        for(int i = 0; i< myVec.size(); i++){
           for(int j=0 ;j < myVec[m].DNA1[i] && myVec[m].DNA2[i] ; j++ ){
            if(myVec[m].DNA1[i] == charToReplace){
                myVec[m].DNA1[i] = charReplacement;
                counter++;
                }
            if(myVec[m].DNA2[i] == charToReplace)    
               { myVec[m].DNA2[i] = charReplacement;
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





int main(){
    cell c;
    Genome g1("AATTCC","TTAAGG","");
    Genome g2("ATATCT","TATAGT","");
    Genome g3("CGATC","GCTAG","");
    c.push(g1);
    c.push(g2);
    c.push(g3);

    c.hugeJump("AA",0,"CG",2);
    cout << c.myVec[0].DNA1 << " | " << c.myVec[0].DNA2 << endl;
    cout << c.myVec[2].DNA1 << " | " << c.myVec[2].DNA2 << endl;
    return 0;
}