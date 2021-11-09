#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <typeinfo>

using std::cout;
using std::endl;
using std::string;
using std::memset;
using std::vector;
using std::pair;
using std::make_pair;

vector< pair <int, int>> countSubStringPalindromes(string s) {

    // vector<starting position, length>
    vector<pair <int, int>> vect;

    const int len = s.length();

    // If the string is empty then return an empty vector
    if(len <= 0) {
        return vect;
    }

    // If the string contains a single character then it's a Palindrome
    if(len == 1) {
        vect.push_back(make_pair(0, 1));
    }

    /*
    * P[i][j] = true if substring str[i...j] is palindrome; else it's false
    */
    bool p[len][len];
    memset(p, false, sizeof(p));

    // A single character is considered a Palindrome
    for(int i = 0; i < len; i++) {
        p[i][i] = true;
    }

    // If two adjacent characters are the same, then they are considered a Palindrome
    for(int i = 0; i < len - 1; i++) {
        if(s[i] == s[i + 1]) {
            p[i][i + 1] = true;
            vect.push_back(make_pair(i, 2));
        }
    }

    // Determining whether a string that has more than two characters is a Palindrome.
    // dist is the distance between the start point and the end point of the substring
    for(int dist = 2; dist < len; dist++) {
        // i is the starting point of the substring
        for(int i = 0; i < len - dist; i++) {
            // j is the ending point of the substring
            int j = i + dist;

            /*
            * If the first and last characters are the same, and
            * the middle part is Palindrome. Then you can say, the whole
            * substring is also a Palindrome
            */
            if(s[i] == s[j] && p[i + 1][j - 1]) {
                p[i][j] = true;
            }

            if(p[i][j] == true) {
                vect.push_back(make_pair(i, (j - i) + 1));
            }
        }
    }

   return vect;
}

void printPalindromes(string s, vector<pair<int, int>> &vec) {
    string palindromeSubString;
    for(int i = 0; i < vec.size(); i++) {
        palindromeSubString = s.substr(vec[i].first, (vec[i].second));
        cout << palindromeSubString;
        cout << ", " << vec[i].first << ", " << vec[i].second << endl;
    }
}

int main() {

    /*
    * Replace string s with an arbitrary string of your choosing.
    * For instance: string s = "madam";
    */
    string s = "ABCBAHELLOHOWRACECARAREYOUILOVEUEVOLIIAMAIDOINGGOOD";

    vector <pair<int, int>> ans;

    ans = countSubStringPalindromes(s);

    printPalindromes(s, ans);

    return 0;
}