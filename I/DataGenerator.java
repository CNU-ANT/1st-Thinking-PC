import java.util.*;
import java.io.*;

public class DataGenerator {

	private static final int MAXCLUB = 9;
	private static int N;
	private static int count;
	private static final String[] CLUB = new String[] { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };

	public static void main(String... args) throws Exception {
		for (int i = 1; i <= 100; i += 2) {
			N = i;
			count++;
			
			int[][] input = new int[MAXCLUB][N];
			generate(input);
			print(input);
			boolean OK = decision(solution(input));

			if (OK)
				save(input);
			else {
				i -= 2;
				count--;
			}
		}
	}

	private static void generate(int[][] input) {
		for (int i = 0; i < MAXCLUB; i++)
			for (int n = 0; n < N; n++)
				input[i][n] = random(10, 50);
	}

	private static void print(int[][] input) {
		System.out.println(N);
		for (int i = 0; i < MAXCLUB; i++) {
			System.out.print(input[i][0]);
			for (int n = 1; n < N; n++)
				System.out.print(" " + input[i][n]);
			System.out.println();
		}
	}

	private static HashSet<String> solution(int[][] input) {
		int[] maxAge = new int[MAXCLUB];
		for (int i = 0; i < MAXCLUB; i++) {
			int max = 0;
			for (int n = 0; n < N; n++)
				max = Math.max(max, input[i][n]);
			maxAge[i] = max;
		}

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < MAXCLUB; i++)
			min = Math.min(min, maxAge[i]);

		HashSet<String> output = new HashSet<String>();
		for (int i = 0; i < MAXCLUB; i++)
			if (maxAge[i] == min)
				output.add(CLUB[i]);

		for (String name : output)
			System.out.print(name + " ");

		return output;
	}

	private static boolean decision(HashSet<String> output) {
		if (output.size() != 1)
			return false;
		if (!output.contains("ANT"))
			return false;

		return true;
	}

	private static void save(int[][] input) throws Exception {
		BufferedWriter in = new BufferedWriter(new FileWriter("/home/kmh/ANT/I/data/" + count + ".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("/home/kmh/ANT/I/data/" + count + ".out"));

		in.write(String.valueOf(N) + "\n");
		for (int i = 0; i < MAXCLUB; i++) {
			in.write(String.valueOf(input[i][0]));
			for (int n = 1; n < N; n++)
				in.write(" " + String.valueOf(input[i][n]));

			if (i != MAXCLUB - 1)
				in.write("\n");
		}

		out.write("ANT");

		in.close();
		out.close();
	}

	private static int random(int first, int second) {
		return (int) (Math.random() * (second - first + 1)) + first;
	}
}