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
			HashMap<String, Integer> output = solution(input);
			boolean OK = decision(output);

			int max = 0;
			String result = null;
			for (String name : output.keySet()) {
				if (output.get(name) > max) {
					result = name;
					max = output.get(name);
				}
			}

			print(input, result);

			if (OK)
				save(input, result);
			else {
				i -= 2;
				count--;
			}
		}
	}

	private static void generate(int[][] input) {
		for (int i = 0; i < MAXCLUB; i++)
			for (int n = 0; n < N; n++)
				input[i][n] = random(1, 1000);
	}

	private static void print(int[][] input, String result) {
		System.out.println(N);
		for (int i = 0; i < MAXCLUB; i++) {
			System.out.print(input[i][0]);
			for (int n = 1; n < N; n++)
				System.out.print(" " + input[i][n]);
			System.out.println();
		}

		System.out.println(result);
	}

	private static HashMap<String, Integer> solution(int[][] input) {
		int[] maxScore = new int[MAXCLUB];
		for (int i = 0; i < MAXCLUB; i++) {
			int max = 0;
			for (int n = 0; n < N; n++)
				max = Math.max(max, input[i][n]);
			maxScore[i] = max;
		}

		int max = 0;
		for (int i = 0; i < MAXCLUB; i++)
			max = Math.max(max, maxScore[i]);

		HashMap<String, Integer> output = new HashMap<String, Integer>();
		for (int i = 0; i < MAXCLUB; i++)
			output.put(CLUB[i], maxScore[i]);

		return output;
	}

	private static boolean decision(HashMap<String, Integer> output) {
		boolean check = true;
		String[] keySet = new String[MAXCLUB];
		int iter = 0;
		for (String key : output.keySet())
			keySet[iter++] = key;

		for (int i = 0; i < MAXCLUB; i++)
			for (int j = 0; j < MAXCLUB; j++)
				if (i != j)
					if (output.get(keySet[i]) == output.get(keySet[j]))
						check = false;

		if (!check)
			return false;
		return true;
	}

	private static void save(int[][] input, String name) throws Exception {
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

		out.write(name);

		in.close();
		out.close();
	}

	private static int random(int first, int second) {
		return (int) (Math.random() * (second - first + 1)) + first;
	}
}
