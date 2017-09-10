import java.util.*;
import java.io.*;

public class DataGenerator {

	private static final String[] FRUIT = new String[] { "APPLE", "BANANA",
			"CHERRY", "DURIAN", "ELDERBERRY", "FIG", "GRAPH", "HONEYDEW",
			"IRISH", "KIWI", "LEMON", "MELON", "NECTARINE", "ORANGE",
			"PINENUT", "QUINCES", "RADISH", "SESAME", "TANGERINE", "UGLI",
			"VOAVANGA", "WATERMELON", "YAM", "ZUCCHINI" };
	
	private static int DEPTH = 4;
	private static int MAXCHILD = 10;
	private static int COUNT = 10;
	private static HashSet<String> exInput;
	private static ArrayList<String> exOutput;

	public static void main(String... args) throws Exception {
		HashMap<String, Child> input = new HashMap<String, Child>();
		generate(input, 0);
		print(input);
		save(input);
	}

	private static void generate(HashMap<String, Child> subtree, int n) {
		if (n == DEPTH)
			return;

		String[] childs = new String[randomNumber(1, MAXCHILD)];
		boolean dupli = false;
		while (!dupli) {
			for (int i = 0; i < childs.length; i++)
				childs[i] = randomString(0, 23);

			dupli = true;
			for (int i = 0; i < childs.length; i++)
				for (int j = 0; j < childs.length; j++)
					if (i != j)
						if (childs[i].equals(childs[j]))
							dupli = false;
		}

		for (String name : childs) {
			if (!subtree.containsKey(name))
				subtree.put(name, new Child());
			generate(subtree.get(name).childs, n + 1);
		}
	}

	private static void print(HashMap<String, Child> input) {
		for (String name : input.keySet())
			printdfs(name, "", input);
	}

	private static void save(HashMap<String, Child> input) throws Exception {
		exInput = new HashSet<String>();

		for (String name : input.keySet())
			savedfs(name, "", 1, input);

		BufferedWriter in = new BufferedWriter(new FileWriter("/home/kmh/ANT/J/data/" + COUNT + ".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("/home/kmh/ANT/J/data/" + COUNT + ".out"));

		in.write(String.valueOf(exInput.size()));
		for (String line : exInput)
			in.write("\n" + line);
		in.close();

		exOutput = new ArrayList<String>();
		solution();

		out.write(exOutput.get(0));
		for (int i = 1; i < exOutput.size(); i++)
			out.write("\n" + exOutput.get(i));
		out.close();
	}

	private static void solution() throws Exception {
		Scanner sc = new Scanner(new FileReader("/home/kmh/ANT/J/data/" + COUNT + ".in"));
		TreeMap<String, Dir> tree = new TreeMap<String, Dir>();

		int N = sc.nextInt();
		while (N-- > 0) {
			TreeMap<String, Dir> subtree = tree;
			String[] childs = new String[sc.nextInt()];

			for (int i = 0; i < childs.length; i++)
				childs[i] = sc.next();

			for (String name : childs) {
				if (!subtree.containsKey(name))
					subtree.put(name, new Dir());
				subtree = subtree.get(name).childs;
			}
		}

		for (String name : tree.keySet())
			soldfs(name, "", tree);
	}

	private static void soldfs(String name, String indent, TreeMap<String, Dir> tree) {
		System.out.println(indent + name);
		exOutput.add(indent + name);
		indent += "--";

		for (String subname : tree.get(name).childs.keySet())
			soldfs(subname, indent, tree.get(name).childs);
	}

	private static void savedfs(String name, String path, int depth, HashMap<String, Child> tree) {
		path += " " + name;

		if (tree.get(name).childs.size() == 0) {
			System.out.print(depth);
			System.out.println(path);
			exInput.add(depth + path);
			return;
		}

		for (String subname : tree.get(name).childs.keySet())
			savedfs(subname, path, depth + 1, tree.get(name).childs);
	}

	private static void printdfs(String name, String indent,
			HashMap<String, Child> tree) {
		System.out.println(indent + name);
		indent += "--";

		for (String subname : tree.get(name).childs.keySet())
			printdfs(subname, indent, tree.get(name).childs);
	}

	private static int randomNumber(int first, int second) {
		return (int) (Math.random() * (second - first + 1)) + first;
	}

	private static String randomString(int first, int second) {
		return FRUIT[randomNumber(0, 23)];
	}

	private static class Child {
		public HashMap<String, Child> childs;

		public Child() {
			this.childs = new HashMap<String, Child>();
		}
	}

	private static class Dir {
		public TreeMap<String, Dir> childs;

		public Dir() {
			this.childs = new TreeMap<String, Dir>();
		}
	}
}