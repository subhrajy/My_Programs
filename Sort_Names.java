import java.util.Arrays;
import java.util.Scanner;

public class Sort_Names
{
	static Scanner sc = new Scanner(System.in);
	static String names = null;
	static String[] name_Array;

	static void input()
	{
		System.out.println("\nEnter the names separated by comma ','");
		names = sc.nextLine();
	}

	static void output(String[] arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i] + " ");
		}
	}

	public static void main(String[] args)
	{
		input();
		name_Array = names.split(",");
		Arrays.sort(name_Array);

		output(name_Array);
	}
}
