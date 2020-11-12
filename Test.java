import java.util.Scanner;

class NameFormatException extends Exception
{
	public NameFormatException(String msg)
	{
		super(msg);
	}
}

public class Test 
{
	static String name;
	static Scanner sc = new Scanner(System.in);
		
	static void input()
	{
		System.out.println("Please enter your name - ");
		name =  sc.next();
	}
	
	static void check_Validity(String name)
	{
		for (int i = 0; i < name.length(); i++) 
		{
			char ch = name.charAt(i);
			if (! Character.isAlphabetic(ch))
			{
				try 
				{
					throw new NameFormatException("\nSorry, your name can only contain English alphabets");
				} 
				catch (NameFormatException e) 
				{
					System.out.println(e.getMessage());
				}
			}
			else
			{
				System.out.println("\nEverything okay!!");
				System.exit(0);
			}
		}
	}
	
	public static void main(String[] args) 
	{
		input();
		check_Validity(name);
	}
}
