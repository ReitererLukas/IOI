package ads;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Generator
{
  public static void main(String[] args)
  {
    int size = 300;
    PrintWriter pw = null;
    try
    {
      pw = new PrintWriter(new File(System.getProperty("user.dir") + "\\src\\files\\in2.txt"));
    } catch (FileNotFoundException e)
    {
      System.out.println(e);
    }
    pw.append(size+" "+size+" "+100+""+ String.format("%n"));
    int[][] arr = new int[size][size];
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        pw.append("" + ((int) (Math.random() * 1000)));
        if (j != size-1)
        {
          pw.append(" ");
        }
        //arr[i][j] = (int) (Math.random() * 1000);
      }
      if(i != size-1)
      {
        pw.append(String.format("%n"));
      }
    }

    pw.close();
    //printArr(arr);
  }



  private static void printArr(int[][] arr)
  {
    int i, j;
    for (i = 0; i < arr.length; i++)
    {
      for (j = 0; j < arr[i].length; j++)
      {
        System.out.print(" " + arr[i][j]);
      }
      System.out.println();
    }
  }
}
