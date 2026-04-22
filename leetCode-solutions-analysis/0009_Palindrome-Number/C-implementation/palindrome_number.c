#include <stdbool.h>

bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }
    else{
        int digits[10];

        int mod;
        int i = 0;
        while(x > 0){
            mod = x % 10;
            digits[i] = mod;
            i++;
            x /= 10;
        }

        for(int j = 0; j < i / 2; j++){
            if(digits[j] != digits[i - j - 1]){
                return false;
            }

        }
        return true;
    }
    
}