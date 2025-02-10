// 251. Flatten 2D Vector
/*
Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

Example:
Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false

Notes:
Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.
*/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        iter = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        hasNext();
        return (*iter)[j++];
    }

    bool hasNext() {
        while(iter != end && j == (*iter).size()){
            j = 0;
            iter++;
        }
        return iter != end;
    }

private:
    vector<vector<int>>::iterator iter, end;
    int j = 0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */