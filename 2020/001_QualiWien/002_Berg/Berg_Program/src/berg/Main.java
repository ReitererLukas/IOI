package berg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.file.Path;
import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    try
    {
      //long t1 = System.currentTimeMillis();

      int[] arr;
      //System.getProperty("user.dir") + "\\src\\files\\in2.txt"
      arr = read();
      //System.out.println("finish" + arr.length);
      int counter = calcRoutesCounter(arr);
      //printArr(arr);
      System.out.println("" + counter);

      //long t2 = System.currentTimeMillis();
      //System.out.println("" + (t2 - t1) / 1000.0 + "\n");
    } catch (IOException e)
    {
      e.printStackTrace();
    }
  }

  /*private static int[] read(String s) throws IOException
  {
    int[] arr;
    Scanner sc = new Scanner(Path.of(s));
    int length = Integer.parseInt(sc.nextLine());
    arr = new int[length];
    String[] token = sc.nextLine().split(" ");

    for (int i = 0; i < token.length; i++)
    {
      arr[i] = Integer.parseInt(token[i]);
    }

    return arr;
  }*/

  private static int[] read() throws IOException
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

    return arr;
  }

  /*private static void printArr(int[] arr)
  {
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
      System.out.print(arr[i] + ", ");
    }
    System.out.println("" + arr[i]);
  }*/

  private static int calcRoutesCounter(int[] arr)
  {
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

    return counter * 2;
  }

  /*private static int calcRoutesCounter2(int[] arr)
  {
    int[] position = new int[arr.length];
    position = fillArr(position);

    int i, counter = 0, setLength = 0;
    int[] set = new int[arr.length];

    for (i = 0; i < arr.length; i++)
    {
      int j = setLength - 1;
      while (j >= 0)
      {
        int x = set[j];
        if (x < arr[i])
        {
          position[x] = 0;
          set[j] = set[setLength - 1];//removeElement
          setLength--;
        } else if (x == arr[i])
        {
          counter += position[x];
        }
        j--;
      }
      set[setLength] = arr[i];
      setLength++;
      position[arr[i]]++;
    }

    return counter * 2;
  }

  private static int[] fillArr(int[] position)
  {
    int i;
    for (i = 0; i < position.length; i++)
    {
      position[i] = 0;
    }
    return position;
  }*/
}