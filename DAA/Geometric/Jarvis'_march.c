#include <stdio.h>

typedef struct Point
{
    int x, y;
} Point;

// Function to find the orientation of three points (p, q, r)
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Function to find the convex hull using Jarvis' March Algorithm
void convexHull(Point points[], int n)
{
    // There must be at least 3 points
    if (n < 3)
        return;

    // Initialize result
    int hull[n];
    for (int i = 0; i < n; i++)
        hull[i] = -1;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from the leftmost point, keep moving counterclockwise
    // until we reach the start point again
    int p = l, q;
    do
    {
        // Add current point to result
        hull[p] = 1;

        // Search for a point 'q' such that orientation(p, i, q) is counterclockwise
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            // If i is more counterclockwise than current q, then update q
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Set p as q for next iteration, so that q is added to result
        p = q;

    } while (p != l);

    // Print convex hull
    for (int i = 0; i < n; i++)
    {
        if (hull[i] == 1)
            printf("%d %d\n", points[i].x, points[i].y);
    }
}

// Main function
int main()
{
    Point points[100];
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        // printf("Point %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    convexHull(points, n);
    return 0;
}
