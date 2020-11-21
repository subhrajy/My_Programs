import java.util.Scanner;

class Question_4 implements Runnable
{
	int m, sum = 0;
	static Question_4 q4 = new Question_4();
	static Scanner sc = new Scanner(System.in);

	@Override
	public void run()
	{
		synchronized (this)
		{
			int n = 0;
			System.out.println("Enter n : ");
			n = sc.nextInt();

			q4.sum += n;
		}
	}

	static void input()
	{
		System.out.println("Enter m : ");
		q4.m = sc.nextInt();
	}

	public static void main(String[] args)
	{
		input();

		Thread th[] = new Thread[q4.m];

		for (int i = 0; i < q4.m; i++)
		{
			th[i] = new Thread(q4);
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

		System.out.println("sum is - " + q4.sum);
	}
}
