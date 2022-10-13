package ex;

import java.util.Arrays;

public class Main
{
  public static void main(String[] args)
  {
    bubbleSort();
  }

  private static int[] createArr()
  {
    int[] arr = new int[50];
    for (int i = 0; i < arr.length; i++)
    {
      arr[i] = (int) (Math.random() * 1000);
    }

    return arr;
  }

  private static void printArr(int[] arr)
  {
    for (int i = 0; i < arr.length; i++)
    {
      System.out.print("" + arr[i]);
      if (i != arr.length - 1)
      {
        System.out.print(", ");
      }
    }
    System.out.println();
  }

  private static void bubbleSort()
  {
    int[] arr = createArr();
    for (int i = 0; i < arr.length; i++)
    {
      for (int j = 0; j < arr.length; j++)
      {
        if (arr[i] < arr[j])
        {
          int tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      }
    }
    printArr(arr);
  }
}
