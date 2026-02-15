#include<iostream>
#include<string>
using namespace std;
int ifPossible(string s){
    int freq[26]={0};
    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;

    }
    int oddCount=0;
    for(int i=0;i<26;i++){
        if(freq[i]%2!=0){
            oddCount++;
        }
    }
    return oddCount<=1?1:0;
}
int main(){
    string s;
    cin>>s;
    ifPossible(s)?cout<<"Yes"<<endl:cout<<"No"<<endl;
}