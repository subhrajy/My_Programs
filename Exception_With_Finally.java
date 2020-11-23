import java.util.Scanner;

public class Exception_With_Finally
{
	static Scanner sc = new Scanner(System.in);
	static int num0, num1;

	static void input() {
		System.out.println("Enter two numbers to divide. Number 2 should not be zero\n");
		num0 = sc.nextInt();
		num1 = sc.nextInt();
	}

	static void check_Numbers() throws ArithmeticException
	{
		if (num1 == 0)
		{
			try
			{
				throw new ArithmeticException();
			}

			finally
			{
				System.out.println("\nException to be handled by main() method");
			}
		}
	}

	public static void main(String[] args)
	{
		input();

		try
		{
			check_Numbers();
		}

		catch (ArithmeticException ae)
		{
			ae.getMessage();
		}

		finally
		{
			System.out.println("\nException caught");
		}
	}
}