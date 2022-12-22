#include <iostream>
#include <string>
#include "math.h"

using namespace std;
int getmagicnumber(int n){
    int magicnumber = 0;
    for(int i = 0; (pow(3,i) + 1) <= n ;i ++)
    {
        magicnumber = pow(3,i) + 1;
    }
    return magicnumber;
}

char solve(string s) {
    int magicnumber = getmagicnumber(s.length());
    while (s.size() > magicnumber) {
        int jumpnumber = getmagicnumber(s.size()-magicnumber);
        string newString;
        if(jumpnumber == s.size()){
            int jumpsize = jumpnumber - magicnumber;
            string first = reinterpret_cast<const char *>(s[0] + s[jumpsize]);
            string two = reinterpret_cast<const char *>(s[s.length()-1-jumpsize] + s[s.length()-1]);
            string newstring = first + two;
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
    if(s.size() == magicnumber){
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
    cout << solve("RGBRGBRGBRGBRGRBG") << endl;
    return 0;
}