import java.util.Scanner;

public class Odd_Even
{
	static Scanner sc = new Scanner(System.in);
	int m, n;
	static Odd_Even oe = new Odd_Even();

	public void input()
	{
		System.out.println("\nEnter 2 numbers 'M' and 'N' : ");

		m = sc.nextInt();
		n = sc.nextInt();

		if (m >= n)
		{
			System.out.println("\n'M' should be lesser than 'N'.\nPlease, enter again.");
			input();
		}
	}

	public void print_Even()
	{
		synchronized (this)
		{
			while (m < n)
			{
				while (m % 2 != 0)
				{
					try
					{
						wait();
					}
					catch (InterruptedException e)
					{
						e.printStackTrace();
					}
				}
				System.out.println("Child : " + m);
				m += 1;

				notify();
			}
		}
	}

	public void print_Odd()
	{
		synchronized (this)
		{
			while (m < n)
			{
				while (m % 2 == 0)
				{
					try
					{
						wait();
					}
					catch (InterruptedException e)
					{
						e.printStackTrace();
					}
				}
				System.out.println("Parent : " + m);
				m += 1;

				notify();
			}
		}
	}

	public static void main(String[] args)
	{
		oe.input();

		Thread th1 = new Thread(new Runnable()
		{
			@Override
			public void run()
			{
				oe.print_Even();
			}
		});

		Thread th2 = new Thread(new Runnable()
		{
			@Override
			public void run()
			{
				oe.print_Odd();
			}
		});

		th1.start();
		th2.start();
	}
}
