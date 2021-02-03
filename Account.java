import java.util.Scanner;

// user-defined exception class
class MinimumBalanceException extends Exception
{
	public MinimumBalanceException(String s)
	{
		super(s);
	}
}

class Account 
{
	String a1_14;
	int a2_14;
	double a3_14 = 0.00, a4_14 = 500.00;
	
	public Account(String name, int acc_No)
	{
		this.a2_14 = acc_No;
		this.a1_14 = name;
		System.out.println("you have " + this.a3_14 + "balance");
	}
	
	
	void deposit(int amt)
	{
		this.a3_14 += (double)amt;
	}
	
	void withdraw(Account ac1, Double amt)
	{
		double res = a3_14 - amt;
		if (res <= 500)
		{
			try 
			{
				throw new MinimumBalanceException("Account balance can not be less than Rs.500. Transaction cancelled.");
			}
			catch (MinimumBalanceException ex)
			{
				System.out.println(ex.getMessage());
			}
		}
		else 
		{
			this.a3_14 = res;
		}
		
	}
	
	void transfer(Account ac1, double amt)
	{
		double res = a3_14 - amt;
		try
		{
			if (res <= 500.0) 
			{
				throw new MinimumBalanceException("Account balance can not be less than Rs.500. Transaction cancelled.");
			}
			else
			{
				System.out.println("Transaction complete.\nCurrent balance is " + (this.a3_14 - amt));
			}
		}
		catch (MinimumBalanceException ex)
		{
			System.out.println(ex.getMessage());
		}
	}
	
	void show(Account ac)
	{
		System.out.println("\n" + this.a3_14);
	}
}


public class Test
{
	static Scanner sc = new Scanner(System.in);
	static int a5_14;
	
	static void withdraw(Account ac)
	{
		System.out.println("Enter amount");
		ac.withdraw(ac, sc.nextDouble());
	}
	
	static void transfer(Account ac)
	{
		System.out.println("Enter amount");
		ac.withdraw(ac, sc.nextDouble());
	}
	
	static void deposit(Account ac)
	{
		System.out.println("Enter amount");
		ac.deposit(sc.nextInt());
	}
	
	static void show(Account ac)
	{
		ac.show(ac);
	}
	
	// execution starts here
	public static void main(String[] args) 
	{
		System.out.println("Enter the details as name\naccount number\n");
		Account ac = new Account(sc.next(), sc.nextInt());
		
		while (true)
		{
			System.out.println("Enter 1) withdraw\n2) tranfer money\n3)deposit\n4)show balance\n0) to exit\n");
			ch = sc.nextInt();
			
			if (a5_14 == 1)
			{
				withdraw(ac);
			}
			else if (a5_14 == 2)
			{
				transfer(ac);
			}
			else if (a5_14 == 3)
			{
				deposit(ac);
			}
			else if (a5_14 == 4) 
			{
				show(ac);
			}
			else if (a5_14 == 0)
			{
				System.exit(0);
			}
		}
	}
}
