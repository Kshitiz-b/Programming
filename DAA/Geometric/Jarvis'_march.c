#include <stdio.h>
#include <stdlib.h>

// Define a structure for the 2D point
typedef struct Point
{
    int x;
    int y;
} Point;

// Helper function to check orientation of 3 points (clockwise or counter-clockwise)
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Jarvis' March Algorithm to find the convex hull
void convexHull(Point points[], int n)
{
    if (n < 3)
        return; // not enough points

    // Initialize the result array
    int hull[n];
    for (int i = 0; i < n; i++)
        hull[i] = -1;

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[leftmost].x)
        {
            leftmost = i;
        }
    }

    // Start from leftmost point, keep moving counterclockwise until we reach the start point again
    int p = leftmost, q;
    int i = 0;
    do
    {
        hull[i++] = p;
        q = (p + 1) % n;
        for (int j = 0; j < n; j++)
        {
            if (orientation(points[p], points[j], points[q]) == 2)
            {
                q = j;
            }
        }
        p = q;
    } while (p != leftmost);

    // Print the convex hull
    printf("The Boundary Coordinates are\n");
    for (int i = 0; i < n; i++)
    {
        if (hull[i] != -1)
        {
            printf("%d %d\n", points[hull[i]].x, points[hull[i]].y);
        }
    }
}

int main()
{
    int n = 7;
    // scanf("%d", &n);

    // Allocate memory for the array of points
    Point *points = (Point *)malloc(n * sizeof(Point));

    // Read the points from input
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Compute the convex hull
    convexHull(points, n);

    // Free the allocated memory
    free(points);

    return 0;
}
