// 2391. Minimum Amount of Time to Collect Garbage
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int gTravel=0;
        int gPickup = 0;
        int gLastHouse=0; 
        
        int pTravel=0;
        int pPickup = 0;
        int pLastHouse=0;

        int mTravel=0;
        int mPickup = 0;
        int mLastHouse=0;


        for(int i=0; i<garbage.size(); i++){ //max to max jayega bhi to n time
            string currentHouse = garbage[i];

            for(int j=0; j<currentHouse.length(); j++){ //1 <= garbage[i].length <= 10
            //given in question so ye jayega bhi to contanr time
                //yaha pe current house pe hu to ab pahle chek kro ki kya kya  hai usme
                switch(currentHouse[j]){
                    case 'G' : 
                        gPickup++;
                        gLastHouse = i;
                        break;
                    case 'P' : 
                        pPickup++;
                        pLastHouse = i;
                        break;
                    case 'M' :
                        mPickup++;
                        mLastHouse = i; 
                        break;
                }
            }
        }

        //ab mere pass mai yaha pe truck ka last house hai and pickup time;
            //toh now will calculate the travel time jo alag se array me diya hua hai

            for(int i=0; i<gLastHouse; i++){
                gTravel += travel[i];
            }

            for(int i=0; i<pLastHouse; i++){
                pTravel += travel[i];
            }

            for(int i=0; i<mLastHouse; i++){
                mTravel += travel[i];
            }
        
        //ab travel time bhi hai and pickup bhi

        int totalPickupTime = gPickup + pPickup + mPickup;
        int totalTravelTime = gTravel + pTravel + mTravel;

        return totalPickupTime + totalTravelTime;        
    }
};