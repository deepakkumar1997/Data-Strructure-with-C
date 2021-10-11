#include<iostream>
using namespace std;

void combination(string str1, string str2){
    int len1 = str1.length();
    int len2 = str2.length();
    int count=0;
    for(int i=0; i<len1; ++i){
        for(int j=0; j<len2; ++j){
            if(str1[i]==str2[j]){
                count++;
            }
        }
    }
    if(count==len1)
        cout<<"Anagram";
    else cout<<"not";
}

int main(int argc, char const *argv[])
{
    string word1 = "mary";
    string word2 = "abcd";
    combination(word1,word2);
    return 0;
}
