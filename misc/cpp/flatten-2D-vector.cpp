/* Design and implement an iterator to flatten a 2d vector. It should support
   the following operations: next and hasNext.

    Example:

    Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

    iterator.next(); // return 1
    iterator.next(); // return 2
    iterator.next(); // return 3
    iterator.hasNext(); // return true
    iterator.hasNext(); // return true
    iterator.next(); // return 4
    iterator.hasNext(); // return false

   LC 251. Flatten 2D Vector
   Author: Shruti
*/
class Vector2D {
    queue<int> result;
    void flattenVector(vector<int> vec) {
        for(auto v : vec) {
            result.push(v);
        }
    }

public:
    Vector2D(vector<vector<int>>& v) {
        for(int i = 0; i < v.size(); i++) {
            flattenVector(v[i]); // all elements of v are vectors
        }
    }

    int next() {
        int val = 0;
        if(hasNext()) {
            val = result.front();
            result.pop();
        }
        return val;
    }

    bool hasNext() {
        if(result.size() > 0) {
            return true;
        }
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
