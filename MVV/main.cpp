#include <iostream>
#include <string>
#include "math.h"

using namespace std;
int getmagicnumber(int n){
    int magicnumber = 0;
    for(int i = 0; (pow(3,i) + 1) <= n -1 ;i ++)
    {
        magicnumber = pow(3,i) + 1;
    }
    return magicnumber;
}

char solve(string s) {
    bool ismagic = false;
    int size = s.size();
    int magicnumber = getmagicnumber(s.length());
    int jumpnumber = getmagicnumber(s.size()-magicnumber);
    while (s.size() > magicnumber || ismagic == false) {
        string newString;
        if((size - jumpnumber) == s.size()){
            int jumpsize = jumpnumber - magicnumber;
            string schring;
            schring += s[0];
            schring += s[jumpsize];
            schring += s[s.size() - 1 - jumpsize];
            schring += s[s.size()-1];
            string b = schring;
            for (int i = 0; i < b.size() - 1; i++) {
                if (b[i] == b[i + 1]) {
                    newString += b[i];
                } else {
                    if (b[i] != 'R' && b[i + 1] != 'R') {
                        newString += 'R';
                    } else if (s[i] != 'G' && s[i + 1] != 'G') {
                        newString += 'G';
                    } else {
                        newString += 'B';
                    }
                }

            }
            s = newString;
            ismagic = true;
        }
        else{
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == s[i + 1]) {
                    newString += s[i];
                } else {
                    if (s[i] != 'R' && s[i + 1] != 'R') {
                        newString += 'R';
                    } else if (s[i] != 'G' && s[i + 1] != 'G') {
                        newString += 'G';
                    } else {
                        newString += 'B';
                    }
                }
            }
        }
        s = newString;
    }
    if(s.size() == magicnumber || ismagic == true){
        string firstLast;
        firstLast += s[0];
        firstLast += s[s.size()-1];
        s = firstLast;
        if (s[0] == s[1]) {
            return s[0];
        } else {
            if (s[0] != 'R' && s[1] != 'R') {
                return 'R';
            } else if (s[0] != 'G' && s[1] != 'G') {
               return 'G';
            } else {
                return 'B';
            }
        }
    }
}

int main() {
    cout << solve("RRRRRRRRRRRRRRRRRRRRRRRRRR") << endl;
    return 0;
}