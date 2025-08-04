class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        //greedy approach
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int playersSize = players.size();
        int trainersSize = trainers.size();

        int i=0, j=0;
        int count = 0;

        while(i<playersSize && j<trainersSize){
            if(players[i] <= trainers[j]){
                i++;
                j++;
                count++;
            }else{
                j++;
            }
        }

        return count;
        
    }
};