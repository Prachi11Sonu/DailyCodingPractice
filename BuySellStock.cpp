#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int BuySellStock(vector<int>& arr){
        int profit=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                profit+=arr[i]-arr[i-1];
            }
        }
        return profit;

         
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<obj.BuySellStock(arr)<<endl;
    return 0;
}