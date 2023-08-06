//PHONE KEYPAD PROBLEM

#include<iostream>
#include<vector>
using namespace std;

void Solve(string digits,string output,int idx,vector<string>& ans,string mapping[]){

    //Base case
    if(idx >= digits.length()){
        ans.push_back(output);
        return;
    }

    int number = digits[idx] - '0';
    string value = mapping[number];

    for(int i = 0;i < value.length();i++){
        output.push_back(value[i]);
        Solve(digits,output,idx+1,ans,mapping);

        output.pop_back();
    }
}


vector<string> Phone_keypad(string digits){
    vector<string> ans;

    string output = "";
    int idx = 0;

    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    Solve(digits,output,idx,ans,mapping);

    return ans;
}

int main(){
    string digits = "23";

    vector<string> result = Phone_keypad(digits);

    for(int i = 0;i < result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}