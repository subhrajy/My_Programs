import java.util.Scanner;

class NumberExceedException extends Throwable
{
    public NumberExceedException(String msg)
    {
        super(msg);
    }
}

public class Multiple_Exception
{
    static Scanner sc = new Scanner(System.in);
    static int num0, num1;

    static void input() {
        System.out.println("Enter two numbers to divide. Number 1 should be greater than number 2. And number 2 should not be zero\n");
        num0 = sc.nextInt();
        num1 = sc.nextInt();
    }

    static void check_Numbers()
    {
        if (num0 < num1)
        {
            try
            {
                throw new NumberExceedException("Number 1 is lesser than number 2");
            }
            catch (NumberExceedException e)
            {
                System.out.println(e.getMessage());
            }
        }

        if (num1 == 0)
        {
            try
            {
                throw new ArithmeticException("can not divide by zero");
            }
            catch (ArithmeticException ae)
            {
                System.out.println(ae.getMessage());
            }
        }
    }

    public static void main(String[] args)
    {
        input();
        check_Numbers();
    }
}