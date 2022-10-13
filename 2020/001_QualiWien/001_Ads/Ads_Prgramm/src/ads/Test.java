package ads;

import java.util.Arrays;

public class Test
{
  public static void main(String[] args)
  {
    long t1 = System.currentTimeMillis();
    int[][] arr = new int[1000][1000];
    for(int i = 0;i<arr.length;i++)
    {
      for(int j = 0;j<arr[i].length;j++)
      {
        arr[i][j] = 0;
      }
    }
    long t2 = System.currentTimeMillis();
    System.out.println(""+(t2-t1));
  }
}
