import java.util.Scanner;

class Sum_Using_Thread implements Runnable
{
	int m, sum = 0;
	static Sum_Using_Thread su = new Sum_Using_Thread();
	static Scanner sc = new Scanner(System.in);

	@Override
	public void run()
	{
		synchronized (this)
		{
			int n = 0;
			System.out.println("Enter n : ");
			n = sc.nextInt();

			su.sum += n;
		}
	}

	static void input()
	{
		System.out.println("Enter m : ");
		su.m = sc.nextInt();
	}

	public static void main(String[] args)
	{
		input();
		Thread th[] = new Thread[su.m];

		for (int i = 0; i < su.m; i++)
		{
			th[i] = new Thread(su);
			th[i].start();

			try
			{
				th[i].join();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}

		System.out.println("sum is - " + su.sum);
	}
}
