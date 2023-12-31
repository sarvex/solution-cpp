class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        if (jug1Capacity == 0 or jug2Capacity == 0)
            return targetCapacity == 0 or jug1Capacity + jug2Capacity == targetCapacity;
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};