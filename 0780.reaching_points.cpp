class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx and ty > sy and tx != ty) {
            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        }
        if (tx == sx and ty == sy) return true;
        if (tx == sx) return ty > sy and (ty - sy) % tx == 0;
        if (ty == sy) return tx > sx and (tx - sx) % ty == 0;
        return false;
    }
};