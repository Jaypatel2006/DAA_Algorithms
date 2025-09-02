#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) -
              (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
}

Point p0;

bool compare(Point a, Point b) {
    int o = orientation(p0, a, b);
    if (o == 0)
        return distSq(p0, a) < distSq(p0, b);
    return (o == 2);
}

vector<Point> grahamScan(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};

    int ymin = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < ymin || 
           (points[i].y == ymin && points[i].x < points[minIndex].x)) {
            ymin = points[i].y;
            minIndex = i;
        }
    }
    swap(points[0], points[minIndex]);
    p0 = points[0];

    sort(points.begin() + 1, points.end(), compare);

    vector<Point> uniquePoints;
    uniquePoints.push_back(points[0]);
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        uniquePoints.push_back(points[i]);
    }

    if (uniquePoints.size() < 3) return {};

    stack<Point> hull;
    hull.push(uniquePoints[0]);
    hull.push(uniquePoints[1]);
    hull.push(uniquePoints[2]);

    for (int i = 3; i < (int)uniquePoints.size(); i++) {
        while (hull.size() > 1) {
            Point top = hull.top(); hull.pop();
            Point nextToTop = hull.top();
            if (orientation(nextToTop, top, uniquePoints[i]) == 2) {
                hull.push(top);
                break;
            }
        }
        hull.push(uniquePoints[i]);
    }

    vector<Point> result;
    while (!hull.empty()) {
        result.push_back(hull.top());
        hull.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<Point> points = {{0,3},{1,1},{2,2},{4,4},
                            {0,0},{1,2},{3,1},{3,3}};

    vector<Point> hull = grahamScan(points);

    for (auto& p : hull)
        cout << "(" << p.x << "," << p.y << ")\n";

    return 0;
}
