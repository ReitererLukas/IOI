package mvv;

import java.io.PrintWriter;

public class Generator
{
  public static void main(String[] args)
  {
    try
    {
      int n = 50000;
      PrintWriter pw = new PrintWriter(System.getProperty("user.dir") + "\\src\\files\\in2.txt");

      pw.append(n + "\n");
      for (int i = 0; i < n; i++)
      {
        int rand = (int) (Math.random() * 100)%3;
        switch (rand)
        {
          case 0:
            pw.append("R");
            break;
          case 1:
            pw.append("G");
            break;
          case 2:
            pw.append("B");
            break;
        }
      }

      pw.close();
      System.out.println();
    } catch (Exception e)
    {
      System.out.println(e);
    }
  }
}
