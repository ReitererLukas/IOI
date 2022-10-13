package mvv;

public class test
{
  public static void main(String[] args)
  {
    int i, tmp, j;
    int[][] arr = new int[27][3];
    for (i = 0; i < 27; i++)
    {
      tmp = i;
      System.out.print("case \"");
      for (j = 0; j < 3; j++)
      {
        arr[i][j] = tmp % 3;
        System.out.print("" + tmp % 3);
        tmp /= 3;
      }
      System.out.println("\":\n\nbreak;");
    }
    /*System.out.println("-------------");
    int[] erg = new int[27];
    for (i = 0; i < arr.length; i++)
    {
      int sum1 = (arr[i][0] + arr[i][1]) % 3;
      sum1 = 3 - sum1;
      sum1 %= 3;

      int sum2 = (arr[i][1] + arr[i][2]) % 3;
      sum2 = 3 - sum2;
      sum2 %= 3;

      int sum3 = (sum1 + sum2) % 3;
      sum3 = 3 - sum3;
      erg[i] = sum3 % 3;
      //System.out.println(""+erg[i]);
    }

    for (i = 0; i < 27; i++)
    {
      System.out.print(arr[i][0]+""+arr[i][1]+""+arr[i][2]+" = ");
      arr[i][0] *= 2;
      arr[i][1] *= 4;
      arr[i][2] *= 3;
      int sum = 0;
      for (j = 0; j < 3; j++)
      {
        sum += arr[i][j];
      }

      System.out.println(erg[i] + " ==> " + sum % 3);
    }*/
  }
}
