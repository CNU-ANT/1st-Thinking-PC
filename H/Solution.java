import java.util.*;

public class Solution {
	public static void main(String... args) {
		int N = new Scanner(System.in).nextInt();
		int g = (int) ((Math.sqrt((8 * N) - 7) - 1) / 2) + 1;
		int m = (g * (g + 1)) / 2;
		
		System.out.printf("%d %d", m - N + 1, N - m + g);
	}
}