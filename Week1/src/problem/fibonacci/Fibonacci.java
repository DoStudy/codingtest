// https://leetcode.com/problems/fibonacci-number/
package problem.fibonacci;

public class Fibonacci {
    public static void main(String[] args) {
        Fibonacci solution = new Fibonacci();
        System.out.println(solution.fib(5));
    }

    public int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fib(n-1) + fib(n-2);
        }
    }
}