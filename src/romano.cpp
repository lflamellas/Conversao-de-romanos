#include <map>
#include <string>
#include <iostream>
#include "romano.hpp"
using namespace std;

string arabic_to_roman(int num) {
    string str2;
    int romans[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string symbol[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i = 12;    
    while (num > 0) {
      int div = num/romans[i];
      num = num%romans[i];
      while(div--) str2 += symbol[i];
      i--;
    }
    return str2;
}

int roman_to_arabic(string str) {
    map <char, int> M; 
    M.insert(pair<char, int> ('I', 1));
    M.insert(pair<char, int> ('V', 5));
    M.insert(pair<char, int> ('X', 10));
    M.insert(pair<char, int> ('L', 50));
    M.insert(pair<char, int> ('C', 100));
    M.insert(pair<char, int> ('D', 500));
    M.insert(pair<char, int> ('M', 1000));
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        if(M[str[i]] < M[str[i+1]]) res -= M[str[i]];
        else res += M[str[i]];
    }
    return res;
}

int validate_convert(string str) {
    int guess = roman_to_arabic(str);
    string str2 = arabic_to_roman(guess);
    if(str == str2 && guess <= 3000) return guess;
    else return -1;
}