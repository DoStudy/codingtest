/*
    선택 정렬은 다음과 같은 순서로 이루어진다.
    1. 주어진 리스트 중에 최소값을 찾는다.
    2. 그 값을 맨 앞에 위치한 값과 교체한다.
    3. 맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다.
 */
package selection;

import java.util.Arrays;

public class SelectionSort {

    public static void main(String[] args) {
        SelectionSort sort = new SelectionSort();
        int[] array = {3, 4, 2, 5, 1};
        int[] answer = sort.selectionSort(array);
        System.out.println(Arrays.toString(answer));
    }

    public int[] selectionSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int index = findMinIndex(i, array);
            int tmp = array[i];
            array[i] = array[index];
            array[index] = tmp;
        }

        return array;
    }

    private int findMinIndex(int start, int[] array) {
        int min = (int) (Math.pow(2, 31) - 1); // int의 최댓값
        int index = -1;
        for (int i = start; i < array.length; i++) {
            if (array[i] <= min) {
                min = array[i];
                index = i;
            }
        }

        return index;
    }

}
