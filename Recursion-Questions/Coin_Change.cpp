#include<iostream>
using namespace std;

int solve(int coins[],int n,int sum,int currentIdx){
    //base case
    if(sum < 0){
        return 0;
    }
    if(sum == 0){
        return 1;
    }

    int ways = 0;

    for(int i = currentIdx;i < n;i++){
        ways += solve(coins,n,sum-coins[currentIdx],i);
    }

    return ways;
}

int get_ways(int coins[],int n,int sum){
    int currentIdx = 0;

    int ways = solve(coins,n,sum,currentIdx);

    return ways;
}

int main(){
    int coins[] = {1,2,3};
    int n = 3;
    int sum = 4;

    int ways = get_ways(coins,n,sum);

    cout<<"ways are -> "<<ways<<endl;

    return 0;
}