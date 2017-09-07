import java.util.*;
import java.io.*;

public class DataGenerator {

	private static boolean[][] input;
	private static boolean[][] visited;
	private static int Y = 2;
	private static int X = 2;
	private static int COUNT = 1;

	public static void main(String... args) throws Exception {
		for (int i = 1; i <= 50; i++) {
			COUNT = i;
			Y = randomNumber(1, i * 5);
			X = randomNumber(1, i * 5);
			input = new boolean[Y][X];
			generate();
			//print();
			save();
		}
	}

	private static void generate() {
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
				input[y][x] = (randomNumber(0, 1) == 1) ? true : false;
	}

	private static void print() {
		for (int y = 0; y < Y; y++)
			System.out.println(Arrays.toString(input[y]));
	}

	private static int solution() {
		visited = new boolean[Y][X];

		int answer = 0;
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
				if (input[y][x] && !visited[y][x]) {
					dfs(y, x);
					answer++;
				}

		return answer;
	}

	private static void save() throws Exception {
		BufferedWriter in = new BufferedWriter(new FileWriter("/home/kmh/ANT/A/data/" + COUNT + ".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("/home/kmh/ANT/A/data/" + COUNT + ".out"));

		in.write(String.valueOf(Y) + " " + String.valueOf(X));
		for (int y = 0; y < Y; y++) {
			in.write("\n" + ((input[y][0]) ? "1" : "0"));
			for (int x = 1; x < X; x++)
				in.write(" " + ((input[y][x]) ? "1" : "0"));
		}

		out.write(String.valueOf(solution()));

		in.close();
		out.close();
	}

	private static void dfs(int y, int x) {
		visited[y][x] = true;

		if (y - 1 >= 0 && !visited[y - 1][x] && input[y - 1][x])
			dfs(y - 1, x);
		if (y + 1 < Y && !visited[y + 1][x] && input[y + 1][x])
			dfs(y + 1, x);
		if (x - 1 >= 0 && !visited[y][x - 1] && input[y][x - 1])
			dfs(y, x - 1);
		if (x + 1 < X && !visited[y][x + 1] && input[y][x + 1])
			dfs(y, x + 1);
		if (y - 1 >= 0 && x - 1 >= 0 && !visited[y - 1][x - 1] && input[y - 1][x - 1])
			dfs(y - 1, x - 1);
		if (y - 1 >= 0 && x + 1 < X && !visited[y - 1][x + 1] && input[y - 1][x + 1])
			dfs(y - 1, x + 1);
		if (y + 1 < Y && x - 1 >= 0 && !visited[y + 1][x - 1] && input[y + 1][x - 1])
			dfs(y + 1, x - 1);
		if (y + 1 < Y && x + 1 < X && !visited[y + 1][x + 1] && input[y + 1][x + 1])
			dfs(y + 1, x + 1);
	}

	private static int randomNumber(int first, int second) {
		return (int) (Math.random() * (second - first + 1)) + first;
	}
}
