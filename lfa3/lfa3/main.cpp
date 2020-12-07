//
//  main.cpp
//  lfa3
//
//  Created by Nikita Makeev on 12/5/20.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void initializationOfGrammer(vector<string>& first, vector<string>& second){
    first.push_back("S -> "); second.push_back("AC");
    first.push_back("S -> "); second.push_back("bA");
    first.push_back("S -> "); second.push_back("B");
    first.push_back("S -> "); second.push_back("aA");
    first.push_back("A -> "); second.push_back("EPSILON");
    first.push_back("A -> "); second.push_back("aS");
    first.push_back("A -> "); second.push_back("ABab");
    first.push_back("B -> "); second.push_back("a");
    first.push_back("B -> "); second.push_back("bS");
    first.push_back("C -> "); second.push_back("abC");
    first.push_back("D -> "); second.push_back("AB");
}
void printFunction(vector<string>& first, vector<string>& second){
        for (int i = 0; i < first.size(); i++) {
        cout<<i+1<<". "<<first[i]<<second[i]<<endl;
    }
}
void deleteEPSProd(vector<string>& first, vector<string>& second){
    for (int i = 0 ; i < first.size(); i++) {
        if (!(second[i].find_first_of("EPSILON"))) {
            second.erase(second.begin() + i);
            first.erase(first.begin() +i );
        
    }
}

        first.insert(first.begin(),"S -> "); second.insert(second.begin(),"a ");
        first.insert(first.begin(),"S -> "); second.insert(second.begin(),"b ");    first.insert(first.begin(),"S -> "); second.insert(second.begin(),"C ");
}
void deleteINACCESSandNEPROD(vector<string>& first, vector<string>& second){
    for (int i = 0; i < first.size() ; i++) {
        for (int j = 0; j < second.size(); j++) {
            if (first[i][j] == 'A') {
                first.erase(first.begin() + i );
                second.erase(second.begin() + i);
                i--;
                
            }
            if (second[i][j] == 'A') {
                second.erase(second.begin() + i);
                first.erase(first.begin() +i );
                i--;
            }
            if (second[i][j] == 'D') {
                second.erase(second.begin() + i);
                first.erase(first.begin() +i );
                i--;
            }
        }
    }
}
void deleteChainRules(vector<string>& first, vector<string>& second){
    for (int i = 0; i < first.size() ; i++) {
        for (int j = 0; j < second.size(); j++) {
            if (first[i][j] == 'S' && second[i][j] == 'C') {
                first.erase(first.begin() + i );
                second.erase(second.begin() + i);
                i--;
            }
            if (first[i][j] == 'S' && second[i][j] == 'B') {
                first.erase(first.begin() + i );
                second.erase(second.begin() + i);
                i--;
            }
        }
    }
    first.push_back("S -> "); second.push_back("bS");
    first.push_back("C -> "); second.push_back("bS");
    first.push_back("C -> "); second.push_back("a");
    first.push_back("S -> "); second.push_back("abC");
    swap(first[3], first[7]);
    swap(second[3], second[7]);
    swap(first[4], first[7]);
    swap(second[4], second[7]);
    swap(first[7], first[8]);
    swap(second[7], second[8]);
}
void chomskyNormalForm(vector<string>& first, vector<string>& second){
    for (int i = 0; i < first.size() ; i++) {
        for (int j = 0; j < second.size(); j++) {
            if (second[i][j] == 'b') {
                second[i][j] = 'Y';
            }
            if (second[i][j] == 'a') {
                second[i][j] = 'X';
            }
        }
    }
    first.push_back("Y -> "); second.push_back("b");
    first.push_back("X -> "); second.push_back("a");
}
    void chomskyNormalForm1(vector<string>& first, vector<string>& second){
        for (int i = 0; i < first.size() ; i++) {
            for (int j = 0; j < second.size(); j++) {
                if (second[i][j] == 'S') {
                    second[i][j] = 'Z';
            }
        }
    }
        first.push_back("Z -> "); second.push_back("S");
}
void chomskyNormalForm2(vector<string>& first, vector<string>& second){
    for (int i = 0; i < first.size() ; i++) {
        if (second[i] == "XYC") {
            second[i].replace(second[i].begin(), second[i].end(), "XZ2");
        }
    }
    first.push_back("YC -> "); second.push_back("Z2");
}
int main(int argc, const char * argv[]) {
    vector<string> first;
    vector<string> second;
    initializationOfGrammer(first, second);
    printFunction(first, second);
    cout<<"Удаляем эпсилон продукцию"<<endl;
    deleteEPSProd(first, second);
    printFunction(first, second);
    cout<<"Удаляем все недостижимые и не продуктивные правила "<<endl;
    deleteINACCESSandNEPROD(first, second);
    printFunction(first, second);
    cout<<"Удаляем цепные правила"<<endl;
    deleteChainRules(first, second);
    printFunction(first, second);
    cout<<"Приводим к нормальной форме Хомского "<<endl;
    chomskyNormalForm(first, second);
    printFunction(first, second);
    cout<<"Приводим к нормальной форме Хомского "<<endl;
    chomskyNormalForm1(first, second);
    printFunction(first, second);
    cout<<"Приводим к нормальной форме Хомского "<<endl;
    chomskyNormalForm2(first, second);
    printFunction(first, second);
    return 0;
}
