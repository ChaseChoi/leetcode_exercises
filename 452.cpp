class Solution { 
    
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), sortcol);
        int overlappingCount = 0;
        int size = points.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return 1;
        }
        int previousEnd = points[0][1];
        for (int i = 1; i < size; ++i) {

            int currentStart = points[i][0];
            int currentEnd = points[i][1];

            if (currentStart <= previousEnd) {
                overlappingCount += 1;
                if (previousEnd > currentEnd) {
                    previousEnd = currentEnd;
                }
            } else {
                previousEnd = currentEnd;
            }
        }
        return size - overlappingCount;
    }

private:
    static bool sortcol(const vector<int>& v1, const vector<int>& v2 ) {
        return v1[0] < v2[0];
    }
};