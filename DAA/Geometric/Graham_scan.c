#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to represent a point in 2D space
typedef struct
{
    int x;
    int y;
} Point;

// Global variables to store the reference point and the number of points in the array
Point p0;
int numPoints;

// Function to calculate the squared distance between two points
int distSq(Point p1, Point p2)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return dx * dx + dy * dy;
}

// Function to calculate the orientation of three points
int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Function to swap two points
void swap(Point *p1, Point *p2)
{
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Function to compare two points based on their polar angle with respect to p0
int compare(const void *vp1, const void *vp2)
{
    // Cast the void pointers to Point pointers
    const Point *p1 = (const Point *)vp1;
    const Point *p2 = (const Point *)vp2;

    // Find the orientation of the points with respect to the reference point
    int orientationValue = orientation(p0, *p1, *p2);

    if (orientationValue == 0)
    {
        // If the points are collinear, return the one that is closer to the reference point
        if (distSq(p0, *p2) >= distSq(p0, *p1))
            return -1;
        else
            return 1;
    }
    else if (orientationValue == 2)
    {
        // If p1 is clockwise from p2 with respect to p0, return -1
        return -1;
    }
    else
    {
        // If p1 is counterclockwise from p2 with respect to p0, return 1
        return 1;
    }
}

// Function to partition the array for quicksort
int partition(Point arr[], int left, int right)
{
    // Choose the rightmost element as the pivot
    Point pivot = arr[right];

    // Move all elements smaller than the pivot to the left
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (compare(&arr[j], &pivot) < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Move the pivot to its final position
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

// Function to sort the array using quicksort
void quicksort(Point arr[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(arr, left, right);
        quicksort(arr, left, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, right);
    }
}
// Function to read the coordinates of the polygon from the user
void readPoints(Point arr[])
{
    // printf("Enter the number of points in the polygon: ");
    //scanf("%d", &numPoints);
    numPoints = 8;
    // printf("Enter the coordinates of the points:\n");
    for (int i = 0; i < numPoints; i++)
    {
        // printf("Point %d: ", i + 1);
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
}

// Function to find the convex hull of a set of points using the Graham Scan algorithm
void convexHull(Point points[], int numPoints)
{
    // Find the point with the lowest y-coordinate (and leftmost if there are ties)
    int minY = points[0].y;
    int minIndex = 0;
    for (int i = 1; i < numPoints; i++)
    {
        if (points[i].y < minY || (points[i].y == minY && points[i].x < points[minIndex].x))
        {
            minY = points[i].y;
            minIndex = i;
        }
    }

    // Swap the lowest point with the first point in the array
    swap(&points[0], &points[minIndex]);

    // Set the reference point to be the first point in the array
    p0 = points[0];

    // Sort the remaining points based on their polar angle with respect to the reference point
    quicksort(points, 1, numPoints - 1);

    // Create a new array to store the points in the convex hull
    Point hull[numPoints];
    int hullSize = 0;

    // Add the first two points to the convex hull
    hull[hullSize++] = points[0];
    hull[hullSize++] = points[1];

    // Add the remaining points to the convex hull, discarding any that create a clockwise turn
    for (int i = 2; i < numPoints; i++)
    {
        while (hullSize > 1 && orientation(hull[hullSize - 2], hull[hullSize - 1], points[i]) != 2)
        {
            hullSize--;
        }
        hull[hullSize++] = points[i];
    }

    // Print the coordinates of the points in the convex hull
    printf("The Boundary Coordinates are\n");
    for (int i = hullSize-1; i >= 0; i--)
    {
        printf("%d %d\n", hull[i].x, hull[i].y);
    }
}

// Main function
int main()
{
    Point points[100];
    readPoints(points);
    convexHull(points, numPoints);
    return 0;
}