class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double tempo = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], tempo});
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double ultimoTempo = 0.0;

        for (int i = 0; i < n; i++){
            if (cars[i].second > ultimoTempo) {
                fleets++;
                ultimoTempo = cars[i].second;
            }
        }

        return fleets;
    }
};
