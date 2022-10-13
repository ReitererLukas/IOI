package ads;

import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.nio.Buffer;
import java.nio.file.Path;
import java.util.Scanner;

public class ADS
{
  private static int k;

  public static void main(String[] args)
  {
    long t1 = System.currentTimeMillis();
    int[][] arr;
    int max;
    try
    {
      //arr = read2(System.getProperty("user.dir") + "\\src\\files\\in2.txt");
      arr = read();

      max = calculateVisitors(arr, k);
      System.out.println("" + max);
      long t2 = System.currentTimeMillis();
      System.out.println("Zeit: " + ((t2 - t1) / 1000.0));

    } catch (IOException e)
    {
      System.out.println(e);
    }
  }


  private static void printArr(int[][] arr)
  {
    int i, j;
    for (i = 0; i < arr.length; i++)
    {
      for (j = 0; j < arr[i].length; j++)
      {
        System.out.print(String.format("%4d", arr[i][j]));
      }
      System.out.println();
    }
  }

  private static int calculateVisitors(int[][] arr, int k)
  {
    int max = 0, y, x;
    for (y = k; y < arr.length - k; y++)
    {
      for (x = k; x < arr[y].length - k; x++)
      {
        int vis = 0;
        int endX = x + (k - 1);
        for (int i = x - (k - 1); i <= endX; i++)
        {
          vis += arr[y][i];
        }

        for (int i = 1; i < k; i++)
        {
          endX = x + (k - 1) - i;
          for (int j = x - (k - 1) + i; j <= endX; j++)
          {
            vis += arr[y + i][j];
            vis += arr[y - i][j];
          }
        }
        if (vis > max)
        {
          //System.out.println(x + ":" + y+" = "+arr[y][x]);
          max = vis;
        }
      }
    }


    return max;
  }

  /*public static int[][] read2(String path) throws IOException
  {
    int y, x;
    int[][] arr;
    Scanner sc = new Scanner(Path.of(path));
    String[] tokens = sc.nextLine().split(" ");
    x = Integer.parseInt(tokens[0]);
    y = Integer.parseInt(tokens[1]);
    k = Integer.parseInt(tokens[2]);

    arr = new int[y + 2 * k][x + 2 * k];
    fillArr(arr);
    for (int i = k; i < y + k; i++)
    {
      tokens = sc.nextLine().split(" ");
      for (int j = k; j < tokens.length + k; j++)
      {
        arr[i][j] = Integer.parseInt(tokens[j - k]);
      }
    }
    sc.close();
    return arr;
  }*/

  private static int[][] read() throws IOException
  {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int y, x;
    int[][] arr;
    String[] tokens = br.readLine().split(" ");
    x = Integer.parseInt(tokens[0]);
    y = Integer.parseInt(tokens[1]);
    k = Integer.parseInt(tokens[2]);

    arr = new int[y + 2 * k][x + 2 * k];
    fillArr(arr);
    for (int i = k; i < y + k; i++)
    {
      tokens = br.readLine().split(" ");
      for (int j = k; j < tokens.length + k; j++)
      {
        arr[i][j] = Integer.parseInt(tokens[j - k]);
      }
    }
    br.close();
    return arr;
  }

  private static int[][] fillArr(int[][] arr)
  {
    int i, j;
    for (i = 0; i < arr.length; i++)
    {
      for (j = 0; j < arr[i].length; j++)
      {
        arr[i][j] = 0;
      }
    }

    return arr;
  }
}
