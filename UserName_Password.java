class WrongCredentialException extends Throwable
{
	public WrongCredentialException(String msg)
	{
		super(msg);
	}
}

public class UserName_Password
{
	public static void main(String[] args)
	{
		if (args.length == 0)
		{
			try
			{
				throw new ArithmeticException("\nEmpty UserName and Password.");
			}

			catch (ArithmeticException ae)
			{
				System.out.println(ae.getMessage());
			}
		}

		else if (args.length == 1)
		{
			try
			{
				throw new ArrayIndexOutOfBoundsException("\nOnly one argument is passed.");
			}

			catch (ArrayIndexOutOfBoundsException ai)
			{
				System.out.println(ai.getMessage());
			}
		}

		if (!args[0].equals("username") || !args[1].equals("password"))
		{
			try {
				throw new WrongCredentialException("UserName or Password do not match");
			}

			catch (WrongCredentialException wc)
			{
				System.out.println(wc.getMessage());
			}
		}
	}
}
