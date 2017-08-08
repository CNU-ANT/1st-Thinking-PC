import java.util.Scanner;

public class Solution {
	public static void main(String... args) {
		Scanner input = new Scanner(System.in);
		String[] club = new String[] { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };
		int N = input.nextInt();

		int[] maxAge = new int[9];
		for (int i = 0; i < 9; i++) {
			int max = 0;
			for (int j = 0; j < N; j++)
				max = Math.max(max, input.nextInt());
			maxAge[i] = max;
		}

		int answer = 0;
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < 9; i++)
			if (min > maxAge[i]) {
				answer = i;
				min = maxAge[i];
			}

		System.out.print(club[answer]);
	}
}