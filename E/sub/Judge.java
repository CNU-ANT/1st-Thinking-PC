import java.util.*;
import java.io.*;

public class Judge {
	public static void main(String... args) throws Exception {
		for (int i = 1; i <= 50; i++) {
			Scanner input = new Scanner(new FileReader("/home/kmh/ANT/E/data/" + i + ".in"));
			Scanner output = new Scanner(new FileReader("/home/kmh/ANT/E/data/" + i + ".out"));

			int[] milk = new int[input.nextInt()];
			for (int k = 0; k < milk.length; k++)
				milk[k] = input.nextInt();
				
			String answer = solution(milk);
			System.out.printf("%d> %s\n", i, answer.equals(output.nextLine()));}
	}

	private static String solution(int[] milk) {
		int pointer = 0;
		int answer = 0;
		
		for (int i = 0; i < milk.length; i++)
			if (milk[i] == pointer) {
				answer++;
				pointer = (pointer + 1) % 3;
			}
	
		return String.valueOf(answer);
	}
}