class Solution {
public:
    string getHint(string secret, string guess)
    {
        map<char,int> secretMap, guessMap;
        int bulls = 0, cows = 0;
        
        for (size_t i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            } else {
                secretMap[secret[i]]++;
                guessMap[guess[i]]++;
            }
        }
        
        for(auto x: secretMap)
            if (guessMap.find(x.first) != guessMap.end())     
                cows += min(x.second, guessMap[x.first]);
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }

};