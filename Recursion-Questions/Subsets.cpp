//SUBSETS PROBLEM

#include<iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums,vector<int> output,int idx,vector<vector<int>>& ans){
    //base case
    if(idx >= nums.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(nums,output,idx+1,ans);

    //include
    int number = nums[idx];
    output.push_back(number);
    solve(nums,output,idx+1,ans);
}

vector<vector<int>> Find_Subsets(vector<int> nums){
        vector<vector<int>> ans;
        int idx = 0;
        vector<int> output;

        solve(nums,output,idx,ans);

        return ans;
}

int main(){
    vector<int> nums = {1,2,3};

    vector<vector<int>> res = Find_Subsets(nums);

    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}