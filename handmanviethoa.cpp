#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
string chooseWord(){
    string words[] = {"hello","human", "actor" ,"drive","pilot" ,"niece" ,"uncle", "photo" ,"watch" , "eight" ,"quick" ,"happy","study","learn" ,"above","begin","false","lemon","birth","fruit" ,"drink","train" ,"woman","women","break","small","lucky","money","month","young","messi", };
    int nWords = sizeof(words) / sizeof(string);
    srand(time(NULL));
    int randomIndex = rand() % nWords;
    return words[randomIndex];
}

bool contains(string word, char guess){ // tra ve true khi xau co ki tu guess,
    //int n=word.length();
    for ( int i =0 ; i <word.length(); i++){
        if ( word[i] == guess ) return true;
    }
    return false;
}/**/
string getHanger(int badGuessCount){
    string a,b,c,d,e,f,g;
   a=" | \n";
    b=" O \n";
    c="/";
    d="|";
    e="\\\n";
    f="/";
    g=" \\\n";
    switch (badGuessCount){
        case 1 : return a;
        case 2 : return a+b;
        case 3 : return a+b+c;
        case 4 : return a+b+c+d;
        case 5 : return a+b+c+d+e;
        case 6 : return a+b+c+d+e+f;
        case 7 : return a+b+c+d+e+f+g;
        default :return"";
    }
} 

 void renderGame(string guessedWord, int badGuessCount){ // gia treo co , tu doan dc
system("cls");
	
    cout << "Du doan hien tai = "<< guessedWord <<"\n\n" << "Ban da co "<< badGuessCount <<" du doan sai"<<endl<<endl;
 	cout <<getHanger(badGuessCount) << endl<< endl;
 	if ( badGuessCount != 7) cout <<"Hay nhap 1 chu cai (ko viet hoa) du doan vao day : "<<endl <<endl; 
 }

 char readAGuess(){ // chua can
    char a;
    cin >> a;

   //cout <<"Hay nhap 1 chu cai (ko viet hoa) du doan vao day : "<<endl;
   
    return a;
}

string update(string guessedWord, string word, char guess){ // update guess word

     for ( int i =0 ; i <word.length(); i++){
        if ( word[i] == guess ) guessedWord[i]=guess;
    }
    return guessedWord;
}

int main () {
	int choice;
    
	do{
    string word=chooseWord(), guessedWord="-----";
    char guess;
    int badGuessCount=0;
    renderGame(guessedWord,badGuessCount);
    while ( badGuessCount <7 && word != guessedWord ){
        guess = readAGuess();
        if (contains( word,guess)){
           guessedWord = update(guessedWord,word,guess);
        }
        else badGuessCount++;
        renderGame(guessedWord,badGuessCount);
    }
   if (word == guessedWord){
        cout << "Chuc mung ban da thang cuoc"<<endl<<endl;
   		cout << "Hay nhap  so 1 hoac so 2. " << endl<<endl ;
		cout << "1  :  Choi lai, toi muon thu suc lan nua\n2  :  Dung cuoc choi , vi no qua don gian :) " << endl << endl;
		cout << "Nhap su lua chon cua ban : ";
		cin >> choice;   	
   }
    else {
		cout <<"Ban that la ngu ngoc, nen bi treo co la phai\n\nDap an la: "<<word << endl << endl;
   		cout << "Hay nhap  so 1 hoac so 2. " << endl << endl;
		cout << "1  : Choi lai, toi muon thu suc lan nua\n2  : Dung cuoc choi , vi toi qua ngu, khong the choi duoc :) " << endl<< endl;
		cout << "Nhap su lua chon cua ban : ";
		cin >> choice;  
    }
}
	while ( choice == 1);


    return 0;
}


