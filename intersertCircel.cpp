// We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array
// A of N non-negative integers, specifying the radiuses of the discs, is given.
// The J-th disc is drawn with its center at (J, 0) and radius A[J]. undefined
// We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and
// K-th discs have at least one common point (assuming that the discs contain
// their borders). The figure below shows discs drawn for N = 6 and A as
// follows: A[0] = 1 undefined A[1] = 5 undefined A[2] = 2 undefined
// A[3] = 1 undefined A[4] = 4 undefined A[5] = 0 undefined There are eleven
// (unordered) pairs of discs that intersect, namely: discs 1 and 4 intersect,
// and both intersect with all the other discs; disc 2 also intersects with
// discs 0 and 3. Write a function: class Solution { public int
// solution(int[] A); } that, given an array A describing N discs as explained
// above, returns the number of (unordered) pairs of intersecting discs. The
// function should return −1 if the number of intersecting pairs exceeds
// 10,000,000. Given array A shown above, the function should return 11, as
// explained above. Write an efficient algorithm for the following assumptions:
// N is an integer within the range [0..100,000]; undefined each element of
// array A is an integer within the range [0..2,147,483,647]. undefined
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int solution(vector<int> &A)
    {
        int N = A.size();
        if (N == 0)
        {
            return 0;
        }

        vector<pair<long long, int>> events;
        for (int i = 0; i < N; ++i)
        {
            long long left = i - static_cast<long long>(A[i]);
            long long right = i + static_cast<long long>(A[i]);
            events.push_back({left, 1});
            events.push_back({right, -1});
        }

        sort(events.begin(), events.end(), [](const pair<long long, int> &a, const pair<long long, int> &b)
             {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first; });

        long long activeDiscs = 0;
        long long intersections = 0;

        for (const auto &event : events)
        {
            if (event.second == 1)
            {
                intersections += activeDiscs;
                activeDiscs++;
            }
            else
            {
                activeDiscs--;
            }

            if (intersections > 10000000)
            {
                return -1;
            }
        }

        return static_cast<int>(intersections);
    }
};

int main()
{
    Solution sol;
    vector<int> A = {1, 5, 2, 1, 4, 0};
    cout << sol.solution(A) << endl;
    return 0;
}
