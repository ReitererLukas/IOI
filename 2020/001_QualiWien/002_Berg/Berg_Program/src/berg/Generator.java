package berg;

import java.io.File;
import java.io.PrintWriter;

public class Generator
{
  public static void main(String[] args)
  {
    try
    {
      int n = 10000;
      PrintWriter pw = new PrintWriter(System.getProperty("user.dir") + "\\src\\files\\in2.txt");

      pw.append(n + "\n");
      for (int i = 0; i < n; i++)
      {
        int rand = (int) (Math.random() * 1000-1);
        if (i == n - 1)
        {
          pw.append(rand + "");
          //System.out.print(rand + "");
        } else
        {
          pw.append(rand + " ");
          //System.out.print(rand + " ");
        }
      }

      pw.close();
    } catch (Exception e)
    {
      System.out.println(e);
    }
  }

}
