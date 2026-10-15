#include <stdio.h>

int main() 
{
    char str[] = "abbccdztfutdrdugkhghcfawqazxswedcvfrtgbnhyujmmkiopl";
    int hash[26] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }
        
        if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a';
            hash[index] = hash[index] + 1;
        }
    }
    
    for (int j = 0; j < 26; j++) {
        
            printf("%c = %d\n", 'a' + j, hash[j]);
        
    }

    return 0;
}