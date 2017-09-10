import java.util.*;
import java.io.*;

public class Judge {
	public static void main(String... args) throws Exception {
		for (int i = 1; i <= 50; i++) {
			Scanner input = new Scanner(new FileReader("/home/kmh/ANT/D/data/" + i + ".in"));
			Scanner output = new Scanner(new FileReader("/home/kmh/ANT/D/data/" + i + ".out"));

			int N = input.nextInt();
			String answer = solution(N);

			System.out.printf("%d> %s\n", i, answer.equals(output.nextLine()));}
	}

	private static String solution(int N) {
		int g = (int) ((Math.sqrt((8 * N) - 7) - 1) / 2) + 1;
		int m = (g * (g + 1)) / 2;
		return String.format("%d %d", m - N + 1, N - m + g);
	}
}