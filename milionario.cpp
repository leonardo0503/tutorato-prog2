#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class domanda{
    private:
    //define private element
    string question;
    string arr[4];
    int correct;

    public:
    //class constructor
    domanda(string domanda,string risposta1,string risposta2,string risposta3,string risposta4,int correct){
        this->question=domanda;
        this->arr[0]=risposta1;
        this->arr[1]=risposta2;
        this->arr[2]=risposta3;
        this->arr[3]=risposta4;
        this->correct=correct;
    }
    //methods
    void leggi_testo(){
        cout<<question<<endl;
        for(int i=0;i<4;i++){
            cout<<i+1<<":"<<arr[i]<<endl;
        }
    }
    bool verifica(int guess){
        if(guess==this->correct)
        return true;
        else
        return false;
    }

};

int main(int argc, char**argv){

    //input file (da fare)
    ifstream file("milionario.txt");
    if(!file.is_open()){
        cerr << "errore nellapertura del file"<<endl;
        return 1;
    }
    

    //function
    while(1){
        string question;
        getline(file,question);
        string risposta1;
        getline(file,risposta1);
        string risposta2;
        getline(file,risposta2);
        string risposta3;
        getline(file,risposta3);
        string risposta4;
        getline(file,risposta4);
        int correct;
        file >> correct;
        file.ignore();
        //constructor for question
        domanda domanda_1(question,risposta1,risposta2,risposta3,risposta4,correct);
        domanda_1.leggi_testo();
        int guess;
        cin >> guess;
        domanda_1.verifica(guess);
        if(guess==0){
            break;
        }
    }
    
    file.close();
    return 0;
}