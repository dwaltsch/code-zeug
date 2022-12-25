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
    bool jump = false;
    int magicnumber = getmagicnumber(s.length());
    int sndjump = getmagicnumber(s.length() - magicnumber);
    while (s.size() > magicnumber) {
        string newString;
        if(s.length() > magicnumber + sndjump){
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
        else{
            string solvestring;
            solvestring += s[0];
            solvestring += s[sndjump - 1];
            solvestring += s[s.size() - 1 - sndjump];
            solvestring += s[s.size() - 1];
            for (int i = 0; i < solvestring.size() - 1; i++) {
                if (solvestring[i] == solvestring[i + 1]) {
                    newString += s[i];
                } else {
                    if (solvestring[i] != 'R' && solvestring[i + 1] != 'R') {
                        newString += 'R';
                    } else if (solvestring[i] != 'G' && solvestring[i + 1] != 'G') {
                        newString += 'G';
                    } else {
                        newString += 'B';
                    }
                }
            }
            jump = true;
        }
        s = newString;
    }
    if(jump == 1 || s.length() == magicnumber){
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
    cout << solve("RGBRGBRGBRRGBRGB") << endl;
    return 0;
}