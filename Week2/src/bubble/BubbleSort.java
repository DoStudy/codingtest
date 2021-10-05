/*
  Bubble 정렬
  서로 인접한 두 원소를 검사하여 정렬하는 알고리즘
  인접한 2개의 레코드를 비교하여 크기가 순서대로 되어 있지 않으면 서로 교환한다.
 */
package bubble;

import java.util.Arrays;

public class BubbleSort {

    public static void main(String[] args) {
        int[] array = {2, 4, 3, 1, 5};
        int[] answer = BubbleSort.bubbleSort(array);
        System.out.println(Arrays.toString(answer));
    }

    public static int[] bubbleSort(int[] array) {
        for (int j = array.length - 1; j > 0; j--) {
            for (int i = 0; i < j; i++) {
                if (array[i] > array[i + 1]) {
                    int tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                }
            }
        }
        return array;
    }
}
