import java.util.*;
import java.io.*;

public class Judge {

	private static Scanner input;
	private static Scanner output;
	private static boolean judge;

	public static void main(String... args) throws Exception {
		for (int testCase = 1; testCase <= 10; testCase++) {
			input = new Scanner(new FileReader("/home/kmh/ANT/J/data/" + testCase + ".in"));
			output = new Scanner(new FileReader("/home/kmh/ANT/J/data/" + testCase + ".out"));
			TreeMap<String, Child> tree = new TreeMap<String, Child>();
			judge = true;

			int N = input.nextInt();
			while (N-- > 0) {
				TreeMap<String, Child> subtree = tree;
				String[] childNames = new String[input.nextInt()];

				for (int i = 0; i < childNames.length; i++)
					childNames[i] = input.next();

				for (String name : childNames) {
					if (!subtree.containsKey(name))
						subtree.put(name, new Child());
					subtree = subtree.get(name).childs;
				}
			}

			for (String name : tree.keySet())
				dfs(name, "", tree);

			System.out.printf("%d> %s\n", testCase, judge);
		}
	}

	private static void dfs(String name, String indent, TreeMap<String, Child> tree) {
		if (!output.nextLine().equals(indent + name))
			judge = false;

		indent += "--";

		for (String subname : tree.get(name).childs.keySet())
			dfs(subname, indent, tree.get(name).childs);
	}

	private static class Child {
		public TreeMap<String, Child> childs;

		public Child() {
			this.childs = new TreeMap<String, Child>();
		}
	}
}