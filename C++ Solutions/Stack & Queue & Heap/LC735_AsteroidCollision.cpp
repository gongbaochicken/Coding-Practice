/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right,
 negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: 
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation: 
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
Example 2:
Input: 
asteroids = [8, -8]
Output: []
Explanation: 
The 8 and -8 collide exploding each other.
Example 3:
Input: 
asteroids = [10, 2, -5]
Output: [10]
Explanation: 
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.
Example 4:
Input: 
asteroids = [-2, -1, 1, 2]
Output: [-2, -1, 1, 2]
Explanation: 
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
Note:

The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000]..
*/

// observation:
// 1 at the end, all the negative star has to be on the left, and all the positive star has to be on the right.
// 2 from the left, a negative star will pass through if no positive star on the left;
// 3 keep track of all the positive stars moving to the right, the right most one will be the 1st confront the challenge of any future negative star.
// 4 if it survives, keep going, otherwise, any past positive star will be exposed to the challenge, by being popped out of the stack.
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    for (int i = 0; i < asteroids.size(); ++i) {
        if (asteroids[i] > 0 || st.empty() || st.back() < 0) {
            st.push_back(asteroids[i]);
        } else if (st.back() == -asteroids[i]) { // a[i] negative, st.back() positive and they elimit together
            st.pop_back();
        } else if (st.back() <-asteroids[i]){ // st.back() > 0 which elimit , a[i] is neg, keeps there and is going to check
            i--;
            st.pop_back();
        }
    }
    return st;
}
