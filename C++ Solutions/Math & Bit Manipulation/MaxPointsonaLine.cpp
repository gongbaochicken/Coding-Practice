//Max Points on a Line 
//Tags: Hash-Table

//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

//Solution:
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() <= 2) return points.size();
        int result = 0;
        for(int i = 0; i < points.size() - 1; ++i){
            map<double, int> map;
            int verti = 1, local = 1, duplicate = 0;
            for(int j = i + 1; j < points.size(); ++j){
                if(points[i].x == points[j].x){
                    if(points[i].y == points[j].y){
                        duplicate++;
                    }else{ 
                        verti++;
                    }
                }else{
                    double slope = (double)(points[i].y - points[j].y) /(points[i].x - points[j].x);
                    map[slope] == 0? map[slope] = 2 : map[slope]++;
                    local = max(local, map[slope]);
                }
            }
            local = max(verti+duplicate, local+duplicate);
            result = max(result, local);
        }
        return result;
    }
};