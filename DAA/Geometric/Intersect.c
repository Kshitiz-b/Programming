#include <stdio.h>

typedef struct Point
{
    int x;
    int y;
} Point;

// A utility function to find the orientation of three points
// (used to check if two line segments intersect)
int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Given two line segments, returns true if they intersect
int doLineSegmentsIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return 1;

    // Special Cases (for colinear points)
    if (o1 == 0 && onSegment(p1, p2, q1))
        return 1;
    if (o2 == 0 && onSegment(p1, q2, q1))
        return 1;
    if (o3 == 0 && onSegment(p2, p1, q2))
        return 1;
    if (o4 == 0 && onSegment(p2, q1, q2))
        return 1;

    return 0; // Doesn't fall in any of the above cases
}

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
int onSegment(Point p, Point q, Point r)
{
    if (q.x <= fmax(p.x, r.x) && q.x >= fmin(p.x, r.x) &&
        q.y <= fmax(p.y, r.y) && q.y >= fmin(p.y, r.y))
        return 1;
    return 0;
}

int main()
{
    Point p1 = {1, 1}, q1 = {10, 1};
    Point p2 = {1, 2}, q2 = {10, 2};

    if (doLineSegmentsIntersect(p1, q1, p2, q2))
    {
        printf("The given line segments intersect.\n");
    }
    else
    {
        printf("The given line segments do not intersect.\n");
    }

    return 0;
}
