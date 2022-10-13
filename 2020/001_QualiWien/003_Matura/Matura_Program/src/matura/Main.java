package matura;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Scanner;

public class Main
{
  private static int length;

  public static void main(String[] args)
  {
    try
    {
      int[][] arr;
      //arr = read();
      arr = read2("in.txt");


      boolean[] rows = new boolean[length];
      boolean[] columns = new boolean[length];
      Arrays.fill(rows, true);
      Arrays.fill(columns, true);



    } catch (IOException e)
    {
      System.out.println(e);
    }
  }

  private static void printArr(int[][] arr)
  {
    for (int i = 0; i < arr.length; i++)
    {
      for (int j = 0; j < arr[i].length; j++)
      {
        System.out.print(arr[i][j] + " ");
      }
      System.out.println();
    }
  }

  private static int[][] read2(String path) throws IOException
  {
    Scanner sc = new Scanner(Path.of(System.getProperty("user.dir") + "\\src\\files\\" + path));
    length = Integer.parseInt(sc.nextLine());
    int[][] arr = new int[length][4];
    for (int i = 0; i < length; i++)
    {
      String[] tokens = sc.nextLine().split(" ");
      for (int j = 0; j < tokens.length; j++)
      {
        arr[i][j] = Integer.parseInt(tokens[j]);
      }
    }
    sc.close();
    return arr;
  }

  private static int[][] read() throws IOException
  {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    length = Integer.parseInt(br.readLine());
    int[][] arr = new int[length][4];
    for (int i = 0; i < length; i++)
    {
      String[] tokens = br.readLine().split(" ");
      for (int j = 0; j < tokens.length; j++)
      {
        arr[i][j] = Integer.parseInt(tokens[j]);
      }
    }
    br.close();
    return arr;
  }
}
