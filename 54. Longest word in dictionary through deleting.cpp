/*
Problem statement:

Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed 
by deleting some of the given string characters. If there is more than one possible result, return the longest 
word with the smallest lexicographical order. If there is no possible result, return the empty string.
*/

// code:


class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

        string res;
        for (int i= 0; i< dictionary.size(); i++){
            string& word= dictionary[i];

            if (word.size()> s.size() || word.size()< res.size())
                continue;

            auto found= s.find(word[0]); 

            int j= 1;
            for (j; j< word.size(); j++){    
                found= s.find(word[j],found+1);
                if (found== string::npos)
                    break;                                              
            }

            if (found== string::npos)
                continue;

            if (j> res.size()){
                 res= word;
                 continue;
            }

            if (j== res.size()){
                for (int i= 0; i< res.size(); i++){
                    if (word[i]< res[i]){
                        res= word;
                        break;
                    }
                    else if(word[i]== res[i])
                        continue;
                    else
                        break;
                }
            }
        }
        return res;
    }
};
