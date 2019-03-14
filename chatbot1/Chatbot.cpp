#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define CHATBOT_CAPACITY 6
class Agent {
    public:
    string percept;
    string intro(){
    return "Bem-vindo!";
    }
    string questions[CHATBOT_CAPACITY]={
    "1",
    "2",
    "3",
    "4",
    "5",
    "adeus"
    };

    string answers[CHATBOT_CAPACITY]={
    "resposta 1",
    "resposta 2",
    "resposta 3",
    "resposta 4",
    "resposta 5",
    "ate breve"
    };
    void sense(string percept){
    this->percept = percept;
    }
    string act(){
        string answer = "Desculpe, mas nao entendi a pergunta...";

        bool found=false;
        int i=0;
        while (!found && i<CHATBOT_CAPACITY){
            if(questions[i].compare(percept)==0){
                found = true;
                answer = answers[i];

            }
            i=i+1;
        }
        return answer;
    }
    };
int main(){
    Agent chatbot;
    string question ="";
    cout<< chatbot.intro()<<endl<<endl;

    while(question.compare("adeus")!=0){
        getline(cin, question);
        chatbot.sense(question);
        string answer = chatbot.act();
        cout<<answer<<endl<<endl;
    }
    return 0;
}

