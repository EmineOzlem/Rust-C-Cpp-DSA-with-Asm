char* longestCommonPrefix(char** strs, int strsSize) {
    char* result;
    int counter = 0;

    if(strsSize == 0){
        result = malloc(sizeof(char));
        result[0] = '\0';
        return result;
    }
    else{
        int wordLength = strlen(strs[0]);
        for(int j = 0; j < wordLength; j++){
            for(int i = 0; i < strsSize; i++){
                if(strs[0][j] != strs[i][j]){
                    goto returnResult;
                }
            }
            counter++;
        }
    }

    returnResult:
        result = malloc(sizeof(char) * (counter + 1));
        memcpy(result, strs[0], counter);
        result[counter] = '\0';
        return result;
}
