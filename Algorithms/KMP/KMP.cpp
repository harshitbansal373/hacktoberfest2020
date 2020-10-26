#include <bits/stdc++.h>

using namespace std;

vector<int> computelps(string str){
    vector<int> lps(str.size());
    lps[0]=0;
    int j=0;
    for(int i=1;i<str.size();i++){
        while(j!=0 && str[j]!=str[i]){
            j=lps[j-1];
        }
        if(str[j]==str[i]){
            j++;
        }
        lps[i]=j;
    }
    return lps;
}

bool kmpsearch(string tofind,string text){
    vector<int> lps = computelps(tofind);
    cout<<endl;
    int n = text.size(), m = tofind.size();
    int i = 0, j = 0;
    while( i < n ){
        while( j < m && i < n && tofind[j] == text[i] ){
            i++;
            j++;
        }
        if( j == m && tofind[j-1] == text[i-1]){
            return 1;
        }
        else if( i == n ){
            return 0;
        }
        else{
            if( j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return 0;
}

int main(){
    string text = "EIMAPMABNATTHMEAONS";
    string tofind = "BNAT";
    if(kmpsearch(tofind,text)){
        cout<<"Found "<<tofind<<" in "<<text<<endl;
    }
    else{
        cout<<"Not found "<<tofind<<" in "<<text<<endl;
    }
}
