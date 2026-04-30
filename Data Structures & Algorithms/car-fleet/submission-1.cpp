class Solution {
public:

    static bool valid(const pair<int,double>& a, const pair<int,double>& b){
        return a.first > b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> time(n);

        for(int i = 0 ; i < position.size(); i++){
            double d = (double)(target - position[i]) / speed[i];
            time[i] = {position[i], d};
        }

        sort(time.begin(),time.end(), valid);

        int fleets = 0;
        double maxTime = 0.0;
        for(int i = 0 ; i < n; i++){
            if(time[i].second > maxTime) {
                maxTime = time[i].second;
                fleets++;
            }
        }

        return fleets;
    }
};