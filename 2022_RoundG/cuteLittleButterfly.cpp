#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#include <queue>
#include <assert.h>
using namespace std;

typedef long long ll;
long long N, E;

struct Point{
    int x;
    int y;
    int energy;
    ll max_energy=0;

    Point(int x, int y, int e){
        this->x = x;
        this->y = y;
        energy = e;
    }
};

struct left_first {
    bool operator()(Point lhs, Point rhs) const {
        return lhs.x < rhs.x;
    }
};

struct right_first {
    bool operator()(Point lhs, Point rhs) const {
        return lhs.x > rhs.x;
    }
};

int main()
{
    int t;
    cin>>t;
	for(int ca=1;ca<=t;ca++)
	{
        cin>>N>>E;
        
        map<int, vector<Point>, greater<int>> level_to_points;
        int Xmax = 0;
        int Ymax = 0;
        int A, B, C;
        for(ll i=0; i<N; ++i){
            cin>>A;
            cin>>B;
            cin>>C;
            Xmax = max(Xmax, A);
            Ymax = max(Ymax, B);
            Point p = Point(A, B, C);

            if(level_to_points.find(B) == level_to_points.end()){
                level_to_points[B] = vector<Point>{p};
            }else{
                level_to_points[B].push_back(p);
            }
        }

        multiset<Point, left_first> processed_from_left;
        multiset<Point, right_first> processed_from_right;
        Point dummy = Point(0, int(1e9)+1, 0);
        processed_from_left.insert(dummy);
        Point dummy_right = Point(Xmax, Ymax, 0);
        dummy_right.max_energy = -E;
        processed_from_right.insert(dummy_right);

        ll result = 0;
        int level = Ymax;
        for(const auto &entry : level_to_points){
            int current_level = entry.first;
            vector<Point> current_points = entry.second;

            // posibilities to turn
            ll turn_from_left = processed_from_right.rbegin()->max_energy - E;
            ll turn_from_right = processed_from_left.rbegin()->max_energy - E;

            // process from left to right in current level
            ll my_best_from_left = 0;
            sort(current_points.begin(), current_points.end(), left_first());
            for(Point currentPoint: current_points){
                int my_x = currentPoint.x;
                multiset<Point>::iterator it;
                
                it = lower_bound(processed_from_left.begin(), processed_from_left.end(), currentPoint, left_first());
                // subtract one for non exact match
                if(it == processed_from_left.end() || it->x > currentPoint.x){
                    it--;
                }

                Point closest_left = *it;
                my_best_from_left = closest_left.max_energy + (ll)currentPoint.energy;

                // if the first from left, and not on the highest level
                if(currentPoint.x == current_points.begin()->x && currentPoint.y != Ymax){
                    my_best_from_left = max(my_best_from_left, turn_from_left + currentPoint.energy);
                }
                
                // if not an exact match, advance iterator by one
                multiset<Point>::iterator next = it;
                if(next->x != currentPoint.x){
                    next++;
                }
                
                // update processed_left
                while(next != processed_from_left.end()){
                    if((next->max_energy) <= my_best_from_left){
                        processed_from_left.erase(next++);
                    }else{
                        break;
                    }
                }

                result = max(result, my_best_from_left);
                currentPoint.max_energy = my_best_from_left;
                processed_from_left.insert(currentPoint);
            }

            // process from right to left in current level
            ll my_best_from_right = 0;
            sort(current_points.begin(), current_points.end(), right_first());

            for(Point currentPoint: current_points){
                int my_x = currentPoint.x;
                multiset<Point>::iterator it;
                it = lower_bound(processed_from_right.begin(), processed_from_right.end(), currentPoint, right_first());
                
                // subtract one for non exact match
                if(it == processed_from_right.end() || it->x < currentPoint.x){
                    it--;
                }
                Point closest_right = *it;
                my_best_from_right = closest_right.max_energy + (ll)currentPoint.energy;

                // if the first from right, and not on the highest level
                if(currentPoint.x == current_points.begin()->x && currentPoint.y != Ymax){
                    my_best_from_right = max(my_best_from_right, turn_from_right + currentPoint.energy);
                }
                
                multiset<Point>::iterator next = it;
                if(next->x != currentPoint.x){
                    next++;
                }

                // update processed_from_right
                while(next != processed_from_right.end()){
                    if((next->max_energy) <= my_best_from_right){
                        processed_from_right.erase(next++);
                    }else{
                        break;
                    }
                }
    
                result = max(result, my_best_from_right);
                currentPoint.max_energy = my_best_from_right;
                processed_from_right.insert(currentPoint);
            }
        }


		printf("Case #%d: %lld\n",ca, result);
	}
	return 0;
}	