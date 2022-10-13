package berg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BERG
{
  public static void main(String[] args)
  {
    try
    {
      int[] arr;

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int length = Integer.parseInt(br.readLine());
      arr = new int[length];
      String[] token = br.readLine().split(" ");

      for (int i = 0; i < token.length; i++)
      {
        arr[i] = Integer.parseInt(token[i]);
      }

      int i, counter = 0;
      for (i = 0; i < arr.length - 1; i++)
      {
        int j = i + 1;
        boolean isOver = false;
        while (!isOver && j < arr.length)
        {
          if (arr[j] == arr[i])
          {
            counter++;
          } else if (arr[j] > arr[i])
          {
            isOver = true;
          }
          j++;
        }
      }
      counter *= 2;
      System.out.println(counter);
    } catch (IOException e)
    {
      e.printStackTrace();
    }
  }
}