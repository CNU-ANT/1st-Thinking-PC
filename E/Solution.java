import java.util.*;

public class Solution {
	public static void main(String... args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();

		int pointer = 0;
		int answer = 0;
		while (N-- > 0) {
			if (pointer == input.nextInt()) {
				answer++;
				pointer = (pointer + 1) % 3;
			}
		}

		System.out.print(answer);
	}
}