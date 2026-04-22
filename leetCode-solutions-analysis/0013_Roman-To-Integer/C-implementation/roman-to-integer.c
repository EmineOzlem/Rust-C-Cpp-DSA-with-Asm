int getIntValue(char* ch){
    switch(*ch){
        case 'I':
        return 1;
        case 'V':
        return 5;
        case 'X':
        return 10;
        case 'L':
        return 50;
        case 'C':
        return 100;
        case 'D':
        return 500;
        case 'M':
        return 1000;
        default:
        return 0;
    }
}

int romanToInt(char* s) {
    int value = 0;
    int size = strlen(s);

    for(char* p = s; p < s + size; p++){
        if(*(p+1) != '\0'){
            if(getIntValue(p) < getIntValue(p + 1)){
                value -= getIntValue(p);
            }
            else{
                value += getIntValue(p);
            }
        }else{
            value += getIntValue(p);
        }
        
    }
    return value;
}