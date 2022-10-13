package berg;

import java.io.IOException;
import java.nio.file.Path;
import java.util.Scanner;

public class Reader
{
  public static int[] read(String path) throws IOException
  {
    int[] arr;
    Scanner sc = new Scanner(Path.of(path));

    int length = Integer.parseInt(sc.nextLine());
    arr = new int[length];
    String[] token = sc.nextLine().split(" ");

    for (int i = 0; i < token.length; i++)
    {
      arr[i] = Integer.parseInt(token[i]);
    }

    return arr;
  }
}
