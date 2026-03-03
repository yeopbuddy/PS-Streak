#include <iostream>
#include <string>

using namespace std;

int anss[52];
int curr[52];

bool Check(){
    for(int i = 0; i < 52; i++){
        if(anss[i] != curr[i]) return false;
    }
    return true;
}

int main(){
    
    int answer = 0;
    
    int l1, l2;
    string s1, s2;

    cin >> l1 >> l2 >> s1 >> s2;
    
    for(int i = 0; i < 52; i++) anss[i] = curr[i] = 0;
    
    for(int l = 0; l < l1; l++){
        if('a' <= s1[l] && s1[l] <= 'z') anss[s1[l] - 'a']++;
        else anss[s1[l] - 'A' + 26]++;
    }

    for(int l = 0; l < l1; l++){
        if('a' <= s2[l] && s2[l] <= 'z') curr[s2[l] - 'a']++;
        else curr[s2[l] - 'A' + 26]++;
    }
    
    if(Check()) answer++;
    
    for(int l = l1; l < l2; l++){
        if(Check() && s2[l - l1] == s2[l]){
            answer++;
        }
        else{
            if('a' <= s2[l - l1] && s2[l - l1] <= 'z') curr[s2[l - l1] - 'a']--;
            else curr[s2[l - l1] - 'A' + 26]--;
            if('a' <= s2[l] && s2[l] <= 'z') curr[s2[l] - 'a']++;
            else curr[s2[l] - 'A' + 26]++;
            if(Check()) answer++;
        }
    }

    cout << answer;

    return 0;
}