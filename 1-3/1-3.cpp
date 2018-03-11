#include <string>
#include <iostream>
using namespace std;
void URLify(string& s){
    int len = s.length();
    // find the last character location in the string
    int r = len-1;
    while(s[r] == ' '){
        r--;
    }
    int w = len-1;
    while (r >=0){
        if(s[r] == ' '){
            // Todo inprove using insert function
#if 1
            s[w--] = '0'; 
            s[w--] = '2'; 
            s[w--] = '%';
            r--; 
#else
            w -=2;
            s.insert(w,"%20");
            r--;
#endif
        } else {
            s[w--] = s[r--];
        }
    }
    if(w >= 0){
        s = s.substr(w+1);
    }
}

#include <string.h>
void cURLify(char* s){
    int len = strlen(s);
    char* r = s+len-1;
    char* w = r;
    while(*r == ' ' &&  r >= s){r--;}
    if(r < s){return;}
    cout <<  "starting character = "<< *r << endl;
    while(r >= s){
        if(*r == ' '){
#if 0
            *w-- = '0';
            *w-- = '2';
            *w-- = '%';
#else
            w -= 2;
            strncpy(w--, "%20",3);
#endif
            r--;
        } else {
            *w-- = *r--;
        }
    }
    
    w++;
    if(w > s){
        r = s;
        while(w <= s+len-1){
            *r++ = *w++;
        }
        *r = '\0';
    }
    
}

int main(){
    string s;
    getline(cin, s);
    char* cstr = new char[s.length()];
    sprintf(cstr, s.c_str());
    cout << "in >"<< cstr << "< len "<< strlen(cstr)<< endl;
    cURLify(cstr);
    cout << cstr;
}