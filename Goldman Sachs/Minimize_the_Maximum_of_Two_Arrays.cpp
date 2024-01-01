class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long start = 1;
        long end = 2e15;
        long ans = end;
        long l = lcm((long)divisor1, divisor2);
        
        while (start <= end) 
        {
            long centre = start + (end-start)/2;
            long num1 = centre - centre/divisor1;
            long num2 = centre - centre/divisor2;
            long num12 = centre - centre/l;
            
            if (num1 <uniqueCnt1 || num2 <uniqueCnt2 || num12 <uniqueCnt1 +uniqueCnt2) 
                start = centre + 1;
            else {
                ans = min(ans,centre);
                end = centre-1;
            }
        }
        return ans;

    }
};
// arr1 -> +ve and no multiple of divisor 1
// arr2 -> +ve and no multiple of divisor 2
// none of them are same 
// 