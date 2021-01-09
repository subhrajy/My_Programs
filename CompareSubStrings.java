import java.util.*;

public class CompareSubStrings 
{
    public static void getSmallestAndLargest(String s, int k) 
    {
        String smallest = "";
        String largest = "";
        
        String[] arr = new String[s.length()];
        
        for (int i = 0; i <= s.length() - k; i++)
        {
            arr[i] = s.substring(i, i + k);
        }        
        
        for (int i = 0; i < arr.length - 1; i++)
        {
            for (int j = i + 1; j < arr.length - (k - 1); j++)
            {
                String temp = "";
                
                if (arr[i].compareTo(arr[j]) > 0)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        
        smallest = arr[0];
        largest = arr[arr.length - k];
        
        System.out.println(smallest);
	System.out.println(largest);
    }


    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        getSmallestAndLargest(s, k);
    }
}
