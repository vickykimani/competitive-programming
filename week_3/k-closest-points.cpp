// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto euclidean = [](auto &p)
        { return p[0] * p[0] + p[1] * p[1]; };
        sort(begin(points), end(points), [&](auto &a, auto &b)
             { return euclidean(a) < euclidean(b); });
        points.resize(k);
        return points;
    }
};