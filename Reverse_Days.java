import java.util.*;

public class Reverse_Days
{
	static String days = "Monday Tuesday Wednesday Thursday Friday Saturday Sunday";

	static String reverse_String(String s)
	{
		String[] rev = s.split(" ");
		List l = Arrays.asList(rev);
		Collections.reverse(l);

		return  l.toString();
	}

	public static void main(String[] args)
	{
		System.out.println(reverse_String(days));
	}
}