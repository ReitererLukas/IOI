package ads;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

public class Reader
{
  public static int k;

  public static int[][] read(String path) throws FileNotFoundException
  {
    int y = 0, x = 0;
    int[][] arr;
    File file = new File(path);
    Scanner sc = new Scanner(file);
    String in;
    String[] tokens;
    if(sc.hasNext())
    {
      in = sc.nextLine();
      tokens = in.split(" ");
      x = Integer.parseInt(tokens[0]);
      y = Integer.parseInt(tokens[1]);
      k = Integer.parseInt(tokens[2]);
    }

    arr = new int[y][x];
    fillArr(arr);
    int i = 0,j;
    while(sc.hasNext())
    {
      in = sc.nextLine();
      tokens = in.split(" ");
      for(j = 0;j<tokens.length;j++)
      {
        arr[i][j] = Integer.parseInt(tokens[j]);
      }
      i++;
    }

    sc.close();

    return arr;
  }

  private static int[][] fillArr(int[][] arr)
  {
    int i,j;
    for(i = 0;i<arr.length;i++)
    {
      for(j = 0;j<arr[i].length;j++)
      {
        arr[i][j] = 0;
      }
    }

    return arr;
  }

}
