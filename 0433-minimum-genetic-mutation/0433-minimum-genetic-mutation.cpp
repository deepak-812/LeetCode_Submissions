class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        char chrs[4]={'A','C','G','T'};
        queue<pair<string,int>> q;
        st.erase(startGene);
        q.push({startGene,0});
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endGene)return step;
            for(int i=0;i<word.size();i++){
                char originalLetter=word[i];
                for(int ch=0;ch<4;ch++){
                    word[i]=chrs[ch];
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=originalLetter;
            }
        }
        return -1;
    }
};