package mvv;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Path;
import java.util.Scanner;

public class MVV
{
  public static void main(String[] args)
  {
    try
    {
      int[] arr;
      int i;
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int length = Integer.parseInt(br.readLine());
      String text = br.readLine();
      arr = new int[length];
      long t1 = System.currentTimeMillis();

      for (i = 0; i < length; i++)
      {
        char c = text.charAt(i);
        switch (c)
        {
          case 'R':
            arr[i] = 0;
            break;
          case 'G':
            arr[i] = 1;
            break;
          default:
            arr[i] = 2;
            break;
        }
      }
      System.out.println(""+length);
      while (length > 1)
      {
        for (i = 0; i < length - 1; i++)
        {
          int tmp = (arr[i] + arr[i + 1]) % 3;
          tmp = 3 - tmp;
          tmp %= 3;
          arr[i] = tmp;
        }
        length--;
      }
      String result;
      switch (arr[0])
      {
        case 0:
          result = "R";
          break;
        case 1:
          result = "G";
          break;
        default:
          result = "B";
          break;
      }
      System.out.println(result);
      long t2 = System.currentTimeMillis();
      System.out.println("" + (t2 - t1) / 1000.0 + "\n");
    } catch (IOException e)
    {
      e.printStackTrace();
    }

  }
}
