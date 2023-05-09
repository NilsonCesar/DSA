import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Quicksort {
	public static void sort(Integer[] arr) {
		List<Integer> list = Arrays.asList(arr);

		// The shuffle is necessary to turn improbable the worst case:
		// the elements are in decreasing order.
		// In quicksort, this would be quadratic.
		Collections.shuffle(list);
		Integer[] shuffledArr = list.toArray(new Integer[0]);
		for(int i = 0; i < arr.length; i++) arr[i] = shuffledArr[i];
		
		sort(arr, 0, arr.length - 1);
	}

	private static void sort(Integer[] arr, int lo, int hi) {
		if(hi <= lo) return;
		int j = partition(arr, lo, hi);
		sort(arr, lo, j - 1);
		sort(arr, j + 1, hi);
	}

	private static int partition(Integer[] arr, int lo, int hi) {
		int e = arr[lo];
		int i = lo, j = hi + 1;

		while(true) {
			while(arr[++i] < e)
				if(i == hi) break;

			while(arr[--j] > e)
				if(j == lo) break;

			if(i >= j) break;
			change(arr, i, j);
		}

		change(arr, lo, j);

		return j;
	}

	private static void change(Integer[] arr, int i, int j) {
		int c = arr[i];
		arr[i] = arr[j];
		arr[j] = c;
	}
}