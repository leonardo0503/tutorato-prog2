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
        cout<<"seleziona l'indice della risposta corretta"<<endl;
    }
    bool verifica(int guess){
        if(guess==this->correct)
        return true;
        else
        return false;
    }

};

int main(int argc, char**argv){
    //inizializzo varabili per verificare il numero di domande
    int count=0;
    string line;
    //apertura del file per contare il nuemro di righe
    ifstream infile("milionario.txt");
    if(!infile.is_open()){
        cerr << "errore nell'apertura del file"<< endl;
        return 1;
    }
    while(getline(infile,line)){
        count++;
    }
    count=count/6;
    infile.close();
    
    //apertura del file per la lettura delle domande
    ifstream file("milionario.txt");
    if(!file.is_open()){
        cerr << "errore nellapertura del file"<<endl;
        return 1;
    }
    int corrette=0;
    for(int i=0;i<count;i++){
        //variabili temporanee per la lettura del file
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
        
        if(domanda_1.verifica(guess)){
            corrette++;
        }
    }
    float percentuale=0;
    percentuale =(corrette*100)/count;
    
    cout<<"hai totalizzato il "<<percentuale<<"%"<<endl;
    
    file.close();
    return 0;
}