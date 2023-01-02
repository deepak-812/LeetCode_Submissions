class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0]>='A' && word[0]<='Z'){
           for(int i=2;i<word.size();i++){
               if(word[1]<='Z' && word[1]>='A'){
                   if(word[i]>'Z' || word[i]<'A'){
                       return false;
                   }
               }
               else if(word[1]>='a' && word[1]<='z'){
                   if(word[i]<'a' || word[i]>'z'){
                       return false;
                   }
               }
               else{
                   return false;
               }
           } 
        }
        else{
            for(int i=1;i<word.size();i++){
                if(word[i]>'z' || word[i]<'a'){
                    return false;
                }
            }
        }
        return true;
    }
};